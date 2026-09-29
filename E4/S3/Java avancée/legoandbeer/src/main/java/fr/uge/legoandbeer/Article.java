package fr.uge.legoandbeer;

import java.util.Locale;
import java.util.Objects;

public sealed interface Article permits Beer, Lego {

	static Article parseArticle(String line) {
        Objects.requireNonNull(line);

        var tab = line.split(",", -1);

        if (tab.length != 3) {
            throw new IllegalArgumentException("invalid article: " + line);
        }

        var article = tab[0];
        var quantity = Integer.parseInt(tab[1]);
        var value = tab[2];

        return switch (article) {
            case "lego" -> new Lego(quantity, value);
            case "beer" -> new Beer(quantity, BeerKind.valueOf(value.toUpperCase(Locale.ROOT)));
            default -> throw new IllegalArgumentException("Unexpected value : " + article);
        };
    }
}
