package fr.uge.rental;

import java.util.ArrayList;
import java.util.Objects;
import java.util.function.IntPredicate;
import java.util.stream.Collectors;

public class Rental {
	
	private final int currentYear;
	private final ArrayList<Vehicle> vehicles;
	
	public Rental(int currentYear) {
		if(currentYear < 1900) {
			throw new IllegalArgumentException("current year < 1900 !!");
		}
		
		this.currentYear = currentYear;
		
		this.vehicles = new ArrayList<>();
	}
	
	public void add(Vehicle car) {
		Objects.requireNonNull(car);
		vehicles.add(car);
	}
	
//	public int totalCareCost() {
//		var cost = 0;
//		for(var car: cars) {
//			cost += car.careCost();
//		}
//		return cost;
//	}
	
	public int totalCareCost() {
		
		return vehicles.stream().mapToInt(Vehicle::careCost).sum();
	}
	
	public int countInYears(IntPredicate predicate) {
		var count = 0;
		
		vehicles.forEach(vehicle -> {
			if(predicate.test(vehicle.year())) {
				count = count + 1;
			}
		});
		
		return count;
	}
	
//	@Override
//	public String toString() {
//		var sb = new StringBuilder();
//		sb.append("Rental (" + currentYear + ")\n");
//		var separator = "===== \n";
//		for(var car : cars) {
//			sb.append(separator).append(car + "\n");
//			separator = "----- \n";
//		}
//		return sb.toString();
//	}
	
	@Override
	public String toString() {
		var string = vehicles.stream().map(Vehicle::toString).collect(Collectors.joining("\n----- \n"));
		
		return "Rental (" + currentYear + ")\n" + "===== \n" + string.toString();
	}

}
