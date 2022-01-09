<?php
    //koneksi ke database
    include "sambung.php";
    
    //baca isi tabel sensor
    $level = $data["water_level"];

    //cetak
    echo $level;

?>