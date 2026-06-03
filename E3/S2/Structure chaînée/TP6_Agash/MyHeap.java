public class MyHeap {
    private int[] tree;
    private int size;

    public MyHeap(int capacity) {
        tree = new int[capacity];
        size = 0;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int size() {
        return size;
    }

    private static void swap(int[] tab, int i, int j) {
        var tmp = tab[i];
        tab[i] = tab[j];
        tab[j] = tmp;
    }

    static int parent(int i){
        return (i-1) / 2;
    }

    static int left(int i){
        return (2*i + 1);
    }

    static int right(int i){
        return (2*i + 2);
    }

    public void add(int value){
       
        tree[size] = value;
        var enfant = size;
        var parent = parent(enfant);
        while(enfant > 0 && tree[parent] > tree[enfant]){
            swap(tree, parent, enfant);
            enfant = parent;
            parent = parent(enfant);
        } 
        
        size++;
    }

    public void printTree(){

        for(var i = 0; i < size; i++){
            IO.println(tree[i]);
        }
    }

    public int remove(){

        if (size == 0) {
            throw new IllegalStateException("Heap is empty");
        }

        var min = tree[0];
        tree[0] = tree[size - 1];
        size--;
        var current = 0;

        while (true) {
            var left = left(current);
            var right = right(current);
            if (left >= size) {
                break;
            }
            var smallest = left;
            if (right < size && tree[right] < tree[left]) {
                smallest = right;
            }
            if (tree[current] <= tree[smallest]) {
                break;
            }
            swap(tree, current, smallest);
            current = smallest;
        }

        return min;
    }

    public static void heapSortByInsertion(int[] tab) {
        MyHeap heap = new MyHeap(tab.length);
        
        for (int value : tab) {
            heap.add(value);
        }
        
        for (int i = 0; i < tab.length; i++) {
            tab[i] = heap.remove();
        }
    }

    public boolean isHeap() {
        for (int i = 1; i < size; i++) {
            if (tree[parent(i)] > tree[i]) {
                return false;
            }
        }
        return true;
    }
}