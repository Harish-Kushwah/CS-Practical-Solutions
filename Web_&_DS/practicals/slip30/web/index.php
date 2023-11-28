<?php 
  $my_html =<<<html
    <form action="index.php" method = "POST">
        <label>Enter competition name </label>
        <input type = "text" name=cmp>
        <br> 
        <br>
        
        <button type="submit">Submit</button>
        <button type="reset"> Reset</button>

    </form>
  html;
  echo $my_html;

  $competition_name = $_POST['cmp'];

  $con = pg_connect("host = localhost user=postgres password=Harish dbname=sample");
  if($con != null)
  {

    $my_query =<<<q
    select std_no ,name, class from 
      public.student,public.competition,public.std_com 
      where comp_name = '$competition_name' and comp_id=comp_no and std_no =std_id and rank=1 ;
    q;

    $table_head = <<<t
    <table border=1>
      <thead> First Rank in  $competition_name</thead>
     <tr>
       <td>Student no</td>
       <td>Name</td>
       <td>Class </td>
     </tr>
   t;
   echo $table_head;
   
    $rs = pg_query($con , $my_query);
    while($row = pg_fetch_array($rs))
    {
        $table_body = <<<t1
        <tr style=text-align:center>
            <td>$row[0]</td>
            <td>$row[1]</td>
            <td>$row[2] </td>
        </tr>
    t1;
    echo $table_body;
    }
    echo "</table>";
}
else{
   echo "Connection failed";
}

?>