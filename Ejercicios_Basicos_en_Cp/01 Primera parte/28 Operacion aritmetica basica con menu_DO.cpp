#include <iostream>
using namespace std;
//Usaremos el bucle DO WHILE para pedir salir en el menu.
int main()
{
	int a=0,b=0,c=0;
	cout<<"/// ___MENU CALCULADORA___"<<endl;
			
		do{
		cout<<"Selecciona una opcion del MENU.\n";
		cout<<" Suma(1)\n Resta(2)\n Multiplicacion(3)\n Division(4)\n Resto(5) \n SALIR(6)\n ";
		cout<<"\nSeleccion: ";
		cin>>c;
			if(c>=1 && c<=5){
				cout<<"Introduce el primer numero de la operacion:";
				cin>>a;
				cout<<"Introduce el segundo numero de la operacion:";
				cin>>b;
			}
			switch(c){
					case 1:
						cout<<"La suma es: "<<a+b<<endl;
						cout<<"Siguiente operacion...\n\n";
						break;
					case 2:
						cout<<"La resta es: "<<a-b<<endl;
						cout<<"Siguiente operacion...\n\n";
						break;
					case 3:
						cout<<"La multiplicacion es: "<<a*b<<endl;
						cout<<"Siguiente operacion...\n\n";
						break;
					case 4:
						cout<<"La division es: "<<a/b<<endl;
						cout<<"Siguiente operacion...\n\n";
						break;
					case 5:
						cout<<"El acarreo de la division es: "<<a%b<<endl;
						cout<<"Siguiente operacion...\n\n";
						break;
					case 6:
						cout<<"Cerrando el menu...\n\n --- FIN DEL PROGRAMA --- "<<endl;
						break;
					default:
						cout<<"Orden erronea."<<endl;
						break;
					}
			}while(c != 6);
	return 0;
}
