package sem6.Java.practicals.slip4;
/**
 * 1. Write a Java program using Runnable interface to blink Text on the frame.
 */

import javax.swing.*;
class MyDisplay extends JFrame {
    JLabel title;

    MyDisplay() {
        super("MyDisplay");
        setSize(500, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        title = new JLabel("Hello World!");

        add(title);
        Runnable rh = () -> {
            boolean flag = true;

            while (true) {

                flag = !flag;
                title.setVisible(flag);

                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

        };
        new Thread(rh).start();
        this.setVisible(true);
    }
}
public class Ex1 {
    public static void main(String[] args) {
        new MyDisplay();
    }
}
