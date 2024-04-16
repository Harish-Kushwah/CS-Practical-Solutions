package sem6.Java.practicals.slip22;
/*
1. Write a Menu Driven program in Java for the following: Assume Employee table with
attributes (ENo, EName, Salary) is already created. 1. Insert 2. Update 3. Display 4.
Exit.

 */
import java.sql.*;
import java.util.Scanner;

public class Ex1 {

    Connection conn;
    private String url = "jdbc:postgresql://localhost:5432/sample";
    private String user = "postgres";
    private String pass = "Harish";

    Ex1() {
        try {
            this.conn = DriverManager.getConnection(url, user, pass);
        } catch (Exception exp) {
            exp.printStackTrace();
        }
    }

    public void insertRecord() {
        String sql = "Insert into employee values(?,?,?);";
        try {
            PreparedStatement st = conn.prepareStatement(sql);

            Scanner scan = new Scanner(System.in);
            System.out.println("Enter employee details :");
            System.out.println("Enter Employee number :");
            int eno = scan.nextInt();
            System.out.println("Enter Employee Name :");
            String ename = scan.next();
            System.out.println("Enter Employe Salary :");
            int salary = scan.nextInt();

            st.setInt(1, eno);
            st.setString(2, ename);
            st.setInt(3, salary);

            st.execute();

            System.out.println("Record inserted successfully");

        } catch (SQLException ex) {
            ex.printStackTrace();
        }
    }

    public void updateSalary(String name, int salary) {
        try {
            String sql = "update employee set salary = ? where ename =?";
            PreparedStatement st = conn.prepareStatement(sql);

            st.setInt(1, salary);
            st.setString(2, name);

            if (st.executeUpdate() != 0) {
                System.out.println("Records updated successfully");
            } else {
                System.out.println("Records is not updated");
            }

        } catch (Exception exp) {
            exp.printStackTrace();
        }
    }

    public void displayAllRecords() {
        try {
            String sql = "select * from employee";
            PreparedStatement st = conn.prepareStatement(sql);

            ResultSet set = st.executeQuery();
            System.out.println("_______Details______");
            while (set.next()) {
                System.out.println("Employee number :" + set.getInt(1));
                System.out.println("Employee Name :" + set.getString(2));
                System.out.println("Employee Salary :" + set.getInt(3));
                System.out.println("------------------------");

            }
        } catch (Exception exp) {
            exp.printStackTrace();
        }
    }

    public static void menu() {
        System.out.println("________MENU_________");
        System.out.println("1.Enter for Insert");
        System.out.println("2.Enter for Update");
        System.out.println("3.Enter for Display");
        System.out.println("4.Enter for Exit");
    }

    public static void main(String[] args) {
        Ex1 s = new Ex1();
        Scanner scan = new Scanner(System.in);

        while (true) {
            menu();
            System.out.print("Enter choice");
            int n = scan.nextInt();
            if (n == 1) {
                s.insertRecord();
            } else if (n == 2) {
                System.out.println("Enter employee name :");
                String name = scan.next();
                System.out.println("Enter new salary :");
                int salary = scan.nextInt();
                s.updateSalary(name, salary);
            } else if (n == 3) {
                s.displayAllRecords();
            } else {
                System.exit(0);
            }

        }

    }
}
