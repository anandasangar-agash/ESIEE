package fr.uge.rogue;
import java.util.Scanner;

public class RogueEncapsulated {
    
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
        var purse = Price.randomBelow(new Price(100, 0));
        var scanner = new Scanner(System.in);

        var potions = 0;
        while (true) {
            IO.println("You have " + purse + " gold pieces.");
            var price = Price.randomBelow(new Price(10, 0));
            IO.println("Do you want to buy a potion of healing for " + price +"?");
            var choice = ask(scanner);
            if (choice.equals("quit")){
                break;
            }
            if (choice.equals("no")){
                continue;
            }
            // buy potion
            if (purse.isLowerThan(price)){
              IO.println("You don't have enough gold pieces.");
              continue;
            }
            potions++;
            purse = purse.substract(price);
        }
        IO.println("You manage to acquire " + potions + " potions with " + purse + " gold pieces remaining.");
    }
}
