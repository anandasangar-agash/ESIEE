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
        var list = new MyLinkedList();
        //var list = new MyArrayList();

        var start = System.nanoTime();
        while (scanner.hasNext()) {
            String word = scanner.next();
            // IO.println(word);
            if(!list.contains(word)){
                list.addLast(word);
            }
            words++;
        }
        var end = System.nanoTime();
        IO.println("The file contained " + words + " words and had " + list.size() + " words distinct.");
        IO.println("time (ms): " + (end - start) / 1_000_000.0);

        scanner.close();
    }
}
