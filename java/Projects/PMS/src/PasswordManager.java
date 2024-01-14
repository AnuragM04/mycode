import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

public class PasswordManager {
    private static final String passFname = "passwords.db";
    private final ArrayList<PasswordRecord> passwordRecords;

    PasswordManager() {
        passwordRecords = new ArrayList<>();
        populate();
    }
    public boolean addRecord(PasswordRecord passwordRecord){
        for(PasswordRecord pr : passwordRecords) {
            if(pr.getURL().equals(passwordRecord.getURL()) &&
                pr.getUserID().equals(passwordRecord.getUserID())) {
                return false;

            }
        }
        passwordRecords.add(passwordRecord);
        return true;
    }
    public boolean updateRecord(PasswordRecord passwordRecord){
        for(PasswordRecord pr : passwordRecords) {
            if(pr.getURL().equals(passwordRecord.getURL()) &&
                pr.getUserID().equals(passwordRecord.getUserID())) {
                passwordRecords.remove(pr);
            }
        }
        passwordRecords.add(passwordRecord);
        return true;
    }

    public boolean removeRecord(PasswordRecord passwordRecord){
        passwordRecords.remove(passwordRecord);
        return true;
    }

    public void save(){
        try{
            ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(passFname));
            for(PasswordRecord pr : passwordRecords) {
                oos.writeObject(pr);
            }
            oos.close();
        }
        catch (Exception exp) {
            System.out.println(exp.getMessage());
        }
    }

    public void populate() {
        passwordRecords.clear();
        try{
            ObjectInputStream ois = new ObjectInputStream(new FileInputStream(passFname));
            do{
                Object obj = ois.readObject();
                if (obj.getClass().equals(PasswordRecord.class)) {
                    passwordRecords.add((PasswordRecord) obj);
                }
                else {
                    break;
                }
            }while (true);
            ois.close();
        }
        catch (Exception exp) {
            System.out.println(exp.getMessage());
        }
    }

    public PasswordRecord search(String url) {
        for(PasswordRecord pr : passwordRecords) {
            if(pr.getURL().equals(url)) {
                return pr;
            }
        }
        return new PasswordRecord();
    }

    public String passwordGenerator() {
        return "";
    }
}
