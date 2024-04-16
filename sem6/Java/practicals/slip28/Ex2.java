package sem6.Java.practicals.slip28;

/*Write a java program to display name of currently executing Thread in multithreading.
 */
public class Ex2 {
    public static void main(String[] args) {
        Runnable rh = ()->{
            String threadName = Thread.currentThread().getName();
            System.out.println("Current Thread Name :" + threadName);
        };

        Thread th1 = new Thread(rh , "Thread1");
        Thread th2 = new Thread(rh , "Thread2");
        Thread th3 = new Thread(rh , "Thread3");

        th1.start();
        th2.start();
        th3.start();
    }
}
