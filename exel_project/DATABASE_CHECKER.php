<?php
/**
 * MySQL Database Viewer & Reader
 * Strona: erasmus.skillgate.eu
 * Baza danych: we4sai_erasmuss
 */

// Konfiguracja bazy danych
$db_host = "allbino.mysql.dhosting.pl";
$db_user = "fu9oog_erasmuss";
$db_pass = "ohR6Aisier8w";
$db_name = "we4sai_erasmuss";
$db_port = 3306;

// FTP Info (w celach informacyjnych w razie potrzeby wdrożenia na serwerze)
$ftp_info = [
    'server' => 'allbino.ftp.dhosting.pl',
    'user'   => 'nuzah4_erasmuss',
    'domain' => 'erasmus.skillgate.eu'
];

// Wykrywanie publicznego IP klienta (pomocne przy odblokowywaniu w dAdmin)
$client_ip = $_SERVER['REMOTE_ADDR'] ?? 'nieznany';

// Parametry przeglądania
$current_table = isset($_GET['table']) ? trim($_GET['table']) : '';
$limit = isset($_GET['limit']) ? max(10, min(1000, (int)$_GET['limit'])) : 100;
$page  = isset($_GET['p']) ? max(1, (int)$_GET['p']) : 1;
$offset = ($page - 1) * $limit;

// Zmienne stanu
$connection_error = null;
$conn = null;
$tables = [];
$table_data = [];
$table_columns = [];
$total_rows_in_table = 0;
$server_info = '';

