<?php 
// Q. 1) Write a PHP script to read “Movie.xml” file and print all MovieTitle and ActorName of file using
// DOMDocument Parser. “Movie.xml” file should contain following information with at least 5 records
// with values. MovieInfoMovieNo, MovieTitle, ActorName ,ReleaseYear

$dom = new DOMDocument();

$dom->load("Movie.xml");

$movie_title = $dom -> getElementsByTagName("MovieTitle");
echo "Movie Title Name <br>";
foreach($movie_title as $title)
{
    echo $title->textContent ."<br>";
}

$actor_name = $dom -> getElementsByTagName("ActorName");
echo "Actor Names :";
foreach($actor_name as $name)
{
    echo $name->textContent."<br>";

}