#include <iostream>
using namespace std;
int suma(int a, int b); //declaramos la funcion al principio y ya no necesitamos tener cuidado con la lectura en cascada.
int resta(int a, int b);
int mult(int a, int b);
int divi(int a, int b);
int acarr(int a, int b);

int main(){
    int a=0, b=0, res=0, opMenu=0, cont=1;
        do{
            cout<<"Menu de operaciones aritmeticas\n";
            cout<<"\t(1) - Sumar\n";
            cout<<"\t(2) - Restar\n";
            cout<<"\t(3) - Multiplicar\n";
            cout<<"\t(4) - Dividir\n";
            cout<<"\t(5) - Acarreo de la division\n";
            cout<<"\t(0) - Salir\n";
            cout<<"Eleccion del usuario: ";
            cin>>opMenu;
        while(opMenu<0 || opMenu>5){
            cout<<"\nError de opcion, elige una opcion correcta: ";
            cin>>opMenu;
        }
            if(opMenu != 0){
            cout<<"Numero de operaciones realizadas hasta ahora: "<<cont<<endl;
            cout<<"Primer numero:\t";
            cin>>a;
            cout<<"Segundo numero:\t";
            cin>>b;
            }
                switch (opMenu)
                {
                case 0:
                    cout<<"Fin del programa\n";
                    break;
                case 1:
                    res=suma(a,b);
                    cout<<"\nLa suma es:\t\t\t"<<res;  
                    break;
                case 2:
                    res=resta(a,b);
                    cout<<"\nLa resta es:\t\t\t"<<res;
                    break;
                case 3:
                    res=mult(a,b);
                    cout<<"\nLa multiplicacion es:\t\t"<<res;
                    break;
                case 4:
                    res=divi(a,b);
                    cout<<"\nLa division es:\t\t\t"<<res;
                    break;
                case 5:
                    res=acarr(a,b);
                    cout<<"\nEl acarreo de la division es:\t"<<res;
                    break;
                default:
                    break;
                }
        cout<<endl;
        system("pause");
        cont++;
        }while(opMenu != 0);
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