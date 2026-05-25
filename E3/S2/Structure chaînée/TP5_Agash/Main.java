import java.util.ArrayList;
import java.util.Collections;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
public class Main {

    static void main(String[] args) throws FileNotFoundException {
        var avl = new MyAVL();

        String[] words = {
            "mouton", "chien", "chat", "loup", "souris",
            "abeille", "zebre", "tigre", "renard", "ours"
        };

        for (var word : words) {
            avl.add(word);
            updatePDF(avl);
        }
    
        var list = new ArrayList<String>();
        for (int i = 0; i < 1000; i++) {
            list.add(String.format("%04d", i));
        }
        Collections.shuffle(list);

        for (var key : list) {
            avl.add(key);
            if (!avl.isAVL()) {
                IO.println("The tree is not an AVL tree");
                return;
            }
        }

        IO.println("Ok!");

        IO.println("Height : " + avl.height());
        IO.println("Size   : " + avl.size());


        IO.println("Insertion dans l'ordre");

        var N = 50000;
        var newAvl = new MyAVL();
        var start = System.nanoTime();
        for(int i = 0; i < N; i++){
            var key = String.format("%06d", i);
            newAvl.add(key);
        }
        var end = System.nanoTime();

       IO.println("time (ms): " + (end - start) / 1_000_000.0);
       IO.println("hauteur : " + newAvl.height());


       IO.println("Insertion aléatoire");

       N = 50000;
       newAvl = new MyAVL();
       list = new ArrayList<String>();
       for (int i = 0; i < N; i++) {
            list.add(String.format("%06d", i));
        }
        Collections.shuffle(list);

        start = System.nanoTime();
         for (var key : list) {
            newAvl.add(key);
        }
        end = System.nanoTime();
        IO.println("time (ms): " + (end - start) / 1_000_000.0);
        IO.println("hauteur : " + newAvl.height());

        IO.println("Insertion de mots avec big.txt");

        if(args[0] == null){
             throw new IndexOutOfBoundsException();
        }

        var file = new File(args[0]);
        var scanner = new Scanner(file);

        newAvl = new MyAVL();

        start = System.nanoTime();
        while (scanner.hasNext()) {
            String word = scanner.next();
            newAvl.add(word);
        }
        end = System.nanoTime();

        IO.println("time (ms): " + (end - start) / 1_000_000.0);
        IO.println("hauteur : " + newAvl.height());

        scanner.close();

        IO.println("Insertion de mots avec enwik8");

        if(args[1] == null){
             throw new IndexOutOfBoundsException();
        }

        file = new File(args[1]);
        scanner = new Scanner(file);

        newAvl = new MyAVL();

        start = System.nanoTime();
        while (scanner.hasNext()) {
            String word = scanner.next();
            newAvl.add(word);
        }
        end = System.nanoTime();

        IO.println("time (ms): " + (end - start) / 1_000_000.0);
        IO.println("hauteur : " + newAvl.height());

        scanner.close();
    }

    private static void updatePDF(MyAVL avl){
        avl.writeDot("avl.dot");

        try {
            new ProcessBuilder("dot", "-Tpdf", "avl.dot", "-o", "avl.pdf")
                .start()
                .waitFor();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    private static void updatePDFAndWait(MyAVL avl){
        avl.writeDot("avl.dot");
        IO.readln("Appuyer sur entrée pour visualiser le PDF !!");
        try {
            new ProcessBuilder("dot", "-Tpdf", "avl.dot", "-o", "avl.pdf")
                .start()
                .waitFor();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}
