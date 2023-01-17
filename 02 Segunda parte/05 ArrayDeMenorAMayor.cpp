#include <iostream>
using namespace std;
//Introducir por pantalla 20 numeros y sacarlos por pantalla ordenados de menor a mayor.

int main(){
    int numero[20];
    int cache=0;

    system("color 0E");
    cout<<"Escribe 20 numeros por pantalla\n";
    for(int i=0;i<20;i++){
        cout<<"Numero a guardar en la posicion "<<i<<": ";
        cin>>numero[i];
    }
    cout<<"Los numeros ordenados de menor a mayor serian:\n";
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if(numero[j]>numero[i])
            {
            cache = numero[i];
            numero[i] = numero[j];
            numero[j] = cache;
            }
        }
    }
    for(int i=0;i<20;i++){
        cout<<numero[i]<<", ";
    }
    return 0;
}