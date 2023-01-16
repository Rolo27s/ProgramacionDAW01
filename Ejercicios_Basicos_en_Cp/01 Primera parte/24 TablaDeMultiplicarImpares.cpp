#include <iostream>
using namespace std;

int main() {
  int i = 1, tabla = 0;
  char rep = 'N';
  
  cout<<"ALGORITMO BASICO. Programa que muestra una tabla de multiplicar, SOLO POR LOS NUMEROS IMPARES, del 1 al 9.\n";
  do{
  
  cout<<"\nQue tabla de multiplicar quieres ver?:";
  cin>>tabla;
  
	  for (int i = 1; i <= 10; i=i+2) {
	    cout << tabla <<"x"<<i<< "=" <<tabla*i << "\n";
	  }
	cout<<"Quieres ver otra tabla de multiplicar? (Y/N): ";
	cin>>rep;
	}while(rep == 'Y' || rep == 'y');
	cout<<"\n --- FIN DEL PROGRAMA --- \n";
  return 0;
}

