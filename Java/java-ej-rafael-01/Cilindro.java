public class Cilindro extends Circulo {
    private float altura;

    // Constructores

    // Constructor por defecto
    public Cilindro() {
        super();  // Llama al constructor por defecto de la clase base (Circulo)
        this.altura = 1.0f;  // Asigna el valor predeterminado a la altura
    }

    // Constructor con parámetros Circulo y altura
    public Cilindro(Circulo base, float altura) {
        super(base.centro(), base.radio());  // Llama al constructor de la clase base (Circulo) con el centro y radio del objeto Circulo
        this.altura = altura;
    }

    // Métodos

    // Setter y Getter para altura
    public float altura() {
        return this.altura;
    }

    public void altura(float a) {
        this.altura = a;
    }

    // Método para asignar la base a partir de un objeto Circulo
    public void base(Circulo b) {
        this.centro(b.centro());
        this.radio(b.radio());
    }

    // Método para trasladar el cilindro
    @Override
    public void trasladar(float a, float b) {
        super.trasladar(a, b);  // Utiliza el método de la clase base (Circulo) para trasladar el círculo
    }

    // Método toString
    @Override
    public String toString() {
        return "Cilindro: " + super.toString() + ", altura: " + this.altura;
    }

}
