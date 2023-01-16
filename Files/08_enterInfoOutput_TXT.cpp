/* ENCODING USED: windows-1252 to solve special characters*/
#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <fstream>
/*
#include <bits/stdc++.h>
cout << fixed << setprecision(6) << pi << " " << endl;
*/
using namespace std;

const int N = 10; // Mi listado tendra de momento 10 registros

struct user{
    int id;
    string nombre;
    string apellido;
    int edad;
    char genero;
    float prestamo;
    int plazoMeses;
};

user registro [N];

float comprobarNum(float a);
char comprobarChar(char c);
char comprobarCharGenero(char g);
void consoleLogCpp();
void ingresarInfo();
void generarTXT();

int main(){
    setlocale(LC_ALL, "");
    char again;

    do{
        system ("cls");

        ingresarInfo();
        generarTXT();

        /* Muestra la info por consola */
        consoleLogCpp();

        cout << "\nDesea procesar nuevamente: S o N:";
        cin >> again;
        again = comprobarChar(again);
    }while(again == 'S' || again == 's');
    return 0;
}

char comprobarChar(char c){
    while(c != 'S' && c != 's' && c != 'N' && c != 'n'){
            cout << "Opcion incorrecta\n";
            cout << "Elige (S/N): ";
            cin >> c;
        }
    return c;
}

char comprobarCharGenero(char g){
    while(g != 'M' && g != 'm' && g != 'F' && g != 'f'){
            cout << "Opcion incorrecta\n";
            cout << "Elige M (Male) o F (Female): ";
            cin >> g;
        }
    return g;
}

// Funcion que comprueba que el número introducido sea mayor a 0 para el uso correcto del programa
float comprobarNum(float a){
    while(a <= 0){
        cout << "Opcion incorrecta\n";
        cout << "Introduce valor: ";
        cin >> a;
    }
    return a;
}

void ingresarInfo(){
    int idReg = 1010;

    cout << "Comienzo de ingreso de informacion:\n";
    cout << "-----------------------------------\n";

    for(int i = 0; i < N; i++){
        /* Agrego el id del usuario */
        cout << "\nRegistro numero " << i+1 << ".\n";
        cout << "----------------------\n";
        cout << "El id del registro " << i+1 << " es: " << idReg << endl;
        registro[i].id = idReg;

        /* Agrego el nombre del usuario */
        cout << "Nombre (" << i+1 << "/" << N << "): ";
        getline(cin >> std::ws, registro[i].nombre);

        /* Agrego el apellido del usuario */
        cout << "Apellidos (" << i+1 << "/" << N << "): " ;
        getline(cin >> std::ws, registro[i].apellido);

        /* Agrego la edad del usuario */
        cout << "Edad (" << i+1 << "/" << N << "): ";
        cin >> registro[i].edad;
        registro[i].edad = comprobarNum(registro[i].edad);

        /* Agrego el genero del usuario (M de Male o F de Female) */
        cout << "Genero (M/F) (" << i+1 << "/" << N << "): ";
        cin >> registro[i].genero;
        registro[i].genero = comprobarCharGenero(registro[i].genero);

        /* Agrego el prestamo del usuario */
        cout << "Monto del prestamo (" << i+1 << "/" << N << "): ";
        cin >> registro[i].prestamo;
        registro[i].prestamo = comprobarNum(registro[i].prestamo);

        /* Agrego el plazo de meses */
        cout << "Plazo de meses (" << i+1 << "/" << N << "): ";
        cin >> registro[i].plazoMeses;
        registro[i].plazoMeses = comprobarNum(registro[i].plazoMeses);

        /* Condiciono como autoincremental de 10 en 10 el registro */
        idReg += 10;
    }
    /* Reseteo el id de registro */
    idReg = 1010;
}
    
void generarTXT(){
    
    // ofstream: escribir en un fichero             + archivo.open ios::out
    // ifstream: abrir un fichero de lectura        + archivo.open ios::in
    // fstream: añadir datos al final del fichero   + archivo.open ios::app (append)

    fstream archivo;
    string nombreArchivo = "informe.txt";

    /* Abrimos o generamos el archivo informe.txt*/
    archivo.open(nombreArchivo.c_str(), ios::app);

    if(archivo.fail()){
        cout << "No se encontro el archivo" << endl;
    }else {
        for(int i=0; i < N; i++){
            archivo << registro[i].id << " "<< registro[i].nombre << " "<< registro[i].apellido << " "<< registro[i].edad << " "<< registro[i].genero << " "<<registro[i].prestamo << " "<<registro[i].plazoMeses;
            archivo << endl;
        }
    }

    cout << endl;
    archivo.close();
}

void consoleLogCpp(){
    cout << "\tPrograma que lee " << N << " registros y genera el archivo de salida informe.txt\n";
    cout << "\t-------------------------------------------------------------------------------\n\n";
    cout << "\t\t Datos de los registros de crédito\n";
    cout << "\t\t-----------------------------------\n\n";

    cout << "Nit." << "\t  Nombres  " << "\t  Apellidos  " << "\tGenero" << "\tEdad " << " \tPrestamo " << "\tPlazo meses\n";
    cout << "----" << "\t  -------  " << "\t  ---------  " << "\t------"<< " \t---- " << " \t-------- " << "\t-----------\n";
    for(int i=0; i < N; i++){
        cout << registro[i].id << "\t"<<registro[i].nombre << "\t"<<registro[i].apellido << "\t"<<registro[i].edad << "\t"<<registro[i].genero << "\t"<<registro[i].prestamo << "\t\t"<<registro[i].plazoMeses;
        cout << endl;
    }
    cout << "----" << "\t  -------  " << "\t  ---------  " << "\t------"<< " \t---- " << " \t-------- " << "\t-----------\n\n";
}