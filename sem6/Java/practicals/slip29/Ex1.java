package sem6.Java.practicals.slip29;
import java.sql.*;

/**
 * 1. Write a Java program to display information about all columns in the DONAR
 * table using ResultSetMetaData.
 */
public class Ex1 {
    private static String url = "jdbc:postgresql://localhost:5432/sample";
    private static String username = "postgres";
    private static String pass = "Harish";

    public static void main(String[] args) throws ClassNotFoundException, SQLException {
        
        Class.forName("org.postgresql.Driver");
        Connection conn = DriverManager.getConnection(url, username, pass);

        if (conn != null) {
            PreparedStatement st = conn.prepareStatement("select * from donar;");
            ResultSetMetaData data = st.getMetaData();
            for (int i = 1; i <= data.getColumnCount(); i++) {
                System.out.println("Column No :" + i);
                System.out.println("Column Name : " + data.getColumnName(i));
                System.out.println("Column type name :" + data.getColumnTypeName(i));
                System.out.println("Column Size :" + data.getColumnDisplaySize(i));
                System.out.println();
            }
        } else {
            System.out.println("Connection failed");
        }

    }

}
