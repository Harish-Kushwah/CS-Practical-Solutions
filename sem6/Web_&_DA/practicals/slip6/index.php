<?php 

$xml = simplexml_load_file("book.xml");

foreach($xml ->book as $b)
{
    echo "Name :$b->name "."<br>";
    echo "Price :$b->price <br><br>";
}
