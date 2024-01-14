import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        PasswordManager pm = new PasswordManager();
        //PMSForm pmsForm = new PMSForm();
//        pmsForm.setVisible(true);
//        pmsForm.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        PMSSplash dialog = new PMSSplash();
        dialog.pack();
        dialog.setVisible(true);
        System.exit(0);
    }
}