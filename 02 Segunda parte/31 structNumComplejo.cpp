//Tarea de hoy: Ejemplo de estructura con los numero complejos.
#include <iostream>
using namespace std;

struct numCompl{
    int real;
    int imag;
};

int main(){
    numCompl num;
    
    cout<<"Vamos a hacer la composicion de un numero complejo\n";
    cout<<"Introduce la parte real: ";
    cin>>num.real;
    cout<<"Introduce la parte imaginaria: ";
    cin>>num.imag;
    
    if(num.imag>=0)
        cout<<"Tu numero complejo es "<<num.real<<" + "<<num.imag<<"i"<<endl;
    else{
        cout<<"Tu numero complejo es "<<num.real<<" - "<<num.imag/-1<<"i"<<endl;
    }

    system("pause");
    return 0;
}