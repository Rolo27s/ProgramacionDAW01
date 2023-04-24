package OtroPaquete;

/**
 *
 * @author Fran_Rodriguez
 */

//La clase empleado hereda cosas de la clase persona, que seria su superclase
public class Empleado extends Persona{
    double salario;
    
    public Empleado (String nombre, int edad, double salario) {
        // Esta linea de codigo llama al constructor del padre. En este caso llamo al constructor de la clase Persona. Que tiene dos atributos. En este caso public
        super(nombre, edad);
        this.salario = salario;
    }
    
    @Override //Sustituir un metodo de la superclase
    public void MostrarDatos(){
        super.MostrarDatos();
        System.out.println("Salario es " + salario);
    }
}
