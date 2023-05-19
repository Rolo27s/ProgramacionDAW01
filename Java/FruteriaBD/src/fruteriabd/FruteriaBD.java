/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package fruteriabd;
import conexionBD.Conexion;
import java.util.Scanner;
import tablas.Productos;

/**
 *
 * @author FraN_
 */
public class FruteriaBD {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int opc;
        
        Scanner entrada = new Scanner(System.in);
        Productos objeto1 = new Productos();
        
        System.out.println("MENU PRINCIPAL: productos");
        System.out.println("-------------------------");
        System.out.println("1. Mostrar producto");
        System.out.println("2. Agregar producto");
        System.out.println("3. Modificar producto");
        System.out.println("4. Borrar producto");
        System.out.println("-------------------------");
        System.out.println("5. Vender producto");
        System.out.println("6. Reponer producto");
        System.out.println("-------------------------");
        System.out.println("7. SALIR DEL PROGRAMA");
        System.out.println("-------------------------");
        System.out.print("Ingrese una opcion: ");
        opc = entrada.nextInt();
        // Control de la opcion del menu
        opc = control(opc, 1, 7);
        
        
        switch (opc) {
            case 1:
                objeto1.mostrarProducto("stock", "12");
                break;
            case 2:
                //Los parametros de entrada son los de busqueda para comprobar si existe o no dicha informacion
                //En este caso concreto info es el nombre de la fruta, pe "Platano"
                //Una vez se verifique si existe o no se seguira ingresando info dentro del metodo
                //Argumento nombre de la fruta
                objeto1.agregarProducto("Melon");
                break;
            case 3:
                //Argumento nombre de la fruta
                objeto1.modificarProducto("Platano");
                break;
            case 4:
                //Argumento nombre de la fruta
                objeto1.borrarProducto("Melocoton");
                break;
            default:
                throw new AssertionError();
        }
           
    }
    
    /*Funcion de control de entrada. 3 parametros de entrada: 
    numero a revisar, numero minimo posible y numero maximo posible.*/
    static int control(int opc, int min, int max) {
        while (opc < min || opc > max) {
            Scanner entradaC = new Scanner(System.in);
            System.out.println("Error en la opcion elegida...");
            System.out.print("Ud. puede elegir entre " + min + " y " + max + ": ");
            opc = entradaC.nextInt();
        }

        return opc;
    }
}
