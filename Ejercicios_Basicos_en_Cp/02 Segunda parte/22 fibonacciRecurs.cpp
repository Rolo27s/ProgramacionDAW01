//Sucesion de Fibonacci de los 20 primeros números.
//https://www.i-ciencias.com/pregunta/155146/es-la-secuencia-de-fibonacci-exponencial
//https://www.disfrutalasmatematicas.com/numeros/fibonacci-sucesion.html
//https://www.linuxhispano.net/2013/09/24/entendiendo-la-recursividad/
//Xn=(A^n-(1-A)^n)/sqrt(5)      A=1.618034        sqrt(5)= 2.236     n es la posicion de fibb, Xn es el numero natural correspondiente.
//https://www.codingninjas.com/codestudio/library/passing-arrays-to-functions-in-c-cpp   → Teoria de Arrays con funciones.
#include <iostream>
using namespace std;
int fibonacciR(int n);
int nFib[20];

int main(){
  double n=20;
  
  cout<<"El numero en la posicion 20 de la serie de Fibonacci es: ";
  cout<<fibonacciR(n)<<endl;
  cout<<"\nSucesion de Fibonacci de los 20 primeros numeros\n";
  for (int i = 0; i <= 20; i++)
  {
    cout<<nFib[i]<<" ";
  }
  cout<<endl;
  system("pause");
  return 0;
}

int fibonacciR(int n){
    if(n==0 || n==1){
        nFib[n] = n;
        return n;
    }
        
    nFib[n] = (fibonacciR(n-1)+fibonacciR(n-2));
    return (fibonacciR(n-1)+fibonacciR(n-2));
}