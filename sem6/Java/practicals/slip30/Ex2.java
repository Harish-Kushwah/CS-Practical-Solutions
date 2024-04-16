package sem6.Java.practicals.slip30;

import java.sql.*;

public class Ex2 {
    public static void main(String[] args) {
        Connection connection = null;
        Statement statement = null;
        ResultSet resultSet = null;

        try {
            // Establishing connection to the database
            String jdbcUrl = "jdbc:postgresql://localhost:5432/sample";
            String username = "postgres";
            String password = "Harish";
            connection = DriverManager.getConnection(jdbcUrl, username, password);

            // Creating a statement with ResultSet.TYPE_SCROLL_INSENSITIVE to make ResultSet scrollable
            statement = connection.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);

            // Executing query to select all records from the Teacher table
            resultSet = statement.executeQuery("SELECT * FROM teacher");

            // Moving cursor to the last row using resultSet.last()
            resultSet.last();

            // Getting the total number of rows using resultSet.getRow()
            int rowCount = resultSet.getRow();

            // Printing total number of rows
            System.out.println("Total number of rows: " + rowCount);

            // Moving cursor to the first row using resultSet.first()
            resultSet.first();

            // Printing column values for each row
            System.out.println("Teacher table content:");
            while (resultSet.next()) {
                int tid = resultSet.getInt(1);
                String tname = resultSet.getString(2);
                double salary = resultSet.getDouble(3);
                System.out.println("TID: " + tid + ", TName: " + tname + ", Salary: " + salary);
            }

            // Moving cursor to the last row again
            resultSet.last();

            // Printing column values for the last row
            int lastTid = resultSet.getInt(1);
            String lastTname = resultSet.getString(2);
            double lastSalary = resultSet.getDouble(3);
            System.out.println("Last row - TID: " + lastTid + ", TName: " + lastTname + ", Salary: " + lastSalary);
    
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            // Closing resources
            try {
                if (resultSet != null) resultSet.close();
                if (statement != null) statement.close();
                if (connection != null) connection.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
}

