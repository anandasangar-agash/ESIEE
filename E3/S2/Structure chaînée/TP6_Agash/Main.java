public class Main {
    static void main() {
        var heap = new MyHeap(20);

        int[] values = {3, 4, 2, 5, 1, 6};

        for (var value : values) {
            IO.println("add(" + value + ")");
            heap.add(value);
            heap.printTree();
        }

        while (!heap.isEmpty()) {
            IO.println(heap.remove());
            heap.printTree();
        }
    }
}