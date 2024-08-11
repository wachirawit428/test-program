<?php include 'main.html';?>
<!DOCTYPE html>
<html lang="en">
<head>
  <title>ผลลัพธ์</title>

</head>
<body>
  <h1>ผลลัพธ์</h1>
  <?php
  require('main.html');

    function calculate_value($date_input) {
      $data = explode(' ', $date_input);
      $result = "วันที่: $data[0], เดือน: $data[1], ปี: $data[2]";
      return $result;
    }

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
      $date_input = $_POST["date_input"];
      $calculated_value = calculate_value($date_input);
      echo "<p>ผลลัพธ์ที่คำนวณ: <strong>$calculated_value</strong></p>";
    }
  ?>
</body>
</html>
