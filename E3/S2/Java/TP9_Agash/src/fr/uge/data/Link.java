package fr.uge.data;

record Link(Object value, Link next) {

	public static void main() {
		
		var link2 = new Link(144, null);
		var link = new Link(13, link2);
		IO.println(link);
	}
}
