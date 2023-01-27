#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <locale.h>
#include <wchar.h>
#include <cstdio>
using namespace std;

/* FUNCIONES (DECLARACION) */
void eliminar();

/* PROCEDIMIENTOS (DECLARACION) */
char comprobarChar(char c);
bool comprobarID(string code);

/* FUNCION MAIN */
int main(){
    setlocale(LC_ALL, "");
    char otro;

do {
    cout << "Programa que elimina asesores\n";
    eliminar();

    cout << "\nQuieres procesar de nuevo? (S/N): ";
    cin >> otro;
    comprobarChar(otro);
    } while (otro == 'S' || otro == 's');
    
return 0;
}



/* FUNCIONES (DEFINICION) */
void eliminar(){
    string codigoEliminar, lineaEliminada;
    string codigo, nombre, apellido, ciudad, edad, genero, consulta;
    bool encontrado;

    cout << "\n\tFuncion que elimina asesores\n";
    cout << "Que asesor quieres eliminar? Introduce su codigo: ";
    cin >> codigoEliminar;
    /*  encontrado = 1 ? TRUE
        encontrado = 0 ? FALSE
    */
    encontrado = comprobarID(codigoEliminar);

    if (encontrado) {
        ifstream archivo;
        ofstream temp;

        archivo.open("asesoria.txt", ios::in);
        temp.open("temp.txt", ios::out);

        if (archivo.fail()) {
            cout << "\nNo se encontró el archivo asesoria.txt\n";
        } else {
            while(!archivo.eof()){
                archivo >> codigo >> nombre >> apellido >> ciudad >> edad >> genero >> consulta;
                if (codigo != codigoEliminar) {
                    temp << codigo << " " << nombre << " " << apellido << " " << ciudad << " " << edad << " " << genero << " " << consulta << endl;
                } else {
                    getline(archivo, lineaEliminada);
                }
            }
        }
        archivo.close();
        temp.close();

        remove("asesoria.txt");
        rename("temp.txt", "asesoria.txt");
    
    } else {
        cout << "\n\t Asesor no encontrado...\n";
    }
    
}

/* PROCEDIMIENTOS (DEFINICION) */

/* Comprueba si el char es S, S, N o n para un correcto funcionamiento del programa. */
char comprobarChar(char c){
    while(c != 'S' && c != 's' && c != 'N' && c != 'n'){
            cout << "Opcion incorrecta\n";
            cout << "Elige (S/N): ";
            cin >> c;
        }
    return c;
}

/* Mi codigo de errores será RETURN:
        idLoc = 0, ID vacia y por tanto, disponible.
        idLoc = 1, ID ocupada. Esa id no será posible de asignar.
*/
bool comprobarID(string code){
    ifstream archivo;
    string id;
    bool idLoc = 0;
   
    archivo.open("asesoria.txt", ios::in);

    if(archivo.fail()){
        cout << "No se encontro el archivo" << endl;
    }else {
        while(!archivo.eof()){
            archivo >> id;
            /* Usas la entrada archivo y lo guarda en la variable string "texto" */
            if (id == code){
                idLoc = 1;
                break;
            } 
        }
    }
    return idLoc;
}