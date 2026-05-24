package fr.uge.data;

record Link<E>(E value, Link<E> next) {

	public static void main() {
		
		var link2 = new Link<Integer>(144, null);
		var link = new Link<Integer>(13, link2);
		IO.println(link);
	}
}
