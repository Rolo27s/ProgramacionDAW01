/*
ENUNCIADO DE EJERCICIO 11
Escriba, compile y ejecute un programa en C++ que aplique la recursividad para
concatenar un número de palabras digitado cuyo valor se ingresa por teclado
de un conjunto de 10 palabras que ingresa el usuario almacenadas en un
vector.
*/
#include <stdlib.h> // Libreria necesaria para el uso de comandos tipo system
#include <iostream>
#include <string.h>
using namespace std;

float comprobarNum(float a);
string comprobarCHAR(string letra);
string funcionRecursiva(string miArray[10], int &n);

string resultado; //Variable global que servirá para ver el resultado.

int main(){
    string palabras[10], opcion;
    int nPalabras=0;

    cout<<"Programa que concatena palabras de un vector\n";
    cout<<"--------------------------------------------\n\n";
    do{
        system("cls"); //Primero limpio la pantalla para cuando el programa quiera generar otro grupo nuevo.
        //Ingresamos palabras
        cout<<"Ingresando palabras...\n";
        for(int i = 0 ; i < 10 ; i++){
                cout<<"Palabra ("<<i+1<<"/10): ";
                cin>>palabras[i];
            }

        //A partir de aqui el codigo se dedica a mostrar informacion por pantalla
        cout<<"Imprimir palabras almacenadas\n\n";
        cout<<"Nro.\t\t\t"<<"Palabra\n";
        cout<<"----\t\t\t"<<"-------\n";
            for(int j = 0 ; j < 10 ; j++){
                cout<<j+1<<"\t\t\t"<<palabras[j]<<"\n";
            }
        cout<<endl;

        //Informacion para el juego de la concatenacion con funcion recursiva
        cout<<"Digite el numero de palabras a concatenar < 11: ";
        cin>>nPalabras;
        nPalabras = comprobarNum(nPalabras);
        cout<<endl;

        cout<<"El resultado de concatenar "<<nPalabras<<" palabras es:\n";
        cout<<funcionRecursiva(palabras, nPalabras);

        //Preguntamos si queremos concatenar otras palabras y volver a empezar el programa.
        cout<<"\nDesea concatenar otras palabras: S o N  ";
        cin>>opcion;
        opcion = comprobarCHAR(opcion); //Llama a la funcion comprobar Char
    }while(opcion == "S" || opcion == "s");

    return 0;
}

string funcionRecursiva(string miArray[10], int &n){
    if(n >= 1){
        resultado = resultado + miArray[n-1] + " ";
        n--;
        return funcionRecursiva(miArray, n);
    }else{
        return resultado;
    }
}

// <-- CONTROL DE INFORMACION DE ENTRADA -->
//Comprueba para procesar otro grupo y que solo se usen 4 caracteres ('S', 's', 'N', 'n')
string comprobarCHAR(string letra){
    do{
        if(letra != "s" && letra != "S" && letra != "n" && letra != "N"){
            cout<<"Opcion erronea, introduzca otra vez S o N: ";
            cin>>letra;
        }
    }while(letra != "s" && letra != "S" && letra != "n" && letra != "N");
    return letra;
}
//Comprueba que el numero sea mayor o igual a 0 para el buen funcionamiento del programa
float comprobarNum(float a){
    while(a < 2 || a > 10){
        cout<<"Error... Ingrese nuevamente el valor (2-10): ";
        cin>>a;
    }
    return a;
}