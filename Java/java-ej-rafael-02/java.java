import java.util.Scanner; // Scanner

public class java {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int option;

        System.out.println("Hola mundo");

        String frase = "Hola que pasa";
        System.out.println(frase);

        String[] cars = {"Volvo", "Land Rober", "BMW", "Ford"};
        
        System.out.println("Dame una opcion (1-4): ");
        do {
            try {
                option = scanner.nextInt();
            } catch (Exception e) {
                System.out.println("Some went wrong...\n" + "Error type: " + e);
                option = -1; // option -1 to indicate the error.
                scanner.close();
                break;
            }

            if (option < 1 || option > 4) {
                System.out.println("Option out of range...");
                System.out.println("Dame una opcion (1-4): ");
            } else {
                System.out.println("You choose option " + option);
            }

        } while (option < 1 || option > 4);
        scanner.close();

        switch (option) {
            case 1:
                System.out.println("You choose " + cars[0]);
                break;
            case 2:
                System.out.println("You choose " + cars[1]);
                break;
            case 3:
                System.out.println("You choose " + cars[2]);
                break;
            case 4:
                System.out.println("You choose " + cars[3]);
                break;
            default:
                System.out.println("Your option was out of range");
                break;
        }
    }
}
