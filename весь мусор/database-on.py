import pymysql

try:
    # Nawiązywanie połączenia z bazą danych
    connection = pymysql.connect(host='localhost', user='root',
                                 password='', database='tests_prog')

    print("Pomyślnie połączono...")
    print("#" * 20)

    try:

        # Tworzenie tabeli
        # with connection.cursor() as cursor:
        #     create_table_query = "CREATE TABLE IF NOT EXISTS users (id int AUTO_INCREMENT," \
        #                          " name varchar(32), " \
        #                          " password varchar(32)," \
        #                          " email varchar(32), PRIMARY KEY (id))"
        #     cursor.execute(create_table_query)
        #     print('TABELA ZOSTAŁA UTWORZONA')

        # Wstawianie informacji
        # with connection.cursor() as cursor:
        #     insert_query = "INSERT INTO users (name, password, email) VALUES ('M
        # Tworzenie tabeli
        # with connection.cursor() as cursor:
        #     create_table_query = "CREATE TABLE IF NOT EXISTS users (id int AUTO_INCREMENT," \
        #                          " name varchar(32), " \
        #                          " password varchar(32)," \
        #                          " email varchar(32), PRIMARY KEY (id))"
        #     cursor.execute(create_table_query)
        #     print('TABELA ZOSTAŁA UTWORZONA')

        # Wstawianie informacji
        # with connection.cursor() as cursor:
        #     insert_query = "INSERT INTO users (name, password, email) VALUES ('Mikhail', '123345', 'mikhail@gmail');"
        #     cursor.execute(insert_query)
        #     connection.commit()

        # Pobieranie informacji z tabeli
        # with connection.cursor() as cursor:
        #     select_all_rows = "SELECT * FROM users"
        #     cursor.execute(select_all_rows)
        #     rows = cursor.fetchall()
        #     for row in rows:
        #         print(row)
        #     print('#' * 20)

        # Aktualizacja danych: zmiana hasła dla wszystkich użytkowników, którzy mają imię Mikhail, na XXXXXX
        with connection.cursor() as cursor:
            update_query = "UPDATE users SET password = 'XXXXXXX' WHERE name = 'Mikhail';"
            cursor.execute(update_query)
            connection.commit()

    finally:
        connection.close()

except Exception as ex:
    print('Odmowa połączenia')
    print(ex)
