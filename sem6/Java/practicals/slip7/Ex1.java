package sem6.Java.practicals.slip7;

/**
 * 1. Write a java program that implements a multi-thread application that has three threads.
First thread generates random integer number after every one second, if the number is
even; second thread computes the square of that number and print it. If the number is
odd, the third thread computes the of cube of that number and print it.
 */

import java.util.Random;

public class Ex1 {
    static int num;

    public static void setNum(int num1) {
        num = num1;
    }

    public static void main(String[] args) {

        Runnable randomNumberGenerator = () -> {
            Random rand = new Random();
            while (true) {
                setNum(rand.nextInt(100));

                try {
                    Thread.sleep(1000);
                } catch (Exception exp) {
                }
            }

        };

        Runnable square = () -> {
            while (true) {
                if (num % 2 == 0) {
                    System.out.println(num + " = " + num * num);
                }
                try {
                    Thread.sleep(1000);
                } catch (Exception exp) {

                }
            }

        };
        Runnable cube = () -> {

            while (true) {
                if (num % 2 != 0) {
                    System.out.println(num + " = " + num * num * num);
                }

                try {
                    Thread.sleep(1000);

                } catch (Exception exp) {

                }
            }

        };

        new Thread(randomNumberGenerator).start();
        new Thread(square).start();
        new Thread(cube).start();

    }
}
