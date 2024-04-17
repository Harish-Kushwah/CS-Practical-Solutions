<%@page import="java.time.format.DateTimeFormatter"%>
<%@page import="java.time.*"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <form action="#" method="POST">
            <label>Enyer username :</label>
            <input type="text" name="username">
            <br>
            <label>Set time for greeting:</label>
            <input type="time" name="time">
            <button type="submit">Submit</button>
        </form>
        
        <% 
           if(request.getParameter("username")!= null && request.getParameter("time")!=null)
           {
              String username = request.getParameter("username");
              String time = request.getParameter("time");
              
              DateTimeFormatter dtf =DateTimeFormatter.ofPattern("HH:mm");
              
              
              LocalTime greet_time = LocalTime.parse(time);
              
              while(true){
              
                 LocalDateTime now = LocalDateTime.now();
                 LocalTime current_time = LocalTime.parse(dtf.format(now));
                 Duration duration = Duration.between(greet_time,current_time);
              
                 if(duration.isZero()){
                    out.println("Welcome ," + username);
                    break;
                 }
                 else if(duration.isPositive()){
                    out.println("Set valid time for greeting");
                    break;
                 }
                
                 
               }
              }
        %>
    </body>
</html>
