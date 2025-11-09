import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Admin extends JFrame{
    private JPanel adminPanel;
    private JLabel itmName;
    private JTextField txtItem;
    private JLabel itmPrice;
    private JTextField txtPrice;
    private JButton selectImageBtn;
    private JButton addItemBtn;
    private JButton closeBtn;
    private JButton startAuctionBtn;
    private JLabel timer;
    private JTextField txtTimer;
    private JTable adminDetails;

    public Admin() {
        selectImageBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(selectImageBtn, "Image Added");
            }
        });
        addItemBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(addItemBtn, "Item Added to the List");
            }
        });
    }

    public static void main(String[] args) {
        Admin admin = new Admin();
        admin.setContentPane(admin.adminPanel);
        admin.setTitle("Admin Panel");
        admin.setSize(500,500);
        admin.setVisible(true);
        admin.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
}
