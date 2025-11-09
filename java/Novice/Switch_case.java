import java.util.Scanner;

public class Switch_case
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter a number (1-3): ");
        int choice = scan.nextInt();
        switch(choice)
        {
            case 1:
                System.out.println("Java");
                break;
            case 2:
                System.out.println("Switch");
                break;
            case 3:
                System.out.println("Case");
                break;
            default:
                System.out.println("Invalid choice");
        }
        scan.close();
    }
}
