/*
ENUNCIADO
Escriba, compile y ejecute un programa en C++ que emplee vectores para
almacenar el tiempo de caída desde una altura con variaciones de 1 m.
Imprimir la altura y el tiempo de caída, emplee la fórmula tc = raíz (2 * altura /
g).
*/
#include <iostream>
#include <math.h>
// Libreria que permite definir exactamente el numero de precision de decimales, entre otras cosas...
// setprecision(5) muestra 4 decimales de los elementos que se muestren si la parte no decimal es menor o igual a 9, es decir, el numero tendrá 5 digitos en total.
//*Si la parte entera es 0, se mostraran 5 decimales a parte del 0 como parte entera, es decir, 6 digitos.
#include <iomanip>
using namespace std;
const float G=9.8; // Constante gravitatoria (m/s^2)
int controlarAltura(int h);
char comprobarRepetir(char c);

int main(){
    int alturaMax=0, i=0;
    int altura[1000];
    float tiempo[1000];
    char repetir='A';

    do{
        cout<<"Programa que calcula el tiempo de caida libre!\n";
        cout<<"----------------------------------------------\n";
        cout<<"Digite la altura de caida en (m): ";
        cin>>alturaMax;
        alturaMax = controlarAltura(alturaMax); //Llama a la funcion controlarAltura.
        cout<<"Imprimir altura y tiempo de caida libre\n";
        cout<<"---------------------------------------\n";
        cout<<"Altura(m)\t\tTiempo de caida(s)\n";
        cout<<"---------\t\t------------------\n";
        //Controlo la altura maxima y voy guardando la informacion en arrays.
        //La posicion [0] del array sera relacionado a la altura maxima.
        //Continuara hasta que la altura maxima sea 1.
        for(alturaMax, i;alturaMax>=1;alturaMax--, i++){
            altura[i] = alturaMax;
            tiempo[i] = sqrt(2*alturaMax/G);
            cout<<setprecision(5)<<altura[i]<<"\t\t\t"<<tiempo[i];
            cout<<endl;
        }
    cout<<"Desea realizar otro calculo: S o N  ";
    cin>>repetir;
    repetir = comprobarRepetir(repetir);
    }while(repetir=='S'); //Tuve en cuenta la opcion de 's' en la funcion que comprueba
    return 0;
}
//Controla la altura para que sea mayor a 0.
int controlarAltura(int h){
    while(h<=0){
        cout<<"Altura erronea...\n";
        cout<<"Digite la altura de caida en (m): ";
        cin>>h;
    }
    return h;
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