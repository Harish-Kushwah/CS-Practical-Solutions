package practicals.slip18;
/*
 * Q1) Write a program to implement Border Layout Manager.
 */
import javax.swing.*;
import java.awt.*;
class BorderLayoutDemo extends JFrame 
{
    JPanel east,west,north,south,center;
    Container container;
    public BorderLayoutDemo()
    {
        super("BorderLayout demo");
        setSize(500,500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        east = new JPanel();
        east.add(new JLabel("East"));

        west = new JPanel();
        west.add(new JLabel("West"));

        north = new JPanel();
        north.add(new JLabel("North"));

        south = new JPanel();
        south.add(new JLabel("South"));

        center = new JPanel();
        center.add(new JLabel("Center"));

        container = getContentPane();

        container.add(east , BorderLayout.EAST );
        container.add(west , BorderLayout.WEST);
        container.add(north , BorderLayout.NORTH);
        container.add(south , BorderLayout.SOUTH);
        container.add(center , BorderLayout.CENTER);

        setVisible(true);


    }
}
public class Ex1 {
    public static void main(String[] args) {
        new BorderLayoutDemo();
    }
}
