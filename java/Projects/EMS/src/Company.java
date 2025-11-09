import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.SimpleTimeZone;

public class Company {
    private CompanyInfo companyInfo;
    private Manager managingDirector;
    private Manager ceo;

    private final ArrayList<Employee> empList;
    private final ArrayList<Manager> manList;
    private final ArrayList<Project> projectList;

    Company() {
        companyInfo = new CompanyInfo();
        managingDirector = new Manager();
        ceo = new Manager();
        empList = new ArrayList<>();
        manList = new ArrayList<>();
        projectList = new ArrayList<>();
    }

    protected void finalize() {
        save();
    }

    public CompanyInfo getCompanyInfo() {
        return companyInfo;
    }

    public void setCompanyInfo(CompanyInfo comInfo) {
        this.companyInfo = comInfo;
    }

    public void reload() {
        empList.clear();
        manList.clear();
        projectList.clear();
        open();
    }

    public void displayCompany() {
        System.out.println("Name: " + companyInfo.getName());
        System.out.println("ID: " + companyInfo.getId());
        System.out.println("Description: "+ companyInfo.getDescription());
        System.out.println("Registration Number: " + companyInfo.getRegNo());
        System.out.println("Vat Registration Number: " + companyInfo.getVatRegNo());
        System.out.println("Managing Director: " + getManagingDirector());
        System.out.println("CEO: " + getCeo());
    }

    public Manager getManagingDirector() {
        return managingDirector;
    }

    public void setManagingDirector(Manager managingDirector) {
        this.managingDirector = managingDirector;
    }

    public Manager getCeo() {
        return ceo;
    }

    public void setCeo(Manager ceo) {
        this.ceo = ceo;
    }

    public void addInfo() {
        Scanner scan = new Scanner(System.in);
        System.out.println("Managing Director Details: ");
        managingDirector.addInfo();
        System.out.println("CEO Details: ");
        ceo.addInfo();
        String choice;
        System.out.println("Do you want to add Projects?(y/n): ");
        choice = scan.next();
        if (choice.equals("y")) {
            do {
                // Add project details
                System.out.println("Add Project: ");
                Project proj = new Project();
                proj.addInfo();
                projectList.add(proj);

                // Add manager details
                System.out.println("Manager Details: ");
                Manager man = new Manager();
                man.addInfo();
                proj.setManagerId(man.getId());
                manList.add(man);

                // Add employee details
                do {
                    System.out.println("Add Employees: ");
                    Employee emp = new Employee();
                    emp.addInfo();
                    empList.add(emp);
                    System.out.println("Do you want to add more Employees?(y/n): ");
                    choice = scan.next();
                } while (choice.equals("y"));

                // Add projects
                System.out.println("Do you want to add more Projects?(y/n): ");
                choice = scan.next();
            } while (choice.equals("y"));
        }
        save();
    }

    public void showMenu() {
        Scanner scan = new Scanner(System.in);
        int choice = 0;
        do {
            System.out.println(companyInfo.getName());
            System.out.println("1. Add Project");
            System.out.println("2. Remove Project");
            System.out.println("3. Manage Project");
            System.out.println("4. Display Project Details");
            System.out.println("5. List Projects");
            System.out.println("6. Exit");
            System.out.println("Enter an option");
            choice = scan.nextInt();
            switch (choice) {
                case 1:
                        addProject();
                    break;
                case 2:
                        removeProject();
                    break;
                case 3:
                        manageProject();
                    break;
                case 4:
                        displayProject();
                    break;
                case 5:
                        listProjects();
                    break;
                case 6:
                    System.out.println("Exiting");
                    return;
                default:
                    System.out.println("Invalid input");
                    break;
            }
        }while (choice <= 5);
    }

    public void addManager() {
        Manager man = new Manager();
        man.addInfo();
        for(Manager manInfo : manList) {
            if(manInfo.getId().equals(man.getId())) {
                System.out.println("This Manager already exists");
                return;
            }
        }
        manList.add(man);
        save();
    }

    public void removeManager() {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Manager ID: ");
        String id = scan.next();
        for(Manager manInfo : manList) {
            if(manInfo.getId().equals(id)) {
                manList.remove(manInfo);
                break;
            }
        }
        save();
    }

    public void updateManager() {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Manager ID: ");
        String id = scan.next();
        for(Manager manInfo : manList) {
            if(manInfo.getId().equals(id)) {
                manList.remove(manInfo);
                break;
            }
        }
        addManager();
    }

    public void addEmployee() {
        Employee emp = new Employee();
        emp.addInfo();
        for(Employee empInfo : empList) {
            if(empInfo.getId().equals(emp.getId())) {
                System.out.println("This Employee details already exists");
                return;
            }
        }
        empList.add(emp);
        save();
    }

    public void removeEmployee() {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Employee ID: ");
        String id = scan.next();
        for(Employee empInfo : empList) {
            if(empInfo.getId().equals(id)) {
                empList.remove(empInfo);
                break;
            }
        }
        save();
    }

    public void updateEmployee() {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Employee ID: ");
        String id = scan.next();
        for(Employee empInfo : empList) {
            if(empInfo.getId().equals(id)) {
                empList.remove(empInfo);
                break;
            }
        }
        addEmployee();
    }

    public void displayManager() {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Manager ID: ");
        String id = scan.next();
        for(Manager manInfo : manList) {
            if(manInfo.getId().equals(id)) {
                manInfo.display();
                break;
            }
        }
    }

    public void displayEmployee() {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Employee ID: ");
        String id = scan.next();
        for(Employee empInfo : empList) {
            if(empInfo.getId().equals(id)) {
                empInfo.display();
                break;
            }
        }
    }

