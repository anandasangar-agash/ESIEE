package fr.uge.manifest;

import java.util.*;

public class Manifest {

	private final ArrayList<Ship> elements;
	
	private final HashSet<String> identifiers = new HashSet<>();
	
	public Manifest(){
		elements = new ArrayList<>();
	}
	
	public void add(Ship element) {
	    Objects.requireNonNull(element, "element is null");
	    
	    String id;
	    
	    if (element instanceof Passenger passenger) {
	        id = passenger.name();
	    } else if (element instanceof Container container) {
	        id = container.bic();
	    } else {
	        throw new IllegalStateException("Unknown element type");
	    }
	    
	    if (!identifiers.add(id)) {
	        throw new IllegalStateException("Duplicate identifier: " + id);
	    }
	    
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
	
//	public void checkIsInvalid() {
//	    var seen = new HashSet<String>();
//	    
//	    for (var element : elements) {
//	        String id;
//	        
//	        if (element instanceof Passenger passenger) {
//	            id = passenger.name();
//	        } else if (element instanceof Container container) {
//	            id = container.bic();
//	        } else {
//	            continue;
//	        }
//	        
//	        if (!seen.add(id)) {
//	            throw new IllegalStateException("Duplicate identifier found: " + id);
//	        }
//	    }
//	}
	
	@Override
	public String toString() {
		var sb = new StringBuilder();
		for(var i = 0; i < elements.size(); i++) {
			sb.append((i+1) + ". " + elements.get(i) + "\n");
		}
		
		return sb.toString();
	}
}
