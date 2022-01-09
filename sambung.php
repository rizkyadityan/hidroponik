<?php
    $konek = mysqli_connect("localhost", "id18212439_db_hidroponikadit", "Dataadit*123", "id18212439_db_monitoring");
        //baca isi tabel sensor
    $sql = mysqli_query($konek,"select * from tb_sensor order by id
        desc");
    $data = mysqli_fetch_array($sql);
?>