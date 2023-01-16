#include <iostream>
using namespace std;

int main() {
  int i = 0, tabla = 0;
  char rep = 'N';
  
  cout<<"ALGORITMO BASICO. Programa que muestra una tabla de multiplicar del 0 al 10.\n";
  do{
  
  cout<<"\nQue tabla de multiplicar quieres ver?:";
  cin>>tabla;
  
	  for (int i = 0; i <= 10; i++) {
	    cout << tabla <<"x"<<i<< "=" <<tabla*i << "\n";
	  }
	cout<<"Quieres ver otra tabla de multiplicar? (Y/N): ";
	cin>>rep;
	}while(rep == 'Y' || rep == 'y');
	cout<<"\n --- FIN DEL PROGRAMA --- \n";
  return 0;
}

