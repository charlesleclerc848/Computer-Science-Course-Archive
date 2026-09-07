<!-- <!doctype html>
<html lang="en">
    <head>
        <title>Title</title>
        <!-- Required meta tags -->
        <!-- <meta charset="utf-8" />
        <meta
            name="viewport"
            content="width=device-width, initial-scale=1, shrink-to-fit=no"
        />

        Bootstrap CSS v5.2.1 -->
        <!-- <link
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
    </head> -->

    <!-- <body> -->

    <?php
    require_once 'connection.php';
    include 'header.php'
    if(isset($_POST['submit'])){
        $uname=mysqli_real_escape_string()
    }
        <main class="form-signin w-100 m-auto mt-5 " >
            <form>
              <img class="mb-4" src="https://getbootstrap.com//docs/5.2/assets/brand/bootstrap-logo.svg" alt="" width="72" height="57">
              <h1 class="h3 mb-3 fw-normal">Register Yourself</h1>
          
              <div class="form-floating mt-1">
                <input type="text" class="form-control" id="floatingInput" placeholder="Enter username">
                <label for="floatingInput">Username</label>
              </div>
              <div class="form-floating mt-1">
                <input type="email" class="form-control" id="floatingInput" placeholder="name@example.com">
                <label for="floatingInput">Email address</label>
              </div>
              <div class="form-floating mt-1">
                <input type="password" class="form-control" id="floatingPassword" placeholder="Password">
                <label for="floatingPassword">Password</label>
              </div>
          
              <div class="checkbox mb-3">
                <label>
                  <input type="checkbox" value="remember-me"> Agree
                </label>
              </div>
              <button class="w-100 btn btn-lg btn-primary" type="submit">Register</button>
              <!-- <p class="mt-5 mb-3 text-muted">© 2017–2022</p> -->
            </form>
          </main>
        <!-- Bootstrap JavaScript Libraries -->
        <script
            src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.11.8/dist/umd/popper.min.js"
            integrity="sha384-I7E8VVD/ismYTF4hNIPjVp/Zjvgyol6VFvRkX/vR+Vc4jQkC+hVqc2pM8ODewa9r"
            crossorigin="anonymous"
        ></script>

        <script
            src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.min.js"
            integrity="sha384-BBtl+eGJRgqQAUMxJ7pMwbEyER4l1g+O15P+16Ep7Q9Q+zqX6gSbd85u4mG4QzX+"
            crossorigin="anonymous"
        ></script>
    </body>
</html>
