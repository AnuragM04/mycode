import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(System.in);
        System.out.println("EMPLOYEE MANAGEMENT SYSTEM");
        int choice = 0;
        Ems ems = new Ems();
        do {
            System.out.println("1. Add Company");
            System.out.println("2. Remove Company");
            System.out.println("3. Manage Company");
            System.out.println("4. Display Company Details");
            System.out.println("5. List Companies");
            System.out.println("6. Exit");
            System.out.println("Enter an option");
            choice = scan.nextInt();
            ems.clearScreen();
            switch (choice) {
                case 1:
                    ems.addCompany();
                    break;
                case 2:
                    ems.removeCompany();
                    break;
                case 3:
                    ems.manageCompany();
                    break;
                case 4:
                    ems.displayCompany();
                    break;
                case 5:
                    ems.listCompanies();
                    break;
                case 6:
                    System.out.println("Exiting");
                    return;
                default:
                    System.out.println("Invalid input");
                    break;
            }
        }while (choice <= 5);
        scan.close();
    }

}