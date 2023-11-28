<?php 

  $sentence = $_POST['sentence'];
  $word = $_POST['word'];
  $pos = $_POST['pos'];
  $n = $_POST['n'];

  $ch = $_POST['c'];

  if($ch=='a')
  {
    $str = substr_replace($sentence ," " , $pos , $n);
    echo $str;
  }
  else if($ch == 'b')
  {
    $str = substr_replace($sentence , $word , $pos , 0);
    echo $str;
  }
  else if($ch == 'c')
  {
    $str = substr_replace($sentence ,$word , $pos , strlen($word));
    echo $str;
  }
?>