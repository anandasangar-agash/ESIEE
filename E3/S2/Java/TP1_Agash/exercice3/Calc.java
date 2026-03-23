import java.util.Scanner; 

    class Calc { 
    	static void main(String[] args) {
    		var scanner = new Scanner(System.in);
    		IO.print("Saissiez un nombre : ");
    		var value1 = scanner.nextInt();
    		IO.print("Saissiez un deuxième nombre : ");
    		var value2 = scanner.nextInt();
    		var somme = value1 + value2;
    		IO.println("La somme des deux vaut : " + somme);
    		var difference = value1 - value2;
    		IO.println("La difference des deux vaut : " + difference);
    		var produit = value1 * value2;
    		IO.println("Le produit des deux vaut : " + produit);
    		var quotient = value1 / value2;
			IO.println("Le quotient des deux vaut : " + quotient);
			var reste = value1 % value2;
			IO.println("Le reste de la division vaut : " + reste);
    		scanner.close();
    	}
    }