    public void listManagers() {
        System.out.println("Managers list: ");
        for(Manager manInfo : manList) {
            System.out.println("ID \t NAME");
            System.out.println(manInfo.getId() + "\t" + manInfo.getName());
        }
    }

    public void listEmployees() {
        System.out.println("Employees list: ");
        for(Employee empInfo : empList) {
            System.out.println("ID \t NAME");
            System.out.println(empInfo.getId() + "\t" + empInfo.getName());
        }
    }

    public void findEmployee() {

    }

    public void addProject() {
        Project proj = new Project();
        proj.addInfo();
        // Check if project exists
        for(Project projInfo : projectList) {
            if(projInfo.getId().equals(proj.getId())) {
                System.out.println("This Project already exists");
                return;
            }
        }
        projectList.add(proj);
        save();
    }

    public void removeProject() {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Project ID: ");
        String id = scan.next();
        for(Project projInfo : projectList) {
            if(projInfo.getId().equals(id)) {
                projectList.remove(projInfo);
                break;
            }
        }
        save();
    }

    public void manageProject() {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter Project ID: ");
        String id = scan.next();
        boolean flag = false;

        Project pInfo = new Project();
        for(Project projInfo : projectList) {
            if(projInfo.getId().equals(id)) {
                flag = true;
                pInfo = projInfo;
                break;
            }
        }
        if(flag) {
            int choice = 0;
            do {
                System.out.println(pInfo.getName());
                System.out.println("1. Add Manager");
                System.out.println("2. Remove Manager");
                System.out.println("3. Update Manager");
                System.out.println("4. Add Employee");
                System.out.println("5. Remove Employee");
                System.out.println("6. Update Employee");
                System.out.println("7. Display Manager");
                System.out.println("8. Display Employee");
                System.out.println("9. List Managers");
                System.out.println("10. List Employees");
                System.out.println("11. Find Employee");
                System.out.println("12. Exit");
                System.out.println("Enter an option");
                choice = scan.nextInt();
                switch (choice) {
                    case 1:
                        addManager();
                        break;
                    case 2:
                        removeManager();
                        break;
                    case 3:
                        updateManager();
                        break;
                    case 4:
                        addEmployee();
                        break;
                    case 5:
                        removeEmployee();
                        break;
                    case 6:
                        updateEmployee();
                        break;
                    case 7:
                        displayManager();
                        break;
                    case 8:
                        displayEmployee();
                        break;
                    case 9:
                        listManagers();
                        break;
                    case 10:
                        listEmployees();
                        break;
                    case 11:
                        findEmployee();
                        break;
                    case 12:
                        System.out.println("Exiting");
                        return;
                    default:
                        System.out.println("Invalid input");
                        break;
                }
            } while (choice <= 5);
        }
    }

    public void displayProject() {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter project ID: ");
        String id = scan.next();
        for(Project projInfo : projectList) {
            if(projInfo.getId().equals(id)) {
                projInfo.displayProject();
                break;
            }
        }
    }

    public void listProjects() {
        System.out.println("Projects list: ");
        System.out.println("ID \t NAME");
        reload();
        for(Project projInfo : projectList) {
            System.out.println(projInfo.getId() + "\t" + projInfo.getName());
        }
    }

    public boolean checkIfCompanyExists(String name) {
        String dbFileName = name.replace(" ", "_") + ".db";
        File file = new File(dbFileName);
        return file.exists() && !file.isDirectory();
    }

    public void save(){
        String dbFileName = companyInfo.getName().replace(" ", "_") + ".db";
        try{
            ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(dbFileName));
            oos.writeObject(companyInfo);
            oos.writeObject(managingDirector);
            oos.writeObject(ceo);
            for(Project proj : projectList) {
                oos.writeObject(proj);
            }
            for(Manager man : manList) {
                oos.writeObject(man);
            }
            for(Employee emp : empList) {
                oos.writeObject(emp);
            }
            oos.close();
        }
        catch (Exception exp) {
            System.out.println(exp.getMessage());
        }
    }

    private void open() {
        String dbFileName = companyInfo.getName().replace(" ", "_") + ".db";
        try{
            FileInputStream fin = new FileInputStream(dbFileName);
            ObjectInputStream ois = new ObjectInputStream(fin);
            companyInfo = (CompanyInfo) ois.readObject();
            managingDirector = (Manager) ois.readObject();
            ceo = (Manager) ois.readObject();
            do{
                Object obj = ois.readObject();
                if (obj.getClass() == Project.class) {
                    projectList.add((Project) obj);
                }
                else if (obj.getClass() == Manager.class) {
                    manList.add((Manager) obj);
                }
                else if (obj.getClass() == Employee.class) {
                    empList.add((Employee) obj);
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
}


//    Previous Methods...
//    public void showEmployee() throws IOException {
//        Scanner scan = new Scanner(System.in);
//        System.out.println("Employee ID: ");
//        String id = scan.next();
//        Employee emp = getEmployee(id);
//        if(emp != null){
//            display_employee(emp);
//        }
//    }

//    private void display_employee(Employee emp) {
//        System.out.println("Employee Details: ");
//        System.out.println("Name: " + emp.getName());
//        System.out.println("ID: " + emp.getId());
//        System.out.println("Contact: " + emp.getContact());
//        System.out.println("Gender: " + emp.getGender());
//        System.out.println("Age: " + emp.getAge());
//        System.out.println("Salary: " + emp.getSalary());
//        System.out.println("Address: " + emp.getAddress_asString());
//        System.out.println("Designation: " + emp.getDesignation());
//        System.out.println("Status: " + emp.getStatus());
//        System.out.println("Is On Bench: " + emp.getOnBench());
//    }