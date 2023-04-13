import java.util.Random;

public class FisherYatesShuffle {
    public static void main(String[] args) {
        char[] letras = {'a', 'b', 'c', 'd', 'e', 'f'}; // Array a mezclar
        shuffleArray(letras); // Llamada al método shuffleArray para mezclar el arreglo
        System.out.println(Arrays.toString(letras)); // Imprime el arreglo mezclado
    }

    public static void shuffleArray(char[] array) {
        Random random = new Random();
        for (int i = array.length - 1; i > 0; i--) {
            int index = random.nextInt(i + 1);
            char temp = array[index];
            array[index] = array[i];
            array[i] = temp;
        }
    }
}
