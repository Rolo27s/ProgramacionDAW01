/* ENCODING USED: windows-1252 to solve special characters*/
#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <fstream>

using namespace std;

void modificar();

int main(){
    setlocale(LC_ALL, "");
    
    modificar();
}

void modificar(){
    
    // ofstream: escribir en un fichero             + archivo.open ios::out
    // ifstream: abrir un fichero de lectura        + archivo.open ios::in
    // fstream: añadir datos al final del fichero   + archivo.open ios::app (append)


    fstream archivo;
    string nombreArchivo, fraseNueva;

    cout << ("Introduce el nombre del archivo de texto a buscar para modificarlo\n (la extension del archivo de texto se añade automáticamente): ");
    getline(cin >> std::ws,nombreArchivo);
    nombreArchivo += ".txt";

    archivo.open(nombreArchivo.c_str(), ios::app);

    if(archivo.fail()){
        cout << "No se encontro el archivo" << endl;
    }else {
        cout << "Introduce la frase nueva a añadir: ";
        getline(cin >> std::ws, fraseNueva);
        archivo << endl << fraseNueva << endl;
    }

    cout << endl;
    archivo.close();
}