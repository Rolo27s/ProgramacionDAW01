/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package tiendaropadomingo;

import controles.Controles;
import java.util.Scanner;
import tablas.Producto;

/**
 *
 * @author FraN_
 */
public class TiendaRopaDomingo {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Controles control = new Controles();
        Producto prod = new Producto();

        // Constantes
        final String NOM_TABLA = "producto";
        final String N_CAMPO[] = {"id", "nombre", "talla", "precio", "stock", "tipoTejido"};

        boolean repetir = true;

        do {
            Scanner cin = new Scanner(System.in);
            Scanner pause = new Scanner(System.in);
            Scanner cinInfo = new Scanner(System.in);

            String info;
            Float p;
            //int s;

            System.out.println("Bienvenido a la tienda de ropa");
            System.out.println("------------------------------");
            System.out.println("1. Ver todo (Solo para empleados)");
            System.out.println("2. Ver producto");
            System.out.println("3. Modificar producto (Solo para empleados)");
            System.out.println("4. Eliminar producto (Solo para empleados)");
            System.out.println("5. Agregar producto (Solo para empleados)");
            System.out.println("6. Salir");
            System.out.print("Ingrese opcion: ");

            control.setNumInt(cin.nextInt());
            int opc = control.controlInt(1, 6);

            System.out.println("\n");

            switch (opc) {

                // Ver todo
                case 1:
                    prod.VerTodo(); //Uso exclusivo para empleados
                    break;

                // Buscar producto
                case 2:
                    System.out.println("Por donde quieres buscar?");
                    System.out.println("1. " + N_CAMPO[1]);
                    System.out.println("2. " + N_CAMPO[2]);
                    System.out.println("3. " + N_CAMPO[3]);
                    System.out.println("4. " + N_CAMPO[4]);
                    System.out.println("5. " + N_CAMPO[5]);
                    System.out.println("6. Volver");
                    System.out.print("Ingresa opcion: ");

                    control.setNumInt(cin.nextInt());
                    int opc2 = control.controlInt(1, 6);

                    System.out.print("Ingrese " + N_CAMPO[opc2] + ": ");
                    info = cinInfo.nextLine();

                    // El metodo Buscar devuelve el id del producto si se encuentra. Si no devuelve 0.
                    // Los parametros de entrada son el nombre del campo y la informacion que quieres Buscar en ese campo. Son dos Strings
                    // Tenemos tambien float e int, pero el programa entiende perfectamente estos ajustes.
                    // En caso de Buscar un tipo float, la sintaxis será usando el punto. Ej: 29.99
                    prod.Ver(N_CAMPO[opc2], info);
                    break;

                // Modificar producto 
                case 3:
                    //AVISO IMPORTANTE PARA INGRESAR CORRECTAMENTE INFORMACION. Documentacion disponible comentada.
                    System.out.println(" \n -> Aviso para empleado que modifica!");
                    System.out.println(" -> Todo será modificado en formato 'String', por lo que los precios se escriben con PUNTO");
                    System.out.println(" -> (Automaticamente el programa se encarga de ajustar formatos posteriormente\n");

                    System.out.println("Que quieres modificar?");
                    System.out.println("1. " + N_CAMPO[1]);
                    System.out.println("2. " + N_CAMPO[2]);
                    System.out.println("3. " + N_CAMPO[3]);
                    System.out.println("4. " + N_CAMPO[4]);
                    System.out.println("5. " + N_CAMPO[5]);
                    System.out.println("6. Volver");
                    System.out.print("Ingresa opcion: ");

                    control.setNumInt(cin.nextInt());
                    int opc3 = control.controlInt(1, 6);

                    System.out.print("Ingrese " + N_CAMPO[opc3] + " a modificar: ");
                    info = cinInfo.nextLine();

                    System.out.print("Ingrese la nueva informacion: ");
                    String updateInfo = cinInfo.nextLine();

                    prod.Modificar(N_CAMPO[opc3], info, updateInfo);
                    break;

                // Eliminar producto
                case 4:
                    //AVISO IMPORTANTE PARA INGRESAR CORRECTAMENTE INFORMACION. Documentacion disponible comentada.
                    System.out.println(" \n -> Aviso para empleado que elimina!");
                    System.out.println(" -> Todo será eliminado en formato 'String', por lo que los precios se escriben con PUNTO");
                    System.out.println(" -> (Automaticamente el programa se encarga de ajustar formatos posteriormente\n");

                    System.out.println("Que quieres eliminar?");
                    System.out.println("1. " + N_CAMPO[1]);
                    System.out.println("2. " + N_CAMPO[2]);
                    System.out.println("3. " + N_CAMPO[3]);
                    System.out.println("4. " + N_CAMPO[4]);
                    System.out.println("5. " + N_CAMPO[5]);
                    System.out.println("6. Volver");
                    System.out.print("Ingresa opcion: ");

                    control.setNumInt(cin.nextInt());
                    int opc4 = control.controlInt(1, 6);

                    System.out.print("Ingrese " + N_CAMPO[opc4] + " a eliminar: ");
                    info = cinInfo.nextLine();
                    
                    prod.Borrar(N_CAMPO[opc4], info);
                    break;

                // Agregar producto. Lo logico es agregar por el campo nombre. No veo mucho sentido usar otros campos aqui.
                case 5:
                    System.out.print("Nombre del producto a agregar: ");
                    info = cinInfo.nextLine();
                    prod.Agregar("nombre", info);
                    break;

                // Salir
                case 6:
                    repetir = false;
                    System.out.println("Saliendo del programa. Hasta otra!");
                    break;

                default:
                    throw new AssertionError();
            }

            if (repetir) {
                System.out.println("Ingrese cualquier tecla para continuar...");
                pause.nextLine();
            }

        } while (repetir);
    }

}
