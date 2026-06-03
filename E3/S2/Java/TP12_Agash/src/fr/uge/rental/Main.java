package fr.uge.rental;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		var mustang = new Car("Ford Mustang", 2014);
		IO.println(mustang);
		// Car Ford Mustang, 2014 model (off-road: no)
		var beetle = new Car("Coccinelle", 1985, true);
		IO.println(beetle);
		// Car Coccinelle, 1985 model (off-road: yes)
		
		var rental = new Rental(2023);
		var ds = new Car("Citroen DS", 1970);
	    rental.add(mustang);
	    rental.add(beetle);
	    rental.add(ds);
	    IO.println(rental);
	    
	    IO.println(mustang.careCost());
	    // 240
	    IO.println(beetle.careCost());
	    // 150
	    
	    IO.println(rental.totalCareCost());
	    // 490
	    
	    var limo = new Limousine("Cadillac", 2012, 13);
	    IO.println(limo.careCost());
	    IO.println(limo);
	    
	    rental.add(limo);
	    IO.println(rental.totalCareCost());
	}

}
