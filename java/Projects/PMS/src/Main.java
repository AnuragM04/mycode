public class Main {
    public static void main(String[] args) {
        PasswordManager pm = new PasswordManager();
        pm.populate();
        PMSSplash dialog = new PMSSplash();
        dialog.pack();
        dialog.setVisible(true);
        System.exit(0);
    }
}