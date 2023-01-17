#include <iostream>
#include <cmath>
using namespace std;

int main(){
	float a=0, b=0, c=0, x1=0, x2=0, p1=0;
	
	cout<<"Programa de calculo ECUACION de segundo grado\n";
	
	cout<<"Valor de a:";
		cin>>a;
	cout<<"Valor de b:";
		cin>>b;
	cout<<"Valor de c:";
		cin>>c;
	
	p1 = sqrt(pow(b,2)-(4*a*c));
	
	x1 = (-b + p1)/(2*a);
	x2 = (-b - p1)/(2*a);
	cout<<"La solucion es:"<<x1<<" y "<<x2;
return 0;
}
