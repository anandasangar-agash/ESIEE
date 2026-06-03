package fr.uge.cmdline1;

import java.util.List;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		var argument1 = new Argument("foo.txt");
		var argument2 = new Argument("bar.png");
		IO.println(argument1);  // Argument{ text:'foo.txt' }
		IO.println(argument2);  // Argument{ text:'bar.png' }
		
		List<Argument> arguments1 = CmdLine1.parseCmdLine("foo.txt", "bar.png");
	    IO.println(arguments1);  // [Argument{ text:'foo.txt' }, Argument{ text:'bar.png' }]
	    
	    var option1 = new Option("--verbose", OptionInfo.VERBOSE);
	    var option2 = new Option("-v", OptionInfo.VERBOSE);
	    IO.println(option1);  // Option{ text: '--verbose', info: VERBOSE }
	    IO.println(option2);  // Option{ text: '-v', info: VERBOSE }
	    
	    var arguments2 = CmdLine1.parseCmdLine("-v", "bar.png");
	    IO.println(arguments2);  // [Option{ text: '-v', info: VERBOSE }, Argument{ text:'bar.png' }]
	}

}
