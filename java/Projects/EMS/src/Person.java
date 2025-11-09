import java.io.Serializable;
import java.util.Scanner;

public class Person implements Serializable {
    private String name;
    private String id;
    private String contact;
    private String gender;
    private int age;
    private float salary;
    private Address address;

    Person() {
        address = new Address();
    }

    public String getName() {
        return name;
    }

    public String getId() {
        return id;
    }

    public String getContact() {
        return contact;
    }

    public String getGender() {
        return gender;
    }

    public int getAge() {
        return age;
    }

    public float getSalary() {
        return salary;
    }

    public Address getAddress() {
        return address;
    }

    public String getAddress_asString() {
        return address.getAddress();
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public void setContact(String contact) {
        this.contact = contact;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void setId(String id) {
        this.id = id;
    }

    public void setSalary(float salary) {
        this.salary = salary;
    }

    public void setAddress(Address address) {
        this.address = address;
    }

    public void addInfo() {
        Scanner scan = new Scanner(System.in);

        System.out.println("Personal Details");
        System.out.println("Name: ");
        name = scan.nextLine();
        System.out.println("ID: ");
        id = scan.nextLine();
        System.out.println("Contact: ");
        contact = scan.nextLine();
        System.out.println("Gender: ");
        gender = scan.nextLine();
        System.out.println("Age: ");
        age = scan.nextInt();
        System.out.println("Salary: ");
        salary = scan.nextFloat();
        address.addInfo();
    }

    public void display() {
        System.out.println("Name: " + getName());
        System.out.println("ID: " + getId());
        System.out.println("Contact: " + getContact());
        System.out.println("Gender: " + getGender());
        System.out.println("Age: " + getAge());
        System.out.println("Salary: " + getSalary());
    }
}