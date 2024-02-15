<?php

$f1_name = $_POST['first'];
$f2_name = $_POST['second'];

$f1 = fopen($f1_name , "r") or die ("Unable to open file");
$f2 = fopen($f2_name , "a")  or die ("Unable to open file");

$f1_size  = filesize($f1_name);
$f1_content = fread($f1 ,$f1_size);

//appending the first file content to f2 file
fwrite($f2 , $f1_content , $f1_size);

echo "File content appended successfully";

?>