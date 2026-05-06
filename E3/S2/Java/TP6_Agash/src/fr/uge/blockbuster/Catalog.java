package fr.uge.blockbuster;

import java.io.IOException;
import java.nio.file.*;
import java.time.Duration;
import java.util.*;

public class Catalog {
	
	private final HashMap<String, Article> articles;
	
	public Catalog() {
		this.articles = new HashMap<>();
	}
	
	public void add(Article article) {
		Objects.requireNonNull(article);
		
		var name = articles.getOrDefault(article.name(), null);
		if(name != null) throw new IllegalArgumentException("This article is already exists !!!");
		
		articles.put(article.name(), article);
	}
	
	public Article lookup(String name) {
		Objects.requireNonNull(name);
		
		return articles.get(name);
	}
	
	public List<Article> videoTapesLessThan(Duration duration){
		var list = new ArrayList<Article>();
		for(var article: articles.values()) {
			switch(article) {
			case VideoTape v : if(v.duration().toMinutes() < duration.toMinutes()) list.add(article);
			case LaserDisc _ : continue;
			default:
				break;
			}
		}
		return List.copyOf(list);
	}
	
	public void save(Path path) throws IOException {
        var lines = new ArrayList<String>();
        for (var article : articles.values()) {
            lines.add(article.toText());
        }
        Files.write(path, lines);
    }
	
	public static Catalog load(Path path) throws IOException {
        var catalog = new Catalog();
        for (var line : Files.readAllLines(path)) {
            if (!line.isBlank()) {
                catalog.add(Article.fromText(line));
            }
        }
        return catalog;
    }

}
