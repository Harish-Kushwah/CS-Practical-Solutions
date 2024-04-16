package sem6.Java.practicals.slip16;
/*
2. Write a Java program to accept the details of Teacher (TNo, TName, Subject). Insert at
least 5 Records into Teacher Table and display the details of Teacher who is teaching
“JAVA” Subject. (Use PreparedStatement Interface) 
*/
import java.sql.*;
import java.util.Scanner;
public class Ex2 {
    private String url = "jdbc:postgresql://localhost:5432/studentdb";
    private String user = "postgres";
    private String pass = "Harish";
    
    Connection conn = null;
    Ex2()
    {
        try{
         this.conn = DriverManager.getConnection(url ,user,pass);
        }
        catch(Exception exp){
            exp.printStackTrace();
        }
    }
    public void insertTeacherDetails(int numberOfRecords)
    {
        try{
           String sql = "insert into teacher values(?,?,?)";
           PreparedStatement st = conn.prepareStatement(sql);
           
           for(int i=0; i<numberOfRecords ; i++)
           {
              System.out.println("Enter teacher details :");
              Scanner scan = new Scanner(System.in);
              System.out.print("Enter Teacher Number :");
              int tno = scan.nextInt();
              
              scan.nextLine(); //consume the extra \n generated in about integer input
              System.out.print("ENter Teacher Name:");
              String tname = scan.nextLine();
              
              System.out.println("Enter Teacher Subject:");
              String subject = scan.nextLine();
               
              st.setInt(1, tno);
              st.setString(2, tname);
              st.setString(3, subject);
              
              st.execute();
              System.out.println((i+1)+" teacher record inserted successfully");
           }
        }
        catch(Exception exp)
        {            
             exp.printStackTrace();
        }
    }
    
    public void showAllTeacherDetails()
    {
        try{
            String sql = "select * from teacher";
            PreparedStatement st = conn.prepareStatement(sql);
            ResultSet set = st.executeQuery();
            while(set.next())
            {
                System.out.println("______________Details______________");
                System.out.println("Teacher no : " + set.getInt(1));
                System.out.println("Teacher Name :"+ set.getString(2));
                System.out.println("Teacher Subject :"+set.getString(3));
                        
            }
        }
        catch(Exception exp)
        {
             exp.printStackTrace();
            
        }
    }
    public void showSubjectTeachers(String subject)
    {
        try{
            String sql = "select * from teacher where UPPER(subject) = ?";
            PreparedStatement st = conn.prepareStatement(sql);
            st.setString(1, subject.toUpperCase());
            
            ResultSet set = st.executeQuery();
            while(set.next())
            {
                System.out.println("Details of tehacher who studying subject "+subject);
                System.out.println("Teacher no : " + set.getInt(1));
                System.out.println("Teacher Name :"+ set.getString(2));
                System.out.println("Teacher Subject :"+set.getString(3));
            }          
        }
        catch(Exception exp)
        {
            exp.printStackTrace();
        }
    }
    public static void main(String[] args)
    {
        Ex2 db = new Ex2();
        db.insertTeacherDetails(5);
        db.showAllTeacherDetails();
        db.showSubjectTeachers("JAVA");
    }
}
