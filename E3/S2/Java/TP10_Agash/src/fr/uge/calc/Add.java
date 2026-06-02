package fr.uge.calc;

import java.util.Objects;

public record Add(Expr exp1, Expr exp2) implements Expr {

	public Add{
		Objects.requireNonNull(exp1);
		Objects.requireNonNull(exp2);
	}
	
//	@Override
//	public int eval() {
//		return exp1.eval() + exp2.eval();
//	}
}
