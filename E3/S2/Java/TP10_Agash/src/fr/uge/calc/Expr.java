package fr.uge.calc;

import java.util.Iterator;

public sealed interface Expr permits Add, Mul, Value {

//	int eval();

	public static Expr parse(Iterator<String> scanner) {

		var exp = scanner.next();

		return switch (exp) {
		case "+" -> new Add(parse(scanner), parse(scanner));

		case "*" -> new Mul(parse(scanner), parse(scanner));

		default -> new Value(Integer.parseInt(exp));
		};
	}
	
	public static int evalWithSwitch(Expr expr) {

	    return switch (expr) {
			case Value(int v)           -> v;
			case Add(Expr e1, Expr e2)  -> evalWithSwitch(e1) + evalWithSwitch(e2);
			case Mul(Expr e1, Expr e2)  -> evalWithSwitch(e1) * evalWithSwitch(e2);
    	};
	}
}
