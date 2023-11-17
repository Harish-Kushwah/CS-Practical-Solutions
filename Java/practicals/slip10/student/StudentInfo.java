package practicals.slip10.student;
/*
 * Q2)  Write  a  program  to  create  a  package  name  student.  Define  class  StudentInfo  with  method  to 
display  information  about  student  such  as  rollno,  class,  and  percentage.  Create  another  class 
StudentPer with method to find percentage of the student. Accept student details like 
          rollno, name, class and marks  of 6 subject from user.
 */

import java.util.Scanner;

class StudentPer 
{
    int rollno;
    float percentage;
    String class_name;
    int []marks = new int[6];

    public void inputDetails()
    {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter roll number :");
        this.rollno = scan.nextInt();

        scan.nextLine();
        System.out.print("Enter class name :");
        this.class_name = scan.nextLine();

       System.out.println("Enter marks of all  out of 100 ");
       for(int i=0;i<6;i++)
       {
        System.out.printf("Enter marks of subject %d :" , i+1);
        marks[i] = scan.nextInt();
       }
    }

    public void calculatePercentage()
    {
        int total_marks =0;
        for(int i=0;i<6;i++)
        {
            total_marks+=marks[i];
        }

        this.percentage = (total_marks/6)*1;
    }

    public void showDetails()
    {
        System.out.println("Roll number :" + this.rollno);
        System.out.println("Class name :" + this.class_name);
        System.out.println("Percentage :"+this.percentage +"%");
    }



}
public class StudentInfo extends StudentPer{

    public static void main(String[] args) {
        StudentInfo sInfo = new StudentInfo();
        sInfo.inputDetails();
        sInfo.calculatePercentage();
        sInfo.showDetails();
    }
}
