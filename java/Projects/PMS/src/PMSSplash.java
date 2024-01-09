import javax.swing.*;
import java.awt.*;

public class PMSSplash {
    private JPanel panel1;
    private JLabel title;
    private JProgressBar loading;
    private JLabel icon;
}

//class PMSSplash {
//    JFrame frame;
//    JLabel icon = new JLabel(new ImageIcon("pms_icon.png"));
//    JLabel text = new JLabel("Password Management System");
//    JProgressBar progressBar = new JProgressBar();
//    JLabel message = new JLabel();
//
//    PMSSplash() {
//        createGUI();
//        addImage();
//        addText();
//        addProgressBar();
//        runningPBar();
//    }
//
//    public void createGUI() {
//        frame = new JFrame();
//        frame.getContentPane().setLayout(null);
//        frame.setUndecorated(true);
//        frame.setSize(400,400)
//        frame.setLocationRelativeTo(null);
//        frame.getContentPane().setBackground(new Color(0x95E0FF));
//        frame.setVisible(true);
//    }
//
//    public void addImage() {
//        icon.setSize(400,200);
//        frame.add(icon);
//    }
//
//    public void addText() {
//        text.setFont(new Font("Monospaced",Font.BOLD,20));
//        text.setBounds(30,200,400,30);
//        text.setForeground(Color.black);
//        frame.add(text);
//    }
//
//    public void addProgressBar() {
//        progressBar.setBounds(100,280,200,30);
//        progressBar.setBorderPainted(true);
//        progressBar.setStringPainted(true);
//        progressBar.setBackground(Color.black);
//        progressBar.setForeground(new Color(0x002ABC));
//        progressBar.setValue(0);
//        frame.add(progressBar);
//    }
//
//    public void runningPBar() {
//        int i=0;
//        while( i<=100) {
//            try{
//                Thread.sleep(40);
//                progressBar.setValue(i);
//                i++;
//                if(i==100)
//                    frame.dispose();
//            }
//            catch(Exception e){
//                e.printStackTrace();
//            }
//        }
//    }
//}