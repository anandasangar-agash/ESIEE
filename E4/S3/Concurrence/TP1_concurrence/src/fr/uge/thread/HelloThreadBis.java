package fr.uge.thread;

public class HelloThreadBis {

  public static void println(String s) {
    for (var i = 0; i < s.length(); i++) {
      IO.print(s.charAt(i));
    }
    IO.print("\n");
  }

  public static void main(String[] args) {
    int nbThreads = 5;

    for (int j = 0; j < nbThreads; j++) {
      int actuallyFinal = j;
      Thread.ofPlatform().start(() -> {
        for (int i = 0; i < 5000; i++) {
          println("hello " + actuallyFinal + " " + i);
        }
      });
    }
  }
}
