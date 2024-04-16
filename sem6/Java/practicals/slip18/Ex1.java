package sem6.Java.practicals.slip18;
/*1. Write a java program to display name and priority of a Thread. */
public class Ex1 {
    public static void main(String[] args) {
        Thread th  = new Thread();
        System.out.println("Thread name :"+th.getName());
        System.out.println("Priority :"+th.getPriority());
    }
}
