package sem6.Java.practicals.slip17;
/*
 * 1. Write a java program to accept ‘N’ integers from a user. Store and display integers in
sorted order having proper collection class. The collection should not accept duplicate
elements.
 */
import java.util.Scanner;
import java.util.TreeSet;
public class Ex1 {
    public static void main(String[] args) {
        TreeSet<Integer> tree = new TreeSet<>();

        Scanner scan = new Scanner(System.in);
        System.out.print("Enter how many integers wants to add :");
        int n = scan.nextInt();
        for(int i =0; i<n; i++)
        {
            System.out.print("Enter number:");
            int num = scan.nextInt();
            tree.add(num);
        }

        System.out.println(tree);
        
    }
}
