/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
/*
Ejercicio 51
Definir una clase que permita controlar un sincronizador digital de emisora FM;
concretamente, se desea dotar al controlador de una interfaz que permita subir(up) o
bajar(down) la frecuencia (en saltos de 0,5 MHz) y mostrar la frecuencia sintonizada en
un momento dado(display). Supondremos que el rango de frecuencia para manejar
oscila entre los 80 MHz y los 108 MHz y que, al inicio, el controlador sintonice la
frecuencia indicada en el constructor o 80 MHz por defecto. Si durante una operación
de subida o bajada se sobrepasa uno de los dos límites, la frecuencia sincronizada
debe pasar a ser la del extremo contrario. Escribe un pequeño programa que principal
para probar su funcionamiento.

Para poder probarlo:
1) Iniciamos nuestro sincronizador a 107 MHz, luego subiremos la frecuencia 4
veces seguidas. ¿Qué frecuencia es la sé que muestra? 80.5
2) Iniciamos nuestro sincronizador a 80.5 MHz, luego bajaremos la frecuencia 3
veces seguidas. ¿Qué frecuencia es la sé que muestra? 107.5
3) Iniciamos nuestro sincronizador a 200 MHz. ¿Qué frecuencia es la sé que
muestra? 180 y un aviso.
*/
package ejercicio51;

import java.util.Scanner;

/**
 *
 * @author Fran_Rodriguez
 */
public class Ejercicio51 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner entrada = new Scanner (System.in);
        Scanner pause = new Scanner (System.in);
        double frecInicial;
        int opc; 
        int numP;
        
        // TODO code application logic here
        System.out.println("PROGRAMA DE CONTROL DE SINCRONIZADOR DIGITAL");
        System.out.println("--------------------------------------------");
        System.out.println("Generamos el control de la nueva emisora");
        System.out.print("En que frecuencia quieres comenzar (80,0 - 108,0)?: ");
        frecInicial = entrada.nextDouble();
        
        //Genero el objeto alpha de clase sincronizador y llamo al setter
        sincronizador alpha = new sincronizador();
        
        //El control interno en el metodo se encargara de ajustar la frecuencia inicial a parametros correctos
        alpha.setSincronizador(frecInicial);
        
        System.out.println("Parametros guardados correctamente");
        
        
        do {            
            System.out.println("MENU DE OPCIONES");
            System.out.println("----------------");
            System.out.println("1. Subir frecuencia");
            System.out.println("2. Bajar frecuencia");
            System.out.println("3. Mostrar frecuencia actual");
            System.out.println("4. Salir");
            System.out.print("Elige una opcion: ");
            opc = entrada.nextInt();
            
            while (opc < 1 || opc > 4) {
                System.out.println("Opcion incorrecta...");
                System.out.println("----------------");
                System.out.println("1. Subir frecuencia");
                System.out.println("2. Bajar frecuencia");
                System.out.println("3. Mostrar frecuencia actual");
                System.out.println("4. Salir");
                System.out.print("Elige una opcion: ");
                opc = entrada.nextInt();
            }
            
            switch (opc) {
                case 1 -> {
                    System.out.print("Cuantas veces quiere subir la frecuencia? :");
                    numP = entrada.nextInt();
                    
                    //Control para pulsaciones positivas o 0
                    while(numP < 0) {
                        System.out.println("No puede pulsar de forma negativa.");
                        System.out.print("Cuantas veces quiere subir la frecuencia? :");
                        numP = entrada.nextInt();
                    }
                    
                    //Una vez se cuantas veces tengo que pulsar, tengo el argumento del metodo a llamar
                    alpha.frecuenciaUp(numP);
                    
                    //Muestro la frecuencia actual tras la sincronizacion
                    System.out.println("Frecuencia actual: " + alpha.getFrecuencia());
                }
                case 2 -> {
                    System.out.print("Cuantas veces quiere bajar la frecuencia? :");
                    numP = entrada.nextInt();
                    
                    //Control para pulsaciones positivas o 0
                    while(numP < 0) {
                        System.out.println("No puede pulsar de forma negativa.");
                        System.out.print("Cuantas veces quiere bajar la frecuencia? :");
                        numP = entrada.nextInt();
                    }
                    
                    //Una vez se cuantas veces tengo que pulsar, tengo el argumento del metodo a llamar
                    alpha.frecuenciaDown(numP);
                    
                    //Muestro la frecuencia actual tras la sincronizacion
                    System.out.println("Frecuencia actual: " + alpha.getFrecuencia());
                }
                case 3 -> System.out.println("LA FRECUENCIA ACTUALMENTE ES LA EMISORA " + alpha.getFrecuencia());
                case 4 -> System.out.println("Saliendo del programa...");
                default -> throw new AssertionError();
            }
            
            System.out.println("Pulse INTRO para continuar...\n\n");
            pause.nextLine();
        } while (opc != 4);
    }
    
}
