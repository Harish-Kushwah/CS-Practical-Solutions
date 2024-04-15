package sem6.Java.practicals.slip7;

/*
2. Write a java program for the following:
i. To create a Product(Pid, Pname, Price) table.
ii. Insert at least five records into the table.
iii. Display all the records from a table. 
*/

import java.sql.*;
import java.util.Scanner;
public class Ex2 {
    Connection conn ;
    private String url = "jdbc:postgresql://localhost:5432/sample";
    private String user = "postgres";
    private String pass = "Harish";
    
    Ex2()
    {         
        try{
           this.conn = DriverManager.getConnection(url , user , pass);
        }
        catch (SQLException ex) {
            ex.printStackTrace();
         }
    }
    public void createTable()
    {
        try { 
            Statement stmt = conn.createStatement();
            String sql = "CREATE TABLE Product ( Pid Int NOT NULL , Pname Text , Price Int); ";
            stmt.executeUpdate(sql);
            System.out.println("Table created succefully"); 
        } catch (SQLException ex) {
            ex.printStackTrace();
        }
    }
    public void insertRecords(int number_of_records)
    {
        String sql = "INSERT INTO Product values(?,?,?);";
        try{
          Scanner scan = new Scanner(System.in);
          PreparedStatement st = conn.prepareStatement(sql);
          for(int i =0; i<number_of_records;i++)
          {
             System.out.println("Enter details of product :"+(i+1));
             
             System.out.print("Enter Produce number :");
             int pno = scan.nextInt();
             System.out.print("Enter product name :");
             String pname = scan.next();
             System.out.print("Enter product price :");
             int price  = scan.nextInt();
             
             st.setInt(1, pno);
             st.setString(2, pname);
             st.setInt(3, price);
             
             st.execute();
             
             System.out.println("Product "+(i+1)+" details inserted successfully");  
          }   
        }
        catch(Exception exp)
        {
            exp.printStackTrace();          
        }
    }
    
    public void displayAllDetails()
    {
        try{
          String sql = "select * from product";
          PreparedStatement stm = conn.prepareStatement(sql);
          
          ResultSet set = stm.executeQuery();          
          while(set.next())
          {
             System.out.println("__________Details____________");
             System.out.println("Product No :" + set.getInt(1));
             System.out.println("Product Name :" + set.getString(2));
             System.out.println("Product Price :" + set.getInt(3));
          }
        }
        catch(Exception exp){
            exp.printStackTrace();
        }
    }
    public static void menu()
    {  
        System.out.println("____________Menu________________");
        System.out.println("1.Enter to create table product");
        System.out.println("2.Enter to insert records into table");
        System.out.println("3.Enter to Display all the records from a table");
        System.out.println("4.Exit");
        
    }
    public static void main(String[] args)
    {
        Ex2 productDb = new Ex2();
        Scanner scan = new Scanner(System.in);
        while(true)
        {
            menu();
            System.out.print("Enter choice :");
            int choice = scan.nextInt();
            
            switch (choice) {
                case 1:
                    productDb.createTable();
                    break;
                case 2:
                    System.out.print("Enter how many records wants to insert :");
                    int num_reco = scan.nextInt();
                    productDb.insertRecords(num_reco);
                    break;
                case 3:
                    productDb.displayAllDetails();
                    break;
                default:
                    System.exit(0);
            }
        }
    }
}