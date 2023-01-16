#include <iostream>
using namespace std;
int comprobar(int x);
void areaCuadrado();
void perimetroCuadrado();
void areaTriangulo();
void perimetroTriangulo();

int main(){
    int a=0, b=0;
    cout<<"PROGRAMA PARA CALCULAR EL AREA O EL PERIMETRO DE UN CUADRADO O DE UN TRIANGULO\n";

    cout<<"Selecciona cuadrado (1) o triangulo (2): ";
	cin>>a;
    a = comprobar(a);
    cout<<"\nSelecciona para calcular el area (1) o el perimetro (2): ";
    cin>>b;
    b = comprobar(b);

    if(a==1 && b==1){
        areaCuadrado();
    }else if(a==1 && b==2){
        perimetroCuadrado();
    }else if(a==2 && b==1){
        areaTriangulo();
    }else{
        perimetroTriangulo();
    }

    system("pause");
    return 0;
}

int comprobar(int x){
    while(x<1 || x>2){
        cout<<"Seleccion erronea...\n";
        cout<<"Ingrese nuevamente la opcion: ";
        cin>>x;
    }
    return x;
}

void areaCuadrado(){
    int p1=0;
    cout<<"\nVamos a calcular el area de un cuadrado...\n";
			cout<<"Dame el valor del lado del cuadrado en cm: ";
			cin>>p1;
			while(p1<=0){
				cout<<"Valor erroneo...\n";
				cout<<"Dame el valor del lado del cuadrado en cm: ";
				cin>>p1;
			}
			cout<<"La solucion es: "<<p1*p1<<" cm^2\n";
}
void perimetroCuadrado(){
    int p1=0;
        cout<<"\nVamos a calcular el perimetro de un cuadrado...\n";
        cout<<"Dame el valor del lado del cuadrado en cm: ";
        cin>>p1;
        while(p1<=0){
            cout<<"Valor erroneo...\n";
            cout<<"Dame el valor del lado del cuadrado en cm: ";
            cin>>p1;
        }
        cout<<"La solucion es: "<<p1*4<<" cm\n";
}

void areaTriangulo(){
    int p1=0, p2=0;
        cout<<"\nVamos a calcular el area de un triangulo...\n";
        cout<<"Dame el valor de la base del triangulo en cm: ";
        cin>>p1;
        while(p1<=0){
            cout<<"Valor erroneo...\n";
            cout<<"Dame el valor de la base del triangulo en cm: ";
            cin>>p1;
        }
        cout<<"Dame el valor de la altura del triangulo en cm: ";
        cin>>p2;
        while(p2<=0){
				cout<<"Valor erroneo...\n";
				cout<<"Dame el valor de la altura del triangulo en cm: ";
				cin>>p2;
			}
		cout<<"La solucion es: "<<(p1*p2)/2<<" cm^2\n";
}

void perimetroTriangulo(){
    int p1=0, p2=0, p3=0;
        cout<<"\nVamos a calcular el perimetro de un triangulo...\n";
        cout<<"Dame el valor del primer lado del triangulo en cm: ";
        cin>>p1;
        while(p1<=0){
            cout<<"Valor erroneo...\n";
            cout<<"Dame el valor del primer lado del triangulo en cm: ";
            cin>>p1;
        }
        cout<<"Dame el valor del segundo lado del triangulo en cm: ";
        cin>>p2;
        while(p2<=0){
            cout<<"Valor erroneo...\n";
            cout<<"Dame el valor del segundo lado del triangulo en cm: ";
            cin>>p2;
        }
        cout<<"Dame el valor del tercer lado del triangulo en cm: ";
        cin>>p3;
        while(p3<=0){
            cout<<"Valor erroneo...\n";
            cout<<"Dame el valor del tercer lado del triangulo en cm: ";
            cin>>p3;
        }
        cout<<"La solucion es: "<<p1+p2+p3<<" cm\n";
}