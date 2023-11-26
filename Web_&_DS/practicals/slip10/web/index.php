<?php 
 
 $num1 = $_POST['a'];
 $num2 = $_POST['b'];
 $ch = $_POST['c'];

function mod($num1  , $num2)
{
    echo "Mod of $num1 and $num2 is :".$num1%$num2; 
}
function power($num1 , $num2)
{
    $pr = 1;
    for($i = 1;$i<=$num2;$i++)
    {
        $pr*=$num1;
    }

    echo "Power of $num1 ^ $num2 is :".$pr;
}
function sum($n)
{
    $sum = 0 ;
    for($i = 1; $i<=$n;$i++)
    {
        $sum+=$i;
    }
    echo "sum of first $n numbers is :".$sum;
}
function fact($n)
{
    $pr = 1;
    for($i = 2; $i<=$n ; $i++)
    {
        $pr*=$i;
    }
    echo "Factorial of $n is :".$pr;
}


if($ch=='a')
{
    mod($num1, $num2);
}
else if($ch=='b')
{
    power($num1,$num2);
}
else if($ch=='c')
{
    sum($num1);
}
else if($ch == 'd')
{
    fact($num2);
}

?>