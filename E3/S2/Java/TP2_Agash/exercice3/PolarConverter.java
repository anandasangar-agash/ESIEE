class PolarConverter {
    static void main() {
      var point = new Point(3,4);

      var polar = point.toPolar();
      IO.println("Coordonnées cartésiennes: " + point);
      IO.println("Coordonnées polaires: (" + polar.r() + "," + polar.theta() + ")");
    }
}