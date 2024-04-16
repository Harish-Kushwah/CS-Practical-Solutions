<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <form action="#" method="post">
            <label>Enter name : <label>
            <input type="text" name="name"><br>
            <label>Enter Age :</label> 
            <input type="number" name="age"> 
            <br>
            <button type="submit">Submit</button>
         </form>
        
        
        <% 
           if(request.getParameter("name")!=null&& request.getParameter("age")!=null)
           {
             int age = Integer.parseInt(request.getParameter("age"));
             String name = request.getParameter("name");
             if(age>18){
                out.println( "<br>Congratulation , <b>"+ name + "</b> you are eligible for voting" );
              }
              else{
                        out.println( "<br>Opp's Sorry ,<b> "+ name + "</b> you are not eligible for voting" );
        }
           }
        %>
    </body>
</html>
