
<!-- 2.Write a JSP program to check whether a given number is prime or not. Display the result -->
<!-- in red color. -->
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>

        <form action="Ex2.jsp" method="POST">
            <input type="text" placeholder="Enter number" name="num" id="num">  
            <button type="submit">Submit</button>
        </form>

        <%

            if(request.getParameter("num")!=null){

            int num = Integer.parseInt(request.getParameter("num"));

            boolean isPrime = true;
            for (int i = 2; i <= num / 2; i++) {
                if (num % i == 0) {
                    isPrime = false;
                    break;
                }
            }

            if (isPrime) {
        %>
        <h1> <%= num%> is Prime Number </h1>
        <% } else {%>
        <h1 style="color:red"> <%= num%> is Not Prime Number </h1>
        <% }}%>

    </body>
</html>
