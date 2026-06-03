package fr.uge.cmdline1;

import java.util.Objects;

public class Option extends Argument {
	
	private final OptionInfo info;
	
	public Option(String text, OptionInfo info){
		Objects.requireNonNull(text);
		Objects.requireNonNull(info);
		
		super(text);
		this.info = info;
	}
	
	@Override
	public String toString(){
		return "Option{ text:'" + text +"', info: " + info + " }";
	}
	
	@Override
	public boolean equals(Object o) {
		return o instanceof Option op && info.equals(op.info) && getClass() == o.getClass();
	}
	
	@Override
	public int hashCode() {
		return info.hashCode() ^ 3141592;
	}
}
