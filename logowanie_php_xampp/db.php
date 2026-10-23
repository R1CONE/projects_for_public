<?php
// Konfiguracja połączenia z bazą danych XAMPP (MySQL)
$host = '127.0.0.1';
$user = 'root';
$pass = '';
$dbname = 'auth_app';
$charset = 'utf8mb4';

try {
    // Najpierw łączymy się bez wskazania konkretnej bazy, aby w razie potrzeby utworzyć ją automatycznie
    $pdo = new PDO("mysql:host=$host;charset=$charset", $user, $pass, [
        PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION,
        PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC,
        PDO::ATTR_EMULATE_PREPARES => false,
    ]);

    // Tworzenie bazy danych jeśli jeszcze nie istnieje
    $pdo->exec("CREATE DATABASE IF NOT EXISTS `$dbname` CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci");
    $pdo->exec("USE `$dbname`");

    // Tworzenie tabeli użytkowników jeśli nie istnieje
    $createTableQuery = "
        CREATE TABLE IF NOT EXISTS `users` (
            `id` INT AUTO_INCREMENT PRIMARY KEY,
            `username` VARCHAR(50) NOT NULL UNIQUE,
            `email` VARCHAR(100) NOT NULL UNIQUE,
            `password` VARCHAR(255) NOT NULL,
            `created_at` TIMESTAMP DEFAULT CURRENT_TIMESTAMP
        ) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
    ";
    $pdo->exec($createTableQuery);

} catch (PDOException $e) {
    die("Błąd połączenia z bazą danych MySQL (XAMPP): " . htmlspecialchars($e->getMessage()) . "<br>Upewnij się, że moduł MySQL jest uruchomiony w panelu XAMPP.");
}
