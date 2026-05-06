package fr.uge.blockbuster;

import java.time.Duration;

public interface Article {

	String name();
	String toText();
	
	public static Article fromText(String text) {
        var parts = text.split(":");
        return switch (parts[0]) {
            case LaserDisc.TYPE -> new LaserDisc(parts[1]);
            case VideoTape.TYPE -> new VideoTape(parts[1], Duration.ofMinutes(Long.parseLong(parts[2])));
            default -> throw new IllegalArgumentException("Unknown article type: " + parts[0]);
        };
    }

}
