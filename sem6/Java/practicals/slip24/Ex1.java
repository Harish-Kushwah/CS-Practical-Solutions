package sem6.Java.practicals.slip24;
/*
 * 1. Write a java program to scroll the text from left to right continuously
 */
import javax.swing.*;

public class Ex1 extends JFrame implements Runnable {
    private JLabel label;
    private String text;

    public Ex1(String text) {
        super("Text Scrolling");
        this.text = text;

        label = new JLabel(text, SwingConstants.CENTER);
        add(label);
        setSize(400, 100);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    @Override
    public void run() {
        try {
            while (true) {
                String newText = text.substring(1) + text.charAt(0);
                label.setText(newText);
                Thread.sleep(100); // Adjust this value to change scrolling speed
                text = newText;
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        String text = "How are you?";
        Ex1 ex1 = new Ex1(text);
        Thread thread = new Thread(ex1);
        thread.start();
    }
}
