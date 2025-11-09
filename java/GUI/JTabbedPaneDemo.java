import javax.swing.*;

public class JTabbedPaneDemo {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Tabbed Pane Demo");
        JTabbedPane tabbedPane = new JTabbedPane();

        JPanel panel1 = new JPanel();
        panel1.add(new JLabel("Content for Tab 1"));

        // JPanel panel2 = new JPanel();
        // panel2.add(new JLabel("Content for Tab 2"));

        JLabel l = new JLabel("Content for Tab 2");        

        tabbedPane.addTab("Tab 1", panel1);
        tabbedPane.addTab("Tab 2", l);

        frame.getContentPane().add(tabbedPane);
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}