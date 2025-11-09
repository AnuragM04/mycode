import java.io.Serializable;
import java.util.Scanner;

public class Employee extends Person implements Serializable {
    private String designation;
    private String status;
    private boolean isOnBench;

    public String getDesignation() {
        return designation;
    }

    public String getStatus() {
        return status;
    }
    public boolean getOnBench() {
        return isOnBench;
    }

    public void setDesignation(String designation) {
        this.designation = designation;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public void setOnBench(boolean onBench) {
        isOnBench = onBench;
    }

    public void addInfo() {
        super.addInfo();
        Scanner scan = new Scanner(System.in);

        System.out.println("Employee Details");
        System.out.println("Designation: ");
        designation = scan.next();
        System.out.println("Status: ");
        status = scan.next();
        System.out.println("Is on Bench: ");
        isOnBench = scan.nextBoolean();
    }

    public void display() {
        super.display();
        System.out.println("Designation: " + getDesignation());
        System.out.println("Status: " + getStatus());
        System.out.println("Is on Bench: " + getOnBench());
    }
}
