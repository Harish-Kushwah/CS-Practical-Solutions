package sem6.Java.practicals.slip11;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

/**
 *
 * @author haris
 */
public class ConnectionProvider {
    private static final String URL = "jdbc:postgresql://localhost:5432/sample";
    private static final String USER = "postgres";
    private static final String PASSWORD = "Harish";
    
    private static Connection conn = null;
    public static Connection getConnection() throws ClassNotFoundException {
        try {
            if (conn == null) {
                Class.forName("org.postgresql.Driver");
                conn = DriverManager.getConnection(URL, USER, PASSWORD);
                return conn;
            }
            return conn;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }
}
