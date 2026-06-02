package fr.uge.calc.main;

import fr.uge.calc.Add;
import fr.uge.calc.Expr;
import fr.uge.calc.Mul;
import fr.uge.calc.Value;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Expr expression = new Add(new Value(2), new Value(3));
		Expr expression2 = new Add(new Mul(new Value(2), new Value(3)), new Value(4));

//		IO.println(expression.eval());
//		IO.println(expression2.eval());
		var scanner = new Scanner("+ * 2 3 4");
		var exp = Expr.parse(scanner);
		IO.println(exp);
//		IO.println(exp.eval());
		IO.println(Expr.evalWithSwitch(expression));
        IO.println(Expr.evalWithSwitch(expression2));
		IO.println(Expr.evalWithSwitch(exp));
	}
	
	

}
