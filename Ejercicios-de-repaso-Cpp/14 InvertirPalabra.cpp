/*
EJERCICIO 14
Escriba, compile y ejecute un programa en C++ que aplique la recursividad para
invertir las letras de máximo 20 palabras almacenadas en un vector
*/

#include <stdlib.h>
#include <iostream>
#include <locale.h>
#include <string.h>
#include <string>

using namespace std;
const int N = 20;   // Usaremos de momento 20 palabras como máximo

string palabraNormal[N], palabraInvertida[N];
string palabraInvertidaAUX;
int tamPalabra[N];

void ingresaPalabra(int nPalabras, int i);
void longitudPalabra(int numPal);
string invertirPalabra (string palNorm, int longi);
void mostrar(int numP, int contador);

float comprobarNum(float a);
string comprobarCHAR(string letra);

int main(){
    string repetirTODO;
    int numPalabras=0, i=0;

    // Para el uso de todo tipo de caracteres.
    setlocale(LC_ALL, "");

    do
    {
        // Limpio la pantalla al principio del bucle para las N veces que se repetira.
        system("cls");

        cout<<"Programa que invierte las letras de maximo 20 palabras de un vector\n";
        cout<<"-------------------------------------------------------------------\n\n";
        cout<<"Cuantas palabras va a querer invertir (min=1 y max 20)?: ";
        cin>>numPalabras;
        // Nos aseguramos que el datos introducido sea válido.
        comprobarNum(numPalabras);

        // Llamamos a ingresaPalabra
        ingresaPalabra(numPalabras, i);

        // Reseteo el contador i
        i=0;

        // Llamo a la funcion longitudPalabra
        longitudPalabra(numPalabras);

        cout<<" No. de  "<<"\t\t Palabra "<<"\t\t  Palabra  \n";
        cout<<" palabra "<<"\t\t Inicial "<<"\t\t Invertida \n";
        cout<<"---------"<<"\t\t---------"<<"\t\t-----------\n";
        
        // Llamo a la funcion mostrar
        mostrar(numPalabras, i);

        cout<<"Desea invertir otro grupo de palabras: S o N  \t";
        cin>>repetirTODO;
        
        // Nos aseguramos que el datos introducido sea válido.
        repetirTODO = comprobarCHAR(repetirTODO); 
    } while (repetirTODO == "S" || repetirTODO == "s");
    
    cout<<"Cerrando el programa. ";
    system("pause");

    return 0;
}
//Funcion que ingresa "nPalabras". Usaremos el contador i para ir avanzando en el array de palabraNormal
void ingresaPalabra(int nPalabras, int i){
    
    // Cuando la funcion recursiva valga 0, saldrá y mientras sea mayor que 0 pedirá más palabras.
    if(nPalabras > 0){
        cout<<"Digite la palabra numero "<<i+1<<" : ";
        cin>>palabraNormal[i];
        nPalabras--;
        i++;
        ingresaPalabra(nPalabras, i);
    }
}

// Funcion que mide la longitud de las palabras ingresadas por teclado
// Tambien llama a la funcion invertirPalabra por cada palabra normal ingresada
// Guarda la palabra invertida en el array de string global.
void longitudPalabra(int numPal){
    for(int i = 0; i < numPal; i++){
        tamPalabra[i] = palabraNormal[i].size();
        palabraInvertidaAUX = "";
        palabraInvertida[i] = invertirPalabra(palabraNormal[i], tamPalabra[i]);
    }
}

// Funcion recursiva para invertir palabra a palabra.
// Usamos la propiedad de acceder a cada char del string con los corchetes.
string invertirPalabra (string palNorm, int longi){
    if(longi >= 0){
        palabraInvertidaAUX += palNorm[longi];
        longi--;
        invertirPalabra (palNorm, longi);
    }
    return palabraInvertidaAUX;
}

// Funcion encargada de mostrar la informacion recopilada al usuario
// Las entradas son el numero de palabras procesadas y un contador que inicia en 0
void mostrar(int numP, int contador){
    if(numP > 0){
        cout <<"    "<<contador + 1<<"  \t\t\t " <<palabraNormal[contador]<<"     \t\t"<<palabraInvertida[contador]<<endl;
        numP--;
        contador++;
        mostrar(numP, contador);
    }

}


// << --- FUNCIONES AUXILIARES PARA COMPROBAR LOS INPUTS --- >>
//Comprueba que el numero no sea menor que 1 o mayor que 20 para el buen funcionamiento del programa.
float comprobarNum(float a){
    while(a<1 || a>20){
        cout<<"Error. Ingrese nuevamente el valor: ";
        cin>>a;
    }
    return a;
}
//Comprueba para procesar otro grupo y que solo se usen 4 caracteres ('S', 's', 'N', 'n')
string comprobarCHAR(string letra){
    do{
        if(letra != "s" && letra != "S" && letra != "n" && letra != "N"){
            cout<<"Error. Introduzca otra vez S o N: ";
            cin>>letra;
        }
    }while(letra !="s" && letra !="S" && letra !="n" && letra !="N");
    return letra;
}

