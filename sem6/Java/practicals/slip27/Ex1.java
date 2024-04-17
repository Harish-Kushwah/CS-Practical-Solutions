package sem6.Java.practicals.slip27;

/*1. Write a Java Program to display the details of College (CID, CName, address, Year)
on JTable. */
import javax.swing.*;
import java.sql.*;
class College
{
    private static String url = "jdbc:postgresql://localhost:5432/sample";
    private static String user = "postgres";
    private static String pass = "Harish";
    
    public static String[][] getAllRecords()
    {
        try{
          Connection conn = DriverManager.getConnection(url,user,pass);
          if(conn!=null)
          {
              String sql ="select * from college";
              PreparedStatement st = conn.prepareStatement(sql);
             
              ResultSet set = st.executeQuery();
             
              String data[][]= new String[10][10];
              int i =0;
              while(set.next())
              {
                  data[i][0] = Integer.toString(set.getInt(1));
                  data[i][1] = set.getString(2);
                  data[i][2] = set.getString(3);
                  data[i][3] = Integer.toString(set.getInt(4));
                  i++;
              }
              
              return data;
          }
           
        }
        catch(Exception exp)
        {
            exp.printStackTrace();
        }
        return null;
    }
}
class MyFrame extends JFrame
{
    
    MyFrame()
    {
        setSize(500,500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        String data[][] = College.getAllRecords();
        String column []  = {"CID" , "CName" ,"Address" ,"Year"};
        
        JTable table = new JTable(data,column);
        add(table);
        
        setVisible(true);
    }
}
public class Ex1 {
    public static void main(String args[])
    {
        new MyFrame();
    }           
}