package fr.uge.manifest.application;
import fr.uge.manifest.*;

public class Application {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		var container1 = new Container("DSVX 123456 5", 500, "Germany");
	    IO.println(container1.bic());
	    IO.println(container1.weight());
	    IO.println(container1.destination());
	    
	    var container2 = new Container("MSCU 789012 3", 400, "Italy");
	    var container3 = new Container("ONEZ 345678 2", 200, "Austria");
	    var manifest1 = new Manifest();
	    manifest1.add(container2);
	    manifest1.add(container3);
	    
	    var passenger1 = new Passenger("Nicolas F", "France");
	    var container4 = new Container("OOCL 098765 0", 350, "England");
	    var manifest2 = new Manifest();
	    manifest2.add(passenger1);
	    manifest2.add(container4);
	    IO.println(manifest2.totalPrice());
	    
	    var manifest3 = new Manifest();
	    manifest3.add(new Container("OOCL 098765 0", 350, "England"));
	    manifest3.add(new Passenger("Jane D", "US"));
	    IO.println(manifest3);
	    
	    var manifest4 = new Manifest();
	    manifest4.add(new Container("HAPC 543210 3", 450, "Russia"));
	    manifest4.add(new Container("BICU 123456 5", 200, "China"));
	    manifest4.add(new Container("CMAU 432109 6", 125, "Russia"));
	    manifest4.add(new Passenger("Ana K","Russia"));
	    var embargoed = manifest4.toDestination("Russia");
	    IO.println(embargoed);
	}

}
