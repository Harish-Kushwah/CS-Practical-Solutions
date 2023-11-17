package practicals.slip19;
/*
 * Q2) Write a program which shows the combo box which includes list of  T.Y.B.Sc.(Comp. Sci)    
        subjects. Display the selected subject in a text field.
 */

import javax.swing.*;
import java.awt.*;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

class ComboBoxExample extends JFrame {
   
    JComboBox<String> comboBox;
    Container container;
    JLabel comboBoxLabel, selected_label;
    JTextField selected_input;

    ComboBoxExample() {
        super("Combo Box Example");
        setSize(500, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        container = getContentPane();
        setLayout(null);

        addComboBox();
        addSelectedInputField();

        setVisible(true);
    }

    public void addComboBox() {
        String subjects[] = { "Java", "OS" ,"Web Technology" ,"FDS","TCS","Python","Blockchain" };

        comboBoxLabel = new JLabel("Select Subject");
        comboBoxLabel.setBounds(100, 100, 100, 16);

        comboBox = new JComboBox<String>(subjects);
        comboBox.setBounds(200, 100, 150, 25);

        comboBox.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e) {
               if(e.getStateChange()==1){
                selected_input.setText( comboBox.getSelectedItem().toString());
               }
                
            }
            
        });

        container.add(comboBoxLabel);
        container.add(comboBox);
    }
    public void addSelectedInputField()
    {
        selected_label = new JLabel("Selected Subject");
        selected_label.setBounds(100, 50, 150, 25);

        selected_input = new JTextField();
        selected_input.setBounds(200, 50, 150, 25);

        container.add(selected_label);
        container.add(selected_input);
    }

}

public class Ex2 {
    public static void main(String[] args) {
        new ComboBoxExample();
    }
}
