<?php
$requested_name = $_GET['q'];

$data = array(
    "Harish",
    "Rakesh",
    "Pratik",
    "Priya Patel",
    "Rajesh Kumar",
    "Anjali Sharma",
    "Siddharth Singh",
    "Nisha Verma",
    "Akash Gupta",
    "Pooja Shah",
    "Rahul Desai",
    "Aarti Mehta",
    "Arjun Choudhury",
);

$hint = "";
$requested_name = strtolower($requested_name);
$len = strlen($requested_name);
if ($requested_name !== "") {
    foreach ($data as $name) {
        if (stristr($requested_name, substr($name, 0, $len))) {
            if ($hint === "") {
                $hint = $name;
            } else {
                $hint .= " , $name";
            }
        }
    }
    echo $hint;
}
