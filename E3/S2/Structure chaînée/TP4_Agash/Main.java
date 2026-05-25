import java.util.ArrayList;
import java.util.Collections;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
public class Main {

    static void main(String[] args) throws FileNotFoundException {

        var bst = new MyBST();
        IO.println("size = " + bst.size());
        // ...
        bst = MyBST.exampleBST();
        IO.println("-----Print préfixe-----");
        bst.printPreOrder();
        IO.println("-----Print infixe-----");
        bst.printInOrder();
        IO.println("-----Print suffixe-----");
        bst.printPostOrder();

        IO.println("Hauteur : " + bst.height());

        bst.writeDot("tree.dot");
        // convert tree.dot to tree.pdf
        try {
            new ProcessBuilder("dot", "-Tpdf", "tree.dot", "-o", "tree.pdf")
                .start()
                .waitFor();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }

        IO.println("-----Méthode contains-----");
        IO.println("find loup : " + bst.contains("loup"));
        IO.println("find lapin : " + bst.contains("lapin"));
        IO.println("find mouton : " + bst.contains("mouton"));

        int N = 10; // modify to adjust the number of calls to add
        var newBst = new MyBST();
        var rand = new java.util.Random();

        for (int i = 0; i < N; i++) {
            var key = String.valueOf((char) ('A' + rand.nextInt(26)));
            IO.println("add("+key+")");
            newBst.add(key);
        }

        newBst.writeDot("treeAdd.dot");

        try {
            new ProcessBuilder("dot", "-Tpdf", "treeAdd.dot", "-o", "treeAdd.pdf")
                .start()
                .waitFor();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }

        IO.println("Insertion dans l'ordre");

        N = 50000;
        newBst = new MyBST();
        var start = System.nanoTime();
        for(int i = 0; i < N; i++){
            var key = String.format("%06d", i);
            newBst.add(key);
        }
        var end = System.nanoTime();

       IO.println("time (ms): " + (end - start) / 1_000_000.0);
       IO.println("hauteur : " + newBst.height());


       IO.println("Insertion aléatoire");

       N = 50000;
       newBst = new MyBST();
       var list = new ArrayList<String>();
       for (int i = 0; i < N; i++) {
            list.add(String.format("%06d", i));
        }
        Collections.shuffle(list);

        start = System.nanoTime();
         for (var key : list) {
            newBst.add(key);
        }
        end = System.nanoTime();
        IO.println("time (ms): " + (end - start) / 1_000_000.0);
        IO.println("hauteur : " + newBst.height());

        IO.println("Insertion de mots");

        if(args[0] == null){
             throw new IndexOutOfBoundsException();
        }

        var file = new File(args[0]);
        var scanner = new Scanner(file);

        newBst = new MyBST();

        start = System.nanoTime();
        while (scanner.hasNext()) {
            String word = scanner.next();
            newBst.add(word);
        }
        end = System.nanoTime();

        IO.println("time (ms): " + (end - start) / 1_000_000.0);
        IO.println("hauteur : " + newBst.height());

        scanner.close();
    }
}