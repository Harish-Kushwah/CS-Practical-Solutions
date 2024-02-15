package practicals.slip14;
/*
 * Q2) Write a Java program to create a Package “SY” which has a class SYMarks (members – 
        ComputerTotal, MathsTotal, and ElectronicsTotal). Create another package TY which has a 
        class TYMarks (members – Theory, Practicals). Create ‘n’ objects of Student class (having   
        rollNumber, name, SYMarks and TYMarks). Add the marks of SY and TY computer subjects 
              and calculate the Grade (‘A’ for >= 70, ‘B’ for >= 60 ‘C’ for >= 50, Pass Class for > =40  
        else ‘FAIL’) and display the result of the student in proper forma
 */

import java.util.Scanner;

import practicals.slip14.sy.SYMarks;
import practicals.slip14.ty.TYMarks;

class Student {
    String name;
    float total_marks;
    String grade;
    SYMarks syMarks;
    TYMarks tyMarks;

    public void inputDetails() {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter student name :");
        this.name = scan.nextLine();

        syMarks = new SYMarks();
        syMarks.inputSyMarks();

        tyMarks = new TYMarks();
        tyMarks.inputTyMarks();

    }

    public void calculateGrade() {
        this.total_marks = syMarks.getComputerTotal() + tyMarks.getTotalTyMarks();
        if (this.total_marks >= 70) {
            this.grade = "A";
        } else if (this.total_marks >= 60) {
            this.grade = "B";
        } else if (this.total_marks >= 50) {
            this.grade = "C";
        } else if (this.total_marks >= 40) {
            this.grade = "PASS";
        } else {
            this.grade = "FAIL";
        }

    }

    public void showResult() {
        System.out.print("Name :" + this.name);
        System.out.print("\tSyMarks  :" + syMarks.getTotalSyMarks());
        System.out.print("\tTyMarks  :" + tyMarks.getTotalTyMarks());
        System.out.print("\tTotal marks :" + this.total_marks);
        System.out.println("\tGrade :" + this.grade);

    }
}

public class Ex2 {
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        System.out.println("Enter total number of students :");
        int n = scan.nextInt();
        Student[] s1 = new Student[n];
        System.out.println("Enter all students details :");
        for (int i = 0; i < n; i++) {
            System.out.printf("Enter %dth student details\n" , i+1);
            s1[i] = new Student();
            s1[i].inputDetails();
            s1[i].calculateGrade();
            
        }
        System.out.println("\n\t\tRESULT ");
        for (int i = 0; i < n; i++) {

            s1[i].showResult();
        }

        scan.close();

    }
}
