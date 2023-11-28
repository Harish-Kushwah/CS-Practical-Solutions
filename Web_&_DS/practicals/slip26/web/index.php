<?php

$my_html = <<<html
    <form action = "index.php" method=POST>
        <label>Enter hospital name :</label>
        <input type="text" name=hname  >
        <br>
        <br>
        <button type="submit">Submit</button>
        <button type="reset">Reset</button>
    </form>
  html;
  
echo $my_html;

$hospital_name = $_POST['hname'];

$con = pg_connect("host = localhost user = postgres password = Harish  dbname = sample");
if ($con != null) {

    $my_query = <<<m1
     select * from public."Doctor",public."Hospital" where hname='$hospital_name' and fk_hospital=hosp_no;
    m1;
    $rs  = pg_query($con, $my_query);

    $table_head = <<<t
     <table border=1>
      <tr>
        <td>Doc no</td>
        <td>Name</td>
        <td>Address </td>
        <td>City</td>
        <td>area</td>
        <td>Hospital name</td>
        <td>Hospital city</td>
      </tr>
    t;
    echo $table_head;

    while ($row = pg_fetch_array($rs)) {
        $table_body = <<<t1
            <tr>
                <td>$row[0]</td>
                <td>$row[1]</td>
                <td>$row[2] </td>
                <td>$row[3] </td>
                <td>$row[4] </td>
                <td>$row[0] </td>
                <td>$row[8] </td>
            </tr>
        t1;
        echo $table_body;
    }
    echo "</table>";
 }
 else{
    echo "Connection failed";
 }
