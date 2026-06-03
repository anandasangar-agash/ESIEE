
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

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

        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < 1000; i++) {
            list.add(i);
        }

        Collections.shuffle(list);

        int[] tab1 = new int[1000];
        for (int i = 0; i < 1000; i++) {
            tab1[i] = list.get(i);
        }

        int[] tab2 = Arrays.copyOf(tab1, tab1.length);

        MyHeap.heapSortByInsertion(tab1);

        Arrays.sort(tab2);

        if (Arrays.equals(tab1, tab2)) {
            IO.println("Les tableaux sont égaux : tri correct !");
        } else {
            IO.println("Les tableaux diffèrent : erreur dans le tri.");
        }

        var heap1 = new MyHeap(1000);

        for (int i = 0; i < 1000; i++) {
            heap1.add(rand.nextInt());

            if (!heap1.isHeap()) {
                IO.println("The array does not represent a heap");
                return;
            }
        }

        IO.println("Ok!");
    }
}