<?php 
  $serial = [];
  $sub = [];
  $marks =[];

  $string = 1;

  $total_marks = 0;

  for($i=1;$i<=5;$i++)
  {
    $sr_r = "s".$i;
    $sub_r = "sub".$i;
    $marks_r = "marks".$i;
    $serial[$i-1] = $_POST[$sr_r]; 
    $sub[$i-1] = $_POST[$sub_r ]; 
    $marks[$i-1] = $_POST[$marks_r]; 

    $total_marks +=$marks[$i-1];
  }

  $percentage = $total_marks/5;

  echo "<h4> Result </h4>";
  
  echo "<table border=1 height=280 width=320 style=\"text-align:center;font-size:20px; \">";
    echo "<tr>";
     echo "<td>";
       echo "serial";
     echo "</td>";

     echo "<td>";
       echo "sub";
     echo "</td>";
     echo "<td>";
       echo "marks";
     echo "</td>";
 
    echo "</tr>";

   for($i = 1 ; $i<=5;$i++)
   {
    echo "<tr>";
    echo "<td>";
      echo $serial[$i-1];
    echo "</td>";

    echo "<td>";
      echo $sub[$i-1];
    echo "</td>";
    echo "<td>";
      echo $marks[$i-1];
    echo "</td>";

   echo "</tr>";
   }
  
  
  echo"</table>";
  echo "<br>";
  echo "Total Marks  : " .$total_marks ."<br>";
  echo "Percentage  : " .$percentage ."% <br>";
  echo "Grade  : " . getGrade($percentage) ."<br>";

  function getGrade($percentage)
  {
    if($percentage >=80)
    return "A";
    else  if($percentage >=70)
    return "B";
    else if($percentage >=50)
    return "C";
    else if($percentage >=30)
    return "D";
    else    
    return "F";

  }
?>