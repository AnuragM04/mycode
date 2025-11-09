import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Customer {
    private JPanel customerPanel;
    private JLabel timer;
    private JTextField txtBidderName;
    private JTextField txtBidPrice;
    private JLabel bidPrice;
    private JLabel bidderName;
    private JButton addBidBtn;
    private JButton closeBtn;
    private JTextField txtItemName;
    private JLabel itmName;
    private JLabel itmPrice;
    private JTextField txtItemPrice;
    private JLabel itmImage;

    public Customer() {
        addBidBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(addBidBtn, "Bid Placed Successfully");
            }
        });
    }

    public static void main(String[] args) {

    }
}
