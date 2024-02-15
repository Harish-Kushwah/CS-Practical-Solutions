<?php
$string = $_POST['str'];

$ch = $_POST['c'];

if ($ch == 'a') {
  $arr = explode(" ", $string);
  for ($i = 0; $i < 5; $i++) {
    echo $arr[$i] . " ";
  }
} else if ($ch == 'b') {
  $string = strtolower($string);
  echo "Lower case string :" . $string;
  $string = ucwords($string);
  echo "<br> Upper case string :" . $string;
} else if ($ch == 'c') {
  $string = str_pad($string, strlen($string) + 2, "*", STR_PAD_BOTH);
  echo $string;
} else if ($ch == 'd') {
  echo "Length before removing white space :" . strlen($string) . "<br>";
  $string = trim($string);
  echo "Length after removing white space :" . strlen($string);
} else if ($ch == 'e') {
  $string =  strrev($string);
  echo "Reverse is :" . $string;
}
