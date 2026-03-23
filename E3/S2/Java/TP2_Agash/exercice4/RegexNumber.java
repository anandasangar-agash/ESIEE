import java.util.regex.Pattern;
import java.util.regex.Matcher;

class RegexNumber {

    static final Pattern IPV4_PATTERN = Pattern.compile("(\\d+)\\.(\\d+)\\.(\\d+)\\.(\\d+)");

    static int[] parseIPv4(String s) {
        Matcher m = IPV4_PATTERN.matcher(s);

        if (!m.matches()) {
            throw new IllegalArgumentException("Invalid IPv4 address");
        }

        int[] res = new int[4];

        for (int i = 1; i <= 4; i++) {
            int val = Integer.parseInt(m.group(i));

            if (val < 0 || val > 255) {
                throw new IllegalArgumentException("IPv4 byte out of range (0-255)");
            }

            res[i - 1] = (int) val;
        }

        return res;
    }

    static void main(String[] args){

/* Question 2
        Pattern p = Pattern.compile("[0-9]+");

        for(String s : args){
            if(p.matcher(s).matches()){
                IO.println(s);
            }
        }
*/

// Question 3 

        Pattern p = Pattern.compile("(\\d+)$");
        Matcher m = p.matcher("");

        for (String s : args) {
            m.reset(s);

            if (m.find()) {
                System.out.println(m.group(1));
            }
        }
// Question 4

        int[] ip = parseIPv4("193.43.55.67");

        for (int b : ip) {
            System.out.println(b);
        }
    }
}