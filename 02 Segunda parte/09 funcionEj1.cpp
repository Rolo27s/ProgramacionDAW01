#include <iostream>
using namespace std;
int suma(int a, int b); //declaramos la funcion al principio y ya no necesitamos tener cuidado con la lectura en cascada.
int resta(int a, int b);
int multi(int a, int b);
int divi(int a, int b);
int acarr(int a, int b);

int main(){
    int a=0, b=0, res=0;
        res=suma(a,b);
        cout<<"La suma es: "<<res<<endl;
        
        res=resta(a,b);
        cout<<"La resta es: "<<res<<endl;

        res=multi(a,b);
        cout<<"La multiplicacion es: "<<res<<endl;

        res=divi(a,b);
        cout<<"La division es: "<<res<<endl;
        
        res=acarr(a,b);
        cout<<"El acarreo de la division es: "<<res<<endl;

    system("pause");
    return 0;
}

int suma(int a, int b){
    int c;
    cout<<"Dame dos numeros para sumarlos\n";
    cout<<"Primer numero:";
    cin>>a;
    cout<<"Segundo numero:";
    cin>>b;
    c = a+b;
    return c;
}

int resta(int a, int b){
    int c;
    cout<<"Dame dos numeros para restarlos\n";
    cout<<"Primer numero:";
    cin>>a;
    cout<<"Segundo numero:";
    cin>>b;
    c = a-b;
    return c;
}

int multi(int a, int b){
    int c;
    cout<<"Dame dos numeros para multiplicarlos\n";
    cout<<"Primer numero:";
    cin>>a;
    cout<<"Segundo numero:";
    cin>>b;
    c = a*b;
    return c;
}

int divi(int a, int b){
    int c;
    cout<<"Dame dos numeros para dividirlos\n";
    cout<<"Primer numero:";
    cin>>a;
    cout<<"Segundo numero:";
    cin>>b;
    c = (a/b);
    return c;
}

int acarr(int a, int b){
    int c;
    cout<<"Dame dos numeros para ver el acarreo de la division\n";
    cout<<"Primer numero:";
    cin>>a;
    cout<<"Segundo numero:";
    cin>>b;
    c = a%b;
    return c;
}