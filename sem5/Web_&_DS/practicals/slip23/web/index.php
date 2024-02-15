<?php

session_start();

if (!isset($_SESSION['stack'])) {
    $_SESSION['stack'] = [];
}

$my_html = <<<html

 <form action="index.php" method="POST"> 
   <label>Enter number : </label>
   <input type="text" name="num">
   <br>
   <br>

   <input type="radio" name=c value=a>
   <label>a) Insert an element in stack</label>
   <br>

   <input type="radio" name=c value=b>
   <label>b) Delete an element from stack</label>
   <br>

   <input type="radio" name=c value=c>
   <label>c) Display the contents of stack</label>
   <br>
   <br>

   <button type="submit"> Submit </button>
   <button type="reset"> Reset </button>


 </form>
html;

echo $my_html;

$ch = $_POST['c'];

function print_stack()
{
    echo "Stack :<br>";
    foreach (array_reverse($_SESSION['stack']) as $val) {
        echo $val . "<br>";
    }
}

if ($ch == 'a') {
    array_push($_SESSION['stack'], $_POST['num']);
    print_stack();
} else if ($ch == 'b') {
    array_pop($_SESSION['stack']);
    print_stack();
}
else if($ch=='c')
{
    print_stack();
}
