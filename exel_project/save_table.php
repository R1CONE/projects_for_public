<?php
/**
 * API: Zapisywanie / aktualizacja tabeli Excel w bazie danych we4sai_erasmuss
 * Zapisuje metadane i dane do `comp41_saved_sheets` oraz tworzy fizyczną tabelę relacyjną w MySQL!
 */

header('Content-Type: application/json; charset=utf-8');
require_once __DIR__ . '/../config/db.php';

// Pobranie danych przesłanych metodą POST (JSON)
$raw_input = file_get_contents('php://input');
$data = json_decode($raw_input, true);

if (!$data) {
    if (!empty($_POST)) {
        $data = $_POST;
        if (isset($data['headers']) && is_string($data['headers'])) {
            $data['headers'] = json_decode($data['headers'], true);
        }
        if (isset($data['data']) && is_string($data['data'])) {
            $data['data'] = json_decode($data['data'], true);
        }
    }
}

if ($is_remote_bridge) {
    echo forward_to_remote_api('api/save_table.php', 'POST', $raw_input ?: json_encode($data));
    exit;
}

require_login_json();

if (!$data) {
    echo json_encode([
        'success' => false,
        'error' => 'Brak danych do zapisu lub nieprawidłowy format JSON.'
    ]);
    exit;
}

$id = isset($data['id']) && (int)$data['id'] > 0 ? (int)$data['id'] : null;
$name = isset($data['name']) ? trim($data['name']) : '';
$headers = isset($data['headers']) && is_array($data['headers']) ? $data['headers'] : [];
$sheet_data = isset($data['data']) && is_array($data['data']) ? $data['data'] : [];

// Walidacja nazwy tabeli
if (empty($name)) {
    echo json_encode([
        'success' => false,
        'error' => 'Podaj nazwę tabeli! Nazwa nie może być pusta.'
    ]);
    exit;
}

// Obliczenie wymiarów
$row_count = count($sheet_data);
$col_count = count($headers);
if ($col_count === 0 && $row_count > 0) {
    $col_count = count($sheet_data[0]);
    for ($i = 0; $i < $col_count; $i++) {
        $headers[] = chr(65 + ($i % 26)); // A, B, C...
    }
}

$headers_json = json_encode($headers, JSON_UNESCAPED_UNICODE);
$sheet_data_json = json_encode($sheet_data, JSON_UNESCAPED_UNICODE);

$me_id = (int)current_user()['id'];
$admin = is_admin();

// Jeśli edytujemy istniejący arkusz, sprawdź prawo własności
if ($id) {
    $own_stmt = $conn->prepare("SELECT user_id FROM `$registry_table` WHERE id = ?");
    $own_stmt->bind_param("i", $id);
    $own_stmt->execute();
    $own_row = $own_stmt->get_result()->fetch_assoc();
    $own_stmt->close();
    if (!$own_row || (!$admin && (int)$own_row['user_id'] !== $me_id)) {
        echo json_encode(['success' => false, 'error' => 'Nie masz uprawnień do edycji tej tabeli.']);
        exit;
    }
}

$sql_table_name = sanitize_sql_table_name($name);

// Sprawdzenie, czy istnieje już inna tabela o tej samej nazwie lub tej samej tabeli SQL
$check_stmt = $conn->prepare("SELECT id, user_id FROM `$registry_table` WHERE (name = ? OR sql_table_name = ?) AND id != ?");
$check_id = $id ? $id : 0;
$check_stmt->bind_param("ssi", $name, $sql_table_name, $check_id);
$check_stmt->execute();
$check_res = $check_stmt->get_result();

if ($check_res->num_rows > 0) {
    $existing = $check_res->fetch_assoc();
    if (!$id && ($admin || (int)$existing['user_id'] === $me_id)) {
        // Zapis pod istniejącą nazwą własnej tabeli = aktualizacja
        $id = (int)$existing['id'];
    } else {
        $check_stmt->close();
        echo json_encode(['success' => false, 'error' => 'Tabela o takiej nazwie już istnieje. Wybierz inną nazwę.']);
        exit;
    }
}
$check_stmt->close();

