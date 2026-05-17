package fr.uge.lambda;

import java.util.*;
import java.util.function.*;

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
	
	public static Map<String, List<Actor>> actorGroupByFirstName(List<Actor> actors) {
        var map = new HashMap<String, List<Actor>>();

        actors.forEach(actor ->
            map.computeIfAbsent(actor.firstName(), key -> new ArrayList<>())
               .add(actor)
        );

        return map;
    }
	
	public static Map<String, List<Actor>> actorGroupBy(List<Actor> actors, Function<Actor, String> classifier) {

        var map = new HashMap<String, List<Actor>>();

        actors.forEach(actor -> {
            var key = classifier.apply(actor);

            map.computeIfAbsent(key, k -> new ArrayList<>())
               .add(actor);
        });

        return map;
    }
	
	public static List<String> filter(List<String> list, Predicate<String> predicate ){
		 var result = new ArrayList<String>();
		 
		 list.forEach(s -> {
			 if(predicate.test(s)) {
				 result.add(s);
			 }
		 });
		 
		 return result;
	}
	
	public static Predicate<String> startsWithNStars(int n){
		return s -> {
			int count = 0;
			
			while (count < s.length() && s.charAt(count) == '*') {
				count++;
			}
			
			return count >= n;
		};
	}
}
