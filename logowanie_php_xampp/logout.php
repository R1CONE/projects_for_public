<?php
session_start();

// Wyczyszczenie zmiennych sesji
$_SESSION = [];

// Usunięcie ciasteczka sesyjnego jeśli istnieje
if (ini_get("session.use_cookies")) {
    $params = session_get_cookie_params();
    setcookie(
        session_name(),
        '',
        time() - 42000,
        $params["path"],
        $params["domain"],
        $params["secure"],
        $params["httponly"]
    );
}

// Zniszczenie sesji
session_destroy();

// Przekierowanie do strony logowania
header("Location: index.php");
exit;
