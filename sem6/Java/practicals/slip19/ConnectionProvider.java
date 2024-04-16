package sem6.Java.practicals.slip19;

import java.sql.*;
public class ConnectionProvider {
    private static final String URL = "jdbc:postgresql://localhost:5432/sample";
    private static final String USER = "postgres";
    private static final String PASSWORD = "Harish";
    
    private static Connection conn = null;
    public static Connection getConnection(){
        try {
            if (conn == null) {
                Class.forName("org.postgresql.Driver");
                conn = DriverManager.getConnection(URL, USER, PASSWORD);
                return conn;
            }
            return conn;
        } catch (SQLException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException ex) {
        }
        return null;
    }
}

