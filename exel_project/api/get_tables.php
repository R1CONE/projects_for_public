<?php
/**
 * API: Pobieranie listy zapisanych arkuszy użytkownika
 */
header('Content-Type: application/json; charset=utf-8');
require_once __DIR__ . '/../config/db.php';

require_login_json();

if (!$conn) {
    echo json_encode(['success' => false, 'error' => 'Brak połączenia z bazą danych.']);
    exit;
}

$me    = current_user();
$admin = is_admin();

// Admin widzi wszystkie arkusze; zwykły użytkownik – tylko swoje
if ($admin) {
    $res = $conn->query("SELECT id, name, row_count, col_count, sql_table_name, updated_at FROM `$registry_table` ORDER BY updated_at DESC");
} else {
    $stmt = $conn->prepare("SELECT id, name, row_count, col_count, sql_table_name, updated_at FROM `$registry_table` WHERE user_id = ? ORDER BY updated_at DESC");
    $uid  = (int)$me['id'];
    $stmt->bind_param('i', $uid);
    $stmt->execute();
    $res  = $stmt->get_result();
}

$tables = [];
while ($row = $res->fetch_assoc()) {
    $tables[] = [
        'id'            => (int)$row['id'],
        'name'          => $row['name'],
        'row_count'     => (int)$row['row_count'],
        'col_count'     => (int)$row['col_count'],
        'sql_table_name'=> $row['sql_table_name'],
        'updated_at'    => $row['updated_at'],
    ];
}

echo json_encode(['success' => true, 'tables' => $tables]);
