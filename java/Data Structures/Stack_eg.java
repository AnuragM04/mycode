import java.util.Stack;

public class Stack_eg {
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();

        stack.push(4);
        stack.push(11);
        stack.push(44);

        int popped_val = stack.pop();
        System.out.println("Popped Value: " + popped_val);

        int top_val = stack.peek();
        System.out.println("Top Value: " + top_val);

        boolean isEmpty = stack.isEmpty();
        System.out.println("Is Stack Empty? " + isEmpty);
    }
}