package fr.uge.blockbuster;

import java.util.Objects;

public record LaserDisc(String name) implements Article {

	public static final String TYPE = "LaserDisc";
	
	public LaserDisc{
		Objects.requireNonNull(name);
	}
	
	@Override
    public String toText() {
        return TYPE + ":" + name;
    }
}
