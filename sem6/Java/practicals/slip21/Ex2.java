package sem6.Java.practicals.slip21;
/*
 * 2. Write a java program to solve producer consumer problem in which a producer
produces a value and consumer consume the value before producer generate the next
value. (Hint: use thread synchronization) 
 */
class SharedResources {
    int count = 0;

    public synchronized void produce() {
        try {
            while (count == 5) {
                wait();
            }
            System.out.println("Producer produce the value : " + ++count);
            notify();
            Thread.sleep(1000);
        } catch (Exception exp) {

        }
    }

    public synchronized void consume() {
        try {
            while (count == 0) {
                wait();
            }
            System.out.println("Consumer consumed the value : " + --count);

            notify();
            Thread.sleep(1000);

        } catch (Exception exp) {

        }
    }
}

class Producer extends Thread {
    SharedResources resources;
    Producer(SharedResources resources) {
        this.resources = resources;
    }

    public void run() {
        while (true) {
            resources.produce();
        }
    }
}

class Consumer extends Thread {
    SharedResources resources;
    Consumer(SharedResources resources) {
        this.resources = resources;
    }
    public void run() {
        while (true) {
            resources.consume();
        }
    }
}

public class Ex2 {
    public static void main(String[] args) throws InterruptedException {
        SharedResources resources = new SharedResources();

        Producer producer = new Producer(resources);
        Consumer consumer = new Consumer(resources);

        producer.start();
        consumer.start();

        producer.join();
        consumer.join();
    }
}
