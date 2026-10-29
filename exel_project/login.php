<?php
/**
 * Logowanie użytkownika / administratora
 */
require_once __DIR__ . '/config/db.php';

if (current_user()) {
    header('Location: index.php');
    exit;
}

$error = '';
$info = isset($_GET['registered']) ? 'Konto zostało utworzone. Możesz się zalogować.' : '';

if (!$conn) {
    $error = 'Logowanie wymaga bezpośredniego połączenia z bazą MySQL (uruchom aplikację na serwerze produkcyjnym).';
} elseif ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $login = trim($_POST['login'] ?? '');
    $password = $_POST['password'] ?? '';

    $_SESSION['login_fails'] = $_SESSION['login_fails'] ?? 0;
    $_SESSION['login_last'] = $_SESSION['login_last'] ?? 0;

    if (!csrf_check()) {
        $error = 'Sesja wygasła. Odśwież stronę i spróbuj ponownie.';
    } elseif ($_SESSION['login_fails'] >= 5 && time() - $_SESSION['login_last'] < 60) {
        $error = 'Zbyt wiele nieudanych prób. Poczekaj minutę.';
    } elseif ($login === '' || $password === '') {
        $error = 'Podaj login (lub e-mail) i hasło.';
    } else {
        $stmt = $conn->prepare("SELECT id, username, email, password_hash, role FROM `$users_table` WHERE username = ? OR email = ? LIMIT 1");
        $stmt->bind_param("ss", $login, $login);
        $stmt->execute();
        $user = $stmt->get_result()->fetch_assoc();
        $stmt->close();

        if ($user && password_verify($password, $user['password_hash'])) {
            session_regenerate_id(true);
            $_SESSION['user'] = [
                'id' => (int)$user['id'],
                'username' => $user['username'],
                'email' => $user['email'],
                'role' => $user['role']
            ];
            $_SESSION['login_fails'] = 0;
            header('Location: ' . ($user['role'] === 'admin' ? 'admin.php' : 'index.php'));
            exit;
        }
        $_SESSION['login_fails']++;
        $_SESSION['login_last'] = time();
        $error = 'Nieprawidłowy login lub hasło.';
    }
}
?>
<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Logowanie – Excel Online</title>
    <link rel="stylesheet" href="assets/css/style.css">
</head>
<body class="auth-body">
    <div class="auth-card">
        <div class="excel-icon auth-icon">X</div>
        <h1>Logowanie</h1>
        <p class="auth-sub">Zaloguj się, aby zarządzać swoimi tabelami.</p>

        <?php if ($error): ?><div class="auth-alert auth-error"><?= htmlspecialchars($error) ?></div><?php endif; ?>
        <?php if ($info): ?><div class="auth-alert auth-ok"><?= htmlspecialchars($info) ?></div><?php endif; ?>

        <form method="post" autocomplete="on">
            <input type="hidden" name="csrf" value="<?= htmlspecialchars(csrf_token()) ?>">
            <label for="login">Login lub e-mail</label>
            <input type="text" id="login" name="login" required autofocus value="<?= htmlspecialchars($_POST['login'] ?? '') ?>">
            <label for="password">Hasło</label>
            <input type="password" id="password" name="password" required>
            <button type="submit" class="btn btn-primary auth-submit">Zaloguj się</button>
        </form>

        <p class="auth-footer">Nie masz konta? <a href="register.php">Zarejestruj się</a></p>
    </div>
</body>
</html>
