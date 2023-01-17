//Longitud de cilindro -→ l = m / (d*pi*r^2)

#include <iostream>
#include <string.h>
#include <math.h>
//Aportación de Antonio que de momento no me funciona...
/* #include <wchar.h>    // UTF-8 en C++
#include <locale.h>   // UTF-8 en C++
setlocale(LC_ALL, ""); // UTF-8 en C++ */

using namespace std;
const float DEN=2.7;

float comprobar(float a);
/* char comprobarChar(char b); */
void comprobarCHAR(string &letra);
void programa();

int main(){
    string opcion="S";
    while(opcion=="S"||opcion=="s"){
        programa();
        cout<<"Desea procesar otro cilindro: S o N  ";
/*        cin>>opcion; */
/*        opcion=comprobarChar(opcion); */
    comprobarCHAR(opcion);
    }

    return 0;
}

void programa(){
    float masa=0, radio=0;
    
    cout<<"Programa que calcula la longitud de un cilindro de aluminio!\n";
    cout<<"------------------------------------------------------------\n\n";
    cout<<"Captura y validacion de datos";
    cout<<"-----------------------------\n\n";
    cout<<"Digite la masa del cilindro en gramos: ";
    cin>>masa;
    masa=comprobar(masa);
    cout<<endl;

    cout<<"Digite el radio del cilindro en cm: ";
    cin>>radio;
    radio=comprobar(radio);
    cout<<endl;

    cout<<"Calculando longitud del cilindro...\n\n";
    cout<<"Imprimir datos y resultados\n";
    cout<<"-------------------------------------------\n\n";
    cout<<"Masa del cilindro en gramos: \t"<<masa<<endl;
    cout<<"Radio del cilindro en cm: \t"<<radio<<endl;
    cout<<"Densidad del aluminio g/cm^3: \t"<<DEN<<endl;
    cout<<"Longitud del cilindro en cm: \t"<<masa/(DEN*M_PI*pow(radio,2))<<endl; //M_PI es el numero Pi en la libreria Math
    cout<<"-------------------------------------------\n\n\n\n";
}

float comprobar(float a){
    while(a<=0){
        cout<<"Numero erroneo, ingrese nuevamente el valor: ";
        cin>>a;
    }
    return a;
}
//Esta funcion de comprobarChar es recursiva y prefiero usar otro método con do---while.
/* char comprobarChar(char b){
        if(b=='S'||b=='s'||b=='N'||b=='n'){
            return b;
        }else{
            cout<<"Opcion erronea, ingrese nuevamente el valor S o N: ";
            cin>>&b;
            return comprobarChar(b);
        }
} */
void comprobarCHAR(string &letra){
    do{
        cin>>letra;
        if(letra!="s"&&letra!="S"&&letra!="n"&&letra!="N"){
            cout<<"opcion erronea, introduzca otra vez S o N: ";
        }
    }while(letra!="s"&&letra!="S"&&letra!="n"&&letra!="N");
}
