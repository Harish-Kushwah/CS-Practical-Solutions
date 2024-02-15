package practicals.slip6;
/*
 * Q2) Create an abstract class “order” having members id, description. Create two subclasses  
       “Purchase  Order” and “Sales Order” having members customer_name name and Vendor name     
         respectively. Define methods accept and display in all cases. Create 3 objects each of Purchase  
         Order and Sales Order and accept and display details.
 */

import java.util.Scanner;

abstract class Order 
{
    int id;
    String description;
}
class PurchaseOrder extends Order 
{
    String customer_name;
    public void accept()
    {
        Scanner scan  = new Scanner(System.in);
        System.out.print("Enter customer id :");
        this.id = scan.nextInt();

        scan.nextLine();
        System.out.print("Enter customer name :");
        this.customer_name = scan.nextLine();

        System.out.print("Enter description :");
        this.description = scan.nextLine();
    }
    public void display()
    {
        System.out.println("customer Id :" + this.id);
        System.out.println("customer name :"+this.customer_name);
        System.out.println("Description :" + this.description);
    }

}

class SalesOrder extends Order 
{
    String vender_name;

     public void accept()
    {
        Scanner scan  = new Scanner(System.in);
        System.out.print("Enter vender id :");
        this.id = scan.nextInt();

        scan.nextLine();
        System.out.print("Enter vendor name :");
        this.vender_name = scan.nextLine();

        System.out.print("Enter description :");
        this.description = scan.nextLine();
    }
    public void display()
    {
        System.out.println("vender Id :" + this.id);
        System.out.println("vender name :"+this.vender_name);
        System.out.println("Description :" + this.description);
    }

}
public class Ex2 {
    public static void main(String[] args) {
        PurchaseOrder []o1  = new PurchaseOrder[3];
        
        SalesOrder []s1 = new SalesOrder[3];
        for(int i=0;i<3;i++)
        {
            System.out.println("\nEnter Purchase Order details");
            o1[i] = new PurchaseOrder();
            o1[i].accept();
            o1[i].display();

            System.out.println("\nEnter Sales Order details");
            s1[i] = new SalesOrder();
            s1[i].accept();
            s1[i].display();
        }
    }
}
