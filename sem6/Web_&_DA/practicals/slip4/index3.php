<?php 
session_start();
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Employee details</title>
</head>
<body>
    <h3>Employee Details </h3>
    <h3>Employee No: <?php echo $_SESSION['eno']?></h3>
    <h3>Employee name: <?php echo $_SESSION['ename']?></h3>
    <h3>Employee address: <?php echo $_SESSION['address']?></h3>
    <h3>Employee basic: <?php echo $_SESSION['basic']?></h3>
    <h3>Employee DA: <?php echo $_SESSION['da']?></h3>
    <h3>Employee HRA: <?php echo $_SESSION['hra']?></h3>
    <h3>Total :<?php echo $_SESSION['total']?></h3>
    <a href="index1.php">Go to Page-1</a>
</body>
</html>