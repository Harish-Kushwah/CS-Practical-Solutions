<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    
    <form acction="#" method="POST">

        <label>Enter number </label>
        <input type="number" name="num">
        <br>
        <input type="radio" name="c" value="a">Select for Fibonacci series<br>
        <input type="radio" name="c" value="b">To find sum of the digits of that number<br>
        <button type="submit" >Submit</button>
        <button type="reset">Reset</button>

    </form>
</body>
</html>

<?php 

    if(isset($_POST['c']) && isset($_POST['num']))
    {
        $ch = $_POST['c'];
        $num = $_POST['num'];

        if($ch =='a'){
            $f1  = 0;
            $f2  = 1;
            echo "fibonacci series up to $ch :".$f1.",".$f2;

            $i = 0;
            $num -=2;
            while($i<$num){
                $f3 = $f1 + $f2;
                $f1 = $f2;
                $f2 = $f3;
                $i++;
                echo ","."$f3";
            }

        }
        else{
            $sum = 0;
            while($num>0)
            {
                $rem = $num%10;
                $sum += $rem;
                $num/=10;
            }
            echo "Sum of the all the digits :".$sum;
        }


    }

?>