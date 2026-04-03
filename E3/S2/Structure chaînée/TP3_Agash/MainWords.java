import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class MainWords {

    public static void main(String[] args) throws FileNotFoundException {

        if(args[0] == null){
             throw new IndexOutOfBoundsException();
        }

        var file = new File(args[0]);
        var scanner = new Scanner(file);

        var words = 0;
        var map = new MyHashMap(10000);

        var start = System.nanoTime();
        while (scanner.hasNext()) {
            String word = scanner.next();
            // IO.println(word);
            if(map.containsKey(word)){
                map.put(word, map.get(word) + 1);
            } else {
                map.put(word, 1);
            }
            words++;
        }
        var end = System.nanoTime();
        IO.println("The file contained " + words + " words and had " + map.getOrDefault("the", 0) + " \"the\" word.");
        IO.println("time (ms): " + (end - start) / 1_000_000.0);

        scanner.close();
    }
}
