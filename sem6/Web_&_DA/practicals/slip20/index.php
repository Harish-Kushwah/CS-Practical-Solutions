<?php 
$str = <<<xml
<?xml version="1.0" ?>
    <StudentDetails>
        <student>
            <name>Harish</name>
            <class>TYBCS</class>
            <branch>CS</branch>
        </student>
        <student>
            <name>Pratik</name>
            <class>TYBCS</class>
            <branch>CS</branch>
        </student>
        <student>
            <name>Rupesh</name>
            <class>BTECH</class>
            <branch>CSE</branch>
        </student>
        <student>
            <name>Rakesh</name>
            <class>SYBCS</class>
            <branch>CS</branch>
        </student>
        <student>
            <name>Roahn</name>
            <class>TYBCS</class>
            <branch>CS</branch>
        </student>
        
</StudentDetails>
xml;

$fp  = fopen("./student.xml" , "w+");

fwrite($fp , $str);
fclose($fp);
echo "File created successfully";