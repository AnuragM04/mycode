class Box {
    double d,w,h;

    Box() {
        d=w=h=-1;
    }

    Box(double d, double w, double h) {
        this.d = d;
        this.w = w;
        this.h = h;
    }

    void showDetails() {
        System.out.println(d);
        System.out.println(w);
        System.out.println(h);
    }
}


public class Hello_world
{
    public static void main(String[] args)
    {
        // // System.out.println("Hello, World!");
        // int arr[][] = new int[3][4];
        // int arr2[][] = new int[3][];
        // int arr2[0] = new int[1];
        // int arr2[1] = new int[2];
        // int arr2[2] = new int[5];

        // for(int i=0; i<3; i++) {
        //     for(int j=0; j<i; j++) {
        //             System.out.print(arr2[i][j]);
        //     }
        //     System.out.println();
        // }

        Box myBox = new Box(10,10,10);
        myBox.showDetails();
    }
}
