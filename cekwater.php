<?php
    //koneksi ke database
    include "sambung.php";
    
    //baca isi tabel sensor
    $watertemp = $data["water_temp"];

    //cetak
    echo $watertemp;

?>