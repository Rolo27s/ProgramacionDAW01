import java.util.Scanner;

public class CalculadoraGeometrica {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int opcion;
        
        do {
            // Mostrar menú principal
            System.out.println("=== MENÚ PRINCIPAL ===");
            System.out.println("1. Calcular perímetro");
            System.out.println("2. Calcular área");
            System.out.println("3. Calcular volumen");
            System.out.println("4. Salir");
            System.out.print("Ingresa una opción: ");
            opcion = scanner.nextInt();
            
            switch (opcion) {
                case 1:
                    calcularPerimetro();
                    break;
                case 2:
                    calcularArea();
                    break;
                case 3:
                    calcularVolumen();
                    break;
                case 4:
                    System.out.println("¡Hasta luego!");
                    break;
                default:
                    System.out.println("Opción inválida. Intenta de nuevo.");
                    break;
            }
        } while (opcion != 4);
        
        scanner.close();
    }
    
    public static void calcularPerimetro() {
        // Submenú para calcular perímetro
        Scanner scanner = new Scanner(System.in);
        int opcion;
        
        do {
            System.out.println("=== SUBMENÚ DE CÁLCULO DE PERÍMETRO ===");
            System.out.println("1. Cuadrado");
            System.out.println("2. Círculo");
            System.out.println("3. Triángulo");
            System.out.println("4. Volver al menú principal");
            System.out.print("Ingresa una opción: ");
            opcion = scanner.nextInt();
            
            switch (opcion) {
                case 1:
                    // Cálculo del perímetro de un cuadrado
                    System.out.print("Ingresa el lado del cuadrado: ");
                    double lado = scanner.nextDouble();
                    double perimetro = 4 * lado;
                    System.out.println("El perímetro del cuadrado es: " + perimetro);
                    break;
                case 2:
                    // Cálculo del perímetro de un círculo
                    System.out.print("Ingresa el radio del círculo: ");
                    double radio = scanner.nextDouble();
                    perimetro = 2 * Math.PI * radio;
                    System.out.println("El perímetro del círculo es: " + perimetro);
                    break;
                case 3:
                    // Cálculo del perímetro de un triángulo
                    System.out.print("Ingresa la longitud del primer lado del triángulo: ");
                    double lado1 = scanner.nextDouble();
                    System.out.print("Ingresa la longitud del segundo lado del triángulo: ");
                    double lado2 = scanner.nextDouble();
                    System.out.print("Ingresa la longitud del tercer lado del triángulo: ");
                    double lado3 = scanner.nextDouble();
                    perimetro = lado1 + lado2 + lado3;
                    System.out.println("El perímetro del triángulo es: " + perimetro);
                    break;
                case 4:
                    // Volver al menú principal
                    break;
                default:
                    System.out.println("Opción inválida. Intenta de nuevo.");
                    break;
            }
        } while (opcion != 4);
        
        scanner.close();
    }
    
    public static void calcularArea() {
    // Submenú para calcular área
      Scanner scanner = new Scanner(System.in);
      int opcion;
          do {
        System.out.println("=== SUBMENÚ DE CÁLCULO DE ÁREA ===");
        System.out.println("1. Cuadrado");
        System.out.println("2. Círculo");
        System.out.println("3. Triángulo");
        System.out.println("4. Volver al menú principal");
        System.out.print("Ingresa una opción: ");
        opcion = scanner.nextInt();

        switch (opcion) {
            case 1:
                // Cálculo del área de un cuadrado
                System.out.print("Ingresa el lado del cuadrado: ");
                double lado = scanner.nextDouble();
                double area = lado * lado;
                System.out.println("El área del cuadrado es: " + area);
                break;
            case 2:
                // Cálculo del área de un círculo
                System.out.print("Ingresa el radio del círculo: ");
                double radio = scanner.nextDouble();
                area = Math.PI * radio * radio;
                System.out.println("El área del círculo es: " + area);
                break;
            case 3:
                // Cálculo del área de un triángulo
                System.out.print("Ingresa la base del triángulo: ");
                double base = scanner.nextDouble();
                System.out.print("Ingresa la altura del triángulo: ");
                double altura = scanner.nextDouble();
                area = (base * altura) / 2;
                System.out.println("El área del triángulo es: " + area);
                break;
            case 4:
                // Volver al menú principal
                break;
            default:
                System.out.println("Opción inválida. Intenta de nuevo.");
                break;
        }
    } while (opcion != 4);

    scanner.close();
}

    public static void calcularVolumen() {
        // Submenú para calcular volumen
        Scanner scanner = new Scanner(System.in);
        int opcion;

        do {
            System.out.println("=== SUBMENÚ DE CÁLCULO DE VOLUMEN ===");
            System.out.println("1. Cubo");
            System.out.println("2. Esfera");
            System.out.println("3. Volver al menú principal");
            System.out.print("Ingresa una opción: ");
            opcion = scanner.nextInt();

            switch (opcion) {
                case 1:
                    // Cálculo del volumen de un cubo
                    System.out.print("Ingresa el lado del cubo: ");
                    double lado = scanner.nextDouble();
                    double volumen = lado * lado * lado;
                    System.out.println("El volumen del cubo es: " + volumen);
                    break;
                case 2:
                    // Cálculo del volumen de una esfera
                    System.out.print("Ingresa el radio de la esfera: ");
                    double radio = scanner.nextDouble();
                    volumen = (4/3) * Math.PI * radio * radio * radio;
                    System.out.println("El volumen de la esfera es: " + volumen);
                    break;
                case 3:
                    // Volver al menú principal
                    break;
                default:
                    System.out.println("Opción inválida. Intenta de nuevo.");
                    break;
            }
        } while (opcion != 3);

        scanner.close();
    }
}
