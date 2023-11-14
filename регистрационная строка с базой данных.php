<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Регистрация</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #f4f4f4;
            margin: 0;
            padding: 0;
            display: flex;
            align-items: center;
            justify-content: center;
            height: 100vh;
        }

        .container {
            background-color: #fff;
            border-radius: 8px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
            padding: 20px;
            width: 300px;
            text-align: center;
        }

        input {
            width: 100%;
            padding: 10px;
            margin: 10px 0;
            box-sizing: border-box;
            border: 1px solid #ccc;
            border-radius: 4px;
        }

        button {
            background-color: #4caf50;
            color: white;
            padding: 10px 20px;
            border: none;
            border-radius: 4px;
            cursor: pointer;
        }

        button:hover {
            background-color: #45a049;
        }
    </style>
</head>

</html>




<?php
$servername = "localhost"; // Название сервера базы данных
$username = "root"; // Имя пользователя базы данных
$password = ""; // Пароль пользователя базы данных
$database = "try_bd"; // Название базы данных

// Подключение к базе данных
$conn = new mysqli($servername, $username, $password, $database);

// Проверка подключения
if ($conn->connect_error) {
    die("Ошибка подключения к базе данных: " . $conn->connect_error);
} else {

    // Проверяем, была ли отправлена форма
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // Получаем данные из формы
        $login = $_POST["login"];
        $password = $_POST["password"];

        // Проверяем уникальность логина
        $check_query = "SELECT * FROM accounts WHERE login = '$login'";
        $result = $conn->query($check_query);

        if ($result->num_rows > 0) {
            echo "Ошибка: Логин '$login' уже существует. Пожалуйста, выберите другой логин.";
        } else {
            // Используем подготовленный запрос для предотвращения SQL-инъекций
            $stmt = $conn->prepare("INSERT INTO accounts (login, password) VALUES (?, ?)");
            $stmt->bind_param("ss", $login, $password);

            if ($stmt->execute()) {
                header("Location: main.html");
                    exit();
            } else {
                echo "Ошибка: " . $stmt->error;
            }

            $stmt->close();
        }

        $result->close();
    }

    // Закрываем подключение
    $conn->close();
}
?>

<form method="post" action="<?php echo $_SERVER["PHP_SELF"]; ?>">
    <label for="login">Логин:</label>
    <input type="text" name="login" required>

    <label for="password">Пароль:</label>
    <input type="password" name="password" required>

    <input type="submit" value="Войти">
</form>



