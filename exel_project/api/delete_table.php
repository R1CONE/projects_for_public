<?php
/**
 * API: Usuwanie tabeli z bazy danych we4sai_erasmuss
 */

header('Content-Type: application/json; charset=utf-8');
require_once __DIR__ . '/../config/db.php';

$raw_input = file_get_contents('php://input');
$data      = json_decode($raw_input, true);

$id = isset($data['id']) ? (int)$data['id'] : (isset($_POST['id']) ? (int)$_POST['id'] : 0);

if ($id <= 0) {
    echo json_encode(['success' => false, 'error' => 'Niepoprawny identyfikator tabeli.']);
    exit;
}

require_login_json();

if (!$conn) {
    echo json_encode(['success' => false, 'error' => 'Brak połączenia z bazą danych.']);
    exit;
}

$owner_sql = is_admin() ? '' : ' AND user_id = ' . (int)current_user()['id'];
$stmt      = $conn->prepare("SELECT name, sql_table_name FROM `$registry_table` WHERE id = ?$owner_sql");
$stmt->bind_param('i', $id);
$stmt->execute();
$row = $stmt->get_result()->fetch_assoc();
$stmt->close();

if (!$row) {
    echo json_encode(['success' => false, 'error' => "Tabela o tym ID nie istnieje lub brak uprawnień."]);
    exit;
}

$tableName    = $row['name'];
$sqlTableName = $row['sql_table_name'];

if (!empty($sqlTableName)) {
    $conn->query("DROP TABLE IF EXISTS `$sqlTableName`");
}

$del = $conn->prepare("DELETE FROM `$registry_table` WHERE id = ?");
$del->bind_param('i', $id);
$del->execute();
$del->close();

echo json_encode(['success' => true, 'message' => "Tabela '$tableName' została pomyślnie usunięta z bazy $db_name."]);
