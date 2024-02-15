package practicals.slip16;
/*
 * Write a program to design a screen using Awt that
 */

import java.awt.*;
import javax.swing.*;
class Screen extends JFrame 
{
    MenuBar menuBar;
    Menu file,edit,about;
    MenuItem  new_file , open_file,save_file , exit_item,about_item;
    
    Container container;
    Screen()
    {
        super("Java AWT Example");
        setSize(500,500);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        menuBar = new MenuBar();
        file = new Menu("File");
        
        edit = new Menu("Edit");
        about = new Menu("About");
        menuBar.add(file);
        menuBar.add(edit);
        menuBar.add(about);

        
        new_file = new MenuItem("New   CLT+N");
        open_file = new MenuItem("Open");
        save_file = new MenuItem("Save");

        about_item = new MenuItem("Show About");

        exit_item = new MenuItem("Exit");
 
        file.add(new_file);
        file.add(open_file);
        file.add(save_file);
        file.addSeparator();
        file.add(about_item);
        file.addSeparator();
        file.add(exit_item);
       

        setMenuBar(menuBar);
        setVisible(true);
    }
}
public class Ex2 {
    public static void main(String[] args) {
        new Screen();
    }
}
