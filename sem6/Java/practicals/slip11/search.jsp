<%@page import="com.practicalslips.Customer"%>
<%@page import="java.util.ArrayList"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <h1>Search Customer Details</h1>
        <form action="SearchServlet" method="POST">
            <input type="text" placeholder="Enter customer number" name="num">
            <button type="submit">Submit </button>
        </form>
        
        <% 
           
            
           if(request.getAttribute("list") != null){
            ArrayList<Customer> list = (ArrayList<Customer>)request.getAttribute("list");
           
              for(Customer cust : list){
              out.println(cust.getId());
              out.println(cust.getName());
            }
            }
            else{
            out.println(request.getAttribute("list"));
            
            }
            
            

           
        %>
    </body>
</html>
