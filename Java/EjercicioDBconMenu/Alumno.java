/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
Realizar metodos para un futuro menú para poder crear, leer, actualizar y borrar un alumno.
 */
package Clases;

import ConexionConBD.conexionConLaBDInstituto;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Fran_Rodriguez
 */
public class Alumno {

    private int id;
    private String nombre;
    private float notaMedia;
    private String curso;

    public void leerTodo() {
        try {
            //Instancio el objeto conexion de la clase conexionConLaBDInstituto
            conexionConLaBDInstituto conexion = new conexionConLaBDInstituto();
            
            //Llamo al metodo conectar para conectarme a la base de datos del instituto
            conexion.conectar();
            
            Statement sentencia;
            ResultSet resultado;
            String sql = "SELECT * FROM alumno";
            sentencia = conexion.con.createStatement();
            resultado = sentencia.executeQuery(sql);
            
            System.out.println("");
            System.out.println("ALUMNO\tNOTA-MEDIA\tCURSO");
            
            while (resultado.next()) {
                nombre = resultado.getString("nombre");
                notaMedia = resultado.getFloat("notaMedia");
                curso = resultado.getString("curso");
                System.out.println(nombre + "\t" + notaMedia + "\t" + curso);
            }
            
            System.out.println("");
            //Me desconecto de la base de datos
            conexion.desconectar();
        } catch (SQLException ex) {
            Logger.getLogger(Alumno.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public void leerNombre() {
        try {
            //Instancio el objeto conexion de la clase conexionConLaBDInstituto
            conexionConLaBDInstituto conexion = new conexionConLaBDInstituto();
            
            //Llamo al metodo conectar para conectarme a la base de datos del instituto
            conexion.conectar();
            
            Statement sentencia;
            ResultSet resultado;
            String sql = "SELECT * FROM alumno";
            sentencia = conexion.con.createStatement();
            resultado = sentencia.executeQuery(sql);
            
            System.out.println("");
            System.out.println("ALUMNO\tNOTA-MEDIA\tCURSO");
            
            while (resultado.next()) {
                String nombreL = resultado.getString("nombre");
                Float notaMediaL = resultado.getFloat("notaMedia");
                String cursoL = resultado.getString("curso");
                System.out.println(nombreL + "\t" + notaMediaL + "\t" + cursoL);
            }
            
            System.out.println("");
            //Me desconecto de la base de datos
            conexion.desconectar();
        } catch (SQLException ex) {
            Logger.getLogger(Alumno.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

}
