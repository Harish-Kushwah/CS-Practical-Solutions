package sem6.Java.practicals.slip17;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;

/*
 * 2. Write a Multithreading program in java to display the number’s between 1 to 100
continuously in a TextField by clicking on button. (Use Runnable Interface). 
 */
class MyFrame extends JFrame {
    JTextField input;
    JButton button;

    MyFrame() {
        setSize(500, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(null);

        input = new JTextField();
        input.setBounds(100, 40, 200, 30);

        button = new JButton("Start");
        button.setBounds(300, 40, 80, 30);

        add(input);
        add(button);

        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Random rand = new Random();
                Runnable rh = () -> {
                    for (int i = 0; i < 100; i++) {
                        int num = rand.nextInt(100);
                        input.setText(Integer.toString(num));
                        try {
                            Thread.sleep(1000);
                        } catch (Exception exp) {
                        }
                    }
                };
                new Thread(rh).start();
            }
        });
        setVisible(true);
    }
}
public class Ex2 {
    public static void main(String[] args) {
        new MyFrame();
    }
}
