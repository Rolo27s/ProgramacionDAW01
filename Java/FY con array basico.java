import java.util.Random;

public class FisherYatesShuffle {
    public static void main(String[] args) {
        int[] numeros = {1, 2, 3, 4, 5, 6}; // Array a mezclar
        shuffleArray(numeros); // Llamada al método shuffleArray para mezclar el arreglo
        System.out.println(Arrays.toString(numeros)); // Imprime el arreglo mezclado
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
