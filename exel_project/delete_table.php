<?php
/**
 * API: Usuwanie tabeli z bazy danych we4sai_erasmuss
 */

header('Content-Type: application/json; charset=utf-8');
require_once __DIR__ . '/../config/db.php';

$raw_input = file_get_contents('php://input');
$data = json_decode($raw_input, true);

if ($is_remote_bridge) {
    echo forward_to_remote_api('api/delete_table.php', 'POST', $raw_input ?: json_encode($_POST));
    exit;
}

$id = isset($data['id']) ? (int)$data['id'] : (isset($_POST['id']) ? (int)$_POST['id'] : 0);

if ($id <= 0) {
    echo json_encode([
        'success' => false,
        'error' => 'Niepoprawny identyfikator tabeli.'
    ]);
    exit;
}

require_login_json();

// Pobierz nazwę fizycznej tabeli SQL przed usunięciem (zwykły użytkownik tylko własne)
$owner_sql = is_admin() ? '' : ' AND user_id = ' . (int)current_user()['id'];
$stmt = $conn->prepare("SELECT name, sql_table_name FROM `$registry_table` WHERE id = ?$owner_sql");
$stmt->bind_param("i", $id);
$stmt->execute();
$res = $stmt->get_result();
$row = $res->fetch_assoc();
$stmt->close();

if (!$row) {
    echo json_encode([
        'success' => false,
        'error' => "Tabela o tym ID nie istnieje w bazie danych $db_name."
    ]);
    exit;
}

$tableName = $row['name'];
$sqlTableName = $row['sql_table_name'];

// Usuń fizyczną tabelę SQL jeśli istnieje
if (!empty($sqlTableName)) {
    $conn->query("DROP TABLE IF EXISTS `$sqlTableName`");
}

// Usuń z rejestru
$del_stmt = $conn->prepare("DELETE FROM `$registry_table` WHERE id = ?");
$del_stmt->bind_param("i", $id);
$del_stmt->execute();
$del_stmt->close();

echo json_encode([
    'success' => true,
    'message' => "Tabela '$tableName' została pomyślnie usunięta z bazy $db_name."
]);
