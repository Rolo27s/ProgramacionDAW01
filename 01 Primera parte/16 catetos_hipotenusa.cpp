#include <iostream>
#include <cmath>
using namespace std;

int main(){
	float a=0, b=0, c=0;
	
	cout<<"Programa de calculo de hipotenusa de un triangulo con dos catetos conocidos.\n";
	
	cout<<"Valor en centimetros del primer cateto:";
		cin>>a;
	cout<<"Valor en centimetros del segundo cateto:";
		cin>>b;
	
	c=sqrt(pow(a,2) + pow(b,2));
	
	cout<<"El valor de la hipotenusa es:"<<c<<"cm.\n";
return 0;
}
