import javax.swing.*;

public class RadioButtonDemo {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Radio Button Demo");

        JRadioButton radioButton1 = new JRadioButton("Option 1");
        JRadioButton radioButton2 = new JRadioButton("Option 2");
        
        ButtonGroup group = new ButtonGroup();
        group.add(radioButton1);
        group.add(radioButton2);

        JPanel panel = new JPanel();
        panel.add(radioButton1);
        panel.add(radioButton2);

        frame.getContentPane().add(panel);
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}