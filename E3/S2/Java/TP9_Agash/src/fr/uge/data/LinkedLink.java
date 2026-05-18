package fr.uge.data;

import java.util.Objects;
import java.util.StringJoiner;
import java.util.function.Consumer;

public class LinkedLink {

	private Link head;
	
	private int size;
	
	public void add(Object value) {
		Objects.requireNonNull(value);
		var link = new Link(value, head);
		head = link;
		size++;
	}
	
	public int size() {
		return size;
	}
	
	public Object get(int i) {
//		if (size == 0) {
//            throw new IllegalStateException("get(i) on empty list");
//        } ==> Pas nécessaire car ça renvoie déjà une erreur

        if (i < 0 || i >= size){
            throw new IndexOutOfBoundsException();
        }
        var current = head;
        for(int n = 0; n < i; n++){
            current = current.next();
        }
        return current.value();
	}
	
	
	public void forEach(Consumer<Object> consumer) {
		var current = head;
		while(current != null) {
			consumer.accept(current.value());
			current = current.next();
		}
	}
	
	@Override
	public String toString() {
		var joiner = new StringJoiner(" --> ");
		
		var current = head;
		while(current != null) {
			joiner.add(current.value().toString());
			current = current.next();
		}
		
		return joiner.toString();
	}
}
