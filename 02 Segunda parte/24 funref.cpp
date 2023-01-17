// Solucion matemática X^n. 
// Funcion1: Guardar 2 numeros en memoria X y n.
// Funcion2: Potencia con funcion recursiva. 
#include <iostream>
using namespace std;
int dosNum(int &x, int &n);
int pot(int x, int n);
int comprobar(int x);

int main(){
    int x=0,n=0;
    dosNum(x,n);
    cout<<"El resultado es "<<pot(x,n)<<endl;

    system("pause");
    return 0;
}

int dosNum(int &x, int &n){
    cout<<"Introduce el valor de X: ";
    cin>>x;
    x=comprobar(x);
    cout<<"Introduce el valor de n: ";
    cin>>n;
    n=comprobar(n);
}

int pot(int x, int n){
    if(n>0){
        return x*=pot(x,n-1);
    }else{
        return 1;
    }
}

int comprobar(int x){
    while(x<0){
        cout<<"Seleccion erronea...\n";
        cout<<"Ingrese nuevamente la opcion: ";
        cin>>x;
    }
    return x;
}