

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="#" method="POST">
        <h4>Enter Earning details of employee(page-2)</h4>
        <label >Enter Basic :</label>
        <input type="number" name="basic">
        <br>
        <label >Enter DA :</label>
        <input type="number" name="da">
        <br>
        <label >Enter HRA :</label>
        <input type="number" name="hra">
        <br>

        
        <button type="submit">Submit</button>
        <button type="reset">reset</button>
    </form>
</body>
</html>

<?php
session_start();

if (isset($_POST['basic']) && isset($_POST['da']) && isset($_POST['hra'])) {
    $_SESSION['basic'] = $_POST['basic'];
    $_SESSION['da'] = $_POST['da'];
    $_SESSION['hra'] = $_POST['hra'];
    $_SESSION['total'] = $_SESSION['basic'] + $_SESSION['da'] + $_SESSION['hra'];
    echo "<h5>Second Page details saved successfully <a href='index3.php'>page-3</a></h5> ";
}
?> 