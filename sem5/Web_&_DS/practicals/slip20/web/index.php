<?php 

  $arr = ['b' => 2, 'a'=>1 , 'c'=>3];

  echo "Origin array :";
  print_r($arr);
  echo "<br><br>";

  echo "Array after dividing into chunks <br>";
  $new_arr = array_chunk($arr , 2);
  print_r($new_arr);
  echo "<br><br>";

  echo "Array after sorting  <br>";
  asort($arr);
  print_r($arr);
  echo "<br><br>";


  echo "Array after filtering even numbers <br>";
  function even($num)
  {
    if($num%2==0)
    return 1;
    return 0;
  }
  $new_even_arr = array_filter($arr , "even");
  print_r($new_even_arr);
?>