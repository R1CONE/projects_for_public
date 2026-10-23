-- Tworzenie bazy danych dla aplikacji
CREATE DATABASE IF NOT EXISTS `auth_app` CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
USE `auth_app`;

-- Tworzenie tabeli użytkowników
CREATE TABLE IF NOT EXISTS `users` (
    `id` INT AUTO_INCREMENT PRIMARY KEY,
    `username` VARCHAR(50) NOT NULL UNIQUE,
    `email` VARCHAR(100) NOT NULL UNIQUE,
    `password` VARCHAR(255) NOT NULL,
    `created_at` TIMESTAMP DEFAULT CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
