public class Circulo extends Punto{
    private float radio;

    // Constructor que acepta un objeto Punto y un radio
    public Circulo(Punto centro, float radio) {
        super(centro.x(), centro.y());  // Llama al constructor de la clase base (Punto) con las coordenadas del objeto Punto. Uso los getters.
        this.radio = radio;
    }

    // Default constructor. Utilizo setter para definir el punto por defecto.
    public Circulo () {
        super(); // Llama al constructor por defecto de Punto.
        this.radio = 1.0f;
    }

    @Override
    public String toString() {
        return "Círculo: " + super.toString() + ", radio: " + this.radio;
    }

    // Setter y Getter para radio
    public float radio() {
        return this.radio;
    }

    public void radio(float r) {
        this.radio = r;
    }

    // Método para obtener el centro como un objeto Punto
    public Punto centro() {
        return new Punto(this.x(), this.y());
    }

    // Método para asignar el centro a partir de un objeto Punto
    public void centro(Punto p) {
        this.x(p.x());
        this.y(p.y());
    }

    // Método para trasladar el círculo
    public void trasladar(float a, float b) {
        super.transladar(a, b);  // Utiliza el método de la clase base para trasladar el punto central
    }
}
