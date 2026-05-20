public class Main {

    static void main() {
        var avl = new MyAVL();

        String[] words = {
            "mouton", "chien", "chat", "loup", "souris",
            "abeille", "zebre", "tigre", "renard", "ours"
        };

        for (var word : words) {
            avl.add(word);
            updatePDFAndWait(avl);
        }

        IO.println("Height : " + avl.height());
        IO.println("Size   : " + avl.size());
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
