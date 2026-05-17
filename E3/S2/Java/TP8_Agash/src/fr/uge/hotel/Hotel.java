package fr.uge.hotel;

import java.util.*;
import java.util.stream.Collectors;

public record Hotel(String name, List<Room> rooms) {

    public Hotel {
        Objects.requireNonNull(name, "name is null");
        Objects.requireNonNull(rooms, "rooms is null");

        rooms = List.copyOf(rooms);
    }


    public String roomInfo() {
        return rooms.stream()
                .map(Room::name)
                .collect(Collectors.joining(", "));
    }


    public String roomInfoSortedByFloor() {
        return rooms.stream()
                .sorted(Comparator.comparingInt(Room::floor))
                .map(Room::name)
                .collect(Collectors.joining(", "));
    }

    public double averagePrice() {
        return rooms.stream()
                .mapToLong(Room::price)
                .average()
                .orElse(Double.NaN);
    }


    public Optional<Room> roomForPrice1(long price) {
        return rooms.stream()
                .filter(room -> room.price() < price)
                .sorted(Comparator.comparingLong(Room::price).reversed())
                .findFirst();
    }

    public Optional<Room> roomForPrice2(long price) {
        return rooms.stream()
                .filter(room -> room.price() < price)
                .max(Comparator.comparingLong(Room::price));
    }

    public static List<String> expensiveRoomNames(List<Hotel> hotels) {
        return hotels.stream()
                .flatMap(hotel ->
                        hotel.rooms().stream()
                                .sorted(Comparator.comparingLong(Room::price).reversed())
                                .limit(2)
                                .map(Room::name)
                )
                .toList();
    }

    public Map<Integer, List<Room>> roomInfoGroupedByFloor() {
        return rooms.stream()
                .collect(Collectors.groupingBy(Room::floor));
    }

    public Map<Integer, List<Room>> roomInfoGroupedByFloorInOrder() {
        return rooms.stream()
                .collect(Collectors.groupingBy(
                        Room::floor,
                        TreeMap::new,
                        Collectors.toList()
                ));
    }
}
