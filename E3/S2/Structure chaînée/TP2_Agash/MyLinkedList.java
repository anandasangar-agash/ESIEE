public class MyLinkedList {

    private static class ListNode {
        private String value;
        private ListNode next;

        ListNode(String value, ListNode next) {
            this.value = value;
            this.next = next;
        }
    }

    private ListNode head;
    private ListNode tail;
    private int size;

    public MyLinkedList() {
        head = null;
        tail = null;
        size = 0;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int size() {
        return size;
    }

    public void addFirst(String value) {
        var newNode = new ListNode(value, head);
        head = newNode;
        if (tail == null) {
            tail = newNode;
        }
        size++;
    }

    public void addLast(String value) {
        if (head == null){
            var newNode = new ListNode(value, null);
            head = newNode;
            tail = head;
        } else {
            var newNode = new ListNode(value, null);
            tail.next = newNode;
            tail = tail.next;
        }
        size++;
    }

    public String removeFirst() {
        if (size == 0) {
            throw new IllegalStateException("removeFirst() on empty list");
        }

        var value = head.value;
        head = head.next;
        if (head == null) {
            tail = null;
        }
        size--;
        return value;
    }

    public String removeLast() {
        if (size == 0) {
            throw new IllegalStateException("removeLast() on empty list");
        }

        if (size == 1) {
            var value = head.value;
            head = null;
            tail = null;
            size--;
            return value;
        }

        var current = head;
        while (current.next != tail) {
            current = current.next;
        }

        var value = tail.value;
        tail = current;
        tail.next = null;
        size--;
        return value;
    }

    public boolean contains(String value) {
        var current = head;

        while (current != null) {
            if (current.value.equals(value)) {
                return true;
            }
            current = current.next;
        }

        return false;
    }

    public String get(int i){
        if (size == 0) {
            throw new IllegalStateException("get(i) on empty list");
        }

        if (i < 0 || i >= size){
            throw new IndexOutOfBoundsException();
        }
        var current = head;
        for(int n = 0; n < i; n++){
            current = current.next;
        }
        return current.value;
    }

    public void set(int i, String value){
        if (size == 0) {
            throw new IllegalStateException("set(i, value) on empty list");
        }

        if (i < 0 || i >= size){
            throw new IndexOutOfBoundsException();
        }

        var current = head;
        for(int n = 0; n < i; n++){
            current = current.next;
        }
        current.value = value;
    }

    public void print() {
        var current = head;

        while (current != null) {
            IO.print(current.value + " -> ");
            current = current.next;
        }

        IO.println("null");
    }
}
