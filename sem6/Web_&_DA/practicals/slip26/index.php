<?php 
// Q. 1) Create employee table as follows EMP (eno, ename, designation, salary). Write Ajax program to 
// select the employees name and print the selected employee’s details

$username = $_GET['username'];
$conn = pg_connect("host = localhost user = postgres password= Harish dbname = sample");

if($conn != null)
{
    $query = "select * from employee where ename = '$username' ";

    $rs = pg_query($conn , $query);
    while($row = pg_fetch_array($rs))
    {
        echo "Emp no : $row[0] <br>";
        echo "Employee Name :$row[1]<br>";
        echo "Designation :$row[2] <br>";
        echo "Salary :Rs.$row[3]<br>";
    }
}
else{
    echo "connection failed";
}
