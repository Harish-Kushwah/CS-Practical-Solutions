<?php

$s1 = $_POST['s1'];
$s2 = $_POST['s2'];
$ch = $_POST['c'];

if($ch=='a')
{

    $pos =(int) strpos($s2,$s1);
        if($pos == 0)
        {
            echo "<p> ".$s1." Is smaller appears at start ".$s2."</p>";

        }
        else{
            echo "<p> ".$s1." Is smaller not  appears at start ".$s2."</p>";
        }
}

if($ch=='b')
{
    $pos =(int) strpos($s2,$s1);
    echo $pos;
}

if($ch=='c')
{
    if(strcasecmp($s1,$s2)>0)
    {
        echo "First string is bigger";
    }
    else{
        echo "Second string is bigger";
    }
}

?>