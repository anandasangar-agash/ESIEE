package fr.uge.legoandbeer;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Objects;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public final class LegoAndBeer {
	
	private LegoAndBeer() {}
	
	public static List<Article> readArticlesFromFile(Path file) throws IOException {
    Objects.requireNonNull(file);
    var list = new ArrayList<Article>();
    try (var lines = Files.lines(file)) {
        lines.filter(line -> !line.isBlank()).map(line -> Article.parseArticle(line)).forEach(list::add);
    }
    return List.copyOf(list);
  }
	
	static void printReceipt(List<Article> articles) {
		articles.stream().collect(Collectors.teeing(
	      Collectors.summingLong(article -> switch (article) {
	        case Lego(int quantity, String name) -> (long) quantity * name.length() * 20;
	        case Beer(int quantity, BeerKind kind) ->
	            kind == BeerKind.BLONDE ? quantity : 3L * quantity;
	      }),
	      Collectors.flatMapping(
	          article -> switch (article) {
	            case Lego lego -> Stream.of(lego);
	            case Beer _ -> null;
	          },
	          Collectors.maxBy(Comparator.comparingInt((Lego lego) -> lego.name().length() * 20))),
	      (sum, maxLego) -> {
	        IO.println("sum: " + sum);
	        maxLego.ifPresent(lego -> IO.println("max lego: " + lego.name()));
	        return null;
	      }));
	}

	public static void main(String[] args) {
	  if (args.length != 1) {
	    System.err.println("Usage: java LegoAndBeer <file>");
	    System.exit(1);
	    return;
	  }
	  List<Article> articles;
	  try {
	    articles = readArticlesFromFile(Path.of(args[0]));
	  } catch (IOException | IllegalArgumentException e) {
	    System.err.println(e.getMessage());
	    System.exit(1);
	    return;
	  }
	  printReceipt(articles);
	}
}
