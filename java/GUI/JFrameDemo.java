import javax.swing.*;

public class JFrameDemo extends JFrame {
    public JFrameDemo() {
         JPanel p = new JPanel();
         add(p);
        // p.setLayout(null );
        
        setTitle("My Swing Frame");
        setSize(400, 300);
        setDefaultCloseOperation(3);
        setLocationRelativeTo(null);
        setVisible(true);
        // setLayout(null);
    }

    public static void main(String[] args) {
        // SwingUtilities.invokeLater(() -> new MyFrame());
        new JFrameDemo();
    }
}