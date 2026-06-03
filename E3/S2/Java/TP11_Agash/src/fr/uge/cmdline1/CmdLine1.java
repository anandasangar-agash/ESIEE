package fr.uge.cmdline1;

//import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Objects;
import java.util.Optional;

public class CmdLine1 {
	
//	private static Option asOptionInfo(String option) {
//		
//		if(option.equals("-v") || option.equals("--verbose")) {
//			return new Option(option, OptionInfo.VERBOSE);
//		}
//		
//		if(option.equals("-a") || option.equals("--all")) {
//			return new Option(option, OptionInfo.ALL);
//		}
//		
//		return null;
//	}
//
//	
//	public static List<Argument> parseCmdLine(String ...texts){
//		Objects.requireNonNull(texts);
//		var list = new ArrayList<Argument>();
//		for(var text: texts) {
//			if(asOptionInfo(text) != null) {
//				list.add(asOptionInfo(text));
//			} else {
//				list.add(new Argument(text));
//			}
//		}
//		
//		return List.copyOf(list);
//	}
	
	public static List<Argument> parseCmdLine(String...strings){
		Objects.requireNonNull(strings);
		return Arrays.stream(strings).map(CmdLine1::asArgument).toList();
	}
	
	private static Optional<OptionInfo> asOptionInfo(String text){
		return switch(text) {
		case "-v" -> Optional.of(OptionInfo.VERBOSE);
		case "--verbose" -> Optional.of(OptionInfo.VERBOSE);
		case "-a" -> Optional.of(OptionInfo.ALL);
		case "--all" -> Optional.of(OptionInfo.ALL);
		default -> Optional.empty();
		};
	}
	
	private static Argument asArgument(String text) {
//		var info = asOptionInfo(text);
//		return info == null ? new Argument(text) : new Option(text, info);
		return asOptionInfo(text).<Argument>map(info -> new Option(text, info)).orElseGet(() -> new Argument(text));
	}
	
	public static void checkCmdLine(List<Argument> list) {
		if(list.stream().distinct().count() != list.size()) {
			throw new IllegalArgumentException();
		}
	}
}
