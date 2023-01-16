/* ENCODING USED: windows-1252 to solve special characters*/
#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <fstream>

using namespace std;

void escribir();
void leer();

int main(){
    setlocale(LC_ALL, "");
    
    leer();
}

void escribir(){
    
    // ofstream: escribir en un fichero             + archivo.open ios::out
    // ifstream: abrir un fichero de lectura        + archivo.open ios::in
    // fstream: a�adir datos al final del fichero   + archivo.open ios::??

}

void leer(){
    ifstream archivo;
    string nombreArchivo, texto;

    cout << ("Introduce el nombre del archivo de texto a buscar (la extension del archivo de texto se a�ade autom�ticamente): ");
    getline(cin >> std::ws,nombreArchivo);
    nombreArchivo += ".txt";

    archivo.open(nombreArchivo.c_str(), ios::in);

    if(archivo.fail()){
        cout << "No se encontro el archivo" << endl;
    }else {
        while(!archivo.eof()){
            getline(archivo, texto);
            /* Usas la entrada archivo y lo guarda en la variable string "texto" */
            cout << texto << endl;
        }
    }
    cout << endl;
    archivo.close();
}