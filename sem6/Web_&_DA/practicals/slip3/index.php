<!-- Q. 1) Write a PHP script to accept username and password. If in the first three chances, username and
password entered is correct then display second form with “Welcome message” otherwise display error
message. [Use Session] -->

<?php

session_start();
$correct_username = "Harish";
$correct_pass = "123";

if(isset($_POST['username'])){
 $username = $_POST['username'];
 $pass = $_POST['password'];


 if(strcmp($username , $correct_username)==0  && strcmp($pass , $correct_pass)==0){

    $_SESSION['count'] = 3;
    echo "<h3>Welcome , $username </h3>";
   
 }
 else{
    if(isset($_SESSION['count'])){

        $_SESSION['count']--;

        if($_SESSION['count']<1){
            echo "Total number of attempts finished";
            
        }
        else{ 
            echo "Total chance remaining :".$_SESSION['count'];
        }
    }
    else{
        $_SESSION['count'] = 3;
    }
   
 }

}
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <form action="index.php" method="POST">
        <label>Enter Username :</label>
        <input type="text" name="username">
        <br>
        <label>Enter Password :</label>
        <input type="password" name="password">
        <br>
        <button type="submit" >Submit</button>
        <button type="reset">Reset</button>
        <a href="index.php" type="button">Retry</a>
    </form>
</body>
</html>