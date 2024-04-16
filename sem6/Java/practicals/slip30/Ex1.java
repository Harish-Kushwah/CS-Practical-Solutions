package sem6.Java.practicals.slip30;
/*
 * Write a java program for the implementation of synchronization. 
 */
class SharedResource {
    // Shared variable
    private int count = 0;

    // Method to increment the count, synchronized to ensure thread safety
    public synchronized void increment() {
        count++;
        System.out.println(Thread.currentThread().getName() + ": Incremented count to " + count);
    }
}

class MyRunnable implements Runnable {
    private SharedResource sharedResource;

    public MyRunnable(SharedResource sharedResource) {
        this.sharedResource = sharedResource;
    }

    @Override
    public void run() {
        // Calling the synchronized method on the shared resource
        sharedResource.increment();
    }
}

public class Ex1 {
    public static void main(String[] args) {
        SharedResource sh = new SharedResource();
        
        // Creating and starting multiple threads
        new Thread(new MyRunnable(sh), "Thread 1").start();
        new Thread(new MyRunnable(sh), "Thread 2").start();;
        
    }
}
