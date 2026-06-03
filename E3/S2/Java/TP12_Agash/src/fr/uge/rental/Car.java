package fr.uge.rental;

import java.util.Objects;

public record Car(String nom, int year, boolean offRoad) implements Vehicle {
	
	public Car{
		Objects.requireNonNull(nom);
		if(year < 1900) {
			throw new IllegalArgumentException("year < 1900 !");
		}
	}
	
	public Car(String nom, int year){
		this(nom, year, false);
	}
	
	public int careCost() {
		var cost = 100;
		
		if(offRoad) cost += 50;
		
		if(year > 2000) {
			cost += (year - 2000) * 10;
		}
		
		return cost;
	}
	
	@Override
	public String toString() {
		return "Car " + nom + ", " + year + " model (off-road: " + (offRoad ? "yes" : "no") + ")";
	}

}
