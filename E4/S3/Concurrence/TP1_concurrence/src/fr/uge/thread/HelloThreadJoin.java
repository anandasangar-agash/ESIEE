package fr.uge.thread;

import java.lang.Thread;
import java.util.ArrayList;

public class HelloThreadJoin {

	public static void main(String[] args) throws InterruptedException {
		// TODO Auto-generated method stub
		Runnable runnable = () -> {
			var subThreads = new ArrayList<Thread>();
			for(var i = 0; i < 4; i++) {
				var index = i;
				var thread = Thread.ofPlatform().start(() -> {
					for (int j = 0; j <= 5000; j++) {
						var index2 = j;
					IO.println("hello " + index + " " + index2);
					}
				});
				subThreads.add(thread);
			}
			
			for(var t : subThreads) {
				try {
					t.join();
				} catch (InterruptedException e) {
					throw new AssertionError(e);
				}
			}
		};
		var thread = Thread.ofPlatform().start(runnable);
        thread.join();
        IO.println("Le thread a fini son Runnable");
	}

}
