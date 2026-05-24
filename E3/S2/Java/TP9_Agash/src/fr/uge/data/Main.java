package fr.uge.data;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		var l = new LinkedLink<Integer>();
		
		l.add(3);
		l.add(2);
		l.add(1);
		
		IO.println(l.get(0));
		
		l.forEach(value -> IO.println(value));
		IO.println(l.toString());
		
		var l2 = new LinkedLink<String>();
    l2.add("hello");
    l2.add("world");
    l2.forEach(s -> IO.println("string " + s + " length " + ((String) s).length()));
	}

}
