<?php
/**
 * Panel administratora: zarządzanie użytkownikami
 */
require_once __DIR__ . '/config/db.php';
require_admin_page();

$me = current_user();
$msg = '';
$err = '';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    if (!csrf_check()) {
        $err = 'Nieprawidłowy token bezpieczeństwa.';
    } else {
        $action = $_POST['action'] ?? '';
        $uid = (int)($_POST['user_id'] ?? 0);

        if ($uid === $me['id'] && in_array($action, ['delete', 'toggle_role'], true)) {
            $err = 'Nie możesz zmienić ani usunąć własnego konta.';
        } elseif ($action === 'delete' && $uid > 0) {
            $s = $conn->prepare("DELETE FROM `$users_table` WHERE id = ?");
            $s->bind_param("i", $uid);
            $s->execute();
            $s->close();
            // Arkusze usuniętego użytkownika zostają w bazie, ale bez właściciela
            $s = $conn->prepare("UPDATE `$registry_table` SET user_id = NULL WHERE user_id = ?");
            $s->bind_param("i", $uid);
            $s->execute();
            $s->close();
            $msg = 'Użytkownik został usunięty.';
        } elseif ($action === 'toggle_role' && $uid > 0) {
            $s = $conn->prepare("UPDATE `$users_table` SET role = IF(role = 'admin', 'user', 'admin') WHERE id = ?");
            $s->bind_param("i", $uid);
            $s->execute();
            $s->close();
            $msg = 'Zmieniono rolę użytkownika.';
        } elseif ($action === 'reset_password' && $uid > 0) {
            $new = $_POST['new_password'] ?? '';
            if (strlen($new) < 8) {
                $err = 'Nowe hasło musi mieć co najmniej 8 znaków.';
            } else {
                $h = password_hash($new, PASSWORD_DEFAULT);
                $s = $conn->prepare("UPDATE `$users_table` SET password_hash = ? WHERE id = ?");
                $s->bind_param("si", $h, $uid);
                $s->execute();
                $s->close();
                $msg = 'Hasło zostało zmienione.';
            }
        }
    }
}

$users = [];
$res = $conn->query("SELECT u.id, u.username, u.email, u.role, u.created_at,
    (SELECT COUNT(*) FROM `$registry_table` s WHERE s.user_id = u.id) AS sheets
    FROM `$users_table` u ORDER BY u.id ASC");
while ($row = $res->fetch_assoc()) {
    $users[] = $row;
}
$csrf = csrf_token();
?>
<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Panel administratora – Excel Online</title>
    <link rel="stylesheet" href="assets/css/style.css">
</head>
<body>
    <header class="app-header">
        <div class="brand-container">
            <div class="excel-icon">X</div>
            <div>
                <h1 class="brand-title">Panel administratora</h1>
                <div class="brand-subtitle">Zarządzanie użytkownikami</div>
            </div>
        </div>
        <div class="user-bar">
            <a href="index.php" class="btn btn-secondary">📊 Arkusze</a>
            <span class="user-chip">👤 <?= htmlspecialchars($me['username']) ?> (admin)</span>
            <form method="post" action="logout.php" style="display:inline">
                <input type="hidden" name="csrf" value="<?= htmlspecialchars($csrf) ?>">
                <button type="submit" class="btn btn-secondary">Wyloguj</button>
            </form>
        </div>
    </header>

    <main class="main-wrapper">
        <?php if ($msg): ?><div class="auth-alert auth-ok"><?= htmlspecialchars($msg) ?></div><?php endif; ?>
        <?php if ($err): ?><div class="auth-alert auth-error"><?= htmlspecialchars($err) ?></div><?php endif; ?>

        <section class="database-tables-card">
            <h2 class="card-title"><span>👥</span> Użytkownicy (<?= count($users) ?>)</h2>
            <table class="db-tables-list">
                <thead>
                    <tr><th>ID</th><th>Login</th><th>E-mail</th><th>Rola</th><th>Arkusze</th><th>Utworzono</th><th>Akcje</th></tr>
                </thead>
                <tbody>
                <?php foreach ($users as $u): $self = ((int)$u['id'] === $me['id']); ?>
                    <tr>
                        <td><?= (int)$u['id'] ?></td>
                        <td><strong><?= htmlspecialchars($u['username']) ?></strong></td>
                        <td><?= htmlspecialchars($u['email']) ?></td>
                        <td><span class="badge-tag <?= $u['role'] === 'admin' ? 'badge-sql' : '' ?>"><?= htmlspecialchars($u['role']) ?></span></td>
                        <td><?= (int)$u['sheets'] ?></td>
                        <td><?= htmlspecialchars($u['created_at']) ?></td>
                        <td style="white-space:nowrap;">
                            <?php if (!$self): ?>
                            <form method="post" style="display:inline">
                                <input type="hidden" name="csrf" value="<?= htmlspecialchars($csrf) ?>">
                                <input type="hidden" name="user_id" value="<?= (int)$u['id'] ?>">
                                <button name="action" value="toggle_role" class="btn btn-outline" style="padding:4px 10px;font-size:.8rem;"
                                        onclick="return confirm('Zmienić rolę użytkownika?')">
                                    <?= $u['role'] === 'admin' ? 'Odbierz admina' : 'Nadaj admina' ?>
                                </button>
                                <button name="action" value="delete" class="btn btn-danger" style="padding:4px 10px;font-size:.8rem;"
                                        onclick="return confirm('Usunąć użytkownika <?= htmlspecialchars($u['username'], ENT_QUOTES) ?>?')">
                                    🗑️ Usuń
                                </button>
                            </form>
                            <?php endif; ?>
                            <form method="post" style="display:inline" onsubmit="var p=prompt('Nowe hasło (min. 8 znaków):'); if(!p){return false;} this.new_password.value=p; return true;">
                                <input type="hidden" name="csrf" value="<?= htmlspecialchars($csrf) ?>">
                                <input type="hidden" name="user_id" value="<?= (int)$u['id'] ?>">
                                <input type="hidden" name="new_password" value="">
                                <button name="action" value="reset_password" class="btn btn-secondary" style="padding:4px 10px;font-size:.8rem;">🔑 Zmień hasło</button>
                            </form>
                        </td>
                    </tr>
                <?php endforeach; ?>
                </tbody>
            </table>
        </section>
    </main>
</body>
</html>
