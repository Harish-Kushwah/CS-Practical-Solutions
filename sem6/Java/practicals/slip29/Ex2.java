package sem6.Java.practicals.slip29;
/**
 * 2. Write a Java program to create LinkedList of String objects and perform the following:
i. Add element at the end of the list
ii. Delete first element of the list
iii. Display the contents of list in reverse order
 */

import java.util.*;
public class Ex2 {

    public static void menu()
    {
        System.out.println("1.Enter to add element at first position");
        System.out.println("2.Enter to delete last element");
        System.out.println("3.Enter to display the size of link list");
        System.out.println("4.Exit");
    }
    public static void main(String[] args) {
        LinkedList<Integer> list = new LinkedList<>();
        Scanner scan = new Scanner(System.in);
        while(true)
        {
            menu();
            System.out.print("Enter choice :");
            int ch = scan.nextInt();

            if(ch==1){
                System.out.print("Enter number :");
                int num = scan.nextInt();
                list.addFirst(num);
                System.out.println("Number added at first position :" + list);
            
            }
            else if(ch==2)
            {
                list.removeLast();
                System.out.println("Last element removed successfully : " + list);

            }
            else if(ch==3){
                System.out.println("Size if list :" + list.size());
            }
            else
            {
                System.exit(0);
            }
        }
    }
}

