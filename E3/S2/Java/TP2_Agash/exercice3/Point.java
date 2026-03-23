record Point(double x, double y){

    record Polar(double r, double theta) {}
	
	static Point staticMilieu(Point p1, Point p2) {
        return new Point(
            (p1.x() + p2.x()) / 2,
            (p1.y() + p2.y()) / 2
        );
    }

	Point instanceMilieu(Point p) {
        return new Point(
            (this.x + p.x) / 2,
            (this.y + p.y) / 2
        );
    }

    Polar toPolar(){
        double r = Math.sqrt(x*x + y*y);
        double theta = Math.atan2(y, x);
        return new Polar(r, theta);
    }
}