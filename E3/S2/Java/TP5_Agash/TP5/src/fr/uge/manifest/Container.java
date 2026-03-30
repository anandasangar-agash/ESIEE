package fr.uge.manifest;
import java.util.Objects;
public record Container(String bic, int weight, String destination) implements Ship {

	private static final int PRICE_FACTOR = 2;
	public Container{
		Objects.requireNonNull(bic, "bic is null");
		Objects.requireNonNull(destination, "destination is null");
		
		if(weight < 0) {
			throw new IllegalArgumentException("weight < 0");
		}
	}

	@Override
	public int price() {
		// TODO Auto-generated method stub
		return weight*PRICE_FACTOR;
	}
	
	@Override
	public String toString() {
		return bic + " " + weight + "kg to " + destination;
	}
}
