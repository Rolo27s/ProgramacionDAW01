/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Struct;

/**
 *
 * @author FraN_
 */
public class Chalet extends Vivienda{
    public enum Tipo {Adosado, Pareado, Independiente, Casa_mata};
    private Tipo tipo;
    private int metros_terreno;
    
    public Chalet (int id, String nombre_Inm, String direccion_Inm, String sucursal, 
                    String nombre_propietario, String nif_prop, String direccion_viv, int num_habitacion, double precio,
                    Tipo tipo, int metros_terreno) {
        super(id, nombre_Inm, direccion_Inm, sucursal, nombre_propietario, nif_prop, direccion_viv, num_habitacion, precio);
        this.tipo = tipo;
        this.metros_terreno = metros_terreno;
    }
    
    public void MostrarChalet() {
        System.out.println("Tipo de chalet: " + tipo);
        System.out.println("Metros de terreno del chalet: " + metros_terreno);
    }
    
}
