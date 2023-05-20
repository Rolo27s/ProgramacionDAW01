/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package controles;

import java.util.Scanner;

/**
 *
 * @author Fran_Rodriguez
 */
public class controles {
    protected int numInt;
    protected float numFloat;
    protected String respuesta;

    public int getNumInt() {
        return numInt;
    }

    public float getNumFloat() {
        return numFloat;
    }

    public void setNumInt(int numInt) {
        this.numInt = numInt;
    }

    public void setNumFloat(float numFloat) {
        this.numFloat = numFloat;
    }

    public String getRespuesta() {
        return respuesta;
    }

    public void setRespuesta(String respuesta) {
        this.respuesta = respuesta;
    }
    
    
    /*Funcion de control de entrada. 3 parametros de entrada: 
    numero a revisar, numero minimo posible y numero maximo posible.*/
    public int controlInt(int min, int max) {
        while (numInt < min || numInt > max) {
            Scanner entradaC = new Scanner(System.in);
            System.out.println("Error en la opcion elegida...");
            System.out.print("Ud. puede elegir entre " + min + " y " + max + ": ");
            numInt = entradaC.nextInt();
        }
        return numInt;
    }

    /*Funcion de control de floats de entrada. 3 parametros de entrada: 
    numero a revisar, numero minimo posible y numero maximo posible.*/
    public float controlFloat(float min, float max) {
        while (numFloat < min || numFloat > max) {
            Scanner entradaC = new Scanner(System.in);
            System.out.println("Error en la opcion elegida...");
            System.out.print("Ud. puede elegir entre " + min + " y " + max + ": ");
            numFloat = entradaC.nextFloat();
        }
        return numFloat;
    }
    
    //Control de respuesta con S o N
    public String controlSN () {
        while(!"S".equals(respuesta) && !"s".equals(respuesta) && !"N".equals(respuesta) && !"n".equals(respuesta)) {
            Scanner entradaC = new Scanner(System.in);
            System.out.println("Opcion incorrecta. Debe escribir S o N");
            System.out.print("Ingrese opcion (S/N): ");
            respuesta = entradaC.nextLine();
        }
        return respuesta;
    }
}
