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
    // fstream: añadir datos al final del fichero   + archivo.open ios::??

}

void leer(){
    ifstream archivo;
    string texto;

    archivo.open("menu.txt", ios::in);

    if(archivo.fail()){
        cout << "No se encontro el archivo" << endl;
    }else {
        while(!archivo.eof()){
            getline(archivo, texto);
            /* Usas la entrada archivo y lo guarda en la variable string "texto" */
            cout << texto << endl;
        }
    }
}