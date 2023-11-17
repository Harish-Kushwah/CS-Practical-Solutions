package practicals.slip10;
/*
 * Q1) Write a program to find the cube of given number using functional interface.
 */

interface Cube 
{
    public int  cube(int a);
}
class Operation implements Cube 
{
    public int cube(int a)
    {
        return a*a*a;
    }
}

public class Ex1 {
    public static void main(String[] args) {
        Operation op = new Operation();
        System.out.println(op.cube(4));
    }
}
