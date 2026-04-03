public class MyHashMap {

    private Entry[] buckets;
    private int size;
    private static final double MAX_LOAD_FACTOR = 0.75;
    private static final int GROWTH_FACTOR = 2;

    private static class Entry {
        final String key;
        int value;
        Entry next;

        Entry(String key, int value, Entry next) {
            if (key == null) {
                throw new IllegalArgumentException("key must not be null");
            }
            this.key = key;
            this.value = value;
            this.next = next;
        }
    }

    public MyHashMap(int capacity) {
        if (capacity <= 0) {
            throw new IllegalArgumentException("capacity must be positive");
        }
        buckets = new Entry[capacity];
        size = 0;
    }

    public MyHashMap(){
        this(10);
    }

    private void ensureCapacity() {
        if ((double) size / buckets.length < MAX_LOAD_FACTOR){
            return;
        }

        var capacity = buckets.length * GROWTH_FACTOR;

        var tmp = new Entry[capacity];

        for(int i = 0; i < buckets.length; i++){
            var current = buckets[i];
            while(current != null){
               tmp[i] = new Entry(current.key, current.value, tmp[i])
            }
        }
    }

    public boolean isEmpty(){
        return size == 0;
    }

    public int size(){
        return size;
    }

    public void print() {
        IO.println("MyHashMap(size = " + size + ")");
        for (int i = 0; i < buckets.length; i++) {
            StringBuilder line = new StringBuilder();
            line.append(i).append(": ");
            var current = buckets[i];
            while (current != null) {
                line.append("(").append(current.key).append(", ").append(current.value).append(")");
                if (current.next != null) {
                    line.append(" -> ");
                }
                current = current.next;
            }
            IO.println(line.toString());
        }
    }

    private int indexOf(String key){
        return Math.floorMod(key.hashCode(), buckets.length);
    }

    private Entry findEntry(String key){
        var index = indexOf(key);
        var current = buckets[index];
        while(current != null){
            if(current.key.equals(key)) return current;
            current = current.next;
        }
        return null;
    }

    public boolean containsKey(String key){
        return findEntry(key) != null;
    }

    public int get(String key){
        var entry = findEntry(key);
        if (entry == null){
            throw new IllegalArgumentException("key not found : " + key);
        }
        return entry.value;
    }

    public int getOrDefault(String key, int value){
        var entry = findEntry(key);
        if(entry == null) return value;
        return entry.value;
    }

    public void put(String key, int value){
        var index = indexOf(key);
        var current = buckets[index];
        while(current != null){
            if(current.key.equals(key)){
                current.value = value;
                return;
            }
            current = current.next;
        }
        buckets[index] = new Entry(key, value, buckets[index]);
        size++;
    }
}
