/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package conerctarbd;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
//Como hemos comentado los loggers, ya no necesitaríamos estos imports
//import java.util.logging.Level;
//import java.util.logging.Logger;

/**
 *
 * @author Fran_Rodriguez
 */
public class Conectarme {

    String bd = "colores"; //base de datos
    String url = "jdbc:mysql://localhost:3307/"; //url
    String user = "root"; //usuario del localhost
    String pass = ""; //password
    String driver = "com.mysql.cj.jdbc.Driver"; //Clase Driver

    Connection con;

    public Connection conectar() {
        /*try {
            try {
                Class.forName(driver);
            } catch (ClassNotFoundException ex) {
                System.out.println("No encuentra la clase");
                //Logger.getLogger(Conectarme.class.getName()).log(Level.SEVERE, null, ex);
            }
            con = DriverManager.getConnection(url + bd, user, pass);
            System.out.println("La base de datos se ha conectado");
        } catch (SQLException ex) {
            System.out.println("La base de datos no se ha conectado");
            //Logger.getLogger(Conectarme.class.getName()).log(Level.SEVERE, null, ex);
        }*/

        try {
            Class.forName(driver);
            con = DriverManager.getConnection(url + bd, user, pass);
            System.out.println("La base de datos se ha conectado");
        } catch (ClassNotFoundException | SQLException ex) {
            System.out.println("No encuentra la clase o la base de datos no se ha conectado");
            //Logger.getLogger(Conectarme.class.getName()).log(Level.SEVERE, null, ex);
        }

        return con;
    }

    public void desconectar() {
        try {
            con.close();
            System.out.println("Se ha cerrado la conexion");
        } catch (SQLException ex) {
            System.out.println("No se ha ceerrado la conexion");
            //Logger.getLogger(Conectarme.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
