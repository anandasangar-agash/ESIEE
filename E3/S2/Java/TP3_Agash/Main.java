class Main{
    
    static void main(String[] args){

        // Exercice 1
        var book = new Book("Da Vinci Code", "Dan Brown");
        IO.println(book.title() + ' ' + book.author());
        var unknownBook = new Book("Unknown author");
        IO.println(unknownBook);
        var book2 = book.withTitle("New title");
        IO.println(book2);

        //Exercice 2
        var b1 = new Book("Da Java Code", "Duke Brown");
        var b2 = b1;
        var b3 = new Book("Da Java Code", "Duke Brown");

        IO.println(b1 == b2);
        IO.println(b1 == b3);
        IO.println("with equals method :");
        IO.println(b1.equals(b2));
        IO.println(b1.equals(b3));

        IO.println("test for isFormTheSameAuthor() : ");
        var book1 = new Book("Da Vinci Code", "Dan Brown");
        book2 = new Book("Angels & Demons", new String("Dan Brown"));
        IO.println(book1.isFormTheSameAuthor(book2));

        var javaBook = new Book("Da Java Code", "Duke Brown");
        IO.println(javaBook);
    }
}