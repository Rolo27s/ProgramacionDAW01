/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package ej56bien;

import controles.controles;
import java.util.Scanner;
import tablas.*;

/**
 *
 * @author Fran_Rodriguez
 */
public class Ej56Bien {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        Scanner entradaPause = new Scanner(System.in);
        Scanner entradaText = new Scanner(System.in);
        controles opc = new controles();
        Usuario usuario = new Usuario();
        Visita visita = new Visita();

        do {

            // TODO code application logic here
            System.out.println("Programa de gestoria");
            System.out.println("--------------------");
            System.out.println("1. Mostrar usuario");
            System.out.println("2. Mostrar visita");
            System.out.println("3. Dar de alta usuario");
            System.out.println("4. Dar de alta visita");
            System.out.println("5. Borrar usuario");
            System.out.println("6. Borrar visita");
            System.out.println("7. Salir");
            System.out.print("Elige opcion: ");
            opc.setNumInt(entrada.nextInt());
            opc.controlInt(1, 7);
            
            String info;
            switch (opc.getNumInt()) {
                //Mostrar usuario
                case 1:
                    System.out.println("Por que campo quieres buscar?");
                    System.out.println("1. NIF");
                    System.out.println("2. Nombre");
                    System.out.println("3. Apellidos");
                    System.out.println("4. Correo_electronico");
                    System.out.println("5. Telefono");
                    System.out.println("6. Volver al menu principal");
                    System.out.print("Ingresa una opcion: ");
                    opc.setNumInt(entrada.nextInt());
                    opc.controlInt(1, 6);

                    
                    switch (opc.getNumInt()) {
                        case 1 -> {
                            System.out.print("Ingresa NIF: ");
                            info = entradaText.nextLine();
                            usuario.mostrarUsuario("NIF", info);
                        }
                        case 2 -> {
                            System.out.print("Ingresa Nombre: ");
                            info = entradaText.nextLine();
                            usuario.mostrarUsuario("Nombre", info);
                        }
                        case 3 -> {
                            System.out.print("Ingresa Apellidos: ");
                            info = entradaText.nextLine();
                            usuario.mostrarUsuario("Apellidos", info);
                        }
                        case 4 -> {
                            System.out.print("Ingresa Correo electronico: ");
                            info = entradaText.nextLine();
                            usuario.mostrarUsuario("Correo_electronico", info);
                        }
                        case 5 -> {
                            System.out.print("Ingresa Telefono: ");
                            info = entradaText.nextLine();
                            usuario.mostrarUsuario("Telefono", info);
                        }
                        case 6 ->
                            System.out.println("Volviendo al menu principal...");
                        default ->
                            throw new AssertionError();
                    }

                    break;
                // Mostrar visita  
                // Cuando accedo a buscar visita, tengo que mostrar el total apagar del usuario de la visita 
                // El campo a pasarle debe ser nif
                case 2:
                    System.out.println("Por que campo quieres buscar?");
                    System.out.println("1. NIF");
                    System.out.println("2. Fecha_visita");
                    System.out.println("3. Consulta");
                    System.out.println("4. Volver al menu principal");
                    System.out.print("Ingresa una opcion: ");
                    opc.setNumInt(entrada.nextInt());
                    opc.controlInt(1, 4);

                    switch (opc.getNumInt()) {
                        case 1 -> {
                            System.out.print("Ingresa NIF: ");
                            info = entradaText.nextLine();
                            visita.mostrarVisita("NIF", info);
                        }
                        case 2 -> {
                            System.out.print("Ingresa Fecha_visita (YYYY-MM-DD): ");
                            info = entradaText.nextLine();
                            visita.mostrarVisita("Fecha_visita", info);
                        }
                        case 3 -> {
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
                            switch (opc.getNumInt()) {
                                case 1 -> opcConsulta = "Contable";
                                case 2 -> opcConsulta = "Finanzas";
                                case 3 -> opcConsulta = "Inversion";
                                case 4 -> opcConsulta = "Otra";
                                default -> throw new AssertionError();
                            }
                            visita.mostrarVisita("Consulta", opcConsulta);
                        }
                        case 4 ->
                            System.out.println("Volviendo al menu principal...");
                        default ->
                            throw new AssertionError();
                    }
                    break;

                //Agregar usuario  
                case 3:
                    System.out.print("Ingresa el nif a agregar: ");
                    info = entradaText.nextLine();
                    usuario.agregarUsuario("nif", info);
                    break;

                //Agregar visita    campo debe ser NIF
                case 4:
                    System.out.print("Ingresa el nif para la visita: ");
                    info = entradaText.nextLine();
                    visita.agregarVisita("nif", info);
                    break;

                //Borrar usuario    
                case 5:
                    System.out.print("Ingresa el nif a borrar: ");
                    info = entradaText.nextLine();
                    usuario.borrarUsuario("nif", info);
                    break;

                //Borrar visita    
                case 6:
                    System.out.print("Ingresa el nif del usuario para borrar sus visitas: ");
                    info = entradaText.nextLine();
                    visita.borrarVisita("nif", info);
                    break;

                //Salir
                case 7:
                    System.out.println("Cerrando el programa");
                    break;
                default:
                    throw new AssertionError();
            }

            if (opc.getNumInt() != 7) {
                System.out.println("\n\nIngrese una tecla para continuar...\n\n\n");
                entradaPause.nextLine();
            }

        } while (opc.getNumInt() != 7);
    }

}
