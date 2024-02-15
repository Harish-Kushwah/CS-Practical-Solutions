package practicals.slip14;
/*
 * Q1) Write a program to accept a number from the user, if number is zero then throw user defined   
       exception “Number is 0” otherwise check whether no is prime or not (Use static keyword)
 */

import java.util.Scanner;

class ZeroNumberException extends Exception {
    ZeroNumberException(String msg) {
        super(msg);
    }
}

public class Ex1 {

    public static boolean isPrime(int n) {
        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        System.out.print("Enter number :");
        int num = scan.nextInt();
        scan.close();

        try {

            if (num == 0) {

                throw new ZeroNumberException("Number is zero");

            } else if (isPrime(num)) {
                System.out.printf("%d is prime number ", num);
            } else {
                System.out.printf("%d is not prime number", num);
            }

        } catch (ZeroNumberException e) {
            System.out.println(e.getMessage());
        }

    }

}