// Próba połączenia z krótkim timeoutem (żeby strona nie zawieszała się przy braku zdalnego dostępu)
mysqli_report(MYSQLI_REPORT_OFF);
$conn = mysqli_init();
if ($conn) {
    // Timeout 5 sekund na połączenie
    $conn->options(MYSQLI_OPT_CONNECT_TIMEOUT, 5);
    
    $connected = @$conn->real_connect($db_host, $db_user, $db_pass, $db_name, $db_port);
    
    // Jeśli nie udało się połączyć zdalnie, a skrypt może być uruchomiony na serwerze, spróbuj 'localhost'
    if (!$connected && ($conn->connect_errno == 2002 || $conn->connect_errno == 2003)) {
        $connected_local = @$conn->real_connect('localhost', $db_user, $db_pass, $db_name, $db_port);
        if ($connected_local) {
            $connected = true;
            $db_host = 'localhost (lokalnie na serwerze)';
        }
    }
    
    if (!$connected) {
        $connection_error = [
            'code' => $conn->connect_errno,
            'message' => $conn->connect_error
        ];
    } else {
        $conn->set_charset("utf8mb4");
        $server_info = $conn->server_info;

        // Pobranie listy tabel w bazie
        $result_tables = $conn->query("SHOW FULL TABLES WHERE Table_type = 'BASE TABLE'");
        if ($result_tables) {
            while ($row = $result_tables->fetch_array(MYSQLI_NUM)) {
                $tbl_name = $row[0];
                // Pobierz liczbę wierszy
                $cnt_res = $conn->query("SELECT COUNT(*) FROM `$tbl_name`");
                $cnt = 0;
                if ($cnt_res) {
                    $cnt_row = $cnt_res->fetch_row();
                    $cnt = $cnt_row[0] ?? 0;
                    $cnt_res->free();
                }
                $tables[] = [
                    'name' => $tbl_name,
                    'rows' => (int)$cnt
                ];
            }
            $result_tables->free();
        }

        // Jeśli tabela nie została wybrana, wybierz pierwszą z listy
        if (empty($current_table) && !empty($tables)) {
            $current_table = $tables[0]['name'];
        }

        // Sprawdź, czy wybrana tabela faktycznie istnieje w pobranych tabelach
        $table_exists = false;
        foreach ($tables as $t) {
            if ($t['name'] === $current_table) {
                $table_exists = true;
                $total_rows_in_table = $t['rows'];
                break;
            }
        }

        if ($table_exists && !empty($current_table)) {
            // Pobierz strukturę kolumn
            $res_cols = $conn->query("SHOW COLUMNS FROM `$current_table`");
            if ($res_cols) {
                while ($c = $res_cols->fetch_assoc()) {
                    $table_columns[] = $c;
                }
                $res_cols->free();
            }

            // Pobierz dane z tabeli
            $res_data = $conn->query("SELECT * FROM `$current_table` LIMIT $limit OFFSET $offset");
            if ($res_data) {
                while ($r = $res_data->fetch_assoc()) {
                    $table_data[] = $r;
                }
                $res_data->free();
            }
        }
    }
} else {
    $connection_error = [
        'code' => -1,
        'message' => 'Inicjalizacja modułu MySQLi nie powiodła się.'
    ];
}
?>
<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Podgląd bazy danych: <?= htmlspecialchars($db_name) ?> (<?= htmlspecialchars($ftp_info['domain']) ?>)</title>
    <!-- Bootstrap 5 CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.min.css">
    <style>
        body {
            background-color: #f4f6f9;
            font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, "Helvetica Neue", Arial, sans-serif;
            color: #2d3748;
        }
        .navbar-brand {
            font-weight: 700;
            letter-spacing: -0.5px;
        }
        .card {
            border: none;
            border-radius: 12px;
            box-shadow: 0 4px 14px rgba(0, 0, 0, 0.05);
            overflow: hidden;
        }
        .card-header {
            background-color: #ffffff;
            border-bottom: 1px solid #edf2f7;
            font-weight: 600;
        }
        .table-responsive {
            max-height: 70vh;
            overflow-y: auto;
        }
        .table thead th {
            position: sticky;
            top: 0;
            background: #2b3a4a;
            color: #ffffff;
            font-weight: 600;
            font-size: 0.85rem;
            white-space: nowrap;
            z-index: 10;
        }
        .table-hover tbody tr:hover {
            background-color: #edf2f7;
        }
        .col-type {
            font-size: 0.72rem;
            color: #cbd5e0;
            display: block;
            font-weight: 400;
        }
        .badge-null {
            background-color: #e2e8f0;
            color: #718096;
            font-style: italic;
            font-size: 0.75rem;
            padding: 2px 6px;
            border-radius: 4px;
        }
        .nav-pills .nav-link {
            border-radius: 8px;
            padding: 8px 14px;
            color: #4a5568;
            font-weight: 500;
            display: flex;
            justify-content: space-between;
            align-items: center;
            margin-bottom: 4px;
            transition: all 0.15s ease-in-out;
        }
        .nav-pills .nav-link:hover {
            background-color: #e2e8f0;
            color: #1a202c;
        }
        .nav-pills .nav-link.active {
            background-color: #0d6efd;
            color: #ffffff;
            box-shadow: 0 2px 6px rgba(13, 110, 253, 0.35);
        }
        .nav-pills .nav-link.active .badge {
            background-color: rgba(255, 255, 255, 0.25) !important;
            color: #ffffff !important;
        }
        .cell-content {
            max-width: 320px;
            white-space: nowrap;
            overflow: hidden;
            text-overflow: ellipsis;
            display: inline-block;
            vertical-align: middle;
        }
        .cell-content:hover {
            white-space: normal;
            word-break: break-all;
        }
        .search-box {
            position: relative;
        }
        .search-box i {
            position: absolute;
            left: 12px;
            top: 50%;
            transform: translateY(-50%);
            color: #a0aec0;
        }
        .search-box input {
            padding-left: 36px;
            border-radius: 8px;
        }
    </style>
</head>
<body>

<!-- Navbar -->
<nav class="navbar navbar-expand-lg navbar-dark bg-dark shadow-sm">
    <div class="container-fluid px-4">
        <a class="navbar-brand d-flex align-items-center gap-2" href="reader.php">
            <i class="bi bi-database-fill-gear text-primary fs-4"></i>
            <span>MySQL Database Viewer</span>
        </a>
        <div class="d-flex align-items-center gap-3 text-light">
            <span class="badge bg-secondary">
                <i class="bi bi-globe me-1"></i><?= htmlspecialchars($ftp_info['domain']) ?>
            </span>
            <span class="badge bg-dark border border-secondary">
                <i class="bi bi-hdd-network me-1"></i><?= htmlspecialchars($db_host) ?>
            </span>
            <span class="badge bg-success">
                <i class="bi bi-folder2 me-1"></i><?= htmlspecialchars($db_name) ?>
            </span>
        </div>
    </div>
