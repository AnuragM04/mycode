import java.util.Vector;

public class Vector_eg {
    public static void main(String[] args) {
        int size = 10;
        Vector<Integer> vect = new Vector<>();

        for(int i=1; i<=size; i++) {
            vect.add(i * 10);
        }
        System.out.println("Element at index 2: " + vect.get(2));

        vect.set(1, 25);
        vect.remove(3);

        System.out.println("Vector elements:");
        for (Integer element : vect) {
            System.out.println(element);
        }

        boolean containsElement = vect.contains(25);
        System.out.println("Contains 25? " + containsElement);

        int x = vect.size();
        System.out.println("Vector size: " + size);
    }
}