// 1. Zapis lub aktualizacja w rejestrze
if ($id) {
    // Aktualizacja istniejącej tabeli
    $stmt = $conn->prepare("UPDATE `$registry_table` SET name = ?, row_count = ?, col_count = ?, headers = ?, sheet_data = ?, sql_table_name = ?, updated_at = NOW() WHERE id = ?");
    $stmt->bind_param("siisssi", $name, $row_count, $col_count, $headers_json, $sheet_data_json, $sql_table_name, $id);
    if (!$stmt->execute()) {
        echo json_encode(['success' => false, 'error' => 'Błąd aktualizacji tabeli: ' . $stmt->error]);
        exit;
    }
    $saved_id = $id;
    $message = "Tabela '$name' została pomyślnie zaktualizowana w bazie $db_name!";
} else {
    // Nowy wpis w tabeli
    $stmt = $conn->prepare("INSERT INTO `$registry_table` (name, row_count, col_count, headers, sheet_data, sql_table_name, user_id, created_at, updated_at) VALUES (?, ?, ?, ?, ?, ?, ?, NOW(), NOW())");
    $stmt->bind_param("siisssi", $name, $row_count, $col_count, $headers_json, $sheet_data_json, $sql_table_name, $me_id);
    if (!$stmt->execute()) {
        echo json_encode(['success' => false, 'error' => 'Błąd zapisu tabeli: ' . $stmt->error]);
        exit;
    }
    $saved_id = $stmt->insert_id;
    $message = "Tabela '$name' została pomyślnie zapisana do bazy danych $db_name!";
}
$stmt->close();

// 2. Utworzenie fizycznej tabeli MySQL dedykowanej dla tego arkusza
$conn->query("DROP TABLE IF EXISTS `$sql_table_name`");

// Budowanie zapytania CREATE TABLE
$create_cols = ["`id` INT AUTO_INCREMENT PRIMARY KEY", "`wiersz_nr` INT NOT NULL"];
$used_col_names = [];

for ($c = 0; $c < $col_count; $c++) {
    $col_title = isset($headers[$c]) && trim($headers[$c]) !== '' ? trim($headers[$c]) : 'Kolumna_' . ($c + 1);
    $clean_col = preg_replace('/[^a-zA-Z0-9_]/', '_', $col_title);
    $clean_col = trim($clean_col, '_');
    if (empty($clean_col) || is_numeric($clean_col[0])) {
        $clean_col = 'kol_' . ($c + 1) . ($clean_col ? '_' . $clean_col : '');
    }
    if (in_array($clean_col, $used_col_names)) {
        $clean_col .= '_' . ($c + 1);
    }
    $used_col_names[] = $clean_col;
    $create_cols[] = "`$clean_col` TEXT NULL";
}

$sql_create_dynamic = "CREATE TABLE `$sql_table_name` (" . implode(', ', $create_cols) . ") ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;";

if ($conn->query($sql_create_dynamic)) {
    // Wstawianie wierszy danych do fizycznej tabeli MySQL
    if (!empty($sheet_data)) {
        $col_names_sql = '`wiersz_nr`, ' . implode(', ', array_map(function($c) { return "`$c`"; }, $used_col_names));
        $placeholders = '?' . str_repeat(', ?', count($used_col_names));
        
        $insert_sql = "INSERT INTO `$sql_table_name` ($col_names_sql) VALUES ($placeholders)";
        $insert_stmt = $conn->prepare($insert_sql);
        
        if ($insert_stmt) {
            $types = 'i' . str_repeat('s', count($used_col_names));
            
            foreach ($sheet_data as $row_idx => $row) {
                $row_nr = $row_idx + 1;
                $row_values = [$row_nr];
                for ($c = 0; $c < count($used_col_names); $c++) {
                    $val = isset($row[$c]) ? (string)$row[$c] : '';
                    $row_values[] = $val;
                }
                
                $bind_params = [];
                $bind_params[] = &$types;
                for ($i = 0; $i < count($row_values); $i++) {
                    $bind_params[] = &$row_values[$i];
                }
                call_user_func_array([$insert_stmt, 'bind_param'], $bind_params);
                $insert_stmt->execute();
            }
            $insert_stmt->close();
        }
    }
}

echo json_encode([
    'success' => true,
    'message' => $message,
    'id' => $saved_id,
    'name' => $name,
    'sql_table' => $sql_table_name,
    'row_count' => $row_count,
    'col_count' => $col_count
]);
