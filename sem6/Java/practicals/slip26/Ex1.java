package sem6.Java.practicals.slip26;
/*
 * 1. Write a Java program to delete the details of given employee (ENo EName Salary).
Accept employee ID through command line. (Use PreparedStatement Interface)
 */
import java.sql.*;
public class Ex1 {
    private static String url = "jdbc:postgresql://localhost:5432/sample";
    private static String user = "postgres";
    private static String pass = "Harish";
    
    public static void deleteRecord(int eno)
    {
        try{
            Connection conn = DriverManager.getConnection(url,user,pass);
            String sql = "delete from employee where eno = ?";
            PreparedStatement st = conn.prepareStatement(sql);
            st.setInt(1, eno);
            
            if(st.executeUpdate()!=0){
                System.out.println("Record delated successfully");
            }
            else{
                System.out.println("Unable delate record");

            }
        }
        catch(Exception exp)
        {
            exp.printStackTrace();
        }
    }
    public static void main(String[] args)
    {          
        int eno = Integer.parseInt(args[0]);
        deleteRecord(eno);   
    }
}