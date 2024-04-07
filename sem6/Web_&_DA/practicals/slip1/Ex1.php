<?php 
// Q. 1) Write a PHP script to keep track of number of times the web page has been accessed (Use Session 
// Tracking).

session_start();

if(!isset($_SESSION['id'])){
    $_SESSION['id'] = 0;
}
else{
    $_SESSION['id']++;
}

echo "Total number of time accessd : ". $_SESSION['id'];


