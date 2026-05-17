package fr.uge.hotel;

import java.util.*;

public class Main {

	public static void main(String[] args) {
	    var hotel = new Hotel("paradisio", List.of(
	            new Room("blue", 100, 100),
	            new Room("yellow", 110, 200),
	            new Room("fuchsia", 120, 300),
	            new Room("red", 100, 200),
	            new Room("green", 100, 200)
	    ));

	    IO.println(hotel.roomInfo());
	    
	    IO.println(hotel.roomInfoSortedByFloor());

	    IO.println(hotel.averagePrice());

	    IO.println(hotel.roomForPrice1(250));

	    IO.println(hotel.roomForPrice2(250));
	    
	    var hotel2 = new Hotel("fantastico", List.of(
	            new Room("queen", 1, 200),
	            new Room("king", 1, 500)
	    ));

	    IO.println(Hotel.expensiveRoomNames(List.of(hotel, hotel2)));

	    IO.println(hotel.roomInfoGroupedByFloor());

	    IO.println(hotel.roomInfoGroupedByFloorInOrder());
	}

}
