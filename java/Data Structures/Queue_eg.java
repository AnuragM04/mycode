import java.util.LinkedList;
import java.util.Queue;

public class Queue_eg {
	public static void main(String[] args) {
		Queue<Integer> queue = new LinkedList<>();

		for (int i = 4; i <= 11; i++) {
            queue.add(i);
        }
		System.out.println("Queue's list: "	+ queue);

		int front = queue.remove();
		System.out.println("Dequeued element: " + front);

        System.out.println("Updated queue:" + queue);

        queue.add(44);

		int head = queue.peek();
		System.out.println("Head of queue: "+ head);

		int size = queue.size();
		System.out.println("Size of queue: " + size);

        System.out.println("Updated queue:" + queue);
	}
}
