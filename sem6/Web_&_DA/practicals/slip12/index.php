<?php 
// NOTE : CRETE THE contact.dat FILE USING PHP FIRST THEN BECAUSE .dat FILE IS NOT EDITABLE IN EDITORS
// LOAD  USING AJAX
//IN contact.dat FILE DATA IS INSERTED AS JSON FOM EASY PARING AND REPRESENTATION IN THE AJAX  
$str =<<< DATA
    [
    {
      "srno": 1,
      "name": "John Doe",
      "residence_number": "1234567890",
      "mobile_number": "9876543210",
      "address": "123 Main Street, Cityville"
    },
    {
      "srno": 2,
      "name": "Jane Smith",
      "residence_number": "2345678901",
      "mobile_number": "8765432109",
      "address": "456 Elm Street, Townsburg"
    },
    {
      "srno": 3,
      "name": "Alice Johnson",
      "residence_number": "3456789012",
      "mobile_number": "7654321098",
      "address": "789 Oak Avenue, Villagetown"
    }
  ]  
DATA;
$fp = fopen("contact.dat" , "w+");

fwrite($fp , $str);
fclose($fp);
echo "Data written successfully";
?>
<a href="index.html">Back</a>