package fr.uge.blockbuster;

import java.io.IOException;
import java.nio.file.Path;
import java.time.Duration;

public class Main {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		var laserDisc = new LaserDisc("Jaws");
		var videoTape = new VideoTape("The Cotton Club", Duration.ofMinutes(128));
		var videoTape2 = new VideoTape("Mission Impossible", Duration.ofMinutes(110));
		
		var catalog = new Catalog();
	    catalog.add(laserDisc);
	    catalog.add(videoTape);
	    catalog.add(videoTape2);
	    //catalog.add(new LaserDisc("Mission Impossible"));  // exception !
	    IO.println(catalog.lookup("Jaws"));
	    IO.println(catalog.lookup("The Cotton Club"));
	    IO.println(catalog.lookup("Mission Impossible"));
	    IO.println(catalog.lookup("Indiana Jones"));
	    
	    var laserDiscText = laserDisc.toText();
	    var videoTapeText = videoTape.toText();
	    IO.println(laserDiscText);  // LaserDisc:Jaws
	    IO.println(videoTapeText);  // VideoTape:The Cotton Club:128
	    
	    var laserDisc2 = Article.fromText(laserDiscText);
	    var videoTape3 = Article.fromText(videoTapeText);
	    IO.println(laserDisc.equals(laserDisc2));  // true
	    IO.println(videoTape.equals(videoTape3));  // true
	    
	    var catalog2 = new Catalog();
	    catalog2.add(laserDisc);
	    catalog2.add(videoTape);
	    try {
			catalog2.save(Path.of("catalog.txt"));
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	    
	    var catalog3 = new Catalog();
	    catalog3.load(Path.of("catalog.txt"));
	    IO.println(catalog3.lookup("Jaws"));  // LaserDisc:Jaws
	    IO.println(catalog3.lookup("The Cotton Club"));  // VideoTape:The Cotton Club:128
	}

}
