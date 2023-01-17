#include <iostream>
using namespace std;

//PROGRAMA PARA CALCULAR EL AREA O EL PERIMETRO DE UN CUADRADO O DE UN TRIANGULO

int main()
{
	int a=0,b=0,p1=0, p2=0, p3=0;
	cout<<"PROGRAMA PARA CALCULAR EL AREA O EL PERIMETRO DE UN CUADRADO O DE UN TRIANGULO\n";
		
		cout<<"Selecciona cuadrado (1) o triangulo (2): ";
		cin>>a;
		while(a<1 || a>2){
			cout<<"Seleccion erronea...\n";
			cout<<"Selecciona cuadrado (1) o triangulo (2): ";
			cin>>a;
		}
		cout<<"Bien, has seleccionado: ";
		if (a == 1){
			cout<<"CUADRADO\n";
			}else{
				cout<<"TRIANGULO\n";
			}
				
		cout<<"\nSelecciona area (1) o perimetro (2): ";
		cin>>b;
		while(b<1 || b>2){
			cout<<"Seleccion erronea...\n";
			cout<<"Selecciona area (1) o perimetro (2): ";
			cin>>b;
		}
		cout<<"Bien, has seleccionado: ";
		if (b == 1){
			cout<<"AREA\n";
			}else{
			cout<<"PERIMETRO\n";
			}
		
		if(a==1 && b==1){
			cout<<"\nVamos a calcular el area de un cuadrado...\n";
			cout<<"Dame el valor del lado del cuadrado en cm: ";
			cin>>p1;
			while(p1<=0){
				cout<<"Valor erroneo...\n";
				cout<<"Dame el valor del lado del cuadrado en cm: ";
				cin>>p1;
			}
			cout<<"La solucion es: "<<p1*p1<<" cm^2\n";
		}else if(a==1 && b==2){
			cout<<"\nVamos a calcular el perimetro de un cuadrado...\n";
			cout<<"Dame el valor del lado del cuadrado en cm: ";
			cin>>p1;
			while(p1<=0){
				cout<<"Valor erroneo...\n";
				cout<<"Dame el valor del lado del cuadrado en cm: ";
				cin>>p1;
			}
			cout<<"La solucion es: "<<p1*4<<" cm\n";
		}else if(a==2 && b==1){
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
		}else{
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
	return 0;
}