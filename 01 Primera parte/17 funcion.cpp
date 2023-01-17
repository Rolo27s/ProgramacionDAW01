#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;

int main(){
	float x=0, y=0, f=0;
	
	cout<<"Programa de calculo de la funcion f(x,y)= (sqrt(x))/(y^2-1).\n";
	cout<<"Valor de x:";
	cin>>x;
	while not x.isdigit(){
	cout<<"Valor de x:";
	cin>>x;
	}	
	cout<<"Valor de y:";
		cin>>y;
	
	f=sqrt(x)/(pow(y,2)-1);
	cout<<"El valor de la funcion es:"<<f;
return 0;
}
