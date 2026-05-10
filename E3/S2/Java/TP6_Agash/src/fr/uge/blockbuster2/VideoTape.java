package fr.uge.blockbuster2;

import java.time.Duration;
import java.util.Objects;

public record VideoTape(String name, Duration duration) implements Article {
	
	public static final String TYPE = "VideoTape";
	
	public VideoTape{
		Objects.requireNonNull(name);
		Objects.requireNonNull(duration);
	}

	@Override
    public String toText() {
        return TYPE + ":" + name + ":" + duration.toMinutes();
    }
}
