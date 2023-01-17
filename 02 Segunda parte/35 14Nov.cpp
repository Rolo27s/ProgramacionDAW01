#include <iostream>
#include <string.h>
using namespace std;

int main(){
    string cadena;
    string palabra=".Adios.";

    cout<<"introduzca una cadena de caracteres: ";
    getline(cin, cadena);
    cout<<endl<<cadena;

    cout<<endl<<"Tamano: "<<cadena.size()<<endl; //Tamaño de la cadena de caracteres
    cout<<endl<<"Longitud: "<<cadena.length()<<endl; //Longitud de la cadena de caracteres
    cout<<endl<<"Capacidad: "<<cadena.capacity()<<endl; //Capacidad de la cadena de caracteres
    cout<<endl<<"Tamano maximo: "<<cadena.max_size()<<endl; //Tamaño máximo de la cadena de caracteres

    if(cadena.empty()){ //Si "cadena" esta vacio...
        cout<<"La cadena esta vacia"<<endl;
    }else{
        cout<<"La cadena tiene contenido"<<endl;
    }

/*  cadena.insert(5, palabra); // Inserta la cadena "palabra" en la posicion 5 en este caso.
    cout<<"Mi nueva cadena es: "<<cadena<<endl; */

    cadena.insert(cadena.size(), palabra); // Inserta la cadena "palabra" en la posicion final en este caso.
    cout<<"Mi nueva cadena es: "<<cadena<<endl;

    return 0;
}