<?php
/**
 * Konfiguracja połączenia z bazą danych we4sai_erasmuss (allbino.mysql.dhosting.pl)
 * Tabela użytkowników: users_comp41
 */

// ── Konfiguracja bazy danych ───────────────────────────────────────────────
define('DB_HOST',     'allbino.mysql.dhosting.pl');
define('DB_NAME',     'we4sai_erasmuss');
define('DB_USER',     'fu9oog_erasmuss');
define('DB_PASS',     'ohR6Aisier8w');
define('DB_CHARSET',  'utf8mb4');

// Nazwy tabel
$users_table    = 'users_comp41';
$registry_table = 'comp41_saved_sheets';
$db_name        = DB_NAME;

// ── Sesja ─────────────────────────────────────────────────────────────────
if (session_status() === PHP_SESSION_NONE) {
    session_set_cookie_params([
        'lifetime' => 0,
        'path'     => '/',
        'secure'   => false,
        'httponly' => true,
        'samesite' => 'Lax',
    ]);
    session_start();
}

// ── Połączenie z MySQL ─────────────────────────────────────────────────────
$conn = null;
$is_remote_bridge = false;

mysqli_report(MYSQLI_REPORT_OFF);
$conn = new mysqli(DB_HOST, DB_USER, DB_PASS, DB_NAME);
if ($conn->connect_error) {
    $conn = null;
} else {
    $conn->set_charset(DB_CHARSET);
    // Stwórz tabelę użytkowników jeśli nie istnieje
    $conn->query("CREATE TABLE IF NOT EXISTS `$users_table` (
        id            INT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
        username      VARCHAR(30)  NOT NULL UNIQUE,
        email         VARCHAR(191) NOT NULL UNIQUE,
        password_hash VARCHAR(255) NOT NULL,
        role          ENUM('user','admin') NOT NULL DEFAULT 'user',
        created_at    DATETIME     NOT NULL DEFAULT CURRENT_TIMESTAMP
    ) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci");

    // Stwórz tabelę rejestru arkuszy jeśli nie istnieje
    $conn->query("CREATE TABLE IF NOT EXISTS `$registry_table` (
        id             INT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
        user_id        INT UNSIGNED NULL,
        name           VARCHAR(191) NOT NULL,
        row_count      INT NOT NULL DEFAULT 0,
        col_count      INT NOT NULL DEFAULT 0,
        headers        MEDIUMTEXT,
        sheet_data     LONGTEXT,
        sql_table_name VARCHAR(191),
        created_at     DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
        updated_at     DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
    ) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci");

    // ── Tworzenie konta admin/admin jeśli nie istnieje ──────────────────────
    $chk = $conn->prepare("SELECT id FROM `$users_table` WHERE username = 'admin' LIMIT 1");
    $chk->execute();
    $chk->store_result();
    if ($chk->num_rows === 0) {
        $admin_hash = password_hash('admin', PASSWORD_DEFAULT);
        $ins = $conn->prepare("INSERT INTO `$users_table` (username, email, password_hash, role) VALUES ('admin', 'admin@admin.local', ?, 'admin')");
        $ins->bind_param('s', $admin_hash);
        $ins->execute();
        $ins->close();
    }
    $chk->close();
}

// ── Pomocnicze funkcje ─────────────────────────────────────────────────────

/** Zwraca dane zalogowanego użytkownika z sesji lub null */
function current_user(): ?array {
    return $_SESSION['user'] ?? null;
}

/** Czy zalogowany jest adminem? */
function is_admin(): bool {
    $u = current_user();
    return $u && $u['role'] === 'admin';
}

/** CSRF token – generuj przy pierwszym wywołaniu */
function csrf_token(): string {
    if (empty($_SESSION['csrf'])) {
        $_SESSION['csrf'] = bin2hex(random_bytes(24));
    }
    return $_SESSION['csrf'];
}

/** Sprawdź token CSRF z POST */
function csrf_check(): bool {
    $tok = $_POST['csrf'] ?? ($_SERVER['HTTP_X_CSRF_TOKEN'] ?? '');
    return hash_equals(csrf_token(), $tok);
}

/**
 * Wymagaj zalogowanego użytkownika dla stron HTML.
 * Niezalogowanych przekierowuje na login.php.
 */
function require_login_page(): void {
    if (!current_user()) {
        header('Location: login.php');
        exit;
    }
}

/**
 * Wymagaj zalogowanego administratora dla stron HTML.
 */
function require_admin_page(): void {
    $u = current_user();
    if (!$u) {
        header('Location: login.php');
        exit;
    }
    if ($u['role'] !== 'admin') {
        header('Location: index.php');
        exit;
    }
}

/**
 * Wymagaj zalogowania dla endpointów JSON API.
 * Niezalogowanym zwraca HTTP 401 + JSON.
 */
function require_login_json(): void {
    if (!current_user()) {
        http_response_code(401);
        echo json_encode(['success' => false, 'error' => 'Wymagane logowanie.']);
        exit;
    }
}

/**
 * Sanityzacja nazwy tabeli SQL – zostawia tylko bezpieczne znaki.
 */
function sanitize_sql_table_name(string $name): string {
    $clean = preg_replace('/[^a-zA-Z0-9_]/', '_', $name);
    $clean = trim($clean, '_');
    if (empty($clean) || is_numeric($clean[0])) {
        $clean = 'tbl_' . $clean;
    }
    return 'sheet_' . substr($clean, 0, 50);
}

/**
 * Pomocnik do przekierowania do zdalnego API (mostek – nieużywany w tym projekcie).
 */
function forward_to_remote_api(string $endpoint, string $method = 'GET', string $body = ''): string {
    return json_encode(['success' => false, 'error' => 'Remote bridge not configured.']);
}
