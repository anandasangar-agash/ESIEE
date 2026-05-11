package fr.uge.lambda;

import java.util.*;

public class Lambdas {
	
	public static List<String> upperCaseAll(List<String> list) {
        var copy = new ArrayList<>(list);
        copy.replaceAll(s -> s.toUpperCase(Locale.ROOT));
        return copy;
    }
	
	public static Map<String, Integer> occurrences(List<String> list) {
        var map = new HashMap<String, Integer>();

        // list.forEach(s -> map.merge(s, 1, (a, b) -> a + b));
        list.forEach(s -> map.merge(s, 1, Integer::sum));

        return map;
    }
}
