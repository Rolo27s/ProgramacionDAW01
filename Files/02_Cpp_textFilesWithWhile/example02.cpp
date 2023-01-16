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
    int i=1, nFrases;
    
    cout << ("Introduce nombre del archivo: ");
    getline(cin >> std::ws,nombreArchivo);
    
    nombreArchivo += ".txt";
    Archivo.open(nombreArchivo.c_str(), ios::out);

    cout << "Cuantas frases quieres escribir dentro del archivo?: ";
    cin >> nFrases;
    
    while(i <= nFrases){
        if (Archivo.fail()){
            // Si ha ocurrido un error
            cout << "No se pudo abrir el archivo" << endl;
        } else {
            cout << "Introduzca texto: ";
            getline(cin >> std::ws, texto);
            Archivo << "Contenido de la frase " << i << "/" << nFrases << ": "<< texto;
            Archivo << endl;
        }
        i++;
    }
    Archivo.close(); 
}