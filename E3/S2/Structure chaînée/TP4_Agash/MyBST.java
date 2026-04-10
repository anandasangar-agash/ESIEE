import java.lang.Math;
import java.io.PrintWriter;
import java.io.FileNotFoundException;

public class MyBST {

    private static class TreeNode {
        private String key;
        private TreeNode left;
        private TreeNode right;

        TreeNode(String key, TreeNode left, TreeNode right) {
            this.key = key;
            this.left = left;
            this.right = right;
        }
    }

    private TreeNode root;
    private int size;

    public MyBST() {
        root = null;
        size = 0;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int size() {
        return size;
    }

    public static MyBST exampleBST(){
        var bst = new MyBST();
        var node = new TreeNode("mouton", 
                                new TreeNode("chien", 
                                    new TreeNode("chat", null, null), 
                                    new TreeNode("loup", null, null)
                                ),
                                new TreeNode("souris", null, null));
        bst.root = node;
        bst.size = 5;

        return bst;
    }

    public void printPreOrder(){
        printPreOrder(root);
    }

    private void printPreOrder(TreeNode node){
        if (node == null) return;

        IO.println(node.key);

        printPreOrder(node.left);
        printPreOrder(node.right);
    }

    public void printInOrder(){
        printInOrder(root);
    }

    private void printInOrder(TreeNode node){
        if (node == null) return;

        printInOrder(node.left);
        IO.println(node.key);
        printInOrder(node.right);
    }

    public void printPostOrder(){
        printPostOrder(root);
    }

    private void printPostOrder(TreeNode node){
        if (node == null) return;

        printPostOrder(node.left);
        printPostOrder(node.right);
        IO.println(node.key);
    }

    public int height(){
        return height(root);
    }

    private int height(TreeNode node){
        if (node == null) return -1;

        var hLeft = height(node.left);
        var hRight = height(node.right);

        return Math.max(hLeft, hRight) + 1;
    }

    public boolean contains(String key){
        return contains(root, key);
    }

    private boolean contains(TreeNode node, String key){
        if (node == null) return false;

        var cmp = key.compareTo(node.key);

        if (cmp == 0) return true;
        if (cmp < 0) return contains(node.left, key);
        return contains(node.right, key);
    }

    public void add(String key){
        if(isEmpty()){
            root = new TreeNode(key, null, null);
            size++;
            return;
        }

        var parent = root;
        var current = root;
        while(current != null){
            parent = current;
            var cmp = key.compareTo(root.key);
            if(cmp == 0) {
                return;
            }
            if(cmp < 0){
                current = parent.left;
            } else {
                current = parent.right;
            }
        }
        var node = new TreeNode(key, null, null);
        if(key.compareTo(parent.key) < 0){
            parent.left = node;
        } else {
            parent.right = node;
        }
        size++;
    }

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
                + " [label=\"<left> | <key> " + node.key + " | <right>\"];");
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
        if(node == null) return;

        writeNode(out, node);

        if(node.left != null){  
            writeLeftLink(out, node);
            writeTreeAux(out, node.left);
        }

        if(node.right != null){
          writeRightLink(out, node);  
          writeTreeAux(out, node.right);
        }

    }
}
