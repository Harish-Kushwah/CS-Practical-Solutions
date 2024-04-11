<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
</head>
<body>
<!-- Q. 1) Write Ajax program to fetch suggestions when is user is typing in a textbox. (eg like google  -->
<!-- suggestions. Hint create array of suggestions and matching string will be displayed) -->
    
        <input type="text" id="searchInput" placeholder="Search ">
        <div id=searchBox>

        </div>

        <script>
            $(document).ready(function(){
                $("#searchInput").keyup(function(e){

                    $.ajax({
                        type:"GET",
                        url:"hint.php",
                        data:{
                            q:$(this).val()
                        },
                        success:function(res){
                            $("#searchBox").text(res);
                        }
                    })
                   
                })
                
            })
        </script>
</body>
</html>