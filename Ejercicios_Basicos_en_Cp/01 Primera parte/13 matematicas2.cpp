#include <iostream>
using namespace std;

int main(){
	float a=0, b=0, c=0, d=0, f=0, g=0;
	
	cout<<"Vamos a hacer la cuenta matematica (a+(b/c)) / (d + (f/g))\nElige las variables:\n"<<endl;
	cout<<"Valor de la variable a: "; 
	cin>>a;
	cout<<"Valor de la variable b: "; 
	cin>>b;
	cout<<"Valor de la variable c: "; 
	cin>>c;
	cout<<"Valor de la variable d: "; 
	cin>>d;
	cout<<"Valor de la variable f: "; 
	cin>>f;
	cout<<"Valor de la variable g: "; 
	cin>>g;
	cout<<"El resultado de la operacion es:";
	cout<<(a+(b/c)) / (d + (f/g));
	
	return 0;
}
