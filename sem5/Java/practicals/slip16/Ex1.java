package practicals.slip16;
/*
 * Q1) Write a program to find the Square of given number using function interface.
 */
import java.util.Scanner;
interface Operation 
{
    int square(int num);
}
class Math implements Operation 
{

    @Override
    public int square(int num) {
       return num*num;
    }

}
public class Ex1 {
    public static void main(String[] args) {
     
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter number :");
        int num = scan.nextInt();
        Math m1 = new Math();
        System.out.printf("Square of %d is %d ",num,m1.square(num));
        scan.close();

    }
}
