package fr.uge.thread;

public class TurtleRace {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		IO.println("On your mark!");
	  try {
			Thread.sleep(15_000);
		} catch (InterruptedException e) {
			throw new AssertionError(e);
		}
	  IO.println("Go!");
	  int[] times = {25_000, 10_000, 20_000, 5_000, 50_000, 60_000};
	  for (int i = 0; i < times.length; i++) {
      int turtleId = i;
      int sleepTime = times[i];

      Thread.ofPlatform().daemon().start(() -> {
                try {
                    Thread.sleep(sleepTime);
                    IO.println("Turtle " + turtleId + " has finished");
                } catch (InterruptedException e) {
                	throw new AssertionError(e);
                }
            });
     }
	}

}
