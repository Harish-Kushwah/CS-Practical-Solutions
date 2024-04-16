package sem6.Java.practicals.slip19;
/*
 * 1. Write a java program to accept ‘N’ Integers from a user store them into LinkedList
Collection and display only negative integers
 */
import java.util.*;
public class Ex1 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter N :");
        int n = scan.nextInt();

        LinkedList<Integer> list = new LinkedList<>();

        for(int i =0 ; i<n; i++)
        {
            System.out.print("Enter number :");
            int num = scan.nextInt();
            list.add(num);
        }

        for(Integer num : list){
            if(num<0){
                System.out.print(num + " ");
            }
        }
    }
}
