<?php
     //koneksi ke database
    $konek = mysqli_connect("localhost", "id18212439_db_hidroponikadit", "Dataadit*123", "id18212439_db_monitoring");

    //baca data yang dikirim
    if (isset($_GET["suhu"]) AND isset($_GET['water_temp']) AND isset($_GET['lembab'])
    AND isset($_GET['flow']) AND isset($_GET['ph']) AND isset($_GET['water_level']))
        {
            $suhu = $_GET['suhu'];
            $water_temp = $_GET['water_temp'];
            $lembab = $_GET['lembab'];
            $flow = $_GET['flow'];
            $ph = $_GET['ph'];
            $water_level = $_GET['water_level'];
            echo "Data sent to database - - ";
        }
    else { echo "Ada salah bro! - - ";}

    //auto increment = 1
    mysqli_query($konek, "ALTER TABLE tb_sensor AUTO_INCREMENT=1");

    //update data di database
    echo "Updating database... - - ";
    //$simpan = mysqli_query($konek, "insert into tb_sensor(suhu, water_temp, lembab)values('$suhu', '$water_temp')");
    $simpan = mysqli_query($konek, "insert into tb_sensor(suhu, water_temp, lembab, flow, ph, water_level)
    values('$suhu', '$water_temp', '$lembab', $flow, $ph, $water_level)");

    //uji simpan
    if($simpan)
        echo "Berhasil dikirim";
    else
        echo "Gagal Terkirim";
?>
