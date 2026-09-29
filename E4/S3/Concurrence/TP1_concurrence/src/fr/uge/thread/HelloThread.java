package fr.uge.thread;

import java.lang.Thread;

public class HelloThread {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		for(var i = 0; i < 4; i++) {
			var index = i;
			Thread.ofPlatform().start(() -> {
				for (int j = 0; j <= 5000; j++) {
					var index2 = j;
				IO.println("hello " + index + " " + index2);
				}
			});
		}
	}

}
