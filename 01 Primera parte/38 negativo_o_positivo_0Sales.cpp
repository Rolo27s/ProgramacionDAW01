#include <iostream>
#include <string.h>
using namespace std;
//PROGRAMA QUE INDICA SI UN NUMERO ES NEGATIVO O POSITIVO. SI ES 0, SALE.
int main(){
    int a=0;
    do{
        cout<<"Introduce un numero: ";
        cin>>a;
        
        if(a<0){
            cout<<"El numero "<<a<<" es negativo.\n";
        }else if(a>0){
            cout<<"El numero "<<a<<" es positivo.\n";
        }else{
            cout<<"Has introducido el numero 0 y entiendo que quieres cerrar el programa.\n";
        }
    }while(a!=0);
    cout<<"Cerrando el programa\n";
    system("pause");
    return 0;
}