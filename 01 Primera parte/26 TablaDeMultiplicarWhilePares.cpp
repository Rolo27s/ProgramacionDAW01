#include <iostream>
using namespace std;

int main() {
  int i = 0, tabla = 0;
  char rep = 'N';
  
  cout<<"ALGORITMO BASICO. Programa que muestra una tabla de multiplicar, SOLO NUMEROS PARES, del 0 al 10.\n";
  do{
  
  cout<<"\nQue tabla de multiplicar quieres ver?:";
  cin>>tabla;
  
	  while (i <= 10) {
	    cout << tabla <<"x"<<i<< "=" <<tabla*i << "\n";
	    i=i+2;
	  }
	cout<<"Quieres ver otra tabla de multiplicar? (Y/N): ";
	cin>>rep;
	i=0;
	}while(rep == 'Y' || rep == 'y');
	cout<<"\n --- FIN DEL PROGRAMA --- \n";
  return 0;
}

