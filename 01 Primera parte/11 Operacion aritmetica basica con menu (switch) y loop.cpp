#include <iostream>
using namespace std;

int main()
{
	int a=0,b=0,c=0;
	char repetir='n';
	
	do{
		cout<<"Escribe un numero:";
		cin>>a;
		cout<<"Escribe otro numero:";
		cin>>b;
		cout<<"Escribe el numero de la operacion a realizar.\n";
		cout<<"Suma(1), Resta(2), Multiplicacion(3), Division(4), Resto(5): ";
		cin>>c;
		
		switch(c){
			case 1:
				cout<<"La suma es: "<<a+b<<endl;
				break;
			case 2:
				cout<<"La resta es: "<<a-b<<endl;
				break;
			case 3:
				cout<<"La multiplicacion es: "<<a*b<<endl;
				break;
			case 4:
				cout<<"La division es: "<<a/b<<endl;
				break;
			case 5:
				cout<<"El acarreo de la division es: "<<a%b<<endl;
				break;
			default:
				cout<<"Codigo erroneo.\n";
			}
		
		cout<<"Quieres hacer otra operacion? (Y/N): ";
		cin>>repetir;
		
	}while(repetir == 'y' || repetir == 'Y');
	
	cout<<"Fin del programa.\n";

	return 0;
}
