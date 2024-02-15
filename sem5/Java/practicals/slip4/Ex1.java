package practicals.slip4;
/*
 * Q1) Write a program to print an array after changing the rows and columns of a given   
 *    two-dimensional array
 */
import java.util.Scanner;
public class Ex1 {

    public static void printMatrix(int mat[][] , int row , int col)
    {
        for(int i =0 ;i<row ; i++)
        {
            for(int j=0;j<col ; j++)
            {
                System.out.print( mat[i][j] +" ");
            }
           System.out.println();
        }

    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.print("Enter total rows :");
        int row = scan.nextInt();

        System.out.print("Enter total columns");
        int col = scan.nextInt();
       
        
        int [][]mat = new int[row][col];

        int [][]temp = new int[col][row];

        System.out.println("Enter matrix");
        for(int i =0 ;i<row ; i++)
        {
            for(int j=0;j<col ; j++)
            {
                mat[i][j] = scan.nextInt();
                temp[j][i] = mat[i][j];
           }
           
        }
        printMatrix(mat, row, col);       
        System.out.println("After changing :");
        printMatrix(temp, col, row);
           
    }
}
