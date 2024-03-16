package sem6.Java.practicals.slip1;
/*
 * 1. Write a Java program to display all the alphabets between ‘A’ to ‘Z’ after every 2
seconds.
 */
public class Ex1 {
    public static void main(String[] args) {
        for(int i='A' ; i<='Z' ; i++){
            System.out.println((char)i);
            try{
                Thread.sleep(1000);
            }
            catch(Exception exp){

            }
        }
    }
}
