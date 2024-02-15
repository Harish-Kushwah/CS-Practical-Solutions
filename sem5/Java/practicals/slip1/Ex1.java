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
            
        System.out.printf("All prime number");
        for(int i=0;i<args.length;i++)
        {
            if(isPrime(Integer.parseInt(args[i])))
            {
                System.out.print(args[i] + " ");
            }
        }
    }
}
