/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package conexion;

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

    String db = "tiendaderopa";
    String url = "jdbc:mysql://localhost:3307/";
    String user = "root";
    String pass = "";
    String driver = "com.mysql.cj.jdbc.Driver";

    public Connection con;

    public Connection Conectar() {
        try {
            Class.forName(driver);
            con = DriverManager.getConnection(url + db, user, pass);
            System.out.println("Conectado a " + db);
        } catch (SQLException | ClassNotFoundException ex) {
            //Logger.getLogger(Conexion.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println("Error en la conexion a la base de datos " + db);
        }
        return con;
    }
    
    public void Desconectar() {
        try {
            con.close();
            System.out.println("Desconectado de " + db);
        } catch (SQLException ex) {
            //Logger.getLogger(Conexion.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println("Error en la desconexion a la base de datos " + db);
        }
    }

}
