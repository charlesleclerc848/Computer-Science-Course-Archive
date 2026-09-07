<?php

$server = "localhost";
$username = "root";
$password = "";
$dbname = "web6csp26new";

$conn = new mysqli($server, $username, $password, $dbname);

if (!$conn) {
    echo 'Connection is not Successful';
    
}

?>