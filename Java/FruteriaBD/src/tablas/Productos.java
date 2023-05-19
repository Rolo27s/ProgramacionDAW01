/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package tablas;

import conexionBD.Conexion;
import java.sql.PreparedStatement;
import java.sql.Statement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author FraN_
 */
public class Productos {

    private int id;
    private String nombre;
    private int stock;
    private float precio;

    //Getter de la id para trabajar de manera interna. Solo uso para programadores, nunca para clientes.
    public int getId() {
        return id;
    }

    public String getNombre() {
        return nombre;
    }

    public int getStock() {
        return stock;
    }

    public float getPrecio() {
        return precio;
    }
    
    //Metodo para buscar el producto
    public int buscarProducto(String campo, String info) {
        int idRef = 0;
        try {
            Conexion conexion = new Conexion();
            conexion.Conectar();

            Statement sentencia;
            ResultSet resultado;

            String sql = "SELECT * FROM productos WHERE " + campo + " = '" + info + "'";
            sentencia = conexion.con.createStatement();
            resultado = sentencia.executeQuery(sql);

            if (resultado.isBeforeFirst()) {
                //Si encontre la info, guardo el registro completo
                while (resultado.next()) {
                    this.id = resultado.getInt("id");
                    this.nombre = resultado.getString("nombre");
                    this.stock = resultado.getInt("stock");
                    this.precio = resultado.getFloat("precio");
                }
                //Guardo la idRef con la ID donde se encontro la info para usarla en modo programador
                idRef = getId();
                System.out.println("Se ha encontrado la informacion");
            } else {
                //Codigo interno igual a 0 porque no se encontro la info
                idRef = 0;
                System.out.println("No se ha encontrado esa informacion");
            }

            conexion.Desconectar();
        } catch (SQLException ex) {
            //Logger.getLogger(Productos.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println("Hubo un error en la busqueda del producto");
        }
        System.out.println("\n");
        return idRef;
    }

    //Mostrar producto concreto y su precio
    public void mostrarProducto(String campo, String info) {
        if (buscarProducto(campo, info) > 0) {
            System.out.println("Informacion solicitada");
            System.out.println("----------------------");
            System.out.println("Nombre: " + this.nombre);
            System.out.println("Stock: " + this.stock);
            System.out.println("Precio: " + this.precio);
            System.out.println("\n");
        }
    }

