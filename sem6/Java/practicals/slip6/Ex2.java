package sem6.Java.practicals.slip6;
/**
 * 2. Write a java program to simulate traffic signal using threads.
 */

import javax.swing.*;
import java.awt.*;

class MyPanel extends JPanel
{
    MyPanel(Color col){
        setPreferredSize(new Dimension(50, 50));
        setBackground(col);
    }
}
class Signal extends JFrame 
{
    MyPanel red,green,yellow,time;
    Container container;
    JLabel counter , msg;
    Signal(){
        super("Traffic Signal");
        setSize(400,500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setLayout(new BorderLayout());


        container = this.getContentPane();

        JPanel gb = new JPanel(new GridBagLayout());       
       
        container.add(gb, BorderLayout.CENTER);

        red = new MyPanel(Color.red);

        yellow = new MyPanel(Color.yellow);

        green = new MyPanel(Color.green);

        time = new MyPanel(Color.white);

        counter = new JLabel("60");
        msg = new JLabel();

        time.add(counter , SwingConstants.CENTER);
        activate(1);
        Runnable rh = ()->{
          int i = 1;
          int c = 1;
          while(true){
            counter.setText(Integer.toString(i));

            if(i==60){
                c = c%3 + 1;
                activate(c);
            }
          
            try{
                Thread.sleep(100);
            }
            catch(Exception exp){
                exp.printStackTrace();
            }
            i = (i%60) + 1;
          }

        };
    
        new Thread(rh).start();

        GridBagConstraints gbc = new GridBagConstraints();
        gbc.gridx  = 1;
    
        gbc.gridy = 1;
        gb.add(msg , gbc);
        
        gbc.gridy = 2;
        gb.add(red, gbc);
        gbc.gridy = 3;
        gb.add(green , gbc);

        gbc.gridy = 4;
        gb.add(yellow,gbc);

        gbc.gridy = 5;
        gb.add(time,gbc);

        setVisible(true);
    }

    public void activate( int i)
    {
            if(i==1){
                red.setBackground(Color.red);
                yellow.setBackground(Color.white);
                green.setBackground(Color.white);
                msg.setText("Stop!!");
            }
            else if(i==2){
                red.setBackground(Color.white);
                yellow.setBackground(Color.white);
                green.setBackground(Color.green);
                msg.setText("Go Slowly.");

            }
            else{
                red.setBackground(Color.white);
                yellow.setBackground(Color.yellow);
                green.setBackground(Color.white);
                msg.setText("Go Fast.");

            }
        }
}
public class Ex2 {
    public static void main(String[] args) {
        new Signal();
    }
}
