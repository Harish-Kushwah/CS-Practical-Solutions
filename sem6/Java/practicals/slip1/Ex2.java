package sem6.Java.practicals.slip1;
/**
 *
 * 2. Write a Java program to accept the details of Employee (Eno, EName,
 * Designation, Salary) from a user and store it into the database. (Use Swing)
 * => 1.Add the respective database driver in the pom.xml file 2.Create the
 * database and then Employee table in the pgsql with all the fields given here
 * 3.Make connection with given database using jdbc 4.Insert the details
 */

import java.sql.*;
import java.util.Scanner;

class Employee {

    private int Eno;
    private String Ename, Designation;
    private float Salary;

    public int getEno() {
        return Eno;
    }

    public String getEname() {
        return Ename;
    }

    public String getDesignation() {
        return Designation;
    }

    public float getSalary() {
        return Salary;
    }

    public Employee(int Eno, String Ename, String Designation, float Salary) {
        this.Eno = Eno;
        this.Ename = Ename;
        this.Designation = Designation;
        this.Salary = Salary;
    }

}

public class Ex2 {

    private static final String url = "jdbc:postgresql://localhost:5432/test";
    private static final String username = "postgres";
    private static final String password = "Harish";
    public static Connection con;

    public static boolean saveDetails(Employee emp) {

        boolean flag = false;
        try {

            Class.forName("org.postgresql.Driver");
            con = DriverManager.getConnection(url, username, password);
            if (con != null) {
                String query = "INSERT INTO public.employee(eno, ename, designation, salary) VALUES (?, ?, ?, ?);";

                PreparedStatement st = con.prepareStatement(query);
                st.setInt(1, emp.getEno());
                st.setString(2, emp.getEname());
                st.setString(3, emp.getDesignation());
                st.setDouble(4, emp.getSalary());

                st.executeUpdate();

                flag = true;

            } else {
                System.out.println("Connection successfull");
                flag = false;
            }
        } catch (Exception e) {
            flag = false;
            e.printStackTrace();
        }
        return flag;

    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Employee number:");
        int eno = scan.nextInt();

        scan.nextLine();
        System.out.println("Enter Employee Name:");
        String name = scan.nextLine();

        System.out.println("Enter Designation :");
        String designation = scan.nextLine();

        System.out.println("Enter Salary :");
        float salary = scan.nextFloat();

        Employee emp = new Employee(eno, name, designation, salary);

        if (saveDetails(emp)) {
            System.out.println("Employee Details Saved Succefully");
        } else {
            System.out.println("Unable to save");
        }
    }
}
