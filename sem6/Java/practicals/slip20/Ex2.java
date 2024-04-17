package sem6.Java.practicals.slip20;
/*
 * Write a java program to blink image on the JFrame continuously. 
 * 
 * Note:Change the image path with respect to your device
 */
import javax.swing.*;
import java.awt.*;
class MyFrame extends JFrame implements Runnable
{
    JLabel label;
    String imagePath = "C://Users//haris//Desktop//TYBCS//CS-Practical-Solutions//sem6//Java//practicals//slip20//g1.jpg";
    MyFrame()
    {
        setSize(600,600);
        setLayout(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Image image = new ImageIcon(imagePath).getImage();
        image = image.getScaledInstance(400, 400,Image.SCALE_SMOOTH);
        
        label = new JLabel();
        label.setIcon(new ImageIcon(image));
        label.setBounds(40,40,400,400);

        add(label);
        
        setVisible(true);
    }
    public void run()
    {
        boolean flag = true;
        while (true) {
            if(flag){
                remove(label);
                flag = false;
            }
            else{
                add(label);
                flag = true;
            }
            try{
                Thread.sleep(1000);
            }
            catch(Exception exp)
            {

            }
        
         revalidate();
         repaint();
        }

    }
}
public class Ex2 {
    public static void main(String[] args) {
         new Thread(new MyFrame()).start();;
    }
    
}
