<?php
/**
 * Rejestracja nowego użytkownika (rola: user)
 */
require_once __DIR__ . '/config/db.php';

if (current_user()) {
    header('Location: index.php');
    exit;
}

$errors = [];

if (!$conn) {
    $errors[] = 'Rejestracja wymaga bezpośredniego połączenia z bazą MySQL (uruchom aplikację na serwerze produkcyjnym).';
} elseif ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $username = trim($_POST['username'] ?? '');
    $email = trim($_POST['email'] ?? '');
    $password = $_POST['password'] ?? '';
    $password2 = $_POST['password2'] ?? '';

    if (!csrf_check()) {
        $errors[] = 'Sesja wygasła. Odśwież stronę i spróbuj ponownie.';
    }
    if (!preg_match('/^[A-Za-z0-9_.-]{3,30}$/', $username)) {
        $errors[] = 'Login: 3–30 znaków (litery, cyfry, _ . -).';
    }
    if (!filter_var($email, FILTER_VALIDATE_EMAIL) || strlen($email) > 191) {
        $errors[] = 'Podaj poprawny adres e-mail.';
    }
    if (strlen($password) < 8) {
        $errors[] = 'Hasło musi mieć co najmniej 8 znaków.';
    }
    if ($password !== $password2) {
        $errors[] = 'Hasła nie są identyczne.';
    }

    if (!$errors) {
        $stmt = $conn->prepare("SELECT id FROM `$users_table` WHERE username = ? OR email = ? LIMIT 1");
        $stmt->bind_param("ss", $username, $email);
        $stmt->execute();
        $exists = $stmt->get_result()->num_rows > 0;
        $stmt->close();

        if ($exists) {
            $errors[] = 'Użytkownik o takim loginie lub e-mailu już istnieje.';
        } else {
            $hash = password_hash($password, PASSWORD_DEFAULT);
            $ins = $conn->prepare("INSERT INTO `$users_table` (username, email, password_hash, role) VALUES (?, ?, ?, 'user')");
            $ins->bind_param("sss", $username, $email, $hash);
            if ($ins->execute()) {
                $ins->close();
                header('Location: login.php?registered=1');
                exit;
            }
            $errors[] = 'Nie udało się utworzyć konta. Spróbuj ponownie.';
            $ins->close();
        }
    }
}
?>
<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Rejestracja – Excel Online</title>
    <link rel="stylesheet" href="assets/css/style.css">
</head>
<body class="auth-body">
    <div class="auth-card">
        <div class="excel-icon auth-icon">X</div>
        <h1>Rejestracja</h1>
        <p class="auth-sub">Utwórz konto, aby zapisywać własne tabele.</p>

        <?php foreach ($errors as $e): ?><div class="auth-alert auth-error"><?= htmlspecialchars($e) ?></div><?php endforeach; ?>

        <form method="post" autocomplete="on">
            <input type="hidden" name="csrf" value="<?= htmlspecialchars(csrf_token()) ?>">
            <label for="username">Login</label>
            <input type="text" id="username" name="username" required autofocus value="<?= htmlspecialchars($_POST['username'] ?? '') ?>">
            <label for="email">E-mail</label>
            <input type="email" id="email" name="email" required value="<?= htmlspecialchars($_POST['email'] ?? '') ?>">
            <label for="password">Hasło (min. 8 znaków)</label>
            <input type="password" id="password" name="password" required minlength="8">
            <label for="password2">Powtórz hasło</label>
            <input type="password" id="password2" name="password2" required minlength="8">
            <button type="submit" class="btn btn-primary auth-submit">Utwórz konto</button>
        </form>

        <p class="auth-footer">Masz już konto? <a href="login.php">Zaloguj się</a></p>
    </div>
</body>
</html>
