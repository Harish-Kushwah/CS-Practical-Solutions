package practicals.slip13;

import java.util.Date;
import java.text.SimpleDateFormat;

/*
 * Q2) Write a program to display the system date and time in various formats shown below: 
Current date is : 31/08/2021 
Current date is : 08-31-2021 
Current date is : Tuesday  August 31 2021 
Current date and time is : Fri August 31 15:25:59 IST 2021 
Current date and time is :  31/08/21 15:25:59 PM +0530
 */
public class Ex2 {
    public static void main(String[] args) {
        Date date = new Date();
        SimpleDateFormat formatter = new SimpleDateFormat();

        formatter.applyPattern("dd/mm/yyyy ");
        String currentDate = formatter.format(date);
        System.out.println("Current date is  :" + currentDate);

        formatter.applyPattern("dd-mm-yyyy");
        currentDate = formatter.format(date);
        System.out.println("Current date is  :" + currentDate);

        formatter.applyPattern("E M dd yyyy");
        currentDate = formatter.format(date);
        System.out.println("Current date is :" + currentDate);

        formatter.applyPattern("E M  dd hh:mm:ss z yyyy");
        String currentDateTime = formatter.format(date);
        System.out.println("Current date and time :" + currentDateTime);

        formatter.applyPattern("dd/mm/yy kk:mm:ss a Z");
        currentDateTime = formatter.format(date);
        System.out.println("Current date and time :" + currentDateTime);    

    }
}
