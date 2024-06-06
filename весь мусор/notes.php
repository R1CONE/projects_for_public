<?php
    function potenga($podstawa, $wykladnik) {
        $i = 1;
        $potenga = 1;
        while ( $i <= $wykladnik){
            $potenga = $potenga * $podstawa; //степень
            $i++;
        }
        return $potenga;
    }
    echo potenga(12, 2) . "<br>"; //144
?>

<?php
    function potenga($podstawa, $wykladnik) {
        if ($wykladnik == 0){
            return 1;
        }
        return $podstawa*potenga($podstawa, $wykladnik-1);
    }
    echo potenga(5, 2);
?>

<?php
$servername = "localhost";
$username = "root";
$dbPassword = "";
$database = "tests_prog";

$conn = new mysqli($servername, $username, $dbPassword, $database);

if ($conn->connect_error) {
    die("Błąd połączenia: " . $conn->connect_error);
}

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
<?php
    $samorzad = array('przewodniczacy'=>'Jakub','wice'=>'Michał','skarbnik'=>'Antoni','pkn'=>'Filip');
    if (isset($_GET['funkcja']) && isset($_GET['ile_razy'])) {
        $f = $_GET['funkcja'];
        $ile = $_GET['ile_razy']; 
        if (isset($samorzad[$f])) {
            for ($i = 0; $i < $ile; $i++) {
                echo $samorzad[$f] . "<br>";
            }
        } 
    }

    ?>

    <form action = "mikhail_siruts.php" metod="get">
        <select name = "funkcja">
            <option>przewodniczacy</option>
            <option>wice</option>
            <option>skarbnik</option>
            <option>kierowca</option>

        <input type="number" name="ile_razy">
        <input type="submit" value="Wyslij"> 
</body>
</html>
