package practicals.slip1;
/*
 *  Define an abstract class Staff with protected members id and name. Define a parameterized 
 *  constructor. Define one subclass OfficeStaff with member department. Create n objects of 
 *  OfficeStaff and display all details
 */

import java.util.Scanner;

abstract class Staff 
{
    protected int id;
    protected String name;

    Staff(int id , String name)
    {
        this.id = id;
        this.name = name;
    }
}
class OfficeStaff extends Staff
{
    String department;
    OfficeStaff(int id, String name , String department) {
        super(id, name);
        this.department = department;
    }

    public void showOfficeDetails()
    {
        System.out.println("ID :" + this.id);
        System.out.println("Name :" + this.name);
        System.out.println("Department :" + this.department);
    }
    
}
public class Ex2 {
    public static void main(String[] args) {
        System.out.println("Enter total number of objects :");
        Scanner scan = new Scanner(System.in);
        int  n = scan.nextInt();

        OfficeStaff [] officeStaff = new OfficeStaff[n];
        for(int i=0;i<n;i++)
        {
            System.out.print("Enter id :");
            int id = scan.nextInt();
            scan.nextLine();
            System.out.print("Enter name :");
            String name = scan.nextLine();
            System.out.print("Enter department name :");
            String department  = scan.nextLine();
            officeStaff[i] = new OfficeStaff(id, name, department);
        }

        for(int i=0;i<n;i++)
        {
            officeStaff[i].showOfficeDetails();
        }

        scan.close();

    }
}
