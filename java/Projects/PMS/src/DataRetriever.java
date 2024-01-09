import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class DataRetriever {
    public String line;
    public String fname;
    public String retPassData() {
        try {
            Scanner scan  = new Scanner(System.in);
            fname = scan.next();
            FileReader fileReader = new FileReader(fname);
            BufferedReader bufferedReader = new BufferedReader(fileReader);

            line = bufferedReader.readLine();
            while (line != null) {
                System.out.println(line);
                line = bufferedReader.readLine();
            }

            bufferedReader.close();
            fileReader.close();
        }
        catch (IOException e) {
            System.out.println(e);
        }
        return line;
    }
    public String retNoteData() {
        try {
            Scanner scan  = new Scanner(System.in);
            fname = scan.next();
            FileReader fileReader = new FileReader(fname);
            BufferedReader bufferedReader = new BufferedReader(fileReader);

            line = bufferedReader.readLine();
            while (line != null) {
                System.out.println(line);
                line = bufferedReader.readLine();
            }

            bufferedReader.close();
            fileReader.close();
        }
        catch (IOException e) {
            System.out.println(e);
        }
        return line;
    }
}