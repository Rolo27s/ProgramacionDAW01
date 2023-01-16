//Sucesion de Fibonacci de los 10 primeros números.
//https://www.i-ciencias.com/pregunta/155146/es-la-secuencia-de-fibonacci-exponencial
//https://www.disfrutalasmatematicas.com/numeros/fibonacci-sucesion.html
//https://www.linuxhispano.net/2013/09/24/entendiendo-la-recursividad/
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int main(){
  cout<<"Sucesion de Fibonacci de los 10 primeros numeros\n";
  double n[10];
  n[0]=0;
  n[1]=1;
  cout<<n[0]<<" "<<n[1];
  for(int i=2;i<=10;i++){
    n[i] = n[i-2]+n[i-1];
    cout<<" "<<n[i];
  }
  cout<<endl;
  for(int i=0;i<=10;i++){
    while(n[i]>=0){
      if(n[i]>0){
        cout<<".";
        n[i]--;
      }else{
        cout<<endl;
        break;
      }
    }
  }
  system("pause");
  return 0;
}
