/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package conerctarbd;

import java.sql.Statement;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Scanner;
//Como hemos comentado los loggers, ya no necesitaríamos estos imports
//import java.util.logging.Level;
//import java.util.logging.Logger;
/**
 *
 * @author Fran_Rodriguez
 */
public class ConectarBD {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        //Parte de SELECT
        try {
            // TODO code application logic here
            Conectarme conexion = new Conectarme();
            
            //Me conecto a la base de datos
            conexion.conectar();
            
            Statement sentencia;
            ResultSet resultado;
            String sql = "SELECT * FROM color";
            sentencia = conexion.con.createStatement();            
            resultado = sentencia.executeQuery(sql);
            
            while (resultado.next()) {
                String color = resultado.getString("Color");
                String des = resultado.getString("Descripcion");
                System.out.println("El color es " + color + " y la descripcion es: " + des);
                
            }
            
            //Me desconecto de la base de datos
            conexion.desconectar();
        } catch (SQLException ex) {
            System.out.println("No se puede conectar");
            //Logger.getLogger(ConectarBD.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        // Parte de UPDATE, DELETE, INSERT
        try {
            // TODO code application logic here
            Conectarme conexion = new Conectarme();
            
            //Me conecto a la base de datos
            conexion.conectar();
            Statement sentencia;
            
            //Actualizamos datos
            String sql = "UPDATE color SET descripcion = 'verde3' WHERE id = 1";
            sentencia = conexion.con.createStatement();
            sentencia.executeUpdate(sql);
                        
            //Me desconecto de la base de datos
            conexion.desconectar();
        } catch (SQLException ex) {
            System.out.println("No se puede conectar");
            //Logger.getLogger(ConectarBD.class.getName()).log(Level.SEVERE, null, ex);
        }   
        
        //Un UPDATE no escrito directamente en codigo fuente y que luego será escrito por el usuario. (Tambien sirve para el SELECT)
        try {
            // TODO code application logic here
            Conectarme conexion = new Conectarme();
            Scanner entrada = new Scanner(System.in);
            //Me conecto a la base de datos
            conexion.conectar();
            PreparedStatement sentencia;
            
            //Actualizamos datos
            String sql = "UPDATE color SET descripcion = ? WHERE id = 1";
            sentencia = conexion.con.prepareStatement(sql);
            
            System.out.println("introduzca una nueva descripcion: ");
            String descUser = entrada.nextLine();
            sentencia.setString(1, descUser);
            sentencia.executeUpdate();
                        
            //Me desconecto de la base de datos
            conexion.desconectar();
        } catch (SQLException ex) {
            System.out.println("No se puede conectar");
            //Logger.getLogger(ConectarBD.class.getName()).log(Level.SEVERE, null, ex);
        }  
    }
    
}
