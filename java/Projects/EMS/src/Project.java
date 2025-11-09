import java.io.Serializable;
import java.util.ArrayList;
import java.util.Scanner;

public class Project implements Serializable {
    private String name;
    private String id;
    private String managerId;
    private ArrayList<String> empIdList;
    private long budget;
    private int days;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getManagerId() {
        return managerId;
    }

    public void setManagerId(String managerId) {
        this.managerId = managerId;
    }

    public long getBudget() {
        return budget;
    }

    public void setBudget(long budget) {
        this.budget = budget;
    }

    public int getDays() {
        return days;
    }

    public void setDays(int days) {
        this.days = days;
    }

    public ArrayList<String> getEmpIdList() {
        return empIdList;
    }

    public void setEmpIdList(ArrayList<String> empIdList) {
        this.empIdList = empIdList;
    }

    public void addInfo() {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Project Details: ");
        System.out.println("Name: ");
        name = scan.next();
        System.out.println("ID: ");
        id = scan.next();
        System.out.println("Budget: ");
        budget = scan.nextLong();
        System.out.println("Time limit(days): ");
        days = scan.nextInt();
    }

    public void displayProject() {
        System.out.println("Name: " + getName());
        System.out.println("ID: " + getId());
        System.out.println("Manager ID: "+ getManagerId());
        System.out.println("Budget: " + getBudget());
        System.out.println("Time limit(days): " + getDays());
    }
}