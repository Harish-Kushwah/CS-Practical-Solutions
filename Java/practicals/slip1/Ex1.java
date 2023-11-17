package practicals.slip1;
/*
 * Write a Program to print all Prime numbers in an array of ‘n’ elements. (use command line  arguments)   
 * 
 * How to run :
 *  for compilation : javac practicals/slip1/*.java   or javac practicals/slip1/Ex1.java
 *  for run :         java practicals.slip1.Ex1 2
 */
public class Ex1 {

    public static boolean isPrime(int n)
    {
        for(int i=2;i<=n/2;i++)
        {
            if(n%i==0) 
            return false;
        }
        return true;
    }
    public static void main(String[] args) {
        
        int n = Integer.parseInt(args[0]);
        
        System.out.printf("All prime number up to %d\n"  ,n);
        for(int i=2;i<=n;i++)
        {
            if(isPrime(i))
            {
                System.out.print(i + " ");
            }
        }
    }
}
