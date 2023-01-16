//Introduce un numero por teclado e indica si es primo o no.
//Lectura de dato con funcion por referencia.
//Funcion recursiva que detecte si es numero primo o no. Devuelve verdadero o falso.
//Funcion auxiliar de comprobacion de numero introducido.
#include <iostream>
using namespace std;
int comprobar(int x);
int introducirNumero(int &y);
bool esPrimo(int z, int y);

int main(){
    int y=0, z=0;
    y=introducirNumero(y);
    z=y;
    cout<<"El numero "<<y<<" es primo? (0=false, 1=true): "<<esPrimo(y,z);

    cout<<endl;
    system("pause");
    return 0;
}

int comprobar(int x){
    while(x<=0){
        cout<<"Seleccion erronea...\n";
        cout<<"Ingrese nuevamente la opcion: ";
        cin>>x;
    }
    return x;
}

int introducirNumero(int &y){
    cout<<"Introduce un numero por teclado (min=1): ";
    cin>>y;
    y=comprobar(y);
    return y;
}

bool esPrimo(int z, int y){
    y=y-1;
    if(y==1){
        return true;
    }else if((z%y)==0){
        return false;
    }
    else{
        return esPrimo(z,y);
    }
}