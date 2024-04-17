package sem6.Java.practicals.slip18;
/*1. Write a java program to display name and priority of a Thread. */

class MyThread extends Thread
{
    MyThread(String name ,int priority)
    {
        this.setName(name);
        this.setPriority(priority);
    }

    public void run()
    {
        System.out.println("Thread name :"+this.getName());
        System.out.println("Priority :"+this.getPriority());

    }
}
public class Ex1 {
    public static void main(String[] args) {
        MyThread th1  = new MyThread("MyThread1" , 3);
        MyThread th2  = new MyThread("MyThread2" , 2);
        MyThread th3  = new MyThread("MyThread3" , 5);
        th1.start();
        th2.start();
        th3.start();
    }
}