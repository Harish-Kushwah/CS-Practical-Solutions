<?php 
 $ch = $_POST['c'];

 $arr = array("Harish"=> 123 , "Rakesh" => 345 , "Pratik" => 333);

 if($ch=='a')
 {
    echo "Origin array :";
    print_r($arr);

    echo "<br> After reversing array : ";
    $ans = array_reverse($arr);
    print_r($ans);
 }
 else if($ch=='b')
 {
    echo "Origin array :";
    print_r($arr);

    echo "<br> After traversing :";
    foreach($arr as $val)
    {
        echo $val." ";
    }

 }
 else if($ch=='c')
 {
    extract($arr);
    echo "\$Harish = $Harish <br> \$Rakesh = $Rakesh <br> \$Pratik = $Pratik";
 }
 else if($ch=='d')
 {
    echo "Origin array :";
    print_r($arr);
    echo "<br>";
    foreach($arr as $k => $val )
    {
        print_r("$k=>$val");
        echo "<br>";
    }
 }
?>