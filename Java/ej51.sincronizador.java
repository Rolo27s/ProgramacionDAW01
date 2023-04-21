/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package ejercicio51;
/**
 *
 * @author Fran_Rodriguez
 */
public class sincronizador {
    double frecuencia = 80.0;
    final double fMin = 80.0;
    final double fMax = 108.0;
    final double fSalto = 0.5;
    
    //Constructor vacio.
    public sincronizador(){
    }
    
    //Getter de frecuencia
    public double getFrecuencia() {
        return this.frecuencia;
    }
    
    //Constructor con frecuencia
    public void setSincronizador(double _frecuencia) {
        //Control de frec max y min
        if (_frecuencia < fMin) {
            System.out.println("AVISO. Frecuencia minima sobrepasada. Se selecciona la frecuencia minima posible: " + fMin);
            this.frecuencia = fMin;
        }
        else if (_frecuencia > fMax) {
            System.out.println("AVISO. Frecuencia maxima sobrepasada. Se selecciona la frecuencia maxima posible: " + fMax);
            this.frecuencia = fMax;
        }
        else {
            this.frecuencia = _frecuencia;
        }
    }
        
    //Metodo que se encarga de subir la frecuencia 0.5 MHz, el argumento es el numero de veces que se pulsa virtualmente el boton de subir frecuencia
    public void frecuenciaUp(int numPulsaciones) {
        //Mientras exista una pulsacion
        while(numPulsaciones > 0) {
            //Si la frecuencia es menor que la maxima suma 0.5
            if (frecuencia < fMax) {
                this.frecuencia += fSalto;
                //Si es igual que la maxima, la frecuencia pasa a valer el valor inicial, que es fMin
            }
            else {
                this.frecuencia = fMin;
                
            }
            
            numPulsaciones--;
        }
    }
    
    //Metodo que se encarga de bajar la frecuencia 0.5 MHz, el argumento es el numero de veces que se pulsa virtualmente el boton de bajar frecuencia
    public void frecuenciaDown(int numPulsaciones) {
        //Mientras exista una pulsacion
        while(numPulsaciones > 0) {
            //Si la frecuencia es menor que la maxima suma 0.5
            if (frecuencia > fMin) {
                this.frecuencia -= fSalto;
                //Si es igual que la minima, la frecuencia pasa a valer el valor final, que es fMax
            } else {
                this.frecuencia = fMax;
                
            }
            numPulsaciones--;
        }
    }
}
