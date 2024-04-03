<%@page contentType="text/html" pageEncoding="UTF-8"%>

<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <% 
           
           int num = Integer.parseInt(request.getParameter("num"));
          
           boolean isPerfect = false;
           int sum = 0 ;
           for(int i=1; i<num; i++){
              if(num%i==0){
              sum+=i;
            }
            }
            if(sum==num){
                isPerfect = true;
            }

          if(isPerfect){
        %>
        <h1> <%= num %> is Perfect Number </h1>
        <% } else{%>
        <h1 style="color:red"> <%= num %> is Not Perfect Number </h1>
        <% } %>
   
    </body>
</html>
