<?php 
  
  $str = $_POST['str'];

  $ch = $_POST['op'];

  $sep = $_POST['sep'];

  if($ch=='a'){
    foreach(explode($ch , $str) as $val)
    {
      echo $val."<br>";
    }
  }
  else if($ch=='b')
  {
       $cnt = substr_count($str,$sep);
       $new_str = str_replace($sep , "!" , $str , $cnt);
       echo "<br>After changing separators <br>" .$new_str;
  }
  else if($ch=='c')
  {
       $all_words = explode(" " , $str);
       $total_words = count($all_words);
       echo "<br> This is last word :" .$all_words[$total_words -1 ];
  }
 
 
?>