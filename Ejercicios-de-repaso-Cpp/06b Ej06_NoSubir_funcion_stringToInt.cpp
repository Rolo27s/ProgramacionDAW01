#include <stdlib.h> //Para el uso de system
#include <iostream>
#include <string.h> //Controla cadena de caracteres
#include <math.h>
using namespace std;
//Convertir numero de sistema decimal a binario.
//Para la solucion pediremos un numero natural n >= 0 que convertiremos a binario
//Usaremos el operador % para ir consiguiendo el resto y / para ir dividiendo n.
//Caso ejemplo:
//n=13 n%2=1 n/2=6
//n=6 n%2=0 n/2=3
//n=3 n%2=1 n/2=1
//n=1 n%2=1 n/2=0
//n=0....fin del programa cuando n valga cero. El numero binario sería 1101.
int comprobar(int a);
int decimalBinario(int d);
char comprobarRepetir(char c);
int stringToInteger(string str); 

int main(){
    int nDecimal=0, nBinario=0;
    char repetir='S';

    do{
        cout<<"Programa que convierte un numero del sistema decimal al binario!\n";
        cout<<"----------------------------------------------------------------\n\n";
        cout<<"Digite el numero decimal natural: \t";
        cin>>nDecimal;
        nDecimal=comprobar(nDecimal); //Nos aseguramos que el datos introducido sea válido.
        cout<<"Numero digitado en sistema decimal: \t"<<nDecimal<<endl;
        nBinario=decimalBinario(nDecimal); //Convertimos decimal a binario.
        cout<<"Numero convertido al sistema binario: \t"<<nBinario<<endl;
        cout<<"Desea convertir otro numero: S o N  \t";
        cin>>repetir;
        repetir = comprobarRepetir(repetir); //Nos aseguramos que el datos introducido sea válido.
    }while(repetir=='S');
    return 0;
}

//Controla que nDecimal sea mayor o igual a 0.
int comprobar(int a){
    while(a<0){
        cout<<"\nNumero erroneo. Introduce un valor mayor o igual a 0: ";
        cin>>a;
    }
    return a;
}

//Convierto el numero Decimal a numero binario.
int decimalBinario(int d){
    string binary="";
    while(d>=1){
        //Usamos el resto con el divisor 2 porque se busca convertir a binario.
        //Si queremos pasar a octal, hexadecimal, etc, cambiaríamos el divisor a 8, 16... y habría que modificar el if
        if(d%2==0){
            binary = "0" + binary;
        }else{
            binary = "1" + binary;
        }
        d = d/2;
        }
    
    return stringToInteger(binary); //Al devolver el numero binario de tipo int, permite en un futuro operar con el.
}

//Compruebo que se teclee 'S', 's', 'N', 'n'. Si escribe 's', la convierto a 'S'.
char comprobarRepetir(char c){
    while(c!='S'&&c!='s'&&c!='N'&&c!='n'){
        cout<<"\nNo le he entendido...\n";
        cout<<"Desea realizar otra conversion: S o N   ";
        cin>>c;
    }
    if(c=='s') c='S'; //Como hago el if en una sola línea y es muy simple, no necesito llaves.
    return c;
}

//Convierte una cadena de caracteres "string" a tipo "int"
//Funcion copiada de internet. Entiendo que usa referencias con el codigo ASCII
int stringToInteger(string str){
    int num=0, size=str.size();

    for(int i=0, j=size; i<size; i++)
        num += (str[--j]-'0')*pow(10,i);
    
    return num;
}