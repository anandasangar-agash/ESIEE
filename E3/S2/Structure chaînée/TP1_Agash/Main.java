import java.util.Random;
public class Main {

    static void main() {

        // var list = new MyLinkedList();

        // IO.println("Size: " + list.size());

        // list.print();

        // list.addFirst(3);
        // list.addFirst(2);
        // list.addFirst(1);

        // list.print();
 
        // IO.println("Size: " + list.size());

        IO.println("----------Exercice 2----------");
        MyLinkedList list = new MyLinkedList();

        IO.println("Empty? " + list.isEmpty());

        int[] values = {1, 2, 3};
        list.addFromArray(values);

        list.print();

        IO.println("Contains 3? " + list.contains(3));
        IO.println("Contains 1? " + list.contains(1));
        IO.println("Size: " + list.size());

        IO.println("----------Exercice 3----------");
        var rand = new Random();

        MyLinkedList list2 =  new MyLinkedList();

        int i;
        for (i = 0; i < 50000; i++){
            list2.addFirst(rand.nextInt(100));
        }

        var start = System.nanoTime();
        var copySlowList = list2.copySlow();
        var end = System.nanoTime();
        IO.println("copySlow() - time (ms): " + (end - start) / 1_000_000.0);

        start = System.nanoTime();
        var copyFastList = list2.copyFast();
        end = System.nanoTime();
        IO.println("copyFast() - time (ms): " + (end - start) / 1_000_000.0);

        IO.println("----------Exercice 4----------");
        var testEqual = list.equals(copyFastList);
        IO.println("Test 1 : " + testEqual);
        testEqual = list2.equals(copyFastList);
        IO.println("Test 2 : " + testEqual);

        list = new MyLinkedList();
        for (i = 0; i < 100; i++){
            list.addFirst(rand.nextInt(100));
        }

        var copy = list.copyFast();

        IO.println("list.equals(copy) = " + list.equals(copy));
        IO.println("list == copy = " + (list == copy));
    }
}