    //Agregar producto. campo en este caso siempre sera "nombre". Info será el nombre de la fruta, pe. "Platano"
    public void agregarProducto(String info) {
        //Compruebo que la informacion que se quiere agregar no existe
        String campo = "nombre";
        if (buscarProducto(campo, info) == 0) {
            try {
                System.out.println("Agregando producto...");
                System.out.println("---------------------");
                Conexion conexion = new Conexion();
                conexion.Conectar();

                Scanner entrada = new Scanner(System.in);

                PreparedStatement sentencia;

                String sql = "INSERT INTO productos (nombre, stock, precio) VALUES (?, ?, ?)";
                sentencia = conexion.con.prepareStatement(sql);

                //Agrego el nombre
                sentencia.setString(1, info);

                //Agrego stock
                System.out.print("Stock a agregar: ");
                int newStock = entrada.nextInt();
                //Control el stock desde 1 hasta 100
                newStock = control(newStock, 1, 100);
                sentencia.setInt(2, newStock);

                //Limpio buffer de entrada
                entrada.nextLine();

                //Agrego precio
                System.out.println("(recuerde en usar la coma para los decimales)");
                System.out.print("Precio a agregar: ");
                float newPrecio = entrada.nextFloat();
                //control de precio desde 0.25 hasta 100.00
                newPrecio = controlF(newPrecio, 0.25f, 100.00f);
                sentencia.setFloat(3, newPrecio);

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
            System.out.println("No puede agregar un producto con el mismo nombre");
        }
    }

    public void modificarProducto(String info) {
        //Compruebo que la informacion que se quiere modificar existe
        String campo = "nombre";
        if (buscarProducto(campo, info) != 0) {
            try {
                System.out.println("Modificando producto...");
                System.out.println("---------------------");
                Conexion conexion = new Conexion();
                conexion.Conectar();

                Scanner entrada = new Scanner(System.in);

                PreparedStatement sentencia = null;
                
                
                //Puede modificar 3 campos distintos en este caso. nombre, stock y precio
                System.out.println("Que campo quiere modificar?");
                System.out.println("1. Nombre");
                System.out.println("2. Stock");
                System.out.println("3. Precio");
                System.out.println("4. Salir de modificar");
                System.out.print("Ingrese opcion: ");
                int opc = entrada.nextInt();
                opc = control (opc, 1, 4);
                
                //Limpio buffer de entrada
                entrada.nextLine();
                
                switch (opc) {
                    case 1:
                        String sql = "UPDATE productos SET nombre = ? WHERE nombre = '" + info + "'";
                        sentencia = conexion.con.prepareStatement(sql);
                        System.out.print("Nuevo nombre: ");
                        String newName = entrada.nextLine();
                        
                        //Control de nombre nuevo no duplicado. Esta condicion indica que el nombre esta disponible
                        if(buscarProducto(campo, newName) == 0) {
                            sentencia.setString(1, newName);
                        } else {
                            System.out.println("El nombre nuevo que desea poner ya existe y no es posible utilizarlo");
                        }
                        break;
                    case 2:
                        sql = "UPDATE productos SET stock = ? WHERE stock = " + getStock();
                        sentencia = conexion.con.prepareStatement(sql);
                        System.out.print("Nuevo stock: ");
                        int newStock = entrada.nextInt();
                        //Control de stock nuevo
                        newStock = control (newStock, 1, 100);
                        sentencia.setInt(1, newStock);
                        //Limpio buffer de entrada
                        entrada.nextLine();
                        break;
                    case 3:
                        sql = "UPDATE productos SET precio = ? WHERE precio = " + getPrecio();
                        sentencia = conexion.con.prepareStatement(sql);
                        System.out.println("(recuerde que los decimales se escriben con coma)");
                        System.out.print("Nuevo precio: ");
                        float newPrice = entrada.nextFloat();
                        //Control de precio
                        newPrice = controlF(newPrice, 0.25f, 100f);
                        sentencia.setFloat(1, newPrice);
                        //Limpio buffer de entrada
                        entrada.nextLine();
                        break;
                    case 4:
                        System.out.println("Saliendo de modificar...");
                        break;
                    default:
                        throw new AssertionError();
                }
                
                //Actualizo la sentencia ejecutando todos los cambios, si es que han habido
                if(opc >= 1 && opc <= 3){
                    sentencia.executeUpdate();
                    System.out.println("\nProducto modificado correctamente\n\n");
                }
                
                //Me desconecto de la base de datos
                conexion.Desconectar();

                
            } catch (SQLException ex) {
                //Logger.getLogger(Productos.class.getName()).log(Level.SEVERE, null, ex);
                System.out.println("No ha sido posible modificar el producto");
            }

        } else {
            System.out.println("Error. No puede modificar un producto que no existe");
        }
    }

    public void borrarProducto(String info) {
        //Compruebo que la informacion que se quiere borrar existe
        String campo = "nombre";
        if (buscarProducto(campo, info) != 0) {
            try {
                Conexion conexion = new Conexion();
                conexion.Conectar();
                
                System.out.println("Borrando producto...");
                //En este caso preparamos estado
                PreparedStatement sentencia;
                String sql = "DELETE FROM productos WHERE nombre = ?";
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
            System.out.println("Error. No se puede borrar un producto que no existe");
        }
    }
    /*Funcion de control de entrada. 3 parametros de entrada: 
    numero a revisar, numero minimo posible y numero maximo posible.*/
    static int control(int opc, int min, int max) {
        while (opc < min || opc > max) {
            Scanner entradaC = new Scanner(System.in);
            System.out.println("Error en la opcion elegida...");
            System.out.print("Ud. puede elegir entre " + min + " y " + max + ": ");
            opc = entradaC.nextInt();
        }

        return opc;
    }

    /*Funcion de control de floats de entrada. 3 parametros de entrada: 
    numero a revisar, numero minimo posible y numero maximo posible.*/
    static float controlF(float opc, float min, float max) {
        while (opc < min || opc > max) {
            Scanner entradaC = new Scanner(System.in);
            System.out.println("Error en la opcion elegida...");
            System.out.print("Ud. puede elegir entre " + min + " y " + max + ": ");
            opc = entradaC.nextFloat();
        }

        return opc;
    }
}
