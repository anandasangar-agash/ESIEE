record Point(int x, int y){
	double distance(Point p){
		double dx = p.x - this.x;
		double dy = p.y - this.y;
		return Math.sqrt(dx * dx + dy * dy);
	}

	public String toString() {
		return "(" + x + "," + y + ")";
	}
}