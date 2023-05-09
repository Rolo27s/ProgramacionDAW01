/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
Ejercicio 55
Diseñar la clase alumno que tiene los siguientes atributos de manera que se pueda almacenar sus
objetos en la base de datos Instituto que tenga una tabla que se llame Alumno con estos atributos:
• id: es el número identificativo único asignado a cada alumno, que sirve para distinguirlo de
forma unívoca.
• nombre: del alumno. Su tamaño nunca supera los 30 caracteres. En caso de tener una longitud
superior se acortará.
• notaMedia: La calificación media del alumno en el curso.
• curso: cadena formada por dos caracteres que identifican el curso donde está matriculado el
alumno.
Realizar un menú para poder crear, leer, actualizar y borrar un alumno.
 */
package ejercicio55;

import ConexionConBD.conexionConLaBDInstituto;
import Clases.Alumno;

import java.util.Scanner;
import java.sql.Statement;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

/**
 *
 * @author Fran_Rodriguez
 */
public class Ejercicio55 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int opc;

        Scanner entrada = new Scanner(System.in);
        Scanner entradaP = new Scanner(System.in);
        Alumno objeto1 = new Alumno();
        

        do {
            

            //Genero el codigo requerido que interactua con la base de datos
            System.out.println("MENU DE GESTION DE BASE DE DATOS");
            System.out.println("--------------------------------");
            System.out.println("1. Crear");
            System.out.println("2. Leer");
            System.out.println("3. Actualizar");
            System.out.println("4. Borrar");
            System.out.println("5. Salir");
            System.out.print("Ingresa una opcion: ");
            opc = entrada.nextInt();

            //Llamo a la funcion control para controlar que el int es correcto
            opc = control(opc, 1, 5);

            //Ver
            objeto1.leerTodo();
            
            //System Pause virtual
            System.out.println("Ingresa cualquier caracter para continuar ...");
            entradaP.nextLine();
            System.out.println("");
        } while (opc != 5);

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
