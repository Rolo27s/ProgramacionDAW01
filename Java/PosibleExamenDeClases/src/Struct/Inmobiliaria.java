/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Struct;

/**
 *
 * @author FraN_
 */
public class Inmobiliaria {
    private int id;
    private String nombre_Inm, direccion_Inm, sucursal;
    
    //Constructor vacio porque el usuario va a ingresar la id
    public Inmobiliaria(int id, String nombre_Inm, String direccion_Inm, String sucursal) {
        this.id = id;
        this.nombre_Inm = nombre_Inm;
        this.direccion_Inm = direccion_Inm;
        this.sucursal = sucursal;
    }
        
    //Muestra los atributos
    public void MostrarInm() {
        System.out.println("ID inmobiliaria: " + id);
        System.out.println("Nombre inmobiliaria: " + nombre_Inm);
        System.out.println("Direccion inmobiliaria: " + direccion_Inm);
        System.out.println("Sucursal: " + sucursal);
    }
        
    //Getters con nombre de objeto "nombreInmo"
    public int getId(Inmobiliaria nombreInmo) {
        return nombreInmo.id;
    }
    
    public String getNombre(Inmobiliaria nombreInmo) {
        return nombreInmo.nombre_Inm;
    }
    
    public String getDireccion(Inmobiliaria nombreInmo) {
        return nombreInmo.direccion_Inm;
    }
    
    public String getSucursal(Inmobiliaria nombreInmo) {
        return nombreInmo.sucursal;
    }
    
    //Metodo que retorna un nuevo objeto de tipo Inmobiliaria (una inmobiliaria podra crear a otras)
    public Inmobiliaria AgregarInm(int id, String nombre_Inm, String direccion_Inm, String sucursal) {
        return new Inmobiliaria(id, nombre_Inm, direccion_Inm, sucursal);
    }
}
