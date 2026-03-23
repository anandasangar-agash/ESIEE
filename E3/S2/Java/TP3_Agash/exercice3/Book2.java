public class Book2 {
  private final String title;
  private final String author;

  public Book2(String title, String author) {
    this.title = title;
    this.author = author;
  }

  @Override
  public boolean equals(Object o){

    return o instanceof Book2 book 
      && book.title.equals(title)
      && book.author.equals(author);
  }
  
  public static void main(String[] args) {
    var book1 = new Book2("Da Vinci Code", "Dan Brown");
    var book2 = new Book2("Da Vinci Code", "Dan Brown");
    IO.println(book1.equals(book2));
  }
}
