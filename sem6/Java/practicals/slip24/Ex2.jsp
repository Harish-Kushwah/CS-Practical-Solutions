<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <form action="#" method="POST">
            <input type="text" name="username" placeholder="Enter username">
            <br> 
            <input type="password" name="password" placeholder="Enter password">
            <br> 
            <button type="submit">Submit</button>
            
        </form>
        
        <% 
             if(request.getParameter("username")!=null && request.getParameter("password")!=null)
             {
                 if(request.getParameter("username").equals(request.getParameter("password")))
                 {
                   out.println("Login Successfull");
                 }
                 else{
                    out.println("Login Failed");
                 }
             }
        
         
        %>
    </body>
</html>
