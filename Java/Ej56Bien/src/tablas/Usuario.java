/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tablas;

import conexionBD.Conexion;
import java.sql.PreparedStatement;
import java.util.Scanner;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.logging.Level;
import java.util.logging.Logger;
import controles.controles;

/**
 *
 * @author Fran_Rodriguez
 */
public class Usuario {

    private String nif;
    private String nombre;
    private String apellidos;
    private String correo_electronico;
    private String telefono;

    //Metodo para saber si existe o no un campo. Se usara con consultas tipo SELECT porque tiene que devolver algo.
//    public boolean existe(ResultSet resultado, String campo) throws SQLException {
//            while(resultado.next()) {
//                if(resultado.getString(campo) != null)
//                    return true;
//            }
//        return false;
//    }
    //Buscamos un Usuario. Devuelve el primary key si se encontro. Dos parametros de entrada.
    public String buscarUsuario(String campo, String info) {
        try {
            Conexion conexion = new Conexion();
            conexion.Conectar();

            Statement sentencia;
            ResultSet resultado;

            String sql = "SELECT * FROM usuario WHERE " + campo + " = '" + info + "'";
            sentencia = conexion.con.createStatement();
            resultado = sentencia.executeQuery(sql);

            if (resultado.isBeforeFirst()) {
                //Si encontre la info, guardo el registro completo
                while (resultado.next()) {
                    this.nif = resultado.getString("NIF");
                    this.nombre = resultado.getString("Nombre");
                    this.apellidos = resultado.getString("Apellidos");
                    this.correo_electronico = resultado.getString("Correo_electronico");
                    this.telefono = resultado.getString("Telefono");
                }
                System.out.println("Se ha encontrado la informacion");
            } else {
                //Si no se encontro el DNI
                nif = "NO_ENCONTRADO";
                System.out.println("No se ha encontrado esa informacion");
            }
            conexion.Desconectar();
        } catch (SQLException ex) {
            Logger.getLogger(Usuario.class.getName()).log(Level.SEVERE, null, ex);
        }

        return this.nif;
    }

    public void mostrarUsuario(String campo, String info) {
        if (!"NO_ENCONTRADO".equals(buscarUsuario(campo, info))) {
            System.out.println("NIF: " + this.nif);
            System.out.println("Nombre: " + this.nombre);
            System.out.println("Apellidos: " + this.apellidos);
            System.out.println("Correo Electronico: " + this.correo_electronico);
            System.out.println("Telefono: " + this.telefono);
            System.out.println("");
        }
    }

    public void agregarUsuario(String campo, String info) {
        if ("NO_ENCONTRADO".equals(buscarUsuario(campo, info))) {
            try {
                Conexion conexion = new Conexion();
                conexion.Conectar();
                Scanner entrada = new Scanner(System.in);
                PreparedStatement sentencia;
                String sql = "INSERT INTO usuario (NIF, Nombre, Apellidos, Correo_electronico, Telefono) VALUES(?, ?, ?, ?, ?) ";
                sentencia = conexion.con.prepareStatement(sql);

                //Guardo el NIF
                sentencia.setString(1, info);

                //Pido el Nombre
                System.out.print("Dame el Nombre del nuevo usuario: ");
                String newName = entrada.nextLine();
                sentencia.setString(2, newName);

                //Pido el Apellido
                System.out.print("Dame el Apellido del nuevo usuario: ");
                String newlastName = entrada.nextLine();
                sentencia.setString(3, newlastName);

                //Pido el Correo Electronico
                System.out.print("Dame el Correo Electronico del nuevo usuario: ");
                String newEmail = entrada.nextLine();
                sentencia.setString(4, newEmail);

                //Pido el Telefono
                System.out.print("Dame el Telefono del nuevo usuario: ");
                String newTelf = entrada.nextLine();
                sentencia.setString(5, newTelf);

                //Actualizo la sentencia ejecutando todos los cambios
                sentencia.executeUpdate();
                //Me desconecto de la base de datos
                conexion.Desconectar();
            } catch (SQLException ex) {
                Logger.getLogger(Usuario.class.getName()).log(Level.SEVERE, null, ex);
                System.out.println("Error en agregar usuario");
            }
        } else {
            System.out.println("Error. El nif ya ha sido registrado...");
        }
    }
    
    //Borrar. En PHPMyAdmin se hizo una clave foranea relacionada con el NIF de usuario,
    //de tal manera que no puedes borrar usuarios de la tabla usuarios si tiene visitas.
    //No pueden haber visitas sin estar en la tabla de usuarios registrado.
    public void borrarUsuario (String campo, String info) {
        if (!"NO_ENCONTRADO".equals(buscarUsuario(campo, info))) {
            Scanner entrada = new Scanner(System.in);
            
            System.out.println("Datos encontrados");
            System.out.println("-----------------");
            System.out.println("NIF: " + this.nif);
            System.out.println("Nombre: " + this.nombre);
            System.out.println("Apellidos: " + this.apellidos);
            System.out.println("Correo Electronico: " + this.correo_electronico);
            System.out.println("Telefono: " + this.telefono);
            System.out.println("");
            System.out.print("Esta seguro de eliminar este registro? (S/N): ");
            controles opc = new controles();
            opc.setRespuesta(entrada.nextLine());
            opc.controlSN();
            
            if("S".equals(opc.getRespuesta()) || "s".equals(opc.getRespuesta())) {
                try {
                    Conexion conexion = new Conexion();
                    conexion.Conectar();
                    
                    System.out.println("Borrando registro ...");
                    PreparedStatement sentencia;
                    String sql = "DELETE FROM usuario WHERE " + campo + " = '" + info + "'";
                    sentencia = conexion.con.prepareStatement(sql);
                    
                    //Actualizo la sentencia ejecutando todos los cambios
                    sentencia.executeUpdate();
                    
                    System.out.println("Registro borrado correctamente");
                } catch (SQLException ex) {
                    Logger.getLogger(Usuario.class.getName()).log(Level.SEVERE, null, ex);
                }
                
            } else {
                System.out.println("Saliendo de borrar sin modificaciones");
            }
            
        } else {
            System.out.println("Error. No ha sido posible borrar la informacion. Usuario no encontrado.");
        }
    }
}
