//Tarea de hoy: Ejemplo de estructura con los numero complejos 2.
//Funcion que sume dos numeros complejos.
#include <iostream>
using namespace std;

struct numCompl{
    int real;
    int imag;
};
numCompl suma(numCompl a, numCompl b);
void importNumCompl(numCompl &a);

int main(){
    numCompl a,b, result;
    cout<<"Primer numero complejo\n";
    importNumCompl(a);
    cout<<"Segundo numero complejo\n";
    importNumCompl(b);
    cout<<endl;
    result=suma(a,b);
    if(result.imag>=0)
        cout<<"Tu numero complejo es "<<result.real<<" + "<<result.imag<<"i"<<endl;
    else{
        cout<<"Tu numero complejo es "<<result.real<<" - "<<result.imag/-1<<"i"<<endl;
    }

    system("pause");
    return 0;
}
void importNumCompl(numCompl &a){
    cout<<"Parte real del numero complejo: ";
    cin>>a.real;
    cout<<"Parte imaginaria del numero complejo: ";
    cin>>a.imag;
}
numCompl suma(numCompl a, numCompl b){
    numCompl c;
    c.real = a.real+b.real;
    c.imag = a.imag+b.imag;
    return c;
}