<!-- 2. Write a JSP program to calculate sum of first and last digit of a given number. Display
sum in Red Color with font size 18.  -->

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Ex2</title>
    </head>
    <body>
        
       <form action="Ex2.jsp" method="POST">
       <label>Enter number :</label>
       <input type="text" name="num">
       <button type="submit">Submit</button>
       </form>
        <%
            if(request.getParameter("num")!=null){
             int len = request.getParameter("num").length();
             int num = Integer.parseInt(request.getParameter("num"));   
             int pow = (int)Math.pow(10, len-1);
             int sum = num%10 + num/pow;
             
         %>
         <h4 style="color:red; font-size: 18px"><%= sum %></h4>
         <%
            }
        %>
        
    </body>
</html>
