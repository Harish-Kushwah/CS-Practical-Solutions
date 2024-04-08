<?php 

if(isset($_COOKIE['font-style']))
{
    $font_style =  $_COOKIE['font-style'] ;
}
if(isset($_COOKIE['font-size']))
{
    $font_size =  $_COOKIE['font-size'] ;
}
if(isset($_COOKIE['font-color']))
{
    $font_color =  $_COOKIE['font-color'] ;
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title></title>
    <style>
        p{
            font-size: <?php echo $font_size ?> px;
            font-style: <?php echo $font_style ?>;
            color: <?php echo $font_color?>;

        }
    </style>
</head>
<body>
    <p>Lorem ipsum dolor sit amet consectetur adipisicing elit. Voluptatibus ratione consectetur, ipsa ex ipsum doloribus mollitia ad tempore quidem repudiandae fuga. </p>
</body>
</html>

