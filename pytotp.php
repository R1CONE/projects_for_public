<?php

$servername = "localhost";
$username = "root";
$dbPassword = ""; 
$database = "qa";

// Nawiązywanie połączenia z bazą danych
$conn = new mysqli($servername, $username, $dbPassword, $database);

// Sprawdzanie powodzenia połączenia
if ($conn->connect_error) {
    die("Błąd połączenia: " . $conn->connect_error);
}

// SQL-Query do uzyskania informacji o kolumnach w tabeli pytania
$sql = "DESCRIBE pytania";

$result = $conn->query($sql);

// Sprawdzanie powodzenia zapytania
if ($result) {
    $columnNames = array();

    // Wydobywanie nazw kolumn
    while ($row = $result->fetch_assoc()) {
        $columnNames[] = $row['Field'];
    }

    // Przypisywanie nazw zmiennym
    if (count($columnNames) >= 3) {
        $firstquestion = $columnNames[0];
        $secondquestion = $columnNames[1];
        $thirdquestion = $columnNames[2];

    } else {
        echo "Tabela pytania powinna zawierać co najmniej 3 kolumny.";
    }
} else {
    echo "Błąd wykonania zapytania: " . $conn->error;
}

// Zamykanie połączenia z bazą danych
$conn->close();

// Przetwarzanie przesłanych danych z formularza
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $conn = new mysqli($servername, $username, $dbPassword, $database);

    if ($conn->connect_error) {
        die("Błąd połączenia: " . $conn->connect_error);
    }

    $otp1 = $_POST["input1"];
    $otp2 = $_POST["input2"];
    $otp3 = $_POST["input3"];

    // Przygotowane wyrażenie dla wstawiania danych
    $sql = "INSERT INTO otpowiedzi (otpow1, otpow2, otpow3) VALUES (?, ?, ?)";

    $stmt = $conn->prepare($sql);
    $stmt->bind_param("sss", $otp1, $otp2, $otp3);
    
    if ($stmt->execute()) {
        echo "Dane zostały pomyślnie dodane do tabeli otpowiedzi.";
    } else {
        echo "Błąd podczas dodawania danych: " . $stmt->error;
    }

    $stmt->close();
    $conn->close();
}
?>

<!DOCTYPE html>
<html lang="pl">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Formularz wprowadzania informacji</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      margin: 20px;
    }

    label {
      display: block;
      margin-bottom: 5px;
    }

    input {
      width: 100%;
      padding: 8px;
      margin-bottom: 10px;
      box-sizing: border-box;
    }
  </style>
</head>
<body>

  <form method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">
    <label for="input1"><?php echo $firstquestion; ?></label>
    <input type="text" id="input1" name="input1" placeholder="Wprowadź informacje">

    <label for="input2"><?php echo $secondquestion; ?></label>
    <input type="text" id="input2" name="input2" placeholder="Wprowadź informacje">

    <label for="input3"><?php echo $thirdquestion; ?></label>
    <input type="text" id="input3" name="input3" placeholder="Wprowadź informacje">

    <input type="submit" value="Wyślij">
  </form>

</body>
</html>
