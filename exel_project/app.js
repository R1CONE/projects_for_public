/**
 * Główny skrypt aplikacji obsługujący interfejs użytkownika
 * oraz komunikację z backendem PHP i bazą danych we4sai_erasmuss (comp41).
 */

// Wygaśnięcie sesji: odpowiedź 401 z API przekierowuje na logowanie
const _origFetch = window.fetch.bind(window);
window.fetch = async (...args) => {
    const response = await _origFetch(...args);
    if (response.status === 401) {
        window.location.href = 'login.php';
    }
    return response;
};

document.addEventListener('DOMContentLoaded', () => {
    // Referencje do elementów DOM
    const tableNameInput = document.getElementById('tableName');
    const tableSelector = document.getElementById('tableSelector');
    const btnSave = document.getElementById('btnSave');
    const btnLoad = document.getElementById('btnLoad');
    const btnNew = document.getElementById('btnNew');
    const btnDelete = document.getElementById('btnDelete');

    const activeCellIndicator = document.getElementById('activeCellIndicator');
    const formulaInput = document.getElementById('formulaInput');

    const btnAddRow = document.getElementById('btnAddRow');
    const btnDeleteRow = document.getElementById('btnDeleteRow');
    const btnAddCol = document.getElementById('btnAddCol');
    const btnDeleteCol = document.getElementById('btnDeleteCol');
    const btnClear = document.getElementById('btnClear');
    const btnExportCSV = document.getElementById('btnExportCSV');

    const currentSheetBadge = document.getElementById('currentSheetBadge');
    const currentDimensionsBadge = document.getElementById('currentDimensionsBadge');
    const savedTablesBody = document.getElementById('savedTablesBody');

    // Stan bieżącej tabeli
    let currentTableId = null;

    // Inicjalizacja arkusza kalkulacyjnego Excel
    const spreadsheet = new ExcelSpreadsheet('spreadsheetGrid', {
        rows: 15,
        cols: 8,
        onCellSelect: (cellRef, rawValue) => {
            activeCellIndicator.textContent = cellRef;
            formulaInput.value = rawValue;
        },
        onDataChange: () => {
            updateDimensionsBadge();
        }
    });

    // Powiązanie paska formuły (fx) z aktywną komórką
    formulaInput.addEventListener('input', () => {
        spreadsheet.updateActiveCellValue(formulaInput.value);
    });

    formulaInput.addEventListener('keydown', (e) => {
        if (e.key === 'Enter') {
            e.preventDefault();
            const { r, c } = spreadsheet.activeCell;
            spreadsheet.selectCell(r + 1, c);
        }
    });

    // Narzędzia paska wstążki
    btnAddRow.addEventListener('click', () => spreadsheet.addRow());
    btnDeleteRow.addEventListener('click', () => spreadsheet.deleteRow());
    btnAddCol.addEventListener('click', () => spreadsheet.addColumn());
    btnDeleteCol.addEventListener('click', () => spreadsheet.deleteColumn());
    btnClear.addEventListener('click', () => {
        if (confirm('Czy na pewno chcesz wyczyścić wszystkie komórki bieżącego arkusza?')) {
            spreadsheet.clearData();
            showToast('Arkusz został wyczyszczony.', 'info');
        }
    });
    btnExportCSV.addEventListener('click', () => {
        const name = tableNameInput.value.trim() || 'arkusz_excel';
        spreadsheet.exportToCSV(`${name}.csv`);
        showToast(`Wyeksportowano arkusz do pliku ${name}.csv`, 'success');
    });

    // Przycisk "Nowa tabela"
    btnNew.addEventListener('click', () => {
        currentTableId = null;
        tableNameInput.value = '';
        currentSheetBadge.textContent = 'Nowa niezapisana tabela';
        spreadsheet.initDefaultData();
        spreadsheet.renderTable();
        updateDimensionsBadge();
        tableSelector.value = '';
        showToast('Utworzono nowy, czysty arkusz kalkulacyjny.', 'info');
    });

    // Przycisk "Zatwierdź i zapisz do bazy danych"
    btnSave.addEventListener('click', () => {
        saveTableToDatabase();
    });

    // Przycisk "Załaduj / Otwórz tabelę"
    btnLoad.addEventListener('click', () => {
        const selectedId = tableSelector.value;
        if (!selectedId) {
            showToast('Wybierz tabelę z listy rozwijanej!', 'error');
            return;
        }
        loadTableFromDatabase(selectedId);
    });

    // Przycisk "Usuń wybraną tabelę"
    btnDelete.addEventListener('click', () => {
        const selectedId = tableSelector.value;
        if (!selectedId) {
            showToast('Wybierz tabelę do usunięcia z bazy danych!', 'error');
            return;
        }
        const selectedOption = tableSelector.options[tableSelector.selectedIndex];
        deleteTableFromDatabase(selectedId, selectedOption.text);
    });

    // Funkcja zapisu danych do bazy we4sai_erasmuss
    async function saveTableToDatabase() {
        const tableName = tableNameInput.value.trim();
        if (!tableName) {
            showToast('Podaj nazwę tabeli przed zatwierdzeniem!', 'error');
            tableNameInput.focus();
            return;
        }

        const data = spreadsheet.getData();
        const headers = spreadsheet.getHeaders();

        btnSave.disabled = true;
        btnSave.innerHTML = '<span class="spinner">⏳</span> Zapisywanie...';

        try {
            const response = await fetch('api/save_table.php', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json'
                },
                body: JSON.stringify({
                    id: currentTableId,
                    name: tableName,
                    headers: headers,
                    data: data
                })
            });

            const result = await response.json();

            if (result.success) {
                currentTableId = result.id;
                currentSheetBadge.textContent = `${result.name} (ID: ${result.id}, SQL: ${result.sql_table})`;
                showToast(result.message, 'success');
                // Odśwież listę tabel w bazie
                await fetchDatabaseTablesList(currentTableId);
            } else {
                showToast(`Błąd zapisu: ${result.error}`, 'error');
            }
        } catch (error) {
            console.error('Błąd podczas zapisu:', error);
            showToast('Wystąpił błąd komunikacji z serwerem podczas zapisu do bazy.', 'error');
        } finally {
            btnSave.disabled = false;
            btnSave.innerHTML = '💾 Zatwierdź i zapisz do bazy';
        }
    }

    // Funkcja ładowania tabeli z bazy danych po ID
    async function loadTableFromDatabase(id) {
        try {
            const response = await fetch(`api/load_table.php?id=${encodeURIComponent(id)}`);
            const result = await response.json();

            if (result.success && result.table) {
                const t = result.table;
                currentTableId = t.id;
                tableNameInput.value = t.name;
                tableSelector.value = t.id;
                currentSheetBadge.textContent = `${t.name} (ID: ${t.id}, SQL: ${t.sql_table_name})`;

                // Wstawienie danych do siatki Excel
                spreadsheet.setData(t.sheet_data, t.headers);
                updateDimensionsBadge();

                showToast(`Pomyślnie załadowano tabelę "${t.name}" z bazy we4sai_erasmuss. Możesz ją teraz modyfikować i zatwierdzić zmiany!`, 'success');
                
                // Przewiń widok w kierunku arkusza
                document.getElementById('spreadsheetGrid').scrollIntoView({ behavior: 'smooth', block: 'center' });
            } else {
                showToast(`Błąd wczytywania: ${result.error || 'Nieznany błąd'}`, 'error');
            }
        } catch (error) {
            console.error('Błąd podczas wczytywania tabeli:', error);
            showToast('Wystąpił błąd podczas pobierania tabeli z serwera.', 'error');
        }
    }

    // Funkcja usuwania tabeli z bazy danych
    async function deleteTableFromDatabase(id, tableName) {
        if (!confirm(`Czy na pewno chcesz usunąć tabelę "${tableName}" z bazy danych we4sai_erasmuss? Ta operacja jest nieodwracalna.`)) {
            return;
        }

        try {
            const response = await fetch('api/delete_table.php', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json'
                },
                body: JSON.stringify({ id: id })
            });

            const result = await response.json();

            if (result.success) {
                showToast(result.message, 'success');
                if (currentTableId === parseInt(id, 10)) {
                    btnNew.click();
                }
                await fetchDatabaseTablesList();
            } else {
                showToast(`Błąd usuwania: ${result.error}`, 'error');
            }
        } catch (error) {
            console.error('Błąd podczas usuwania:', error);
            showToast('Wystąpił błąd serwera podczas usuwania tabeli.', 'error');
        }
    }

    // Pobranie listy zapisanych tabel i wypełnienie selektora oraz tabeli na dole strony
    async function fetchDatabaseTablesList(selectedIdToSet = null) {
        try {
            const response = await fetch('api/get_tables.php');
            const result = await response.json();

            if (!result.success) {
                console.error('Błąd pobierania tabel:', result.error);
                return;
            }

            const tables = result.tables || [];

            // 1. Aktualizacja selektora <select>
            tableSelector.innerHTML = '<option value="">-- Wybierz tabelę z bazy danych --</option>';
            tables.forEach(t => {
                const opt = document.createElement('option');
                opt.value = t.id;
                opt.textContent = `${t.name} (${t.row_count} wierszy × ${t.col_count} kolumn)`;
                tableSelector.appendChild(opt);
            });

            if (selectedIdToSet) {
                tableSelector.value = selectedIdToSet;
            }

            // 2. Aktualizacja tabeli podglądu tabel na dole strony
            savedTablesBody.innerHTML = '';
            if (tables.length === 0) {
                savedTablesBody.innerHTML = `<tr><td colspan="6" style="text-align:center; color:#888; padding:20px;">Brak zapisanych tabel w bazie we4sai_erasmuss. Wypełnij arkusz powyżej, nadaj mu nazwę i kliknij <strong>"Zatwierdź i zapisz do bazy"</strong>.</td></tr>`;
            } else {
                tables.forEach((t, idx) => {
                    const tr = document.createElement('tr');
                    tr.innerHTML = `
                        <td><strong>${idx + 1}</strong></td>
                        <td><span style="font-weight:600; color:#107c41;">${escapeHtml(t.name)}</span></td>
                        <td><span class="badge-tag">${t.row_count} wierszy × ${t.col_count} kol.</span></td>
                        <td><span class="badge-tag badge-sql">${escapeHtml(t.sql_table_name || 'brak')}</span></td>
                        <td style="color:#666; font-size:0.85rem;">${t.updated_at}</td>
                        <td style="white-space:nowrap;">
                            <button class="btn btn-outline" style="padding:4px 10px; font-size:0.8rem;" data-load-id="${t.id}">
                                📂 Wczytaj do edycji
                            </button>
                            <button class="btn btn-danger" style="padding:4px 10px; font-size:0.8rem; margin-left:6px;" data-del-id="${t.id}" data-name="${escapeHtml(t.name)}">
                                🗑️ Usuń
                            </button>
                        </td>
                    `;
                    savedTablesBody.appendChild(tr);
                });

                // Zdarzenia przycisków w tabeli dolnej
                savedTablesBody.querySelectorAll('[data-load-id]').forEach(btn => {
                    btn.addEventListener('click', () => {
                        const id = btn.getAttribute('data-load-id');
                        loadTableFromDatabase(id);
                    });
                });

                savedTablesBody.querySelectorAll('[data-del-id]').forEach(btn => {
                    btn.addEventListener('click', () => {
                        const id = btn.getAttribute('data-del-id');
                        const name = btn.getAttribute('data-name');
                        deleteTableFromDatabase(id, name);
                    });
                });
            }
        } catch (error) {
            console.error('Błąd pobierania listy tabel:', error);
        }
    }

    // Aktualizacja wskaźnika wymiarów arkusza
    function updateDimensionsBadge() {
        const rows = spreadsheet.rowsCount;
        const cols = spreadsheet.colsCount;
        currentDimensionsBadge.textContent = `${rows} wierszy × ${cols} kolumn`;
    }

    // System powiadomień Toast
    function showToast(message, type = 'info') {
        let container = document.getElementById('toastContainer');
        if (!container) {
            container = document.createElement('div');
            container.id = 'toastContainer';
            container.className = 'toast-container';
            document.body.appendChild(container);
        }

        const toast = document.createElement('div');
        toast.className = `toast ${type}`;

        const icon = type === 'success' ? '✅' : (type === 'error' ? '⚠️' : 'ℹ️');
        toast.innerHTML = `<span>${icon}</span> <div>${escapeHtml(message)}</div>`;

        container.appendChild(toast);

        setTimeout(() => {
            toast.style.opacity = '0';
            toast.style.transition = 'opacity 0.4s ease';
            setTimeout(() => {
                if (toast.parentNode) {
                    toast.parentNode.removeChild(toast);
                }
            }, 400);
        }, 4000);
    }

    function escapeHtml(text) {
        if (!text) return '';
        const div = document.createElement('div');
        div.textContent = text;
        return div.innerHTML;
    }

    // Załaduj listę tabel przy starcie strony
    fetchDatabaseTablesList();
    updateDimensionsBadge();
});
