public class MyArrayList {

    private String[] data;
    private int size;
    private static final int GROWTH_FACTOR = 2;

    public MyArrayList() {
        this(50);
        size = 0;
    }

    public MyArrayList(int initialCapacity){
        if(initialCapacity <= 0){
            throw new IllegalArgumentException();
        }
        data = new String[initialCapacity];
    }

    private void ensureCapacity(){
        if(size < data.length)
            return;

        var capacity = data.length * GROWTH_FACTOR;

        var tmp = new String[capacity];

        for(int i=0; i < size; i++){
            tmp[i] = data[i];
        }

        data = tmp;
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public void addFirst(String value){
        if(size == 50){
            ensureCapacity();
        }
        
        data[size] = value;
        for(int i = size; i > 0; i--){
            var tmp = data[i-1];
            data[i-1] = data[i];
            data[i] = tmp;
        }
        size++;
    }

    public void addLast(String value){
        if(size == 50){
            ensureCapacity();
        }

        data[size] = value;
        size++;
    }

    public String removeFirst() {
        if (size == 0) {
            throw new IllegalStateException("removeFirst() on empty array list");
        }

        var value = data[0];

        for (int i = 1; i < size; i++) {
            data[i - 1] = data[i];
        }

        size--;
        data[size] = null;
        return value;
    }

    public String removeLast(){
        if (size == 0) {
            throw new IllegalStateException("removeLast() on empty array list");
        }

        var value = data[size-1];
        size--;
        data[size] = null;
        return value;
    }

    public boolean contains(String value){

        for(int i=0; i < size; i++){
            if(data[i] == value){
                return true;
            }
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

        return data[i];
    }

    public void set(int i, String value){
         if (size == 0) {
            throw new IllegalStateException("get(i) on empty list");
        }

        if (i < 0 || i >= size){
            throw new IndexOutOfBoundsException();
        }

        data[i] = value;
    }

    public void print() {
        IO.print("[");
        for (int i = 0; i < size; i++) {
            if (i > 0) {
                IO.print(", ");
            }
            IO.print(data[i]);
        }
        IO.println("]");
    }
}
