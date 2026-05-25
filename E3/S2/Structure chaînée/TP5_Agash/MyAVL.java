import java.io.FileNotFoundException;
import java.io.PrintWriter;

public class MyAVL {

    private static class TreeNode {
        private String key;
        private TreeNode left;
        private TreeNode right;
        private int height;

        TreeNode(String key, TreeNode left, TreeNode right) {
            this.key = key;
            this.left = left;
            this.right = right;
            updateHeight(this);
        }
    }

    private TreeNode root;
    private int size;

    public MyAVL() {
        root = null;
        size = 0;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int size() {
        return size;
    }

    public static MyAVL exampleAVL() {
        var avl = new MyAVL();

        avl.root =
            new TreeNode("mouton",
                new TreeNode("chien",
                    new TreeNode("chat", null, null),
                    new TreeNode("loup", null, null)),
                new TreeNode("souris", null, null));

        avl.size = 5;

        return avl;
    }

    public boolean contains(String key) {
        return contains(root, key);
    }

    private boolean contains(TreeNode node, String key) {
        if (node == null) {
            return false;
        }

        var cmp = key.compareTo(node.key);

        if (cmp == 0) {
            return true;
        } else if (cmp < 0) {
            return contains(node.left, key);
        } else {
            return contains(node.right, key);
        }
    }

    public int height() {
        return height(root);
    }

    private static int height(TreeNode node){
        if(node == null) return -1;

        return node.height;
    }

    private static void updateHeight(TreeNode node){

        node.height = 1 + Math.max(height(node.left), height(node.right));
    }

    private static int balance(TreeNode node){

        return height(node.left) - height(node.right);
    }

    private static TreeNode rotateRight(TreeNode y){

        var x = y.left;
        var B = x.right;
        x.right = y;
        y.left = B;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    private static TreeNode rotateLeft(TreeNode x){

        var y = x.right;
        var A = y.left;
        y.left = x;
        x.right = A;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    public void rotateRootRightForTest() {
        root = rotateRight(root);
    }

    private static TreeNode rebalance(TreeNode node){
        if(balance(node) == 2){
            if(balance(node.left) == -1){
                node.left = rotateLeft(node.left);
            }
            node = rotateRight(node);
        }

        if(balance(node) == -2){
            if(balance(node.right) == 1){
                node.right = rotateRight(node.right);
            }
            node = rotateLeft(node);
        }

        return node;
    }

    public void rebalanceAVLForTest(){
        root = rebalance(root);
    }

    public void add(String key){
        root = add(root, key);
    }

    private TreeNode add(TreeNode node, String key){
        if(node == null){
            size++;
            if(root == null){
                root = new TreeNode(key, null, null);
                return root;
            }
            return new TreeNode(key, null, null);
        }

        var cmp = key.compareTo(node.key);

        if (cmp < 0) {
            node.left = add(node.left, key);
        } else {
            node.right = add(node.right, key);
        }

        updateHeight(node);
        return rebalance(node);
    }


    public boolean isAVL() {
        return isAVL(root);
    }

    private static boolean isAVL(TreeNode node) {
        if (node == null) return true;

        int expectedHeight = 1 + Math.max(height(node.left), height(node.right));
        if (node.height != expectedHeight) return false;

        int b = balance(node);
        if (b < -1 || b > 1) return false;

        return isAVL(node.left) && isAVL(node.right);
    }

    /* DOT VISUALIZATION */

    public void writeDot(String filename) {
        try {
            var out = new PrintWriter(filename);
            writeBegin(out);
            writeTreeAux(out, root);
            writeEnd(out);
        } catch (FileNotFoundException e) {
            throw new RuntimeException("Cannot write file " + filename, e);
        }
    }

    private static void writeBegin(PrintWriter out) {
        out.println("digraph tree {");
        out.println("  splines=false");
        out.println("  node [shape=record,height=.1]");
        out.println("  edge [tailclip=false, arrowtail=dot, dir=both];");
        out.println();
    }

    private static void writeEnd(PrintWriter out) {
        out.println();
        out.println("}");
        out.close();
    }

    private static String nodeName(TreeNode node) {
        return "n" + System.identityHashCode(node);
    }

    private static void writeNode(PrintWriter out, TreeNode node) {
        out.println("  " + nodeName(node)
                + " [label=\"<left> |{ <key> " + node.key
                + "|" + node.height
                + " }| <right>\"];");
    }

    private static void writeLeftLink(PrintWriter out, TreeNode node) {
        out.println("  " + nodeName(node) + ":left:c -> "
                + nodeName(node.left) + ":key;");
    }

    private static void writeRightLink(PrintWriter out, TreeNode node) {
        out.println("  " + nodeName(node) + ":right:c -> "
                + nodeName(node.right) + ":key;");
    }

    private static void writeTreeAux(PrintWriter out, TreeNode node) {
        if (node == null) {
            return;
        }

        writeNode(out, node);

        if (node.left != null) {
            writeLeftLink(out, node);
            writeTreeAux(out, node.left);
        }

        if (node.right != null) {
            writeRightLink(out, node);
            writeTreeAux(out, node.right);
        }
    }
}
