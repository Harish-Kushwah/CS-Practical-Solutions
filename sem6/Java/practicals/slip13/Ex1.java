package sem6.Java.practicals.slip13;
/*
 * 1. Write a Java program to display information about the database and list all the tables in 
    the database. (Use DatabaseMetaData).  
 */
import java.sql.*;

public class Ex1 {

    private static String url = "jdbc:postgresql://localhost:5432/sample";
    private static String username = "postgres";
    private static String pass = "Harish";

    public static void main(String[] args) {
        try {

            Connection conn = DriverManager.getConnection(url, username, pass);
            if (conn != null) {
                DatabaseMetaData dbmd = conn.getMetaData();
                //Database meta data
                System.out.println("Driver Name :" + dbmd.getDriverName());
                System.out.println("Database Product Name :" + dbmd.getDatabaseProductName());
                System.out.println("Driver Version :" + dbmd.getDriverVersion());
                System.out.println("DatabaseMinor Version :" + dbmd.getDatabaseMinorVersion());

                //Database tables
                String table[] = {"TABLE"};
                ResultSet set = dbmd.getTables(null, null, null, table);
                while (set.next()) {
                    System.out.println(set.getString(3));
                }

            } else {
                System.out.println("Connection failed");
            }

        } catch (SQLException ex) {
            ex.printStackTrace();
        }

    }

}
