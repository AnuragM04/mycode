import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;

public class UserInfoApp extends JFrame {
    public JTextField nameField, ageField, addressField;

    public UserInfoApp() {
        JLabel nameLabel = new JLabel("Name:");
        JLabel ageLabel = new JLabel("Age:");
        JLabel addressLabel = new JLabel("Address:");

        nameField = new JTextField(20);
        ageField = new JTextField(5);
        addressField = new JTextField(20);

        JButton saveButton = new JButton("Save");
        saveButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                saveUserInfo();
            }
        });

        setLayout(new GridLayout(4, 2, 10, 10));
        add(nameLabel);
        add(nameField);
        add(ageLabel);
        add(ageField);
        add(addressLabel);
        add(addressField);
        add(saveButton);

        setTitle("User Information App");
        setSize(400, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void saveUserInfo() {
        String name = nameField.getText();
        String age = ageField.getText();
        String address = addressField.getText();

        if (name.isEmpty() || age.isEmpty() || address.isEmpty()) {

            JOptionPane.showMessageDialog(this, "Please fill in all fields.", "Error in Data", JOptionPane.ERROR_MESSAGE);
            return;
        }
        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter("user_info.txt", true));
            writer.write("Name: " + name + "\tAge: " + age + "\tAddress: " + address + "\n");
            writer.close();
            JOptionPane.showMessageDialog(this, "User information saved successfully.", "Success", JOptionPane.INFORMATION_MESSAGE);
        }
        catch (IOException e) {
            JOptionPane.showMessageDialog(this, "Error saving user information.", "Error", JOptionPane.ERROR_MESSAGE);
            e.printStackTrace();
        }

        nameField.setText("");
        ageField.setText("");
        addressField.setText("");
    }

    public static void main(String[] args) {
        new UserInfoApp();
    }
}
