/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tablas;

import conexionBD.Conexion;
import controles.controles;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Fran_Rodriguez
 */
public class Visita {

    private int idvisita;
    private String NIF;
    private String Fecha_visita; // Cuidado que en la base de datos es de tipo date YYYY-MM-DD. Controlar.
    private String consulta;
    private float ValorConsulta; //Vendrá dictado por Consulta.

    //Enum de las opciones de la consulta
//    public enum Consulta {
//        FINANZAS("Finanzas", 65),
//        INVERSION("Inversion", 60),
//        CONTABLE("Contable", 50),
//        OTRA("Otra", 55);
//        
//        private final String tipo;
//        private final float costo;
//        
//        Consulta(String tipo, float costo) {
//            this.tipo = tipo;
//            this.costo = costo;
//        }
//        
//        public String getTipo() {
//            return tipo;
//        }
//
//        public float getCosto() {
//            return costo;
//        }
//        
//    }
    //metodo de buscar visita
    public int buscarVisita(String campo, String info) {
        try {
            Conexion conexion = new Conexion();
            conexion.Conectar();

            Statement sentencia;
            ResultSet resultado;

            String sql = "SELECT * FROM visita WHERE " + campo + " = '" + info + "'";
            sentencia = conexion.con.createStatement();
            resultado = sentencia.executeQuery(sql);
            int count = 0;
            if (resultado.isBeforeFirst()) {
                //Si encontre la info, guardo el registro completo
                while (resultado.next()) {
                    this.idvisita = resultado.getInt("idvisita");
                    this.NIF = resultado.getString("NIF");
                    this.Fecha_visita = resultado.getString("Fecha_visita");
                    this.consulta = resultado.getString("Consulta");
                    this.ValorConsulta = resultado.getFloat("ValorConsulta");
                    count++;
                }
                System.out.println("Se ha encontrado la informacion");
                System.out.println("Visitas totales del usuario: " + count);
            } else {
                //Si no se encontro el idvisita. Lo marco a 0 porque no se encontro
                this.idvisita = 0;
                System.out.println("No se ha encontrado esa informacion");
            }
            conexion.Desconectar();
        } catch (SQLException ex) {
            Logger.getLogger(Usuario.class.getName()).log(Level.SEVERE, null, ex);
        }

        return this.idvisita;
    }

    //Agregar visitas. campo debe ser NIF
    public void agregarVisita(String campo, String info) {
        Usuario usuario = new Usuario();
        if (!"NO_ENCONTRADO".equals(usuario.buscarUsuario(campo, info))) {
            try {
                Conexion conexion = new Conexion();
                conexion.Conectar();
                Scanner entrada = new Scanner(System.in);
                PreparedStatement sentencia;
                String sql = "INSERT INTO visita (NIF, Fecha_visita, Consulta, ValorConsulta) VALUES(?, ?, ?, ?) ";
                sentencia = conexion.con.prepareStatement(sql);
                
                //Guardo el NIF
                sentencia.setString(1, info);
                
                //Pido la fecha
                System.out.print("Dame la fecha de la nueva visita (YYYY-MM-DD): ");
                String newDate = entrada.nextLine();
                sentencia.setString(2, newDate);
                
                //Pido el tipo de consulta
                controles opc = new controles();
                
                System.out.println("Ingresa tipo de consulta");
                            System.out.println("------------------------");
                            System.out.println("1. Contable");
                            System.out.println("2. Finanzas");
                            System.out.println("3. Inversion");
                            System.out.println("4. Otra");
                            System.out.print("Ingrese una opcion: ");
                            opc.setNumInt(entrada.nextInt());
                            opc.controlInt(1, 4);
                            String opcConsulta;
                            float monto;
                            switch (opc.getNumInt()) {
                                case 1 -> {opcConsulta = "Contable"; monto = 50;}
                                case 2 -> {opcConsulta = "Finanzas"; monto = 65;}
                                case 3 -> {opcConsulta = "Inversion"; monto = 60;}
                                case 4 -> {opcConsulta = "Otra"; monto = 55;}
                                default -> throw new AssertionError();
                            }
                            
                sentencia.setString(3, opcConsulta);
                sentencia.setFloat(4, monto);
                
                //Actualizo la sentencia ejecutando todos los cambios
                sentencia.executeUpdate();
                System.out.println("\nVisita agregada correctamente\n");
                //Me desconecto de la base de datos
                conexion.Desconectar();
                
            } catch (SQLException ex) {
                Logger.getLogger(Visita.class.getName()).log(Level.SEVERE, null, ex);
                System.out.println("Error en agregar esta visita");
            }
        } else {
            System.out.println("Usuario no encontrado en el registro de usuarios. No puede agregar una visita.");
        }
    }

    //Metodo de mostrar visita
    public void mostrarVisita(String campo, String info) {
        if (buscarVisita(campo, info) != 0) {
            try {
                System.out.println("\nInformacion de la ultima visita");
                System.out.println("-----------------------------------");
                System.out.println("NIF: " + this.NIF);
                System.out.println("Fecha de la visita: " + this.Fecha_visita);
                System.out.println("Consulta: " + this.consulta);
                System.out.println("Valor de la consulta: " + this.ValorConsulta);
                System.out.println("");

                Conexion conexion = new Conexion();
                conexion.Conectar();

                Statement sentencia;
                ResultSet resultado;

                //Total de ValorConsulta (SUM) usando en el WHERE el NIF (PRIMARY KEY de visita)
                String sql = "SELECT SUM(ValorConsulta) AS Total FROM visita WHERE NIF = '" + this.NIF + "'";
                sentencia = conexion.con.createStatement();
                resultado = sentencia.executeQuery(sql);

                if (resultado.next()) {
                    float total = resultado.getFloat("Total");
                    System.out.println("El monto total del usuario en la gestoría es de " + total);
                } else {
                    System.out.println("No se encontró ningún registro para el usuario en la gestoría.");
                }

                conexion.Desconectar();
            } catch (SQLException ex) {
                Logger.getLogger(Visita.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }

    //borrar visita
    //Borrar. En PHPMyAdmin se hizo una clave foranea relacionada con el NIF de usuario,
    //de tal manera que no puedes borrar usuarios de la tabla usuarios si tiene visitas.
    //No pueden haber visitas sin estar en la tabla de usuarios registrado.
    public void borrarVisita(String campo, String info) {
        if (buscarVisita(campo, info) != 0) {
            Scanner entrada = new Scanner(System.in);

            System.out.println("Datos encontrados");
            System.out.println("-----------------");
            System.out.println("NIF: " + this.NIF);
            System.out.println("Fecha de la visita: " + this.Fecha_visita);
            System.out.println("Consulta: " + this.consulta);
            System.out.println("Valor de la consulta: " + this.ValorConsulta);
            System.out.println("");
            System.out.print("Esta seguro de eliminar este registro? (S/N): ");
            controles opc = new controles();
            opc.setRespuesta(entrada.nextLine());
            opc.controlSN();

            if ("S".equals(opc.getRespuesta()) || "s".equals(opc.getRespuesta())) {
                try {
                    Conexion conexion = new Conexion();
                    conexion.Conectar();

                    System.out.println("Borrando registro ...");
                    PreparedStatement sentencia;
                    String sql = "DELETE FROM visita WHERE " + campo + " = '" + info + "'";
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
            System.out.println("Error. No se pudo borrar la visita porque no se encontro");
        }
    }
}
