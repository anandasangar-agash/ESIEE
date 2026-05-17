package fr.uge.stream;

import java.util.*;

public class Streams {
	public static List<String> namesOfTheAdults(List<Person> persons) {
        return persons.stream()
                .filter(person -> person.age() >= 18)
                .map(Person::name)
                .toList();
    }
	
	public static long sumAge(List<Person> persons) {
        return persons.stream()
                .filter(person -> person.name().startsWith("C"))
                .mapToLong(Person::age)
                .sum();
    }

	  public static void main(String[] args) {
	    var persons = List.of(
	        new Person("Ana", 21),
	        new Person("John", 17),
	        new Person("Liv", 29),
	    	new Person("Charles", 35));
	    var names = namesOfTheAdults(persons);
	    IO.println(names);
	    IO.println(sumAge(persons));
	  }
	}
