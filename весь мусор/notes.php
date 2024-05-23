<?php
    function potenga($podstawa, $wykladnik) {
        $i = 1;
        $potenga = 1;
        while ( $i <= $wykladnik){
            $potenga = $potenga * $podstawa;
            $i++;
        }
        return $potenga;
    }
    echo potenga(12, 2) . "<br>"; //144
?>
