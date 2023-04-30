/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package examenclasesv2;
import Struct.*;
import Struct.Chalet.Tipo;
//import java.util.Scanner;

/**
 *
 * @author FraN_
 */
public class ExamenClasesV2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
//        Scanner entrada = new Scanner(System.in);
        
//        Vivienda MiViv = new Vivienda(1, "MiCasa", "Tarragona", "45432", "Pepe Cuenca", "75421347F", "C/Pamplona", 4, 456.44);
//        MiViv.MostrarViv();
//        System.out.println("\n");
//        MiViv.MostrarInm();

//        Inmobiliaria MiInm = new Inmobiliaria(1, "TecnoCasa", "Barcelona", "45781");
//        MiInm.MostrarInm();
//        System.out.println("\n");
//        
//        //Nuevo objeto de la misma clase creado con un metodo interno de manera recursiva
//        Inmobiliaria NuevoObj = MiInm.AgregarInm(3, "InmNueva", "Madrid", "22345");
//        NuevoObj.MostrarInm();

        Chalet c = new Chalet(1, "MiCasa", "Barcelona", "45432", "Pepe Cuenca", "76457245F", "Barcelona", 2, 676.33, Tipo.Adosado, 100);
        System.out.println("Info del chalet");
        c.MostrarChalet();
        System.out.println("");
        
        System.out.println("Info de la vivienda padre de este chalet");
        c.MostrarViv();
        System.out.println("");
        
        System.out.println("Info de la Inmobiliaria padre de esta vivienda, padre a su vez de este chalet");
        c.MostrarInm();
    }
    
}
