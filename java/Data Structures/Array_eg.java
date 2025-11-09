// package Arrays;

// import java.util.Arrays;


// public class Array_eg {
//     public static void main(String args[]) {
//         int arr[] = new int[10];
//         Arrays.fill(arr, 44);
//         System.out.println(Arrays.toString(arr));
//     }
// }

public class Array_eg {
  public static void main(String[] args) {
    int[][] myNumbers = { {1, 2, 3, 4}, {5, 6, 7} };
      for (int[] myNumber : myNumbers) {
          for (int i : myNumber) {
              System.out.println(i);
          }
      }
  }
}