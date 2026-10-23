<?php
session_start();

// Jeśli użytkownik jest już zalogowany, przekieruj na dashboard
if (isset($_SESSION['user_id'])) {
    header("Location: dashboard.php");
    exit;
}

require_once 'db.php';

$error = '';
$success = '';
$activeTab = 'login'; // Domyślna zakładka: 'login' lub 'register'

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $action = $_POST['action'] ?? '';

    if ($action === 'register') {
        $activeTab = 'register';
        $username = trim($_POST['username'] ?? '');
        $email = trim($_POST['email'] ?? '');
        $password = $_POST['password'] ?? '';
        $password_confirm = $_POST['password_confirm'] ?? '';

        if (empty($username) || empty($email) || empty($password)) {
            $error = 'Wszystkie pola są wymagane.';
        } elseif (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
            $error = 'Podaj poprawny adres e-mail.';
        } elseif (strlen($username) < 3) {
            $error = 'Nazwa użytkownika musi mieć co najmniej 3 znaki.';
        } elseif (strlen($password) < 6) {
            $error = 'Hasło musi mieć co najmniej 6 znaków.';
        } elseif ($password !== $password_confirm) {
            $error = 'Podane hasła nie są identyczne.';
        } else {
            // Sprawdzenie, czy użytkownik lub email już istnieje
            $stmt = $pdo->prepare("SELECT id FROM users WHERE username = ? OR email = ? LIMIT 1");
            $stmt->execute([$username, $email]);
            if ($stmt->fetch()) {
                $error = 'Podana nazwa użytkownika lub adres e-mail jest już zajęty.';
            } else {
                // Bezpieczne hashowanie hasła
                $hashedPassword = password_hash($password, PASSWORD_DEFAULT);
                $insertStmt = $pdo->prepare("INSERT INTO users (username, email, password) VALUES (?, ?, ?)");
                
                if ($insertStmt->execute([$username, $email, $hashedPassword])) {
                    $success = 'Konto zostało pomyślnie utworzone! Możesz się teraz zalogować.';
                    $activeTab = 'login'; // Przełącz na logowanie po udanej rejestracji
                } else {
                    $error = 'Wystąpił błąd podczas rejestracji konta. Spróbuj ponownie.';
                }
            }
        }
    } elseif ($action === 'login') {
        $activeTab = 'login';
        $loginInput = trim($_POST['login_input'] ?? '');
        $password = $_POST['password'] ?? '';

        if (empty($loginInput) || empty($password)) {
            $error = 'Wprowadź login/e-mail oraz hasło.';
        } else {
            // Logowanie za pomocą nazwy użytkownika LUB adresu e-mail
            $stmt = $pdo->prepare("SELECT * FROM users WHERE username = ? OR email = ? LIMIT 1");
            $stmt->execute([$loginInput, $loginInput]);
            $user = $stmt->fetch();

            if ($user && password_verify($password, $user['password'])) {
                // Zalogowano pomyślnie - zapis do sesji
                $_SESSION['user_id'] = $user['id'];
                $_SESSION['username'] = $user['username'];
                $_SESSION['email'] = $user['email'];

                header("Location: dashboard.php");
                exit;
            } else {
                $error = 'Nieprawidłowa nazwa użytkownika / e-mail lub hasło.';
            }
        }
    }
}
?>
<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Panel logowania i rejestracji</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>

<div class="auth-container">
    <div class="auth-header">
        <h1>Strefa Użytkownika</h1>
        <p>Zaloguj się lub utwórz nowe konto</p>
    </div>

    <!-- Przełącznik zakładek -->
    <div class="tabs">
        <button type="button" class="tab-btn <?= $activeTab === 'login' ? 'active' : '' ?>" id="tab-login-btn" onclick="switchTab('login')">Zaloguj się</button>
        <button type="button" class="tab-btn <?= $activeTab === 'register' ? 'active' : '' ?>" id="tab-register-btn" onclick="switchTab('register')">Zarejestruj się</button>
    </div>

    <div class="auth-body">
        <?php if (!empty($error)): ?>
            <div class="alert alert-error"><?= htmlspecialchars($error) ?></div>
        <?php endif; ?>

        <?php if (!empty($success)): ?>
            <div class="alert alert-success"><?= htmlspecialchars($success) ?></div>
        <?php endif; ?>

        <!-- Formularz logowania -->
        <form id="form-login" method="POST" action="index.php" style="display: <?= $activeTab === 'login' ? 'block' : 'none' ?>;">
            <input type="hidden" name="action" value="login">
            
            <div class="form-group">
                <label for="login_input">Nazwa użytkownika lub E-mail</label>
                <input type="text" id="login_input" name="login_input" required placeholder="Wpisz login lub e-mail">
            </div>

            <div class="form-group">
                <label for="login_password">Hasło</label>
                <input type="password" id="login_password" name="password" required placeholder="Wpisz hasło">
            </div>

            <button type="submit" class="btn-submit">Zaloguj się</button>
        </form>

        <!-- Formularz rejestracji -->
        <form id="form-register" method="POST" action="index.php" style="display: <?= $activeTab === 'register' ? 'block' : 'none' ?>;">
            <input type="hidden" name="action" value="register">

            <div class="form-group">
                <label for="reg_username">Nazwa użytkownika</label>
                <input type="text" id="reg_username" name="username" required placeholder="np. jan_kowalski">
            </div>

            <div class="form-group">
                <label for="reg_email">Adres E-mail</label>
                <input type="email" id="reg_email" name="email" required placeholder="np. jan@example.com">
            </div>

            <div class="form-group">
                <label for="reg_password">Hasło</label>
                <input type="password" id="reg_password" name="password" required placeholder="Minimum 6 znaków">
            </div>

            <div class="form-group">
                <label for="reg_password_confirm">Powtórz hasło</label>
                <input type="password" id="reg_password_confirm" name="password_confirm" required placeholder="Wpisz ponownie hasło">
            </div>

            <button type="submit" class="btn-submit">Zarejestruj się</button>
        </form>
    </div>
</div>

<script>
function switchTab(tab) {
    const loginForm = document.getElementById('form-login');
    const registerForm = document.getElementById('form-register');
    const loginBtn = document.getElementById('tab-login-btn');
    const registerBtn = document.getElementById('tab-register-btn');

    if (tab === 'login') {
        loginForm.style.display = 'block';
        registerForm.style.display = 'none';
        loginBtn.classList.add('active');
        registerBtn.classList.remove('active');
    } else {
        loginForm.style.display = 'none';
        registerForm.style.display = 'block';
        loginBtn.classList.remove('active');
        registerBtn.classList.add('active');
    }
}
</script>

</body>
</html>
