package fr.uge.lambda;

import java.util.List;

public class Main {

	public static void main(String[] args) {
		
		var list = List.of("hello", "lambda");
	    var list2 = Lambdas.upperCaseAll(list);
	    IO.println(list2);
	    
	    var list3 = List.of("foo", "bar", "foo", "baz", "bar", "foo");
        var result = Lambdas.occurrences(list3);
        IO.println(result);
        
        var list4 = List.of("hello", "lambda", "world");
        var filtered = Lambdas.filter(list4, s -> s.length() > 5);
        IO.println(filtered); // ["lambda"]
        
        var list5 = List.of("*hello", "**world", "***!");
        var filtered2 = Lambdas.filter(list5,Lambdas.startsWithNStars(3));
        IO.println(filtered2); // [ "***!"]
        var filtered3 = Lambdas.filter(list5,Lambdas.startsWithNStars(2));
        IO.println(filtered3); // [ "**world","***!"]
	}

}
