package sem6.Java.practicals.slip13;

/*
 * 2. Write a Java program to show lifecycle (creation, sleep, and dead) of a thread. Program 
should  print  randomly  the  name  of  thread  and  value  of  sleep  time.  The  name  of  the 
thread  should  be  hard  coded  through  constructor.  The  sleep  time  of  a  thread  will  be  a 
random integer in the range 0 to 4999.
 */
import java.util.Random;

class MyThread extends Thread {
   
    public MyThread(String name) {
        super(name);
    }

    @Override
    public void run() {
        Random rand = new Random();
        int sleepTime = rand.nextInt(5000);
        
        System.out.println(this.getName() + " is created.");
        System.out.println(this.getName() + " is going to sleep for " + sleepTime + " milliseconds.");
        
        try {
            Thread.sleep(sleepTime);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        
        System.out.println(this.getName() + " is dead.");
    }
}

public class Ex2 {
    public static void main(String[] args) {
        MyThread thread1 = new MyThread("Thread 1");
        MyThread thread2 = new MyThread("Thread 2");

        thread1.start();
        thread2.start();
    }
}
