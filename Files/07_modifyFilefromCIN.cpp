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
    // fstream: a�adir datos al final del fichero   + archivo.open ios::app (append)


    fstream archivo;
    string nombreArchivo, fraseNueva;

    cout << ("Introduce el nombre del archivo de texto a buscar para modificarlo\n (la extension del archivo de texto se a�ade autom�ticamente): ");
    getline(cin >> std::ws,nombreArchivo);
    nombreArchivo += ".txt";

    archivo.open(nombreArchivo.c_str(), ios::app);

    if(archivo.fail()){
        cout << "No se encontro el archivo" << endl;
    }else {
        cout << "Introduce la frase nueva a a�adir: ";
        getline(cin >> std::ws, fraseNueva);
        archivo << endl << fraseNueva << endl;
    }

    cout << endl;
    archivo.close();
}