package fr.uge.library;
//import java.util.ArrayList;
import java.util.LinkedHashMap;

public class Library {
	
//	private final ArrayList<Book> books;
//	
//	public Library() {
//		books = new ArrayList<Book>();
//	}
//	
//	public void add(Book book) {
//		books.add(book);
//	}
//	
//	public Book findByTitle(String title) {
//// Il ne sert à rien car on retourne déjà null si il est empty
////		if(books.isEmpty()) {
////			return null;
////		}
//		
//		for(var element: books) {
//			if(element.title().equals(title)) {
//				return element;
//			}
//		}
//		
//		return null;
//	}
	
	private final LinkedHashMap<String, Book> books;
	
	public Library() {
		books = new LinkedHashMap<String, Book>();
	}
	
	public void add(Book book) {
		books.put(book.title(), book);
	}
	
	public Book findByTitle(String title) {
		return books.get(title);
	}
	
	public void removeAllBooksFromAuthor(String author) {
		
//		var iterator = books.values().iterator();
//		while(iterator.hasNext()) {
//			var book = iterator.next();
//			if(book.author().equals(author)) {
//				iterator.remove();
//			}
//		}
		
		books.values().removeIf(book -> book.author().equals(author));
	}

	@Override
	public String toString() {
	    StringBuilder sb = new StringBuilder();
	    
	    for (var book : books.values()) {
	        sb.append(book.toString()).append("\n");
	    }
	    
	    return sb.toString();
	}

}
