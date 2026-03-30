package fr.uge.manifest;
import java.util.*;

public record Passenger(String name, String destination) implements Ship{
	
	private static final int PASSENGER_PRICE = 10;
	
	public Passenger{
		Objects.requireNonNull(name, "name is null");
		Objects.requireNonNull(destination, "destination is null");
	}

	@Override
	public int price() {
		// TODO Auto-generated method stub
		return PASSENGER_PRICE;
	}
	
	@Override
	public String toString() {
		return name + " to " + destination;
	}

}
