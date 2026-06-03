package fr.uge.rental;

import java.util.Objects;

public record Limousine(String model, int year, int nbSeats) implements Vehicle {

	public Limousine{
		Objects.requireNonNull(model);
		
		if(year < 1900) {
			throw new IllegalArgumentException("year < 1900");
		}
		
		if(nbSeats < 2) {
			throw new IllegalArgumentException("nbSeats < 2");
		}
	}
	
	
	public int careCost() {
		var cost = 600;
		
		if(year > 2000) {
			cost += (year - 2000) * 10;
		}
		
		return cost;
	}
	
	@Override
	public String toString() {
		return "Limousine " + model + ", " + year + " model, number of seats: " + nbSeats;
	}
}
