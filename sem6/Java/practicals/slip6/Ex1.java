package sem6.Java.practicals.slip6;
/**
 * 1. Write a Java program to accept ‘n’ integers from the user and store them in a collection.
    Display them in the sorted order. The collection should not accept duplicate elements.
    (Use a suitable collection). Search for a particular element using predefined search
    method in the Collection framework.
 */
import java.util.*;
public class Ex1 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter N :");
        int n = scan.nextInt();
        TreeSet<Integer> tree = new TreeSet<>();
        for(int i=0; i<n;i++){
            System.out.println("Enter number :");
            int num = scan.nextInt();

            tree.add(num);
        }

        System.out.println(tree);
        System.out.println("Enter number to search :");
        int target = scan.nextInt();
        if(tree.contains(target)){
            System.out.println("Number is found :");
        }
        else{
            System.out.println("Number not found");
        }
    }
}
