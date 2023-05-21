/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tablas;

import java.sql.Statement;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import conexion.Conexion;
import controles.Controles;
import java.sql.SQLException;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author FraN_
 */
public class Producto {

    private int id;
    private String nombre;
    private String talla;
    private float precio;
    private int stock;
    private String tipoTejido;

    // Constantes
    final String NOM_TABLA = "producto";
    final String N_CAMPO[] = {"id", "nombre", "talla", "precio", "stock", "tipoTejido"};

    // El metodo Buscar devuelve el id del producto si se encuentra. Si no devuelve 0.
    // Los parametros de entrada son el nombre del campo y la informacion que quieres Buscar en ese campo. Son dos Strings
    // Tenemos tambien float e int, pero el programa entiende perfectamente estos ajustes.
    // En caso de Buscar un tipo float, la sintaxis será usando el punto. Ej: 29.99
    public int Buscar(String campo, String info) {
        try {
            Conexion conexion = new Conexion();
            conexion.Conectar();

            Statement sentencia;
            ResultSet resultado;

            String sql = "SELECT * FROM " + NOM_TABLA + " WHERE " + campo + " = '" + info + "'";

            sentencia = conexion.con.createStatement();
            resultado = sentencia.executeQuery(sql);

            // Si encuentra resultado, guardo la info en los atributos
            if (resultado.isBeforeFirst()) {
                System.out.println("\n  -> Resultados encontrados\n");
                while (resultado.next()) {
                    this.id = resultado.getInt("id");
                    this.nombre = resultado.getString("nombre");
                    this.talla = resultado.getString("talla");
                    this.precio = resultado.getFloat("precio");
                    this.stock = resultado.getInt("stock");
                    this.tipoTejido = resultado.getString("tipoTejido");
                }
            } else {
                System.out.println("\n  -> No se encontraron resultados\n");
                this.id = 0; // Si no encuentro resultados, la id será 0. Util para referencias futuras al llamar a este metodo dentro de otros.
            }

            conexion.Desconectar();

        } catch (SQLException ex) {
            Logger.getLogger(Producto.class.getName()).log(Level.SEVERE, null, ex);
        }
        return id;
    }

    // Metodo modificar. Las modificaciones se ingresan de tipo String y el programa convierte automaticamente el formato al necesario.
    public void Modificar(String campo, String info, String updateInfo) {
        int idEncontrada = Buscar(campo, info);

        if (idEncontrada != 0) {
            try {
                Conexion conexion = new Conexion();
                conexion.Conectar();

                PreparedStatement sentencia;

                String sql = "UPDATE " + NOM_TABLA + " SET " + campo + " = ?" + " WHERE " + campo + " = '" + info + "'";

                sentencia = conexion.con.prepareStatement(sql);
                sentencia.setString(1, updateInfo);

                sentencia.executeUpdate();

                System.out.println("\n    Informacion modificada correctamente!\n");
                conexion.Desconectar();
            } catch (SQLException ex) {
                //Logger.getLogger(Producto.class.getName()).log(Level.SEVERE, null, ex);
                System.out.println("Error en la modificacion");
            }

        } else {
            System.out.println("\n    Error! No puedo modificar algo que no existe\n");
        }

    }

    //Metodo de Ver
    public void Ver(String campo, String info) {
        int idEncontrada = Buscar(campo, info);

        if (idEncontrada != 0) {
            try {
                Conexion conexion = new Conexion();
                conexion.Conectar();

                Statement sentencia;
                ResultSet resultado;

                String sql = "SELECT nombre, talla, precio, stock, tipoTejido FROM " + NOM_TABLA + " WHERE " + campo + " = '" + info + "'";

                sentencia = conexion.con.createStatement();
                resultado = sentencia.executeQuery(sql);

                while (resultado.next()) {
                    System.out.println("\n  Nombre: " + nombre);
                    System.out.println("  Talla: " + talla);
                    System.out.println("  Precio: " + precio);
                    System.out.println("  Stock: " + stock);
                    System.out.println("  Tipo de tejido: " + tipoTejido + "\n");
                }
            } catch (SQLException ex) {
                //Logger.getLogger(Producto.class.getName()).log(Level.SEVERE, null, ex);
                System.out.println("\n Error! No se pudo ver los resultados\n\n");
            }

        } else {
            System.out.println("\n    Error! No puedo ver algo que no existe\n");
        }
    }

