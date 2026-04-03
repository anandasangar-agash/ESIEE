public class Main{

    static void main(){

        var map = new MyHashMap();
        map.put("souris", 1);
        map.put("chat", 3);
        map.put("chien", 2);
        map.put("mouton", 2);
        map.put("loup", 5);
        map.print();
        
        IO.println("there is mouton ? " + map.containsKey("mouton"));
        IO.println("there is lapin ? " + map.containsKey("lapin"));
        IO.println("chat values : " + map.get("chat"));
        IO.println("test getOrDefault with lapin and value default 95: " + map.getOrDefault("lapin", 95));
        
        map.put("chien", 6);
        map.print();
    } 
}