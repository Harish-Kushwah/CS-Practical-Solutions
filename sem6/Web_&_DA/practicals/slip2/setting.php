<?php 

$font_style = $_POST['font-style'];
$font_size = $_POST['font-size'];
$font_color = $_POST['font-color'];

echo "Selected Setting :<br>";
echo "Font style : $font_style <br> Font size : $font_size <br> Font color : $font_color";


setcookie("font-style" , $font_style);
setcookie("font-size" , $font_size);
setcookie("font-color" , $font_color);

echo "<br> <a href='result.php'>Go to Page </a>";