package practicals.slip4;

/*
 * Q2) Write a program to design a screen using Awt that will take a user name and password. If 
    the  user  name  and  password  are  not  same,  raise  an  Exception  with  appropriate   message. 
    User can have 3 login chances only. Use clear button to clear the TextFields.
 */
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

class LoginException extends Exception {
    public LoginException(String msg) {
        super(msg);
    }
}

class Login extends JFrame {
    Container container;
    TextField username;
    JPasswordField password;
    Button login, clear;
    Label username_label, password_label, status;

    static int total_login_attempts = 0;

    Login() {
        container = getContentPane();

        setTitle("Login");
        setSize(450, 400);
        setLocationRelativeTo(null);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        setLayout(null);
        container.setBackground(new Color(183, 244, 240));

        addUsernameField();
        addPasswordFiled();
        addLoginButton();
        addStatusLabel();
        addClearButton();

        setVisible(true);
    }

    public void addUsernameField() {
        username_label = new Label("Username");
        username_label.setBounds(55, 50, 100, 14);

        username = new TextField();
        username.setBounds(160, 50, 150, 25);

        container.add(username_label);
        container.add(username);

    }

    public void addPasswordFiled() {
        password_label = new Label("Password");
        password_label.setBounds(55, 100, 100, 14);

        password = new JPasswordField();
        password.setBounds(160, 100, 150, 25);

        container.add(password_label);
        container.add(password);
    }

    public void addLoginButton() {
        login = new Button("Login");
        login.setBounds(150, 150, 70, 26);
        login.setBackground(new Color(45, 229, 91));
        login.setCursor(new Cursor(Cursor.HAND_CURSOR));

        login.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                if (++total_login_attempts < 4) {
                    if (isValidCredentials()) {
                        status.setText("Login successful");
                        status.setForeground(Color.black);
                    } else {
                        try {
                            throw new LoginException("Username and Password are not same");
                        } catch (LoginException exp) {
                            status.setText(exp.getMessage());
                            status.setForeground(Color.red);
                            login.setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
                        }        
                    }
                } else {
                         status.setText("Attempts finished");
                         status.setForeground(Color.red);
                }
            }
        });
        container.add(login);
    }

    public void addStatusLabel() {
        status = new Label();
        status.setBounds(150, 200, 250, 14);

        container.add(status);
    }

    public boolean isValidCredentials() {
        String user_name = username.getText();
        String pass = new String(password.getPassword());
        if (user_name.equals(pass) && user_name.length() > 0)
            return true;
        return false;
    }

    public void addClearButton() {
        clear = new Button("Clear");
        clear.setBounds(250, 150, 70, 26);
        clear.setBackground(new Color(244, 84, 73));
        clear.setCursor(new Cursor(Cursor.HAND_CURSOR));
        clear.setForeground(Color.white);

        clear.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                username.setText("");
                password.setText("");
                status.setText("Inputs cleared");
            }

        });
        container.add(clear);
    }
}

public class Ex2 {
    public static void main(String[] args) {
        new Login();
    }
}
