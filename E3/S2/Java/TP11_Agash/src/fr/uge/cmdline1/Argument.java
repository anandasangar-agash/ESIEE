package fr.uge.cmdline1;

import java.util.Objects;

public class Argument {
	
	/*private*/ final String text;

	public Argument(String text){
		Objects.requireNonNull(text);
		this.text = text;
		super();
	}
	
	@Override
	public String toString(){
		return "Argument{ text:'" + text +"' }";
	}
	
	@Override
	public boolean equals(Object o) {
		return o instanceof Argument a && text.equals(a.text) && getClass() == o.getClass();
	}
	
	@Override
	public int hashCode() {
		return text.hashCode() ^ 3141592;
	}
}
