// class ErrorCheck {
//     public static void main(String[] args) {
//         // int Integer = 24;
//         // char String  = 'I';
//         // System.out.print(Integer);
//         // System.out.print(String);

//         int n = (2**15)-1;
//         System.out.println(n);
//     }
// }

import java.io.*;
import java.util.*;

public class ErrorCheck {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int i=0;i<t;i++)
        {
            try
            {
                long num = sc.nextLong();
                System.out.println(num+" can be fitted in:");

                if(num>=-128 && num<=127)
                    System.out.println("* byte");
                    
                double res = Math.pow(2, 15);   
                if(num >= -res && num <= res-1)
                    System.out.println("* short");                  
                    
                res = Math.pow(2, 31);   
                if(num >= -res && num <= res-1)
                    System.out.println("* int");                  
                
                res = Math.pow(2, 63);   
                if(num >= -res && num <= res-1)
                    System.out.println("* long");                  
            }
            catch(Exception e)
            {
                System.out.println(sc.next()+" can't be fitted anywhere.");
            }
        }
    }
}