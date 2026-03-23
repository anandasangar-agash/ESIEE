public class MyLinkedList {

    private static class ListNode {
        private int value;
        private ListNode next;

        ListNode(int value, ListNode next) {
            this.value = value;
            this.next = next;
        }
    }

    private ListNode head;
    private int size;

    public MyLinkedList() {
        head = null;
        size = 0;
    }

    public int size() {
        return size;
    }

    public void addFirst(int value) {
        var newNode = new ListNode(value, head);
        head = newNode;
        size++;
    }

    public void print() {
        var current = head;

        while (current != null) {
            IO.print(current.value + " -> ");
            current = current.next;
        }

        IO.println("null");
    }

    // A COMPLETER ...

    public boolean isEmpty(){
        return head == null;
    }

    public int removeFirst(){

        if (head == null) {
            throw new IllegalStateException("removeFirst() on empty list");
        }

        var previous = head;
        head = head.next;
        size--;
        return previous.value;
    }

    public boolean contains(int value){

        if(isEmpty()){
            return false;
        }

        var current = head;
        while(current != null){
            if(current.value == value) return true;
            current = current.next;
        }

        return false;
    }

    public void addFromArray(int[] values){

        int i;
        for(i = values.length-1 ; i >= 0; i--){
            this.addFirst(values[i]);
        }
    }

    public void addLast(int value){
        var newNode =  new ListNode(value, null);
        if (head == null) {
            head = newNode;
        } else {
            var current = head;  
            while(current.next != null){
                current = current.next;
            }
            current.next = newNode;
        }
        size++;
    }

    public MyLinkedList copySlow(){
        var list = new MyLinkedList();
        var current = head;
        while(current != null){
            list.addLast(current.value);
            current = current.next;
        }
        return list;
    }

    public MyLinkedList copyFast() {
        var list = new MyLinkedList();

        if (isEmpty()) {
            return list;
        }

        var current = head;
        var newNode = new ListNode(current.value, null);
        list.head = newNode;
        list.size++;

        var tail = list.head;

        current = current.next;
        while (current != null) {
            var nextNode = new ListNode(current.value, null);
            tail.next = nextNode; 
            tail = nextNode; 
            current = current.next;
            list.size++;
        }

        return list;
    }

    public boolean equals(MyLinkedList other){

        if(this.size() != other.size()){
            return false;
        }

        var current = head;
        var current_other = other.head;
        while(current != null){
            if(current.value != current_other.value){
                return false;
            }

            current = current.next;
            current_other = current_other.next;
        }

        return true;
    }
}
