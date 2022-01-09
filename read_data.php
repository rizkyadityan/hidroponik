<?php
    require 'sambung2.php';
    $hasil = mysqli_query($conn,"select * from parameter");
    $row = mysqli_fetch_array($hasil);
    echo "Temp SV :", $row["water_temp_sv"]," ", "Humidity SV :", $row["lembab_sv"];
    echo "\nFlow Limit :", $row["flow_sv"]," ", "pH SV :", $row["ph_sv"];
    echo "\nWater Level Limit :", $row["water_level_sv"],"\n";
?>