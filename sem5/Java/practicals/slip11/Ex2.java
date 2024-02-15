package practicals.slip11;

import java.util.Scanner;

/*
 * Q2) Write a program to accept the username and password from user if username and password are 
not same then raise "Invalid Password" with appropriate msg.
 */
class InvalidPasswordException extends Exception {
    InvalidPasswordException(String msg) {
        super(msg);
    }
}

public class Ex2 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter username :");
        String username = scan.nextLine();

        System.out.print("Enter Password :");
        String password = scan.nextLine();

        scan.close();

        try {

            if (username.equals(password)) {
                System.out.println("Username and Password are same");
            } else {
                throw new InvalidPasswordException("Invalid Password");
            }
        } catch (InvalidPasswordException exp) {
            System.out.println(exp.getMessage());
        }

    }
}
