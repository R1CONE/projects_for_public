<?php
session_start();

// Sprawdzenie, czy użytkownik jest zalogowany
if (!isset($_SESSION['user_id'])) {
    header("Location: index.php");
    exit;
}

$username = htmlspecialchars($_SESSION['username']);
?>
<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Zalogowano</title>
    <link rel="stylesheet" href="style.css">
</head>
<body class="dashboard-page">
    <div class="dashboard-message">
        Użytkownik <span class="dashboard-user"><?= $username ?></span> jest zalogowany
    </div>
    <div>
        <a href="logout.php" class="btn-logout">Wyloguj się</a>
    </div>
</body>
</html>
