<?php
/**
 * Główna strona aplikacji Excel PHP - exel_project
 * Wymagania:
 * - HTML/PHP arkusz kalkulacyjny (Excel)
 * - Nadawanie nazwy tabeli
 * - Przycisk zatwierdzania zapisu do bazy danych XAMPP (exel_db) z użyciem nowego połączenia (new mysqli)
 * - Wybór zapisanej tabeli z bazy danych, wyświetlenie na stronie i możliwość jej modyfikacji
 */

require_once __DIR__ . '/config/db.php';
require_login_page();
$current_user = current_user();
?>
<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Excel Online - Zarządzanie Tabelami (we4sai_erasmuss)</title>
    <link rel="stylesheet" href="assets/css/style.css">
</head>
<body>

    <!-- Górna belka aplikacji w stylu Microsoft Excel -->
    <header class="app-header">
        <div class="brand-container">
            <div class="excel-icon">X</div>
            <div>
                <h1 class="brand-title">Excel Online & Database Manager</h1>
                <div class="brand-subtitle">Projekt HTML/PHP z bazą danych MySQL (erasmus.skillgate.eu / comp41)</div>
            </div>
        </div>

        <div class="user-bar">
            <span class="user-chip">👤 <?= htmlspecialchars($current_user['username']) ?><?= $current_user['role'] === 'admin' ? ' (admin)' : '' ?></span>
            <?php if ($current_user['role'] === 'admin'): ?>
                <a href="admin.php" class="btn btn-secondary">🛡️ Panel admina</a>
            <?php endif; ?>
            <form method="post" action="logout.php" style="display:inline">
                <input type="hidden" name="csrf" value="<?= htmlspecialchars(csrf_token()) ?>">
                <button type="submit" class="btn btn-secondary">Wyloguj</button>
            </form>
        </div>

        <div class="db-status-pill">
            <div class="status-dot"></div>
            <span>Baza MySQL: <strong><?= htmlspecialchars($db_name) ?></strong> (<?= $conn ? 'allbino.mysql.dhosting.pl' : 'Połączono (erasmus.skillgate.eu)' ?>)</span>
        </div>
    </header>

    <!-- Główny kontener aplikacji -->
    <main class="main-wrapper">

        <!-- Panel sterowania i zapisywania -->
        <section class="control-card">
            <!-- Nadawanie nazwy tabeli i zatwierdzenie zapisu -->
            <div class="section-group">
                <label for="tableName" class="input-label">Nazwa tabeli:</label>
                <input type="text" id="tableName" class="table-name-input" placeholder="Wpisz nazwę tabeli (np. Raport_Sprzedazy)...">
                <button type="button" id="btnSave" class="btn btn-primary" title="Zapisz lub zaktualizuj wszystkie dane w bazie MySQL">
                    💾 Zatwierdź i zapisz do bazy
                </button>
            </div>

            <!-- Wybór istniejącej tabeli z bazy danych do modyfikacji -->
            <div class="section-group">
                <label for="tableSelector" class="input-label">Wybierz tabelę z bazy:</label>
                <select id="tableSelector" class="table-select">
                    <option value="">-- Wczytywanie tabel... --</option>
                </select>
                <button type="button" id="btnLoad" class="btn btn-outline" title="Załaduj wybraną tabelę do edytora Excel">
                    📂 Otwórz
                </button>
                <button type="button" id="btnNew" class="btn btn-secondary" title="Utwórz nowy, pusty arkusz kalkulacyjny">
                    ➕ Nowy arkusz
                </button>
                <button type="button" id="btnDelete" class="btn btn-danger" title="Usuń zaznaczoną tabelę z bazy danych">
                    🗑️ Usuń
                </button>
            </div>
        </section>

        <!-- Pasek narzędziowy arkusza (Wstążka) -->
        <section class="excel-toolbar">
            <button type="button" class="tool-btn" id="btnAddRow" title="Dodaj nowy wiersz na dole tabeli">
                <strong>+</strong> Dodaj wiersz
            </button>
            <button type="button" class="tool-btn" id="btnDeleteRow" title="Usuń aktywny wiersz">
                <strong>-</strong> Usuń wiersz
            </button>

            <div class="toolbar-separator"></div>

            <button type="button" class="tool-btn" id="btnAddCol" title="Dodaj nową kolumnę z prawej strony">
                <strong>+</strong> Dodaj kolumnę
            </button>
            <button type="button" class="tool-btn" id="btnDeleteCol" title="Usuń aktywną kolumnę">
                <strong>-</strong> Usuń kolumnę
            </button>

            <div class="toolbar-separator"></div>

            <button type="button" class="tool-btn" id="btnClear" title="Wyczyść wszystkie komórki arkusza">
                🧹 Wyczyść dane
            </button>
            <button type="button" class="tool-btn" id="btnExportCSV" title="Pobierz dane jako plik CSV (dla programu Excel)">
                📥 Pobierz CSV
            </button>

            <div class="toolbar-separator"></div>

            <span style="font-size: 0.8rem; color: #64748b; margin-left: auto;">
                Obsługa formuł: <code>=SUM(A1:A5)</code>, <code>=AVG(A1:A5)</code>, <code>=MIN(A1:A5)</code>, <code>=MAX(A1:A5)</code>, <code>=A1+B1</code>
            </span>
        </section>

        <!-- Pasek formuły (Formula Bar fx) -->
        <div class="formula-bar-container">
            <div class="active-cell-box" id="activeCellIndicator" title="Współrzędna zaznaczonej komórki">A1</div>
            <div class="fx-label">fx</div>
            <input type="text" id="formulaInput" class="formula-input" placeholder="Wpisz wartość tekstową, liczbę lub formułę (np. =SUM(A1:A4) lub =A1*B1)...">
        </div>

        <!-- Siatka arkusza kalkulacyjnego Excel -->
        <div class="spreadsheet-container" id="spreadsheetGrid">
            <!-- Siatka jest generowana dynamicznie przez JavaScript -->
        </div>

        <!-- Belka informacyjna o stanie arkusza -->
        <div class="info-bar">
            <div>
                Bieżący arkusz: <span class="current-table-badge" id="currentSheetBadge">Nowa niezapisana tabela</span>
            </div>
            <div>
                Wymiary: <span id="currentDimensionsBadge">15 wierszy × 8 kolumn</span>
            </div>
            <div style="font-size: 0.8rem; color: #718096;">
                💡 <em>Dwuklik na nagłówek kolumny (np. A, B) pozwala zmienić jej nazwę. Obsługiwane wklejanie (Ctrl+V) z Excela!</em>
            </div>
        </div>

        <!-- Sekcja z listą tabel w bazie danych (we4sai_erasmuss) -->
        <section class="database-tables-card">
            <h2 class="card-title">
                <span>🗄️</span> Zapisane tabele w bazie danych (<code>we4sai_erasmuss</code>)
            </h2>
            <p style="color: #64748b; font-size: 0.9rem; margin-bottom: 12px;">
                Poniżej znajduje się lista wszystkich arkuszy zapisanych w bazie MySQL (<code>we4sai_erasmuss</code>) na serwerze <code>erasmus.skillgate.eu</code> (stanowisko comp41).
                Możesz jednym kliknięciem <strong>wczytać dowolną tabelę</strong> do arkusza powyżej, <strong>zmodyfikować jej dane</strong> i ponownie kliknąć <strong>"Zatwierdź i zapisz do bazy"</strong>.
            </p>

            <table class="db-tables-list">
                <thead>
                    <tr>
                        <th style="width: 40px;">#</th>
                        <th>Nazwa tabeli</th>
                        <th>Rozmiar</th>
                        <th>Fizyczna tabela SQL w MySQL</th>
                        <th>Data modyfikacji</th>
                        <th style="text-align: right;">Akcje</th>
                    </tr>
                </thead>
                <tbody id="savedTablesBody">
                    <tr>
                        <td colspan="6" style="text-align: center; color: #888; padding: 20px;">
                            Wczytywanie zapisanych tabel...
                        </td>
                    </tr>
                </tbody>
            </table>
        </section>

    </main>

    <!-- Kontener powiadomień Toast -->
    <div id="toastContainer" class="toast-container"></div>

    <!-- Skrypty aplikacji -->
    <script src="assets/js/spreadsheet.js"></script>
    <script src="assets/js/app.js"></script>

</body>
</html>
