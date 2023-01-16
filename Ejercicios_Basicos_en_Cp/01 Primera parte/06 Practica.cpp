#include <iostream>

using namespace std;

int main()
{
	int num1 = 0;
	float num2 = 3.1415;
	double num3 = 24.4835654;
	bool state = true;
	char option = 'x';
	
	string adminName = "Fran";
	string userName = "";
	cout<<"Hola, soy "<< adminName <<". Como te llamas?: ";
	cin>>userName;
	cout<<"Encantado de conocerte "<<userName<<"."<<endl;
	// Se puede hacer otro tipo de estructura a partir de aqui.
	
	cout<<"Cual es tu numero entero favorito?: ";
	cin>>num1;
	cout<<"El "<<num1<<"?. Okey. "<<"El mio es el " <<num2<<" al menos el "<<num3<<"% de las veces."<<endl;
	
	cout<<"Quieres ver la informacion que tengo hasta ahora? (Y/N): ";
	cin>>option;
	
	if(option == 'Y' || option == 'y'){
		cout<<"Tampoco tengo tanta informacion. La mostrare en otro ejercicio.";
		state = true;
	}else if(option == 'N' or option == 'n'){
		cout<<"De acuerdo. Hasta la proxima.";
		state = false;
	}else{
		cout<<"No te he entendido. Hasta la proxima.";
		state = false;
	}
	
	return 0;
}
