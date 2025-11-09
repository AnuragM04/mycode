// %b, %B	"true" or "false" based on the argument
// %s, %S	a string
// %c, %C	a Unicode character
// %d	    a decimal integer (used for integers only)
// %o	    an octal integer (used for integers only)
// %x, %X	a hexadecimal integer (used for integers only)
// %e, %E	for scientific notation (used for floating-point numbers)
// %f	    for decimal numbers (used for floating-point numbers)

public class String_format {
    public static void main(String[] args) {
        String name = "Anurag";
        int roll_no = 68;
        String result;

        result = String.format("Name: %s", name);
        System.out.println(result);
        
        result = String.format("Roll Number: %d", roll_no);
        System.out.println(result);
    }
}