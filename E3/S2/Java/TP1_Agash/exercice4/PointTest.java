import java.lang.Integer;

class PointTest {
	static void main(String[] args){
		int a;
		int b;
		a = 0;
		b = 5;
		var p = new Point(a, b);
		IO.println(p);
		var first = Integer.parseInt(args[0]);
		var second = Integer.parseInt(args[1]);
		IO.println("x="+ first + ", y=" + second);
		var p2 = new Point(first, second);
		var origin = new Point(0,0);
		var distance = p2.distance(origin);
		IO.println(p2);
		IO.println("dist = " + distance);
	}
}