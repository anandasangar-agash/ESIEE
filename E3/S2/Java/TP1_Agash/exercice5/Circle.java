record Circle(Point center, double radius){

	Circle {
        if (radius < 0) {
            throw new IllegalArgumentException("radius must be positive");
        }
        if (center == null) {
            throw new NullPointerException("center cannot be null");
        }
    }

	static void main() {
    	var circle = new Circle(new Point(0, 0), 1.0);
      	IO.println(circle);
      	var perimeter = circle.perimeter();
      	IO.println("Perimeter : " + perimeter);
      	var area = circle.area();
      	IO.println("Area : " + area);
      	var circle2 = new Circle(new Point(0, 5), 1.0);
      	var dist = circle.distanceCircle(circle2);
      	IO.println("dist = " + dist);
		var circle3 = new Circle(new Point(5, 5), 1.0);
		IO.println("Intersect with (5,5,r=1) : " + circle.intersect(circle3));
		var circle4 = new Circle(new Point(3, 2), 7.0);
		IO.println("Intersect with (3,2,r=7) : " + circle.intersect(circle4));
		IO.println(circle);
		var circle5 = new Circle(new Point(0,0), -1.0);
    }

    double perimeter(){
    	return ((2*radius) * Math.PI);
    }

    double area (){
    	return (radius * radius * Math.PI);
    }

    double distanceCircle(Circle c){
    	return (center.distance(c.center));
    }

	boolean intersect(Circle c){
		return distanceCircle(c) < radius + c.radius;
	}

	public String toString(){
		return "from " + center.toString() + " with radius " + radius;
	}
}