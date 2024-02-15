<?php 

  $temp = [45.5 , 40.5 ,30, 35 ,36 , 45 , 50 , 60 , 25 , 33 ,
           31.3 , 44.4 ,41.6, 39.99, 35.45];

   $total_temp  = 0;
   foreach($temp as $t )
   {
    $total_temp += $t;
   }

   $avg  = $total_temp / 15;
   echo "Average temperatures is : $avg ";

   rsort($temp);
   echo "<br> five warmest high temps <br> ";
   for($i=0 ; $i<5;$i++)
   {
    echo $temp[$i]."<br>";
   }

   print_r(range(10,40));
?>