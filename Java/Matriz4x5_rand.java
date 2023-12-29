/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
// package matriz4x5_rand;
import java.util.Random;
/**
 *
 * @author FraN_
 */
public class Matriz4x5_rand {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int matrix[][] = new int[4][5];
        
        //Instancio el objeto rand de clase Random, contenida en la librería java.util.Random
        Random rand = new Random();
        
        System.out.println("PROGRAMA QUE GENERA UNA MATRIZ DE 4x5 CON NUMEROS RANDOMS");
        System.out.println("---------------------------------------------------------\n");
        
        //Usamos dos for anidados para rellenar la matriz con numeros randoms
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 5; j++) {
                matrix[i][j] = rand.nextInt(10, 100); // Numero random de 10 a 99
            }
        }
        
        //Misma idea de for anidado para mostrar la informacion de la matriz
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 5; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println("");
        }
        
        System.out.println("");
        System.out.println("");
        
        //Usando un for each para visualizar
        for(int fila[]: matrix) {
            for(int z: fila) {
                System.out.print(z + " ");
            }
            System.out.println("");
        }
    }
    
}
