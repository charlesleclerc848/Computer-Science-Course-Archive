<?php
if (session_status() === PHP_SESSION_NONE) {
  session_start();
}
?>

<!doctype html>
<html lang="en">
    <head>
        <title></title>
        <!-- Required meta tags -->
        <meta charset="utf-8" />
        <meta
            name="viewport"
            content="width=device-width, initial-scale=1, shrink-to-fit=no"
        />
        <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.13.1/font/bootstrap-icons.min.css">
<link rel="stylesheet" href="https://cdn.datatables.net/2.3.8/css/dataTables.bootstrap5.css">
      
        <!-- Bootstrap CSS v5.2.1 -->
        <link
            href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css"
            rel="stylesheet"
            integrity="sha384-T3c6CoIi6uLrA9TneNEoa7RxnatzjcDSCmG1MXxSR1GAsXEV/Dwwykc2MPK8M2HN"
            crossorigin="anonymous"
        />
        <style>
  .form-signin {
    max-width: 330px;
    padding: 15px;
    
    
}
.m-auto {
    margin: auto !important;
}
.w-100 {
    width: 100% !important;
}
*, ::after, ::before {
    box-sizing: border-box;
}

user agent stylesheet
main {
    display: block;
    unicode-bidi: isolate;
}


        </style>

    </head>

    <body>
        
        <nav class="navbar navbar-expand-lg bg-light">
            <div class="container-fluid">
              <a class="navbar-brand" href="index.php">Navbar</a>
              <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
              </button>
              <div class="collapse navbar-collapse" id="navbarSupportedContent">
                <ul class="navbar-nav me-auto mb-2 mb-lg-0">
                  <li class="nav-item">
                    <a class="nav-link active" aria-current="page" href="index.php">Home</a>
                  </li>
                  <li class="nav-item">
                    <a class="nav-link" href="">Link</a>
                  </li>
                  <li class="nav-item dropdown">
                    <a class="nav-link dropdown-toggle" href="#" role="button" data-bs-toggle="dropdown" aria-expanded="false">
                      Dropdown
                    </a>
                    <ul class="dropdown-menu">
                      <li><a class="dropdown-item" href="#">Action</a></li>
                      <li><a class="dropdown-item" href="#">Another action</a></li>
                      <li><hr class="dropdown-divider"></li>
                      <li><a class="dropdown-item" href="#">Something else here</a></li>
                    </ul>
                  </li>
                 <?php if(isset($_SESSION['username'])){
                 ?>              
                  <li class="nav-item">
                  <a class="nav-link" href="display.php"><i class="bi bi-gear me-2"></i>Settings</a>
                  </li> 
                  <?php } ?>
                </ul>
                <form class="d-flex" role="search">
                  <input class="form-control me-2" type="search" placeholder="Search" aria-label="Search">
                  <button class="btn btn-outline-success" type="submit">Search</button>
                </form>
               <?php  if(isset($_SESSION['username'])){ 
?>
                  <a href="logout.php"><button class="btn btn-danger mx-1">Log Out</button></a>
               <?php }else {?>

                  
                  <a href="login.php"><button class="btn btn-primary mx-1">Login</button></a>
                  <a href="signup.php"><button class="btn btn-success me-1">Signup</button></a>
                <?php } ?>
              </div>

            </div>
          </nav>

