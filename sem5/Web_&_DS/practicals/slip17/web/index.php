<?php 
 
$arr = array("Sagar"=>"31","Vicky"=>"41","Leena"=>"39","Ramesh"=>"40");

echo " <br><br> Before sorting on values <br><br> ";
print_r($arr);

echo " <br><br> After sorting In ascending order on values <br><br> ";
asort($arr);
print_r($arr);

echo " <br><br> After sorting  In ascending order on Keys <br><br> ";
ksort($arr);
print_r($arr);

echo " <br><br> After sorting In descending order on values <br><br> ";
arsort($arr);
print_r($arr);

echo " <br><br> After sorting  In descending order on Keys <br><br> ";
krsort($arr);
print_r($arr);


?>