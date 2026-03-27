public class MainArrayList {

    static void main() {

        var tab = new MyArrayList();

        IO.println("Size: " + tab.size());

        tab.print();

        IO.println(tab.isEmpty());

        tab.addLast("Gotta");
        tab.addLast("Catch");
        tab.addLast("'Em");
        tab.addLast("All");

        tab.print();
        IO.println(tab.isEmpty());
        IO.println("Size: " + tab.size());

        tab.removeLast();
        tab.print();
        IO.println("Size: " + tab.size());

        tab.addFirst("All");
        tab.print();
        IO.println("Size: " + tab.size());

        IO.println(tab.get(2));
        tab.set(2, "Alice");
        tab.print();
    }
}
