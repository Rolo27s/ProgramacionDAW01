/* Metodo  "mezcla Fisher-Yates" o "mezcla de Fisher-Yates". 
Es un algoritmo utilizado para mezclar los elementos de un array de manera aleatoria, 
utilizando la función shuffle de la librería random. Este algoritmo fue popularizado por Ronald Fisher e Frank Yates en 1938, 
y es ampliamente utilizado en la programación para realizar mezclas aleatorias de elementos en listas o arrays. */

import java.util.Random;

public class FisherYatesShuffle2 {
    public static void main(String[] args) {
        int[] array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Array a mezclar
        shuffleArray(array); // Llamada al método shuffleArray para mezclar el arreglo
        System.out.println(Arrays.toString(array)); // Imprime el arreglo mezclado
    }

    public static void shuffleArray(int[] array) {
        Random random = new Random();
        for (int i = array.length - 1; i > 0; i--) {
            int index = random.nextInt(i + 1);
            int temp = array[index];
            array[index] = array[i];
            array[i] = temp;
        }
    }
}