</nav>

<div class="container-fluid px-4 py-4">

    <!-- BŁĄD POŁĄCZENIA -->
    <?php if ($connection_error): ?>
        <div class="alert alert-danger shadow-sm border-0 rounded-3 p-4 mb-4">
            <div class="d-flex align-items-start gap-3">
                <i class="bi bi-exclamation-triangle-fill fs-1 text-danger"></i>
                <div class="w-100">
                    <h4 class="alert-heading fw-bold mb-2">Błąd połączenia z bazą danych MySQL</h4>
                    <p class="mb-2">
                        Serwer: <code><?= htmlspecialchars($db_host) ?></code> | 
                        Baza: <code><?= htmlspecialchars($db_name) ?></code> | 
                        Użytkownik: <code><?= htmlspecialchars($db_user) ?></code>
                    </p>
                    <div class="bg-dark text-warning p-3 rounded font-monospace small mb-3">
                        Kod: <?= htmlspecialchars((string)$connection_error['code']) ?><br>
                        Komunikat: <?= htmlspecialchars($connection_error['message']) ?>
                    </div>

                    <div class="card bg-white text-dark mt-3 p-3">
                        <h5 class="fw-bold text-primary"><i class="bi bi-lightbulb-fill text-warning me-2"></i>Dlaczego ten błąd wystąpił i jak go rozwiązać?</h5>
                        <p class="mb-2">Serwery <strong>dhosting.pl</strong> (oraz większość hostingów www) <strong>domyślnie blokują zdalny dostęp do portu MySQL (3306)</strong> z zewnątrz (np. z Twojego lokalnego XAMPP na komputerze). Masz 2 bardzo proste rozwiązania:</p>

                        <div class="row g-3 mt-1">
                            <div class="col-md-6">
                                <div class="border rounded p-3 h-100 bg-light">
                                    <h6 class="fw-bold text-success"><i class="bi bi-1-circle-fill me-1"></i> Rozwiązanie A: Włącz dostęp zdalny w dAdmin (Zalecane dla XAMPP)</h6>
                                    <ol class="small ps-3 mb-2">
                                        <li>Zaloguj się do panelu dAdmin na <a href="https://dhosting.pl" target="_blank" class="fw-bold">dhosting.pl</a>.</li>
                                        <li>Przejdź do zakładki: <strong>Bazy danych MySQL</strong>.</li>
                                        <li>Przy bazie <code><?= htmlspecialchars($db_name) ?></code> lub użytkowniku <code><?= htmlspecialchars($db_user) ?></code> kliknij <strong>Dostęp zewnętrzny</strong> / <strong>Uprawnienia hosta</strong>.</li>
                                        <li>Dodaj swój publiczny adres IP (Twój obecny IP: <code><?= htmlspecialchars($client_ip) ?></code>) lub wpisz <code>%</code> (dowolny host).</li>
                                        <li>Zapisz zmiany i odśwież tę stronę!</li>
                                    </ol>
                                </div>
                            </div>
                            <div class="col-md-6">
                                <div class="border rounded p-3 h-100 bg-light">
                                    <h6 class="fw-bold text-info"><i class="bi bi-2-circle-fill me-1"></i> Rozwiązanie B: Wgraj ten plik przez FTP na serwer</h6>
                                    <ol class="small ps-3 mb-2">
                                        <li>Otwórz program <strong>FileZilla</strong>.</li>
                                        <li>Połącz się danymi FTP:
                                            <ul class="mb-1">
                                                <li>Serwer: <code><?= htmlspecialchars($ftp_info['server']) ?></code></li>
                                                <li>Login: <code><?= htmlspecialchars($ftp_info['user']) ?></code></li>
                                                <li>Hasło: <code>ET5ohPh3oxue</code></li>
                                            </ul>
                                        </li>
                                        <li>Prześlij plik <code>reader.php</code> do katalogu strony <code>erasmus.skillgate.eu</code> (zwykle <code>/public_html</code>).</li>
                                        <li>Otwórz w przeglądarce: <br>
                                            <a href="http://erasmus.skillgate.eu/reader.php" target="_blank" class="fw-bold">http://erasmus.skillgate.eu/reader.php</a>
                                        </li>
                                    </ol>
                                    <div class="small text-muted"><i class="bi bi-check-circle-fill text-success me-1"></i>Na serwerze skrypt połączy się natychmiast bez ograniczeń firewall!</div>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    <?php else: ?>

        <!-- GŁÓWNY WIDOK DANYCH -->
        <div class="row g-4">
            
            <!-- Lewa kolumna: Lista tabel -->
            <div class="col-lg-3 col-md-4">
                <div class="card h-100">
                    <div class="card-header d-flex justify-content-between align-items-center py-3">
                        <span class="fw-bold"><i class="bi bi-table me-2 text-primary"></i>Tabele bazy</span>
                        <span class="badge bg-primary rounded-pill"><?= count($tables) ?></span>
                    </div>
                    <div class="card-body p-2">
                        <?php if (empty($tables)): ?>
                            <div class="text-center py-4 text-muted small">
                                <i class="bi bi-inbox fs-2 d-block mb-2"></i>
                                Brak tabel w bazie danych <code><?= htmlspecialchars($db_name) ?></code>.
                            </div>
                        <?php else: ?>
                            <div class="nav flex-column nav-pills" role="tablist">
                                <?php foreach ($tables as $t): ?>
                                    <a class="nav-link <?= ($t['name'] === $current_table) ? 'active' : '' ?>" 
                                       href="?table=<?= urlencode($t['name']) ?>&limit=<?= $limit ?>">
                                        <span class="text-truncate" title="<?= htmlspecialchars($t['name']) ?>">
                                            <i class="bi bi-grid-3x3 me-2"></i><?= htmlspecialchars($t['name']) ?>
                                        </span>
                                        <span class="badge bg-secondary rounded-pill ms-2"><?= number_format($t['rows'], 0, ',', ' ') ?></span>
                                    </a>
                                <?php endforeach; ?>
                            </div>
                        <?php endif; ?>
                    </div>
                    <div class="card-footer bg-light border-0 py-2 small text-muted">
                        <i class="bi bi-info-circle me-1"></i>MySQL: <?= htmlspecialchars($server_info) ?>
                    </div>
                </div>
            </div>

            <!-- Prawa kolumna: Zawartość wybranej tabeli -->
            <div class="col-lg-9 col-md-8">
                <?php if (empty($current_table)): ?>
                    <div class="card p-5 text-center text-muted">
                        <i class="bi bi-arrow-left-circle fs-1 text-primary mb-3"></i>
                        <h4>Wybierz tabelę z listy po lewej stronie</h4>
                        <p>Wybierz dowolną tabelę, aby wyświetlić jej strukturę kolumn oraz zapisane wiersze.</p>
                    </div>
                <?php else: ?>
                    <div class="card">
                        <div class="card-header py-3">
                            <div class="d-flex flex-wrap justify-content-between align-items-center gap-3">
                                <div>
                                    <h5 class="mb-0 fw-bold text-dark">
                                        <i class="bi bi-table text-primary me-2"></i>Tabela: <span class="text-primary"><?= htmlspecialchars($current_table) ?></span>
                                    </h5>
                                    <span class="text-muted small">
                                        Łącznie wierszy: <strong><?= number_format($total_rows_in_table, 0, ',', ' ') ?></strong> | 
                                        Kolumn: <strong><?= count($table_columns) ?></strong>
                                    </span>
                                </div>
                                <div class="d-flex align-items-center gap-2">
                                    <!-- Wyszukiwarka na żywo -->
                                    <div class="search-box">
                                        <i class="bi bi-search"></i>
                                        <input type="text" id="liveSearchInput" class="form-control form-control-sm" placeholder="Filtruj wiersze...">
                                    </div>
                                    <!-- Limit wierszy -->
                                    <div class="btn-group btn-group-sm">
                                        <button type="button" class="btn btn-outline-secondary dropdown-toggle" data-bs-toggle="dropdown">
                                            Limit: <?= $limit ?>
                                        </button>
                                        <ul class="dropdown-menu dropdown-menu-end">
                                            <li><a class="dropdown-item <?= $limit == 25 ? 'active' : '' ?>" href="?table=<?= urlencode($current_table) ?>&limit=25">25</a></li>
                                            <li><a class="dropdown-item <?= $limit == 50 ? 'active' : '' ?>" href="?table=<?= urlencode($current_table) ?>&limit=50">50</a></li>
                                            <li><a class="dropdown-item <?= $limit == 100 ? 'active' : '' ?>" href="?table=<?= urlencode($current_table) ?>&limit=100">100</a></li>
                                            <li><a class="dropdown-item <?= $limit == 500 ? 'active' : '' ?>" href="?table=<?= urlencode($current_table) ?>&limit=500">500</a></li>
                                            <li><a class="dropdown-item <?= $limit == 1000 ? 'active' : '' ?>" href="?table=<?= urlencode($current_table) ?>&limit=1000">1000</a></li>
                                        </ul>
                                    </div>
                                    <button class="btn btn-sm btn-outline-primary" onclick="exportTableToCSV('<?= htmlspecialchars($current_table) ?>.csv')">
                                        <i class="bi bi-download me-1"></i>CSV
                                    </button>
                                    <a href="?table=<?= urlencode($current_table) ?>&limit=<?= $limit ?>" class="btn btn-sm btn-outline-secondary" title="Odśwież">
                                        <i class="bi bi-arrow-clockwise"></i>
                                    </a>
                                </div>
                            </div>
                        </div>

                        <!-- Tabela z danymi -->
                        <div class="table-responsive">
                            <table class="table table-hover table-striped table-bordered align-middle mb-0" id="dataTable">
                                <thead>
                                    <tr>
                                        <th style="width: 50px;" class="text-center">#</th>
                                        <?php foreach ($table_columns as $col): ?>
                                            <th>
                                                <?= htmlspecialchars($col['Field']) ?>
                                                <?php if (!empty($col['Key']) && $col['Key'] === 'PRI'): ?>
                                                    <span class="badge bg-warning text-dark ms-1" title="Primary Key">PK</span>
                                                <?php endif; ?>
                                                <span class="col-type"><?= htmlspecialchars($col['Type']) ?></span>
                                            </th>
                                        <?php endforeach; ?>
                                    </tr>
                                </thead>
                                <tbody>
                                    <?php if (empty($table_data)): ?>
                                        <tr>
                                            <td colspan="<?= count($table_columns) + 1 ?>" class="text-center py-5 text-muted">
                                                <i class="bi bi-inbox fs-2 d-block mb-2"></i>
                                                Tabela jest pusta (brak danych).
                                            </td>
                                        </tr>
                                    <?php else: ?>
                                        <?php foreach ($table_data as $idx => $row): ?>
                                            <tr>
                                                <td class="text-center text-muted small fw-semibold"><?= $offset + $idx + 1 ?></td>
                                                <?php foreach ($table_columns as $col): ?>
                                                    <?php 
                                                        $val = $row[$col['Field']] ?? null;
                                                    ?>
                                                    <td>
                                                        <?php if ($val === null): ?>
                                                            <span class="badge-null">NULL</span>
                                                        <?php elseif ($val === ''): ?>
                                                            <span class="text-muted fst-italic small">[pusty ciąg]</span>
                                                        <?php else: ?>
                                                            <span class="cell-content" title="<?= htmlspecialchars((string)$val) ?>">
                                                                <?= htmlspecialchars((string)$val) ?>
                                                            </span>
                                                        <?php endif; ?>
                                                    </td>
                                                <?php endforeach; ?>
                                            </tr>
                                        <?php endforeach; ?>
                                    <?php endif; ?>
                                </tbody>
                            </table>
                        </div>

                        <!-- Paginacja -->
                        <?php if ($total_rows_in_table > $limit): ?>
                            <?php $total_pages = ceil($total_rows_in_table / $limit); ?>
                            <div class="card-footer bg-white d-flex justify-content-between align-items-center py-3">
                                <span class="small text-muted">
                                    Pokazano <?= min($total_rows_in_table, $offset + 1) ?> - <?= min($total_rows_in_table, $offset + count($table_data)) ?> z <?= $total_rows_in_table ?> rekordów
                                </span>
                                <nav>
                                    <ul class="pagination pagination-sm mb-0">
                                        <li class="page-item <?= ($page <= 1) ? 'disabled' : '' ?>">
                                            <a class="page-link" href="?table=<?= urlencode($current_table) ?>&limit=<?= $limit ?>&p=<?= $page - 1 ?>">Poprzednia</a>
                                        </li>
                                        <?php 
                                            $start_p = max(1, $page - 2);
                                            $end_p   = min($total_pages, $page + 2);
                                        ?>
                                        <?php for ($p = $start_p; $p <= $end_p; $p++): ?>
                                            <li class="page-item <?= ($p == $page) ? 'active' : '' ?>">
                                                <a class="page-link" href="?table=<?= urlencode($current_table) ?>&limit=<?= $limit ?>&p=<?= $p ?>"><?= $p ?></a>
                                            </li>
                                        <?php endfor; ?>
                                        <li class="page-item <?= ($page >= $total_pages) ? 'disabled' : '' ?>">
                                            <a class="page-link" href="?table=<?= urlencode($current_table) ?>&limit=<?= $limit ?>&p=<?= $page + 1 ?>">Następna</a>
                                        </li>
                                    </ul>
                                </nav>
                            </div>
                        <?php endif; ?>

                    </div>
                <?php endif; ?>
            </div>

        </div>
    <?php endif; ?>

