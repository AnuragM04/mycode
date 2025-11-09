import java.util.LinkedList;

public class Linked_list {
  public static void main(String[] args) {
    LinkedList<String> myCars = new LinkedList<String>();
    myCars.add("Ferrari");
    myCars.add("Lamborghini");
    myCars.add("Pagani");
    myCars.add("Koenigsegg");

    for (String i : myCars) {
      System.out.println(i);
    }
  }
}