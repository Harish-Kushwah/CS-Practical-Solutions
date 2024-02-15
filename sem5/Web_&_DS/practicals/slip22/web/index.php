<?php
session_start();
if (!isset($_SESSION['arr'])) {
    $_SESSION['arr'] = [];
}
$mm = <<<M
  <form action="index.php" method=POST>

        <label for="">Enter number :</label>
        <input type="text" name=num>
        <br>
        <br>

        <input type="radio" name="c" value="a">
        <label for="">a) Insert an element in queue </label>
        <br>
        <input type="radio" name="c" value="b">
        <label for="">b) Delete an element from queue </label>
        <br>
        <input type="radio" name="c" value="c">
        <label for="">c) Display the contents of queue  </label>

        <br>
        <button type="submit">Submit</button>
        <button type="reset">Reset</button>
    </form>
  M;

echo $mm;
$ch = $_POST['c'];

function print_queue()
{
    echo "Queue :";
    foreach($_SESSION['arr'] as $val )
    {
        echo $val." ";
    }
}

if ($ch == 'a') {
    array_push($_SESSION['arr'], $_POST['num']);
    print_queue();

} else if ($ch == 'b') {
    array_shift($_SESSION['arr']);
    print_queue();

} else {
    print_queue();
}