#include <iostream>
using namespace std;
/*
ESTUDIAREMOS SI UN NUMERO INTRODUCIDO POR TECLADO ES MULTIPLO DE 3, 4 O 5. 
El 0 solo es multiplo de 0. 
Los multiplos pueden ser de numeros negativos.
La clave de la resolucion de este problema es el control del acarreo de la division, de tal modo que cuando sea 0, será multiplo de.
REPETIREMOS LA OPERACION SEGUN EL NUMERO DE VECES QUE QUIERA EL USUARIO
*/
int main(){
    int num=0, rep=0, cont=1;
    cout<<"Cuantas veces quieres repetir el programa de calcular multiplos?: ";
    cin>>rep;
    while(rep<1){
        cout<<"Debemos ejecutar el programa al menos una vez (1): ";
        cin>>rep;
    }
    while(rep >= cont){
    cout<<"\nIntroduce un numero para verificar si es multiplo de 3, 4 y/o 5: ";
    cin>>num;
        for(int i=3;i<=5;i++){
            if(num%i == 0 && num!=0){
                cout<<" ---→ El numero introducido es multiplo de "<<i<<endl;
            }else{
                cout<<"El numero introducido NO es multiplo de "<<i<<"..."<<endl;
            }
        }
        cont++;
    }
    cout<<"\nRecuento de numero de soluciones aportadas = "<<cont-1<<endl;
    system("pause");
    return 0;
}