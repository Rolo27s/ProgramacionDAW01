//Tarea de hoy: Ejemplo de estructura con los numero complejos 2.
//Funcion que sume dos numeros complejos.

//ACTUALMENTE NO COMPILA ---- ERRORES

#include <iostream>
using namespace std;
int comprobar(int x);

struct numCompl{
    int real;
    int imag;
};
numCompl suma(numCompl a, numCompl b);
void importNumCompl(numCompl a[20]);

int main(){
    int n=0;
    numCompl num[20];
/*     numCompl result; */
    cout<<"Cuantos numeros complejos quieres introducir (min=1 y max=20)?: ";
    cin>>n;
    n=comprobar(n);

    for(int i=1;i<=n;i++){
        importNumCompl(numCompl num[i]);
    }
    cout<<endl;
 
/*     if(result.imag>=0)
        cout<<"Tu numero complejo es "<<result.real<<" + "<<result.imag<<"i"<<endl;
    else{
        cout<<"Tu numero complejo es "<<result.real<<" - "<<result.imag/-1<<"i"<<endl;
    } */

    system("pause");
    return 0;
}
void importNumCompl(numCompl a[20]){
    cout<<"Parte real del numero complejo: ";
    cin>>a.real;
    cout<<"Parte imaginaria del numero complejo: ";
    cin>>a.imag;
}
/* numCompl suma(numCompl a, numCompl b){
    numCompl c;
    c.real = a.real+b.real;
    c.imag = a.imag+b.imag;
    return c;
} */
int comprobar(int x){
    while(x<1 || x>20){
        cout<<"Seleccion erronea...\n";
        cout<<"Ingrese nuevamente la opcion: ";
        cin>>x;
    }
    return x;
}