public class Main {

    static void main() {

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
    }
}