<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
</head>

<body>
    <!-- Q. 1) Write a PHP script using AJAX concept, to check user name and password are valid or Invalid (use  -->
    <!-- database to store user name and password).      -->

    <form id="login">
        <label for="">Enter Username</label>
        <input type="text" id="username">
        <br>
        <label for="">Enter password</label>
        <input type="password" id="password">
        <br>
        <button type="submit">submit</button>
    </form>

    <div id="status"></div>

    <script>
        $(document).ready(function(){
            $("#login").submit(function(e){
                e.preventDefault();
               var username = $("#username").val();
               var password = $("#password").val();

               $.ajax({
                type:"POST",
                url :"validate.php",
                data:{
                    username:username,
                    password:password,
                },
                success:function(response){
                    var string = String(response);
                    if(string == 'OK')
                    {
                        $("#status").html("<h1>Valid Credentials</h1>");
                    }
                    else{
                        $("#status").html("<h1>Invalid Credentials</h1>");
                    }
                }

               })
            
            })
        })
    </script>
</body>

</html>