/* Template general */
#include <stdlib.h>     // Para el uso de funciones system
#include <iostream>     // Para el uso de cin, cout
#include <locale.h>     // Para el uso de la funcion setlocale(LC_ALL, "");
#include <string.h>     // Para el uso de funciones relacionadas con strings en versiones antiguas de C++
#include <string>       // Para el uso de funciones relacionadas con strings en versiones más actuales

// Controla cantidad de numeros a mostrar con la funcion setprecision().
// cout << setprecision(10);       respeta 10 digitos de la parte entera
// cout << fixed << setprecision(2); respeta 2 digitos de la parte decimal
#include <iomanip>      // Para el uso de fixed y setprecision
using namespace std;

float comprobarNum(float a);
string comprobarCHAR(string letra);

int main(){
    string repetirTODO;

    // Para el uso de todo tipo de caracteres.
    setlocale(LC_ALL, "");

    do
    {
        // Limpio la pantalla al principio del bucle para las N veces que se repetira.
        system("cls");

        cout<<"Template basico\n";

        // Pregunto si quiero volver a repetir el programa
        cout<<"Desea volver al principio?: S o N  \t";
        cin>>repetirTODO;
        // Nos aseguramos que el datos introducido sea válido.
        repetirTODO = comprobarCHAR(repetirTODO); 
    
    } while (repetirTODO == "S" || repetirTODO == "s");
    
    cout<<"Cerrando el programa. ";
    system("pause");

    return 0;
}

// << --- FUNCIONES AUXILIARES PARA COMPROBAR LOS INPUTS --- >>
//Comprueba que el numero este en el rango correcto para el buen funcionamiento del programa
float comprobarNum(float a){
    while(a<0 || a>5){
        cout<<"Error. Ingrese nuevamente el valor: ";
        cin>>a;
    }
    return a;
}
//Comprueba para procesar otro grupo y que solo se usen 4 caracteres ('S', 's', 'N', 'n')
string comprobarCHAR(string letra){
    while(letra != "s" && letra != "S" && letra != "n" && letra != "N"){
        cout<<"Error. Ingrese nuevamente S o N: ";
        cin>>letra;
    }
    return letra;
}