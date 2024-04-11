<?php 
/*
CREATE TABLE IF NOT EXISTS public.teacher
(
    id bigint,
    name text COLLATE pg_catalog."default",
    branch text COLLATE pg_catalog."default",
    exp integer
)
*/
$id = $_GET['id'];

$conn = pg_connect("host=localhost user=postgres password=Harish dbname=sample");
if($conn!=null)
{
    $query = "select * from public.teacher where id = '$id'";
    $res = pg_query($conn , $query);
    while($row = pg_fetch_array($res))
    {
        echo "Teacher id : $row[0] <br>";
        echo "Teacher Name : $row[1] <br>";
        echo "Teacher Branch : $row[2] <br>";
        echo "Teacher Experience : $row[3] <br>";

    }
}
else{
    echo "Connection is not enstablished";
}