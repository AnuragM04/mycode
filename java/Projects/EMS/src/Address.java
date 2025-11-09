import java.io.Serializable;
import java.util.Scanner;

public class Address implements Serializable {
    private String houseNo;
    private String street;
    private String city;
    private String state;
    private String country;
    private String postCode;


    public String getHouse_no() {
        return houseNo;
    }

    public String getStreet() {
        return street;
    }

    public String getCity() {
        return city;
    }

    public String getState() {
        return state;
    }
    public String getCountry() {
        return country;
    }

    public String getPost_code() {
        return postCode;
    }

    public void setHouse_no(String house_no) {
        this.houseNo = house_no;
    }

    public void setStreet(String street) {
        this.street = street;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public void setState(String state) {
        this.state = state;
    }

    public void setCountry(String country) {
        this.country = country;
    }

    public void setPost_code(String postCode) {
        this.postCode = postCode;
    }

    public String getAddress() {
        return houseNo + "\n" + street + "\n" + city + "\n" + state + "\n" + country + "\n" + postCode;
    }

    public void addInfo() {
        Scanner scan = new Scanner(System.in);
        System.out.println("Address: ");
        System.out.println("House No: ");
        houseNo = scan.nextLine();
        System.out.println("Street: ");
        street = scan.nextLine();
        System.out.println("City: ");
        city = scan.nextLine();
        System.out.println("State: ");
        state = scan.nextLine();
        System.out.println("Country: ");
        country = scan.nextLine();
        System.out.println("Post code: ");
        postCode = scan.nextLine();
    }

}