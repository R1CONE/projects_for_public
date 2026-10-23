# Aplikacja Logowania i Rejestracji (PHP + MySQL / XAMPP)

Aplikacja zawiera kompletny system logowania i rejestracji użytkowników, zabezpieczony hashowaniem haseł (`password_hash`), obsługą sesji oraz połączeniem PDO z bazą danych MySQL w XAMPP.

## 📁 Struktura plików
- [`database.sql`](file:///c:/Users/Public/Julian%20Matczak/AplikacjaAntigravity/database.sql) – Skrypt SQL tworzący bazę danych `auth_app` i tabelę `users`.
- [`db.php`](file:///c:/Users/Public/Julian%20Matczak/AplikacjaAntigravity/db.php) – Połączenie z bazą danych PDO (z automatycznym tworzeniem bazy i tabeli przy pierwszym uruchomieniu).
- [`index.php`](file:///c:/Users/Public/Julian%20Matczak/AplikacjaAntigravity/index.php) – Okienko z formularzami **Zaloguj się** oraz **Zarejestruj się** z przełączaniem zakładek.
- [`dashboard.php`](file:///c:/Users/Public/Julian%20Matczak/AplikacjaAntigravity/dashboard.php) – Czysta strona po zalogowaniu z komunikatem `Użytkownik [login] jest zalogowany` oraz przyciskiem wylogowania.
- [`logout.php`](file:///c:/Users/Public/Julian%20Matczak/AplikacjaAntigravity/logout.php) – Bezpieczne wylogowanie i zniszczenie sesji.
- [`style.css`](file:///c:/Users/Public/Julian%20Matczak/AplikacjaAntigravity/style.css) – Nowoczesne i przejrzyste style CSS.

---

## 🚀 Jak uruchomić w XAMPP

### Krok 1: Uruchomienie XAMPP
1. Otwórz **XAMPP Control Panel**.
2. Włącz moduły **Apache** oraz **MySQL** (kliknij **Start** przy obu).

### Krok 2: Umieszczenie plików w XAMPP
Skopiuj zawartość tego katalogu (`c:\Users\Public\Julian Matczak\AplikacjaAntigravity`) do folderu htdocs w XAMPP, np.:
`C:\xampp\htdocs\aplikacja`

### Krok 3: Baza danych
Plik [`db.php`](file:///c:/Users/Public/Julian%20Matczak/AplikacjaAntigravity/db.php) automatycznie utworzy bazę `auth_app` i tabelę `users` podczas pierwszego wejścia na stronę.

*Opcjonalnie (ręcznie w phpMyAdmin):*
1. Otwórz w przeglądarce `http://localhost/phpmyadmin`.
2. Przejdź do zakładki **Import** lub **SQL**.
3. Zaimportuj plik [`database.sql`](file:///c:/Users/Public/Julian%20Matczak/AplikacjaAntigravity/database.sql).

### Krok 4: Otwórz aplikację w przeglądarce
Wejdź pod adres:
👉 **`http://localhost/aplikacja`**

---

## ⚡ Alternatywne uruchomienie (PHP Built-in Server)
Jeśli w XAMPP włączony jest tylko MySQL:
1. Otwórz terminal w tym folderze.
2. Uruchom polecenie:
   ```bash
   php -S localhost:8000
   ```
3. Otwórz w przeglądarce: **`http://localhost:8000`**.
