<?php

require_once 'connection.php';
if (session_status() === PHP_SESSION_NONE) {
  session_start();
}
require_once 'header.php';
if (!isset($_SESSION['username'])) {
  header('location:login.php');
  exit();
}
?>


<div class="container" >
    <h1 class="display-2">
        User Registration Details </h1>

</div>
<div class="container-fluid">
<table class="table table-striped" id="example">
  <thead>
    <tr>
      <th scope="col">Id#</th>
      <th scope="col">Username</th>
      <th scope="col">Email</th>
      <th scope="col">Password</th>
      <th scope="col">Action</th>
    </tr>
  </thead>
  <tbody>
  <?php 
  $sql = "select * from `signup`";
$query_run = mysqli_query($conn,$sql);

// var_dump($row);
// echo $row;
if ($query_run) {
    while ($row = mysqli_fetch_assoc($query_run)) {
        $id = $row["id"];
        $uname = $row["username"];
        $email = $row["email"];
        $password = $row["password"];
        echo '<tr>
        <th scope="row">'.$id.'</th>
        <td>'.$uname.'</td>
        <td>'.$email.'</td>
        <td>'.$password.'</td>
        <td>
        <button type="button" class="btn btn-info"><a class="text-light" href="view.php">View</a></button>
        <button type="button" class="btn btn-primary"><a class="text-light" href="edit.php?updateid='.$id.'">Edit</a></button>
        <button type="button" class="btn mx-1 btn-danger"><a class="text-light" href="delete.php?delete='.$id.'">Delete</a></button></td>
        </tr>';
        
    }
}
        ?>   
  </tbody>
</table>
</div>

<?php include 'footer.php';
?>