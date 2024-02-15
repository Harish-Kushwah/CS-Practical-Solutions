package practicals.slip5;
/*
 * Q2) Write a menu driven program to perform the following operations on multidimensional array 
        ie           matrices : 
        1. Addition 
        2. Multiplication 
        3. Exit 
 */
import java.util.Scanner;

class Matrix {
    int row, col;
    int[][] mat;

    public Matrix(int row, int col) {
        this.row = row;
        this.col = col;
        this.mat = new int[this.row][this.col];
    }

    public Matrix() {
    }

    public void inputMatrix() {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter row :");
        this.row = scan.nextInt();

        System.out.print("Enter col :");
        this.col = scan.nextInt();

        this.mat = new int[this.row][this.col];
        System.out.println("Enter matrix");
        for (int i = 0; i < this.row; i++) {
            for (int j = 0; j < this.col; j++) {
                this.mat[i][j] = scan.nextInt();
            }
        }

    }

    public void printMatrix() {
        for (int i = 0; i < this.row; i++) {
            for (int j = 0; j < this.col; j++) {
                System.out.print(this.mat[i][j] + " ");

            }
            System.out.println();
        }
    }

    public static Matrix addition(Matrix A, Matrix B) {
        Matrix res = new Matrix(A.row, A.col);
        if (A.col == B.col && A.row == B.row) {
            for (int i = 0; i < A.row; i++) {
                for (int j = 0; j < A.col; j++) {
                    res.mat[i][j] = A.mat[i][j] + B.mat[i][j];
                }
            }
        }
        else{
            System.out.println("Matrix are of different dimensions");
        }
        return res;
    }

    public static Matrix multiplication(Matrix A, Matrix B) {
        Matrix res = new Matrix(A.row, B.col);
        if (A.col == B.row) {
            for (int i = 0; i < A.row; i++) {
                for (int j = 0; j < B.col; j++) {
                    for (int k = 0; k < B.row; k++) {
                        res.mat[i][j] += A.mat[i][k] * B.mat[k][j];
                    }
                }
            }
            return res;
        } else {
            System.out.println("Matrix multiplication not possible");
        }
        return null;

    }

}

public class Ex2 {
    public static void menu() {
        System.out.println("1.Addition");
        System.out.println("2.Multiplication");
        System.out.println("3.Exit");
    }
    public static void main(String[] args) {

        menu();
        Matrix A = new Matrix();
        Matrix B = new Matrix();
        System.out.println("Enter matrix A");
        A.inputMatrix();

        System.out.println("Enter matrix B");
        B.inputMatrix();
    
        Scanner scan = new Scanner(System.in);

        while (true) {
            System.out.print("Enter key :");
            int key = scan.nextInt();

            if (key == 1) {
                Matrix res = Matrix.addition(A, B);
                res.printMatrix();
            } else if (key == 2) {
                Matrix res = Matrix.multiplication(A, B);
                res.printMatrix();
            } else {
                break;
            }
        }
    }
}
