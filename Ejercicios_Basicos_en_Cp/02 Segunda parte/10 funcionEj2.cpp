#include <iostream>
using namespace std;
int suma(int a, int b); //declaramos la funcion al principio y ya no necesitamos tener cuidado con la lectura en cascada.
int resta(int a, int b);
int mult(int a, int b);
int divi(int a, int b);
int acarr(int a, int b);

int main(){
    int a=0, b=0, res=0;
        cout<<"Vamos a hacer una serie de operaciones, dame dos numeros\n";
        cout<<"Primer numero:\t";
        cin>>a;
        cout<<"Segundo numero:\t";
        cin>>b;

        res=suma(a,b);
        cout<<"\nLa suma es:\t\t\t"<<res;  

        res=resta(a,b);
        cout<<"\nLa resta es:\t\t\t"<<res;

        res=mult(a,b);
        cout<<"\nLa multiplicacion es:\t\t"<<res;

        res=divi(a,b);
        cout<<"\nLa division es:\t\t\t"<<res;

        res=acarr(a,b);
        cout<<"\nEl acarreo de la division es:\t"<<res;
        cout<<endl;
    system("pause");
    return 0;
}
int suma(int d, int e){
    int c;
    c = d+e;
    return c;
}
int resta(int f, int g){
    int c;
    c = f-g;
    return c;
}
int divi(int h, int i){
    int c;
    c = h/i;
    return c;
}
int mult(int j, int k){
    int c;
    c = j*k;
    return c;
}
int acarr(int l, int m){
    int c;
    c = l%m;
    return c;
}