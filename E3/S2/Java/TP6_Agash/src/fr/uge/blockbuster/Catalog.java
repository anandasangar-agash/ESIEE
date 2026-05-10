package fr.uge.blockbuster;

import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
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
		
		var name = articles.get(article.name());
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
	
	public void save(Path path, Charset charset) throws IOException {
	    try (var writer = Files.newBufferedWriter(path, charset)) {
	        for (var article : articles.values()) {
	            writer.write(article.toText());
	            writer.newLine();
	        }
	    }
	}

    public void save(Path path) throws IOException {
        save(path, StandardCharsets.UTF_8);
    }

    public void load(Path path, Charset charset) throws IOException {
        try (var reader = Files.newBufferedReader(path, charset)) {
            String line;
            while ((line = reader.readLine()) != null) {
                add(Article.fromText(line));
            }
        }
    }

    public void load(Path path) throws IOException {
        load(path, StandardCharsets.UTF_8);
    }

}
