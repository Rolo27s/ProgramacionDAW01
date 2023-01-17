#include <iostream>
#include <cmath>
using namespace std;

int main(){
	float a=0, b=0;
	
	cout<<"Programa que compara dos numeros y devuelve el mayor.\n";
	
	cout<<"Primer numero:";
		cin>>a;
	cout<<"Segundo numero:";
		cin>>b;

	if(a>b){
		cout<<"El numero mayor es el "<<a;
	}else if(a == b){
		cout<<"Los numeros son iguales :)";
	}else{
		cout<<"El numero mayor es el "<<b;
	}
return 0;
}
