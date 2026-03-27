package fr.uge.library;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		var book = new Book("Da Vinci Code", "Dan Brown");
	    var library = new Library();
	    library.add(book);
	    IO.println(library.findByTitle("Da Vinci Code"));
	    var book2 = new Book("Angels & Demons", "Dan Brown");
	    library.add(book2);
	    IO.println(library.toString());
	    
	    var library2 = new Library();
	    library2.add(new Book("Da Vinci Code", "Dan Brown"));
	    library2.add(new Book("Angels & Demons", "Dan Brown"));
	    IO.println("Library 2");
	    IO.println("Before removeAllBooksFromAuthor()");
	    IO.println(library2.toString());
	    library2.removeAllBooksFromAuthor("Dan Brown");
	    IO.println("After removeAllBooksFromAuthor()");
	    IO.println(library2.toString());
	}

}
