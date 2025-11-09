import java.io.Serializable;
import java.security.SecureRandomParameters;
import java.util.Scanner;

public class CompanyInfo implements Serializable {
    private String name;
    private String id;
    private String description;
    private String regNo;
    private String vatRegNo;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getId() {
        return id;
    }

    public void setId(String cId) {
        this.id = id;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public String getRegNo() {
        return regNo;
    }

    public void setRegNo(String regNo) {
        this.regNo = regNo;
    }

    public String getVatRegNo() {
        return vatRegNo;
    }

    public void setVatRegNo(String vatRegNo) {
        this.vatRegNo = vatRegNo;
    }

    public void addInfo() {
        Scanner scan = new Scanner(System.in);

        System.out.println("Company Details");
        System.out.println("Name: ");
        name = scan.next();
        System.out.println("Company ID: ");
        id = scan.next();
        System.out.println("Description: ");
        description = scan.next();
        System.out.println("Registration Number: ");
        regNo = scan.next();
        System.out.println("Vat Registration Number: ");
        vatRegNo = scan.next();
    }
}