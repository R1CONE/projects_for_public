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

<?php
$klasa = array(0 => "Bartosz", 1 => "Kajetan", 2 => "Michail", 3 => "Elvira");
$ind = 0;
$znaleziono = 0;

while($znaleziono < count($klasa)){
    if (isset($klasa[$ind])){
        echo $klasa[$ind]."<br>";
        $znaleziono++;
    }
    $ind++;
}

echo implode('<br>', $klasa);
?>
