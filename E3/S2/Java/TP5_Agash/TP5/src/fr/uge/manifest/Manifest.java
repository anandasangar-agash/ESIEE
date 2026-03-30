package fr.uge.manifest;

import java.util.*;

public class Manifest {

	private final ArrayList<Ship> elements;
	
	public Manifest(){
		elements = new ArrayList<>();
	}
	
	public void add(Ship element) {
		Objects.requireNonNull(element, "element is null");
		elements.add(element);
	}
	
	public int totalPrice() {
		var total = 0;
		for(var element : elements) {
			total += element.price();
		}
		return total;
	}
	
	public ArrayList<Ship> toDestination(String destination){
		var list = new ArrayList<Ship>();
		for(var element : elements) {
			if(element.destination().equals(destination)) {
				list.add(element);
			}
		}
		return list;
	}
	
	@Override
	public String toString() {
		var sb = new StringBuilder();
		for(var i = 0; i < elements.size(); i++) {
			sb.append((i+1) + ". " + elements.get(i) + "\n");
		}
		
		return sb.toString();
	}
}
