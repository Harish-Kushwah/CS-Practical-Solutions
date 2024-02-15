<?php
  $num1 = $_POST['num1'];
  $num2 = $_POST['num2'];

  $op = $_POST['c'];

  if($op=='+')
  {
    echo "$num1 + $num2 = ".($num1 + $num2);
  }
  else if($op=='-')
  {
    echo "$num1 - $num2 = ".($num1 - $num2);
  }
  else if($op=='*')
  {
    echo "$num1 * $num2 = ".($num1 * $num2);
  }
  else if($op=='/')
  {
    echo "$num1 / $num2 = ".($num1 / $num2);
  }
?>