</div>

<!-- Bootstrap 5 Bundle JS -->
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>

<script>
    // Filtrowanie na żywo wierszy w tabeli
    const searchInput = document.getElementById('liveSearchInput');
    if (searchInput) {
        searchInput.addEventListener('keyup', function() {
            const filter = this.value.toLowerCase();
            const rows = document.querySelectorAll('#dataTable tbody tr');
            
            rows.forEach(row => {
                const text = row.textContent.toLowerCase();
                if (text.includes(filter)) {
                    row.style.display = '';
                } else {
                    row.style.display = 'none';
                }
            });
        });
    }

    // Eksport widocznej tabeli do pliku CSV
    function exportTableToCSV(filename) {
        const table = document.getElementById('dataTable');
        if (!table) return;

        let csv = [];
        const rows = table.querySelectorAll('tr');

        for (let i = 0; i < rows.length; i++) {
            let row = [];
            const cols = rows[i].querySelectorAll('th, td');

            for (let j = 0; j < cols.length; j++) {
                // Usuń nadmiarowe spacje i podwójne cudzysłowy
                let text = cols[j].innerText.replace(/"/g, '""').trim();
                row.push('"' + text + '"');
            }
            csv.push(row.join(','));
        }

        const csvFile = new Blob(["\uFEFF" + csv.join("\n")], { type: "text/csv;charset=utf-8;" });
        const downloadLink = document.createElement("a");
        downloadLink.download = filename;
        downloadLink.href = window.URL.createObjectURL(csvFile);
        downloadLink.style.display = "none";
        document.body.appendChild(downloadLink);
        downloadLink.click();
        document.body.removeChild(downloadLink);
    }
</script>

</body>
</html>
<?php
if ($conn && $conn instanceof mysqli && !$conn->connect_error) {
    $conn->close();
}
?>
