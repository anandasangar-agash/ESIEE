import java.util.Scanner;
import java.util.concurrent.ThreadLocalRandom;

public class Rogue {
    
    public static String ask(Scanner scanner){

        while(true){
            IO.println("Type yes (to buy), no (to skip) or quit (to leave)");
            var choice = scanner.nextLine();
            if (choice.equals("yes") || choice.equals("no") || choice.equals("quit")){
                return choice;
            }
            IO.println("Invalid choice, please try again.");
        }
    }

    public static void main(String[] args) {
        // retrieve a random number generator
        var rng = ThreadLocalRandom.current(); 
        // purse contains the amount of gold pieces the player has
        // it is initialized with a random number between 0 and 99
        var purse = new Price(rng.nextInt(100), rng.nextInt(100));
        var scanner = new Scanner(System.in);

        var potions = 0;
        while (true) {
            IO.println("You have " + purse + " gold pieces.");
            var price = new Price(rng.nextInt(10), rng.nextInt(13));
            IO.println("Do you want to buy a potion of healing for " + price + " gold pieces?");
            var choice = ask(scanner);
            if (choice.equals("quit")){
                break;
            }
            if (choice.equals("no")){
                continue;
            }
            // buy potion
            if (!purse.canAfford(price)){
                IO.println("You don't have enough gold pieces.");
                continue;
            }
            potions++;
            purse = purse.subtract(price);
        }
        IO.println("You manage to acquire " + potions + " potions with " + purse + " gold pieces remaining.");
    }
}