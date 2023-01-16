#include <iostream>
using namespace std;
//Vamos a comprobar si un numero es positivo, negativo o 0.

int main() {
  float i = 0;
  
  cout<<"Introduce un numero para comprobar que sea negativo, cero o positivo:";
  cin>>i;
	if(i<0){
		cout<<"El numero "<<i<<" es un numero negativo.\n";
	}else if(i == 0){
		cout<<"El numero "<<i<<" es 0.\n";
		cout<<"Es posible que hayas intentado introducir una letra o palabras.\n";
		cout<<"Recuerda que debes introducir un numero para el buen funcionamiento del programa.\n";
	}else{
		cout<<"El numero "<<i<<" es un numero positivo.\n";
	}
	cout<<"\n --- FIN DEL PROGRAMA --- \n";
  return 0;
}

