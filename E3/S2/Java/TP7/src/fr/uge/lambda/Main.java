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
	}

}
