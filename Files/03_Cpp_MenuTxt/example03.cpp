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
    // fstream: a�adir datos al final del fichero

    ofstream Archivo;
    string nombreArchivo, texto;
    int i=1, nFrases;
    
    cout << ("Introduce nombre del archivo: ");
    getline(cin >> std::ws,nombreArchivo);
    
    nombreArchivo += ".txt";
    Archivo.open(nombreArchivo.c_str(), ios::out);

        if (Archivo.fail()){
            // Si ha ocurrido un error
            cout << "No se pudo abrir el archivo" << endl;
        } else {
            Archivo << "Acceso al menu de c�lculo de per�metros o �reas:\n";
            Archivo << "--------------------------------------------------\n\n";
            Archivo << "Calcularemos una de estas opciones:\n";
            Archivo << "-----------------------------------\n";
            Archivo << "  0 - Per�metro\n";
            Archivo << "  1 - �rea\n";
            Archivo << "  2 - Vol�men\n";
            Archivo << "  3 - Salir\n\n";
            Archivo << "Calcularemos una de estas opciones:\n";
            Archivo << "-----------------------------------\n";
            Archivo << "  0 - Cuadrado\n";
            Archivo << "  1 - Rect�ngulo\n";
            Archivo << "  2 - Tri�ngulo\n";
            Archivo << "  3 - Pent�gono\n";
            Archivo << "  4 - C�rculo\n";
            Archivo << "  5 - Salir\n\n";
            Archivo << "\nAcceso al menu de c�lculo de vol�menes:\n";
            Archivo << "---------------------------------------\n";
            Archivo << "Calcularemos una de estas opciones:\n";
            Archivo << "  0 - Cubo\n";
            Archivo << "  1 - Prisma\n";
            Archivo << "  2 - Pir�mide\n";
            Archivo << "  3 - Cil�ndro\n";
            Archivo << "  4 - Esfera\n";
            Archivo << "  5 - Salir\n\n";
        }
    Archivo.close(); 
}