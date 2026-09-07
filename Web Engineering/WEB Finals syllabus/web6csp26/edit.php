<?php
require_once 'connection.php';
if (session_status() === PHP_SESSION_NONE) {
  session_start();
}
if (!isset($_SESSION['username'])) {
  header('location:login.php');
  exit();
}
require_once 'header.php';


$id = $_GET['updateid'];
$query = "select * from `signup` where id=$id";
$query_run = mysqli_query($conn, $query);
$row = mysqli_fetch_assoc($query_run);
$username = $row['username'];
$useremail = $row['email'];
$userpass = $row['password'];

if(isset($_POST['submit'])){

    $uname = mysqli_real_escape_string($conn,$_POST['username']);
    $email = mysqli_real_escape_string($conn,$_POST['email']);
    $pass = mysqli_real_escape_string($conn,$_POST['password']);
  
  $query = "update `signup` set id='$id', username='$uname', email = '$email', password = '$pass' where id = $id";
  $query_run = mysqli_query($conn, $query);
  if($query_run) {
    // echo 'data Updated successfully';
    header('location:display.php');
  } else {
    echo 'Updation failed';
  }
  }

?>

<div class="container"> <h1 class="display-3"> Update Cresdentials </h1></div>
<main class="form-signin w-100 m-auto mt-5 " >
            <form action="" method="post">
              <img class="mb-4" src="https://getbootstrap.com//docs/5.2/assets/brand/bootstrap-logo.svg" alt="" width="72" height="57">
              <h1 class="h3 mb-3 fw-normal">Update Your Data</h1>
          
              <div class="form-floating mt-1">
                <input type="text" name="username" class="form-control" id="floatingInput" placeholder="Enter username" value="<?php echo $username; ?>">
                <label for="floatingInput">Username</label>
              </div>
              <div class="form-floating mt-1">
                <input type="email" name="email" class="form-control" id="floatingInput" placeholder="name@example.com" value="<?php echo $useremail; ?>">
                <label for="floatingInput">Email address</label>
              </div>
              <div class="form-floating mt-1">
                <input type="password"  name="password" class="form-control" id="pwd" placeholder="Password" value="<?php echo $userpass; ?>">
                <label for="pwd">Password</label>
                <input type="checkbox" onclick = "pwd.type = this.checked ? 'text' : 'password'"
              </div>
          
              
              <button class="w-100 btn my-1 btn-lg btn-outline-success" type="submit" name="submit"  >Update</button>
              <!-- <p class="mt-5 mb-3 text-muted">© 2017–2022</p> -->
            </form>
          </main>

<?php include 'footer.php'; ?>