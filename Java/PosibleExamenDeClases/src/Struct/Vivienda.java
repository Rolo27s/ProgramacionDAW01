/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Struct;

/**
 *
 * @author FraN_
 */
public class Vivienda extends Inmobiliaria{
    private String nombre_propietario, nif_prop, direccion_viv;
    private int num_habitacion;
    private double precio;
        
    public Vivienda(int id, String nombre_Inm, String direccion_Inm, String sucursal, 
                    String nombre_propietario, String nif_prop, String direccion_viv, int num_habitacion, double precio) {
        super(id, nombre_Inm, direccion_Inm, sucursal);
        this.nombre_propietario = nombre_propietario;
        this.nif_prop = nif_prop;
        this.direccion_viv = direccion_viv;
        this.num_habitacion = num_habitacion;
        this.precio = precio;
    }
    
    public void SetVivienda (String nombre_propietario, String nif_prop, String direccion_viv, int num_habitacion, double precio){
        this.nombre_propietario = nombre_propietario;
        this.nif_prop = nif_prop;
        this.direccion_viv = direccion_viv;
        this.num_habitacion = num_habitacion;
        this.precio = precio;
    }
    
    public void MostrarViv() {
        System.out.println("Nombre propietario vivienda: " + nombre_propietario);
        System.out.println("nif propietario vivienda: " + nif_prop);
        System.out.println("direccion vivienda: " + direccion_viv);
        System.out.println("Num habitacion vivienda: " + num_habitacion);
        System.out.println("Precio vivienda: " + precio);
    }
    
}
