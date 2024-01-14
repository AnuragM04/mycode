import java.io.Serializable;

public class PasswordRecord implements Serializable {
    private String URL;
    private String userID;
    private String password;
    private String additionalInfo;
    private String notes;

    public String getURL() {
        return URL;
    }
    public void setURL(String URL) {
        this.URL = URL;
    }

    public String getUserID() {
        return userID;
    }
    public void setUserID(String userID) {
        this.userID = userID;
    }

    public String getPassword() {
        return password;
    }
    public void setPassword(String password) {
        this.password = password;
    }

    public String getAdditionalInfo() {
        return additionalInfo;
    }
    public void setAdditionalInfo(String additionalInfo) {
        this.additionalInfo = additionalInfo;
    }

    public String getNotes() {
        return notes;
    }
    public void setNotes(String notes) {
        this.notes = notes;
    }
}