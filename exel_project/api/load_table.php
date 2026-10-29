<?php
/**
 * API: Pobieranie szczegółowych danych konkretnej tabeli po ID lub nazwie
 */

header('Content-Type: application/json; charset=utf-8');
require_once __DIR__ . '/../config/db.php';

require_login_json();

if (!$conn) {
    echo json_encode(['success' => false, 'error' => 'Brak połączenia z bazą danych.']);
    exit;
}

$id   = isset($_GET['id'])   ? (int)$_GET['id']           : 0;
$name = isset($_GET['name']) ? trim($_GET['name'])         : '';

if ($id <= 0 && empty($name)) {
    echo json_encode(['success' => false, 'error' => 'Nie podano identyfikatora lub nazwy tabeli.']);
    exit;
}

$cols      = 'id, name, row_count, col_count, headers, sheet_data, sql_table_name, updated_at';
$owner_sql = is_admin() ? '' : ' AND user_id = ' . (int)current_user()['id'];

if ($id > 0) {
    $stmt = $conn->prepare("SELECT $cols FROM `$registry_table` WHERE id = ?$owner_sql");
    $stmt->bind_param('i', $id);
} else {
    $stmt = $conn->prepare("SELECT $cols FROM `$registry_table` WHERE name = ?$owner_sql");
    $stmt->bind_param('s', $name);
}

$stmt->execute();
$result = $stmt->get_result();

if ($row = $result->fetch_assoc()) {
    echo json_encode([
        'success' => true,
        'table'   => [
            'id'            => (int)$row['id'],
            'name'          => $row['name'],
            'row_count'     => (int)$row['row_count'],
            'col_count'     => (int)$row['col_count'],
            'headers'       => json_decode($row['headers'], true) ?: [],
            'sheet_data'    => json_decode($row['sheet_data'], true) ?: [],
            'sql_table_name'=> $row['sql_table_name'],
            'updated_at'    => $row['updated_at'],
        ]
    ]);
} else {
    echo json_encode(['success' => false, 'error' => "Nie znaleziono tabeli w bazie $db_name."]);
}

$stmt->close();
