package practicals.slip20;
/*
 *  Q2) Write a package for Operation, which has two classes, Addition and Maximum. Addition has    
         two methods add () and subtract (), which are used to add two integers and subtract two, 
         float values respectively. Maximum has a method max () to display the maximum of two  
         integers
 */

 import java.util.Scanner;

import practicals.slip20.operations.Additon;
import practicals.slip20.operations.Maximum;
public class Ex2 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter number 1 :");
        int num1 = scan.nextInt();

        System.out.print("Enter number 2 :");
        int num2 = scan.nextInt();

        Additon m1 = new Additon();
        Maximum m2 = new Maximum();
        System.out.printf("Addition of %d and %d is %d\n" ,num1,num2, m1.add(num1,num2));

        System.out.printf("Maximum of %d and %d is %d" ,num1,num2, m2.max(num1,num2));

        scan.close();

    }
}
