package practicals.slip19;
/*
 * Q1) Write a program to accept the two dimensional array from user and display sum of its diagonal     
             elements. 
 */
import java.util.Scanner;
public class Ex1 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter no of rows :");
        int row = scan.nextInt();

        System.out.print("Enter no of columns:");
        int col = scan.nextInt();

        int [][] mat = new int[row][col];

        int sum = 0;
        System.out.println("Enter Matrix :");
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                mat[i][j] = scan.nextInt();
                if(i==j)
                {
                    sum+=mat[i][j];
                }
            }
        } 
        System.out.println("Sum of diagonal elements : "+sum);

        scan.close();
    }
}
