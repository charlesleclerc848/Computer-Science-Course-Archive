<?php
require_once 'connection.php';
if (session_status() === PHP_SESSION_NONE) {
  session_start();
}
if (isset($_SESSION['username'])) {
  
  header('location:index.php');
  exit();
}
include 'header.php';
$error = '';
if(isset($_POST['submit'])){

  $uname = mysqli_real_escape_string($conn,$_POST['username']);
  $email = mysqli_real_escape_string($conn,$_POST['email']);
  $pass = mysqli_real_escape_string($conn,$_POST['password']);

$query = "select * from `signup` where email = '$email'";
$query_run = mysqli_query($conn, $query);
if (mysqli_num_rows($query_run)>0) {
  $error = 'Email Already exists';  
}else{

  $query = "insert into `signup` (`username`,`email`,`password`) values ('$uname','$email','$pass')";
  $query_run = mysqli_query($conn, $query);
  if($query_run) {
    header('location:login.php');
    exit();
    // echo 'data inserted successfully';
  } 
  }
}

?>
<?php if($error != '') { ?>
  <div class="alert alert-warning alert-dismissible fade show" role="alert">
    <strong><?php echo $error; ?></strong>
    <button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button>
  </div>
<?php } ?>
        <main class="form-signin w-100 m-auto mt-5 " >
            <form action="" method="post">
              <img class="mb-4" src="https://getbootstrap.com//docs/5.2/assets/brand/bootstrap-logo.svg" alt="" width="72" height="57">
              <h1 class="h3 mb-3 fw-normal">Register Yourself</h1>
          
              <div class="form-floating mt-1">
                <input type="text" name="username" class="form-control" id="floatingInput" placeholder="Enter username">
                <label for="floatingInput">Username</label>
              </div>
              <div class="form-floating mt-1">
                <input type="email" name="email" class="form-control" id="floatingInput" placeholder="name@example.com">
                <label for="floatingInput">Email address</label>
              </div>
              <div class="form-floating mt-1">
                <input type="password" name="password" class="form-control" id="floatingPassword" placeholder="Password">
                <label for="floatingPassword">Password</label>
              </div>
          
              <div class="checkbox mb-3">
                <label>
                  <input type="checkbox" value="remember-me"> Agree
                </label>
              </div>
              <button class="w-100 btn btn-lg btn-success" type="submit" name="submit"  >Register</button>
              <!-- <p class="mt-5 mb-3 text-muted">© 2017–2022</p> -->
            </form>
          </main>
      <?php
      include 'footer.php'
      ?>
