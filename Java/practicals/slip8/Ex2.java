package practicals.slip8;
/*
 * Q2) Design a screen to handle the Mouse Events such as MOUSE_MOVED  
      and MOUSE_CLICKED  and display the position of the Mouse_Click in a TextField
 */
import java.awt.*;
import javax.swing.*;

import java.awt.event.*;
class Screen extends JFrame implements MouseListener ,MouseMotionListener
{
    JTextField position;
    Container container;
    public Screen()
    {
        super("Mouse Events");
        setSize(500,500);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new FlowLayout());


        container = getContentPane();
        container.add(new JLabel("Position of mouse :"));
        
        position = new JTextField();
        position.setPreferredSize(new Dimension(150,20));
        container.add(position);
      
        addMouseListener(this);
        addMouseMotionListener(this);
        setVisible(true);
        

    }

    @Override
    public void mouseClicked(MouseEvent e) {
        String co_ordinates =  Float.toString(e.getX()) +" "+Float.toString(e.getY());
        position.setText(co_ordinates); 
    }

    @Override
    public void mousePressed(MouseEvent e) {
       
    }

    @Override
    public void mouseReleased(MouseEvent e) {
      
    }

    @Override
    public void mouseEntered(MouseEvent e) {
        
    }

    @Override
    public void mouseExited(MouseEvent e) {
       
    }

    @Override
    public void mouseDragged(MouseEvent e) {
       
    }

    @Override
    public void mouseMoved(MouseEvent e) {
         String co_ordinates =  Float.toString(e.getX()) +" "+Float.toString(e.getY());
        position.setText(co_ordinates); 
        
        
    }
}
public class Ex2 {
    public static void main(String[] args) {
        new Screen();
    }
}
