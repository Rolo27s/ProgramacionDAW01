#include <iostream>
using namespace std;

int main()
{
	int a=0,b=0,c=0;
	cout<<"Menu calculadora:\n";
		cout<<"Escribe el numero de la operacion a realizar.\n";
		cout<<" Suma(1)\n Resta(2)\n Multiplicacion(3)\n Division(4)\n Resto(5)\n ";
		cout<<"Seleccion: ";
		cin>>c;
	
		
		
		if(c>=1 && c<=5)
		{
				cout<<"Escribe el primer numero:";
				cin>>a;
				cout<<"Escribe el segundo numero:";
				cin>>b;
				
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
					//default:
						//NOTHING. The break and default keywords are optional, and will be described later in this chapter.
					}
					
		}else{
			cout<<"ERROR. FIN DE PROGRAMA\n";
		}
	return 0;
}