    //Metodo de Ver
    public void VerTodo() {
        System.out.println("\n\n ### Uso exclusivo para empleados ### \n\n");

        try {
            Conexion conexion = new Conexion();
            conexion.Conectar();

            Statement sentencia;
            ResultSet resultado;

            String sql = "SELECT * FROM " + NOM_TABLA;

            sentencia = conexion.con.createStatement();
            resultado = sentencia.executeQuery(sql);

            while (resultado.next()) {
                this.id = resultado.getInt("id");
                this.nombre = resultado.getString("nombre");
                this.talla = resultado.getString("talla");
                this.precio = resultado.getFloat("precio");
                this.stock = resultado.getInt("stock");
                this.tipoTejido = resultado.getString("tipoTejido");

                System.out.println("\n id: " + id);
                System.out.println("  Nombre: " + nombre);
                System.out.println("  Talla: " + talla);
                System.out.println("  Precio: " + precio);
                System.out.println("  Stock: " + stock);
                System.out.println("  Tipo de tejido: " + tipoTejido + "\n");
            }
        } catch (SQLException ex) {
            //Logger.getLogger(Producto.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println("\n Error! No se pudo ver los resultados\n\n");
        }

    }

    //Borrar producto
    public void Borrar(String campo, String info) {
        int idEncontrada = Buscar(campo, info);

        if (idEncontrada != 0) {
            //Veo la info que voy a borrar
            System.out.println("Se eliminara el registro completo");
            System.out.println("Si solo desea eliminar un campo concreto use modificar y pongalo vacio");
            Ver(campo, info);
            System.out.print("Estas seguro de borrar esta informacion (S/N)?: ");
            Controles del = new Controles();
            Scanner confirm = new Scanner(System.in);
            del.setRespuesta(confirm.nextLine());
            String confirmacion = del.controlSN();

            if ("S".equals(confirmacion) || "s".equals(confirmacion)) {
                try {
                    Conexion conexion = new Conexion();
                    conexion.Conectar();

                    System.out.println("Borrando producto...");
                    //En este caso preparamos estado
                    PreparedStatement sentencia;
                    String sql = "DELETE FROM " + NOM_TABLA + " WHERE " + campo + " = ?";
                    sentencia = conexion.con.prepareStatement(sql);

                    // Establecer el valor del parámetro
                    sentencia.setString(1, info);

                    //Actualizo la sentencia ejecutando todos los cambios
                    sentencia.executeUpdate();

                    //Me desconecto de la base de datos
                    conexion.Desconectar();
                } catch (SQLException ex) {
                    //Logger.getLogger(Productos.class.getName()).log(Level.SEVERE, null, ex);
                    System.out.println("No se pudo borrar el producto");
                }
            } else {
                System.out.println(" - Saliendo de borrar sin eliminar ningun registro");
            }

        } else {
            System.out.println("   ** Informacion no encontrada. No se puede borrar porque no existe.");
        }
    }

    //Agregar producto. Lo logico es agregar por nombre.
    public void Agregar(String campo, String info) {
        int idEncontrada = Buscar(campo, info);

        //Si no se ha encontrado puedo agregar.
        if (idEncontrada == 0) {
            try {
                Conexion conexion = new Conexion();
                conexion.Conectar();

                Scanner entrada = new Scanner(System.in);
                Scanner entradaF = new Scanner(System.in);
                Scanner entradaI = new Scanner(System.in);

                PreparedStatement sentencia;

                String sql = "INSERT INTO " + NOM_TABLA + "(nombre, talla, precio, stock, tipoTejido) VALUES (?, ?, ?, ?, ?)";
                sentencia = conexion.con.prepareStatement(sql);

                // Agrego el nombre
                sentencia.setString(1, info);

                // Agrego talla
                System.out.print("Talla: ");
                String newTalla = entrada.nextLine();
                //Falta el control de las posibles tallas
                sentencia.setString(2, newTalla);

                // Agrego precio
                System.out.println("(recuerde en usar la coma para los decimales)");
                System.out.print("Precio a agregar: ");
                // Control de precio desde 0.25 hasta 1000.00
                Controles newPrecio = new Controles();
                newPrecio.setNumFloat(entradaF.nextFloat());
                newPrecio.controlFloat(0.25f, 1000f);
                Float precioNuevo = newPrecio.getNumFloat();
                sentencia.setFloat(3, precioNuevo);

                // Agrego stock inicial
                System.out.println("Stock: ");
                Controles newStock = new Controles();
                newStock.setNumInt(entradaI.nextInt());
                // Controlo de una unidad hasta un maximo de 500 suponiendo que es el limite fisico del almacen
                newStock.controlInt(1, 500);
                int nuevoStock = newStock.getNumInt();
                sentencia.setInt(4, nuevoStock);
                
                // Agrego el Tipo de tejido
                System.out.println("Tipo de tejido: ");
                String TT = entrada.nextLine();
                sentencia.setString(5, TT);
                
                //Actualizo la sentencia ejecutando todos los cambios
                sentencia.executeUpdate();
                //Me desconecto de la base de datos
                conexion.Desconectar();

                System.out.println("\nProducto agregado correctamente\n\n");
            } catch (SQLException ex) {
                //Logger.getLogger(Productos.class.getName()).log(Level.SEVERE, null, ex);
                System.out.println("No ha sido posible agregar el producto");
            }

        } else {
            Ver(campo, info);
            System.out.println("No puedo agregar si ya existe");
        }
    }
}
