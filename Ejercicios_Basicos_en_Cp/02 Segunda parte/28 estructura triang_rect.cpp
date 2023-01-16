#include <iostream>
using namespace std;

struct cuadrado{
    double lado;
};

struct triangulo{
    double base, altura;
};

double area1 (cuadrado cua);
double area2 (triangulo tri);

int main(){
    int x;
        cout<<"Figura a calcular, 1(cuadrado), 2(triangulo):"<<endl;
        cin>>x;
    if(x==1){
        cuadrado cua_a;
        cout<<"Introduzca el valor del lado: "<<endl;
        cin>>cua_a.lado;
        cout<<"El valor del area es: "<<area1(cua_a)<<endl;
    }else{
        triangulo tri_b;
        cout<<"introduce el valor de la base: "<<endl;
        cin>>tri_b.base;
        cout<<"Introduzca el valor de la altura: "<<endl;
        cin>>tri_b.altura;
        cout<<"El valor del area es: "<<area2(tri_b)<<endl;
    }

    return 0;
}

//def funcion area1
double area1 (cuadrado cua){
    return (cua.lado*cua.lado);
}
//def funcion area2
double area2 (triangulo tri){
    return (tri.base*tri.altura)/2;
}