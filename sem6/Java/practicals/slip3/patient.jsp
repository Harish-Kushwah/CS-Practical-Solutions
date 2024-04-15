<%@page import="helper.ConnectionProvider"%>
<%@page import="java.sql.*"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Patient Details</title>
    </head>
    <body>

        <table border="1px">
            <thead>          
            <th>Sr.No</th>
            <th>Name</th>
            <th>Address</th>
            <th>Age</th>
            <th>Disease</th>
        </thead>
        <tbody>
            <%
                Connection conn = ConnectionProvider.getConnection();
                PreparedStatement st = conn.prepareStatement("SELECT  * FROM public.patient;");
                ResultSet set = st.executeQuery();

            %>
            <tr>
                <% while (set.next()) {
                %>
                <td><%= set.getInt(1)%></td>
                <td><%= set.getString(2)%></td>
                <td><%= set.getString(3)%></td>
                <td><%= set.getString(4)%></td>
                <td><%= set.getString(5)%></td>
            </tr>
            <%
                }
            %>
    </table>
</body>
</html>
