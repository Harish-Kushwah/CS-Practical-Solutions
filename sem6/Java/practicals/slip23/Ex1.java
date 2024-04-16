package sem6.Java.practicals.slip23;

import java.util.Scanner;

/*
 * 1. Write a java program to accept a String from a user and display each vowel from a
String after every 3 seconds. 
 */
public class Ex1 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter String :");
        String str = scan.nextLine();

        Runnable rh = ()->{
              for(int i=0; i<str.length(); i++){
                    char ch = str.charAt(i);
                    if(ch=='A' || ch=='a' || ch=='E' || ch=='e' || ch=='I' || ch =='i'||
                       ch=='O' || ch=='o' || ch=='U' || ch=='u')
                       {
                            System.out.println(ch);

                            try{
                                Thread.sleep(3000);
                            }catch(Exception exp){

                            }
                       }
              }
        };

        new Thread(rh).start();
    }
}
