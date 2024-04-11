<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Document</title>

  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
</head>

<body>

  <select id="selectName">

    <option>Select Name</option>

      <?php

      $conn = pg_connect("host=localhost user=postgres password=Harish dbname=sample");
      if ($conn != null) {
        $query = "select * from employee";
        $rs = pg_query($conn, $query);

        while ($row = pg_fetch_array($rs)) {
          print_r($row);
          echo "<option value = " . $row[1] . ">  $row[1] </option>";
        }
      }
      ?>
  </select>
  <hr>
  <div id="showDetails"></div>


  <script>
    $(document).ready(() => {
      $("#selectName").change(function() {
        var name = $(this).val();
        $.ajax({
          type: "GET",
          url: "index.php",
          data: {
            username: name
          },
          success: function(response) {
            $("#showDetails").html(response);

          },
          error: function(xhr, status, error) {
            console.error(xhr);
          }
        })
      })
    })
  </script>
</body>

</html>