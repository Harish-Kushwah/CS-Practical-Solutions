<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <form action="result" method="post">
            <label>Enter Pno :</label>
            <input type="number" name="pno">
            <br>
            <label>Enter Name :</label> 
            <input type="text" name="name"> 
             <br>
            
            <label>Enter Class</label>
            <input type="text" name="class"> 
             <br>
            <label>Enter Total Marks</label> 
            <input type="number" name="total_marks"> 
             <br>
            
            <button type="submit">Submit</submit>
        </form>
    </body>
</html>
