<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <form action="#" method="POST">
        <h4>Enter Basic details of employee(page-1)</h4>
        <label>Enter employee number :</label>
        <input type="number" name="eno">
        <br>
        <label>Enter employee name :</label>
        <input type="text" name="ename">
        <br>
        <label>Enter employee address:</label>
        <textarea name="address">
        </textarea>

        <br>
        <button type="submit">Submit</button>
        <button type="reset">reset</button>
    </form>
</body>
</html>

<?php
session_start();

if (isset($_POST['eno']) && isset($_POST['ename']) && isset($_POST['address'])) {
    $_SESSION['eno'] = $_POST['eno'];
    $_SESSION['ename'] = $_POST['ename'];
    $_SESSION['address'] = $_POST['address'];
    echo "<h5>First Page details saved successfully <a href='index2.php'>page-2</a></h5> ";
}
?>