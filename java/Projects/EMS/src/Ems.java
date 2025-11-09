import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;
import java.io.IOException;

public class Ems {
    private Company company;
    private final ArrayList<CompanyInfo> companyList;

    Ems() {
        companyList = new ArrayList<>();
        open();
    }

    protected void finalize() {
        save();
    }

    public void clearScreen(){
            // try{
            //     String operatingSystem = System.getProperty("os.name");
            //     if(operatingSystem.contains("Windows")){
            //         ProcessBuilder pb = new ProcessBuilder("cmd", "/c", "cls");
            //         Process startProcess = pb.inheritIO.start();
            //         startProcess.waitFor();
            //     } else {
            //         ProcessBuilder pb = new ProcessBuilder("clear");
            //         Process startProcess = pb.inheritIO.start();

            //         startProcess.waitFor();
            //     }
            // }catch(Exception e){
            //     System.out.println(e);
            // }
        try {
            new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
        }
        catch (IOException | InterruptedException i) {
            System.out.println(i.getMessage());
        }
    }

    public void addCompany() {
        CompanyInfo compInfo = new CompanyInfo();
        compInfo.addInfo();
        companyList.add(compInfo);
        save();
    }

    public void removeCompany() {
        System.out.print("Enter Company ID: ");
        Scanner scan = new Scanner(System.in);
        String id = scan.next();
        for(CompanyInfo comInfo : companyList) {
            if(comInfo.getId().equals(id)) {
                companyList.remove(comInfo);
                break;
            }
        }
        scan.close();
        save();
    }

   public void manageCompany() {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter Company ID: ");
        String id = scan.next();
        boolean flag = false;

        CompanyInfo cInfo = new CompanyInfo();
        for(CompanyInfo comInfo : companyList) {
            if(comInfo.getId().equals(id)) {
                flag = true;
                cInfo = comInfo;
                break;
            }
        }
        company = new Company();
        company.setCompanyInfo(cInfo);
        if(!company.checkIfCompanyExists(cInfo.getName())) {
            company.addInfo();
        }
        company.showMenu();
    }


    public void displayCompany() {
        System.out.print("Enter Company ID: ");
        Scanner scan = new Scanner(System.in);
        String id = scan.next();
        for(CompanyInfo comInfo : companyList) {
            if(comInfo.getId().equals(id)) {
                Company com = new Company();
                com.setCompanyInfo(comInfo);
                com.reload();
                com.displayCompany();
                break;
            }
        }
    }

    public void listCompanies() {
        System.out.println("Companies list: ");
        for(CompanyInfo compInfo : companyList) {
            System.out.println(compInfo.getId() + "\t" + compInfo.getName());
        }
    }

    private void save() {
        try {
            ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("Emp.db"));

            for (CompanyInfo comInfo : companyList) {
                oos.writeObject(comInfo);
            }
            oos.close();
        }
        catch (Exception exp) {
            System.out.println(exp.getMessage());
        }
    }

    private void open() {
        companyList.clear();
        try {
            FileInputStream fin = new FileInputStream("Emp.db");
            ObjectInputStream ois = new ObjectInputStream(fin);
            do {
                Object obj = ois.readObject();
                if (obj.getClass() == CompanyInfo.class) {
                    companyList.add((CompanyInfo) obj);
                }
                else {
                    break;
                }
            } while (true);
            ois.close();
        }
        catch (Exception exp) {
            // System.out.println(exp.getMessage());
        }
    }
}

