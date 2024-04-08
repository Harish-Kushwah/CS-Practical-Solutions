<?php 

$str =<<<XML
    <xml version='1.0' encoding="UTF-8"/>
    <Items>
        <item>
            <item-name>Apple</item-name>
            <item-rate>23</item-rate>
            <item-quantity>4</item-quantity>
        </item>
        <item>
            <item-name>Mango</item-name>
            <item-rate>10</item-rate>
            <item-quantity>2</item-quantity>
        </item>
        <item>
            <item-name>Apple</item-name>
            <item-rate>23</item-rate>
            <item-quantity>4</item-quantity>
        </item>
        <item>
            <item-name>Mango</item-name>
            <item-rate>10</item-rate>
            <item-quantity>2</item-quantity>
        </item>
        <item>
            <item-name>Apple</item-name>
            <item-rate>23</item-rate>
            <item-quantity>4</item-quantity>
        </item>
    </Items>
XML;


$fname = "./ Item.xml";
$fp = fopen($fname , "w+");
fwrite($fp , $str);
fclose($fp);

echo 'Created filename is : '.$fname;