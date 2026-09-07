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

if (isset($_POST['submit'])) {
  $email = mysqli_real_escape_string($conn,$_POST['email']);
  $password = mysqli_real_escape_string($conn,$_POST['password']);

  $query = "SELECT * FROM `signup` WHERE email = '$email' AND password = '$password'";
  $query_run = mysqli_query($conn, $query);
  if (mysqli_num_rows($query_run)>0) {
    
    $user = mysqli_fetch_assoc($query_run);
    $_SESSION['username'] = $user['username'];
    header('Location: index.php');
    exit();
  } else {
    $error = 'Invalid email or password';
  }
}
?>
<?php if($error != '') { ?>
  <div class="alert alert-warning alert-dismissible fade show" role="alert">
    <strong><?php echo $error; ?></strong>
    <button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button>
  </div>
<?php } ?>
<div class="container">
    <section class="w-100 p-4 p-xl-5">

        <style>
        .gradient-custom-2 {
            background: #fccb90;
            background: -webkit-linear-gradient(to right, #ee7724, #d8363a, #dd3675, #b44593);
            background: linear-gradient(to right, #ee7724, #d8363a, #dd3675, #b44593);
        }
        @media (min-width: 768px) {
            .gradient-form {
                height: 100vh !important;
            }
        }
        @media (min-width: 769px) {
            .gradient-custom-2 {
                border-top-right-radius: .3rem;
                border-bottom-right-radius: .3rem;
            }
        }
        .p-4 { padding: 1.5rem !important; }
        .w-100 { width: 100% !important; }
        *, *::before, *::after { box-sizing: border-box; }
        .text-center { text-align: center !important; }
        button:not(:disabled),
        [type=button]:not(:disabled),
        [type=reset]:not(:disabled),
        [type=submit]:not(:disabled) { cursor: pointer; }
        .btn-block { display: block; width: 100%; }
        </style>

        <div class="row d-flex justify-content-center">
            <div class="col-12">
                <div class="card rounded-3">
                    <div class="row g-0">
                        <div class="col-lg-6">
                            <div class="card-body p-md-5 mx-md-4">

                                <div class="text-center">
                                    <img src="lotus.png" style="width: 185px;" alt="logo">
                                    <h4 class="mt-1 mb-5 pb-1">We are The Lotus Team</h4>
                                </div>
                                <form action="" method="post">
                                    <p>Please login to your account</p>

                                    <div class="form-outline mb-4">
                                        <input type="email" name="email" id="form2Example11" class="form-control"
                                            placeholder="Phone number or email address" required>
                                        <label class="form-label" for="form2Example11"
                                            style="margin-left: 0px;">Email</label>
                                        <div class="form-notch">
                                            <div class="form-notch-leading" style="width: 9px;"></div>
                                            <div class="form-notch-middle" style="width: 67.2px;"></div>
                                            <div class="form-notch-trailing"></div>
                                        </div>
                                    </div>

                                    <div class="form-outline mb-4">
                                        <input type="password" name="password" id="form2Example22" class="form-control" required>
                                        <label class="form-label" for="form2Example22"
                                            style="margin-left: 0px;">Password</label>
                                        <div class="form-notch">
                                            <div class="form-notch-leading" style="width: 9px;"></div>
                                            <div class="form-notch-middle" style="width: 64px;"></div>
                                            <div class="form-notch-trailing"></div>
                                        </div>
                                    </div>

                                    <div class="text-center pt-1 mb-5 pb-1">
                                        <!-- FIX: This must be type="submit" to actually submit the form! -->
                                        <button
                                            class="btn btn-primary btn-block fa-lg gradient-custom-2 mb-3"
                                            type="submit" name="submit">
                                            Log in
                                        </button>
                                        <a class="text-muted" href="#!">Forgot password?</a>
                                    </div>

                                    <div class="d-flex align-items-center justify-content-center pb-4">
                                        <p class="mb-0 me-2">Don't have an account?</p>
                                        <a href="signup.php" class="text-light">
                                            <button type="button" class="btn btn-outline-danger">Create new</button>
                                        </a>
                                    </div>
                                </form>

                            </div>
                        </div>
                        <div class="col-lg-6 d-flex align-items-center gradient-custom-2">
                            <div class="text-white px-3 py-4 p-md-5 mx-md-4">
                                <h4 class="mb-4">We are more than just a company</h4>
                                <p class="small mb-0">Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do
                                    eiusmod tempor
                                    incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud
                                    exercitation
                                    ullamco laboris nisi ut aliquip ex ea commodo consequat.</p>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </section>
</div>

<?php
include 'footer.php';
?>