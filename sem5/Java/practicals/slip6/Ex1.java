package practicals.slip6;

import java.util.Scanner;

/*
 * Q1) Write a program to display the Employee(Empid, Empname, Empdesignation, Empsal)  
    information using toString().
 */
class Employee
{
    int empid;
    String empname;
    String emp_designation;
    float emp_sal;

    public void inputDetails()
    {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter Employee id :");
        this.empid = scan.nextInt();

        scan.nextLine();
        System.out.print("Enter employee name :");
        this.empname = scan.nextLine();

        System.out.print("Enter employee designation :");
        this.emp_designation = scan.nextLine();

        System.out.print("Enter employee salary :");
        this.emp_sal = scan.nextFloat();

        scan.close();
    }

    public String toString()
    {
        System.out.println("\nEmployee details :");
        String str = "ID :" + this.empid + "\nName :" + this.empname + "\nDesignation :"+ this.emp_designation + "\nsalary" + this.emp_sal;
        return str;
    }
}
public class Ex1 {
    public static void main(String[] args) {
        
        Employee emp = new Employee();
        emp.inputDetails();
        System.out.println(emp);
    }
}
