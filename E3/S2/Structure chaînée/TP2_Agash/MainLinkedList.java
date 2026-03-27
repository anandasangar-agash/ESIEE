public class MainLinkedList {

    static void main() {

        var list = new MyLinkedList();

        IO.println("Size: " + list.size());

        list.print();

        list.addLast("Gotta");
        list.addLast("Catch");
        list.addLast("'Em");
        list.addLast("All");

        list.print();
 
        IO.println("Size: " + list.size());

        IO.println(list.get(3));

        list.removeFirst();

        list.print();

        list.removeLast();

        list.print();

        list.addLast("Gotta");

        list.print();

        list.set(2, "All");

        list.print();
    }
}
