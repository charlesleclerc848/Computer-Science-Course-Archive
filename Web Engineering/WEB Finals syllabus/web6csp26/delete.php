<?php 

include 'connection.php';
if (session_status() === PHP_SESSION_NONE) {
  session_start();
}
if (!isset($_SESSION['username'])) {
  header('location:login.php');
  exit();
}
if (isset($_GET['delete'])) {
    $id = $_GET['delete'];
    $query = "delete from `signup` where id = $id";
    $query_run = mysqli_query($conn, $query);
    if ($query_run) {
        header('location:display.php');

    }else
    {
        echo die(mysqli_error($conn)).'not deleted';
    }
}
?>