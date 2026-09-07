<?php

$username="root";
$server="localhost";
$password="";
$dbname="web6csp26";
$conn=new mysqli($server,$username,$password,$dbname);
if ($conn){
    echo 'Connection Successful';
}


?>