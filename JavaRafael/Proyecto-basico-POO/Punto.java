public class Punto {
    private float x;
    private float y;

    // Constructor
    public Punto (float x, float y) {
        this.x = x;
        this.y = y;
    }

    // Default constructor (No params)
    public Punto () {
        this.x = 1.0f;
        this.y = 1.0f;
    }

    // --- Methods ---

    @Override
    public String toString() {
        return "x: " + this.x + ", y: " + this.y;
    }

    public void transladar(float a, float b) {
        this.x += a;
        this.y += b;
    }

    // Setter x
    public void x(float a) {
        this.x = a;
    }

    // Getter x
    public float x() {
        return this.x;
    }

    // Setter y
    public void y(float a) {
        this.x = a;
    }

    // Getter y
    public float y() {
        return this.y;
    }

}
