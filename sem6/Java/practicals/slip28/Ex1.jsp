
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <form action="#" method="POST">
            <label>Enter String</label>
            <input type="text" name="str"> 
            <button type="submit">Submit</button>
        </form>
        
        <% 
           if(request.getParameter("str")!=null)
           {
              StringBuffer sb  = new StringBuffer(request.getParameter("str"));
              sb.reverse();
              out.println("<br>Reverse String :" + sb);        
           }
        
        %>
    </body>
</html>
