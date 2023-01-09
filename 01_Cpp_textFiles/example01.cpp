/* ENCODING USED: windows-1252 to solve special characters*/
#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <fstream>

using namespace std;

void escribir();

int main(){
    setlocale(LC_ALL, "");

    escribir();
}

void escribir(){
    
    // ofstream: escribir en un fichero
    // ifstream: abrir un fichero de lectura
    // fstream: añadir datos al final del fichero

    ofstream Archivo;
    string nombreArchivo, texto;

    cout << ("Introduce nombre del archivo: ");
    getline(cin,nombreArchivo);
    
    nombreArchivo += ".txt";
    Archivo.open(nombreArchivo.c_str(), ios::out);

    if (Archivo.fail()){
        // Si ha ocurrido un error
        cout << "No se pudo abrir el archivo" << endl;
    } else {
        cout << "Introduzca texto: ";
        getline(cin, texto);
        Archivo << "Nombre del archivo:\n " << nombreArchivo << "\n\n" << "Contenido:\n" << texto;
    }
    Archivo.close(); 
}