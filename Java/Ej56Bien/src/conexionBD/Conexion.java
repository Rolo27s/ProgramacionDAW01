/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package conexionBD;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
//import java.util.logging.Level;
//import java.util.logging.Logger;

/**
 *
 * @author FraN_
 */
public class Conexion {
    String bd = "gestoria";
    String url = "jdbc:mysql://localhost:3307/";
    String user = "root";
    String pass = "";
    String driver = "com.mysql.cj.jdbc.Driver";
    
    //Instancio objeto con de tipo Connection
    public Connection con;
    
    //Conectar a la base de datos
    public Connection Conectar() {
        try {
            Class.forName(driver);
            con = DriverManager.getConnection(url + bd, user, pass);
            System.out.println("Base de datos [" + bd + "] conectada correctamente");
        } catch (ClassNotFoundException | SQLException ex) {
            //Logger.getLogger(Conexion.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println("No se ha podido conectar a la base de datos -> " + bd);
        }
        //Devuelvo la ruta de conexion
        return con;
    }
    
    //Desconectar de la base de datos
    public void Desconectar() {
        try {
            con.close();
            System.out.println("Base de datos [" + bd + "] cerrada correctamente");
        } catch (SQLException ex) {
            //Logger.getLogger(Conexion.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println("Ha ocurrido un error al cerrar la base de datos");
        }
    }
}
