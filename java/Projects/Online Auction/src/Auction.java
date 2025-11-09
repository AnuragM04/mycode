import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Auction extends JFrame{
    private JPanel loginPanel;
    private JLabel username;
    private JTextField txtUsername;
    private JLabel askData;
    private JLabel password;
    private JTextField txtPassword;
    private JButton signin;

    public Auction() {
        signin.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(signin, "Login Successful\n Welcome Back "+txtUsername.getText());
            }
        });
    }
    public static void main(String[] args) {
        Auction auction = new Auction();
        auction.setContentPane(auction.loginPanel);
        auction.setTitle("Online Auction Management System");
        auction.setSize(300,300);
        auction.setVisible(true);
        auction.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
}
