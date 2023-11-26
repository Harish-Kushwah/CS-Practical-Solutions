<?php
$size = $_POST['size'];

$height = $size *50;
$width = $size *50;
echo "<table border = 2 height = $height width= $width> ";
for ($i = 1; $i <= $size; $i++) {
        echo "<tr>";
        for ($j = 1; $j <= $size; $j++) {
                
                if ($i % 2 != 0) {
                        if ($j % 2 != 0) {
                                echo "<td style = \"background-color:black \"> </td>";
                        } else {
                                echo "<td style = \"background-color:white \"> </td>";
                        }
                } else {
                        if ($j % 2 == 0) {
                                echo "<td style = \"background-color:black \"> </td>";
                        } else {
                                echo "<td style = \"background-color:white \"> </td>";
                        }
                }
        }
        echo "</tr>";
}
echo "</table>";
