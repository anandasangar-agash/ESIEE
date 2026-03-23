import java.util.Objects;

public record Book(String title, String author){

    // Book(String title, String author){
    //     Objects.requireNonNull(title);
    //     Objects.requireNonNull(author);
    //
    //     this.title = title;
    //     this.author = author;
    // }

    public Book {
        Objects.requireNonNull(title, "title cannot be null");
        Objects.requireNonNull(author, "author cannot be null"); 
    }

    Book(String title){
        this(title, "<no author>");
    }

    Book withTitle(String title) {
        return new Book(title, this.author);
    }

    boolean isFormTheSameAuthor(Book book){
        return this.author.equals(book.author);
    }

    @Override
    public String toString(){
        return this.title() + " by " + this.author();
    }
}