import java.io.Serializable;
import java.util.ArrayList;
import java.util.Scanner;

public class Manager extends Person {
    private long bonus;
    private long shares;

    Manager() {
        bonus = 100;
        shares = 10;
    }

    public long getBonus() {
        return bonus;
    }

    public void setBonus(long bonus) {
        this.bonus = bonus;
    }

    public long getShares() {
        return shares;
    }

    public void setShares(long shares) {
        this.shares = shares;
    }
    
    public void addInfo() {
        Scanner scan = new Scanner(System.in);
        super.addInfo();
        System.out.println("Bonus: ");
        bonus = scan.nextLong();
        System.out.println("any Shares: ");
        shares = scan.nextInt();
    }

    public void display() {
        super.display();
        System.out.println("Bonus: " + getBonus());
        System.out.println("Shares: " + getShares());
    }
}
