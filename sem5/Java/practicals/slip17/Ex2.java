package practicals.slip17;

/*
 * Q2) Write Java program to design three text boxes and two buttons using swing. Enter different  
        strings in first and second textbox. On clicking the First command button, concatenation of   
        two strings should be displayed in third text box and on clicking second command button, 
        reverse of string should display in third text box
 */
import javax.swing.*;
import java.awt.event.*;
import java.awt.Container;

class MyWindow extends JFrame implements ActionListener {
    JTextField string1, string2, result;
    JLabel first_str_label, second_str_label, result_str_label;
    JButton concat, reverse, clear;
    Container container;

    MyWindow() {
        super("String Operations");
        setSize(425, 400);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(null);

        container = getContentPane();

        addInputFields();
        addButtons();

        setVisible(true);
    }

    public void addInputFields() {
        first_str_label = new JLabel("Enter first String :");
        first_str_label.setBounds(80, 100, 150, 18);

        string1 = new JTextField(10);
        string1.setBounds(210, 100, 120, 25);

        second_str_label = new JLabel("Enter second String :");
        second_str_label.setBounds(80, 130, 150, 18);

        string2 = new JTextField(10);
        string2.setBounds(210, 130, 120, 25);

        result_str_label = new JLabel("Result String :");
        result_str_label.setBounds(80, 160, 150, 18);

        result = new JTextField(10);
        result.setBounds(210, 160, 120, 25);

        container.add(first_str_label);
        container.add(second_str_label);
        container.add(result_str_label);

        container.add(string1);
        container.add(string2);
        container.add(result);
    }

    public void addButtons() {
        concat = new JButton("Concat");
        concat.setBounds(80, 200, 80, 25);
        concat.setFocusPainted(false);

        reverse = new JButton("Reverse");
        reverse.setBounds(170, 200, 90, 25);
        reverse.setFocusPainted(false);

        clear = new JButton("Clear");
        clear.setBounds(270, 200, 80, 25);
        clear.setFocusPainted(false);

        container.add(concat);
        container.add(reverse);
        container.add(clear);

        concat.addActionListener(this);
        reverse.addActionListener(this);
        clear.addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {

        if (e.getSource() == concat) {
            String res = string1.getText() + string2.getText();
            result.setText(res);
        } else if (e.getSource() == reverse) {
            StringBuffer res = new StringBuffer(string1.getText() + string2.getText());
            res = res.reverse();
            result.setText(new String(res));
        } else if (e.getSource() == clear) {
            string1.setText("");
            string2.setText("");
            result.setText("");
        }
    }

}

public class Ex2 {
    public static void main(String[] args) {
        new MyWindow();
    }
}
