package sem6.Java.practicals.slip8;
/**
 * 1. Write a java program to define a thread for printing text on output screen for ‘n’
number of times. Create 3 threads and run them. Pass the text ‘n’ parameters to the
thread constructor.
 Example:
i. First thread prints “COVID19” 10 times.
ii. Second thread prints “LOCKDOWN2020” 20 times
iii. Third thread prints “VACCINATED2021” 30 times 
 */

class MyThread extends Thread
{
    String msg;
    int n;
    MyThread(String msg , int n){
        this.msg = msg;
        this.n = n;
    }

    public void run(){
        for(int i=0 ; i<n;i++){
            System.out.println(msg);
        }
    }
}
public class Ex1 {
    public static void main(String[] args) {
        new MyThread("COVID10", 10).start();
        new MyThread("LOCKDOWN2020", 20).start();
        new MyThread("VACCINATED2021", 30).start();
    }
}
