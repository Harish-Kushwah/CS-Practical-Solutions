package sem6.Java.practicals.slip15;

/*1. Write a java program to display name and priority of a Thread. */
public class Ex1 {
    public static void main(String[] args) {
        Thread th = new Thread();
        th.start();
        System.out.println("Name :"  + th.getName());
        System.out.println("Priority :"+th.getPriority());
    }
}
