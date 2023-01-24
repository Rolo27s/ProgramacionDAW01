/* Programa que solo añade asesores al archivo 'asesores.txt' */
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <locale.h>
#include <wchar.h>
using namespace std;

void addRow();
char comprobarChar(char c);
bool comprobarID(string code);

int main(){
    setlocale (LC_ALL, "");

    cout << "-----------------------------------------------------\n";
    cout << "Programa que añade asesores al archivo 'asesores.txt'\n";
    cout << "-----------------------------------------------------\n\n";

    addRow();

    return 0;
}

void addRow(){
 string id, nombre, apellido, ciudad, edad, genero, consulta, lineaCompleta;
 char otro;
 fstream archivo;   
 
 do{
    cout << "Agregando un asesor nuevo...\n";
    cout << "----------------------------\n";
    
    archivo.open("asesoria.txt", ios::app);
    if (archivo.fail()){
        cout << "No se encontro el archivo\n";
    }else{
        cout << "IMPORTANTE: No usar espacios para introducir informacion. Solo caracteres alfanumericos.\n";

        cout << "Introduce codigo: ";
        cin >> id;
        do{
            if (comprobarID(id) == 0){
                cout << "\n ID introducida disponible. Todo correcto.\n";
            } else{
                cout << "ID no disponible, por favor escribe otra ID distinta: ";
                cin >> id;
            }
        }while (comprobarID(id) != 0);
        

        cout << "Introduce nombre (CUIDADO: Usar . en lugar de espacios): ";
        cin >> nombre;

        cout << "Introduce apellidos (CUIDADO: Usar . en lugar de espacios): ";
        cin >> apellido;

        cout << "Introduce ciudad: ";
        cin >> ciudad;

        cout << "Introduce edad: ";
        cin >> edad;

        cout << "Introduce genero: ";
        cin >> genero;

        cout << "Introduce consulta: ";
        cin >> consulta;

        lineaCompleta = id + " " + nombre + " " + apellido + " " + ciudad + " " + edad + " " + genero + " " + consulta;

        archivo << endl;
        archivo << lineaCompleta;
    }

    archivo.close();

    cout << "\n\tDesea agregar otro asesor? (S/N): ";
    cin >> otro;
    otro = comprobarChar (otro);

 }while(otro == 'S' || otro == 's');
}

// Comprueba si el char es S, S, N o n para un correcto funcionamiento del programa.
char comprobarChar(char c){
    while(c != 'S' && c != 's' && c != 'N' && c != 'n'){
            cout << "Opcion incorrecta\n";
            cout << "Elige (S/N): ";
            cin >> c;
        }
    return c;
}

bool comprobarID(string code){
    ifstream archivo;
    string id;

    /* Mi codigo de errores será:
        empty = 0, ID vacia y por tanto, disponible.
        empty = 1, ID ocupada. Esa id no será posible de asignar.
    */
    bool empty = 0;
   
    archivo.open("asesoria.txt", ios::in);

    if(archivo.fail()){
        cout << "No se encontro el archivo" << endl;
    }else {
        while(!archivo.eof()){
            archivo >> id;
            /* Usas la entrada archivo y lo guarda en la variable string "texto" */
            if (id == code){
                empty = 1;
                break;
            } 
        }
    }
    return empty;
}