#include <iostream>
using namespace std;
double fact(double k);
int comprobar(int x);

int main(){
  int n=0;
  double result=0;
  cout<<"Calculo del factorial de un numero. Que numero (min=0)?: ";
  cin>>n;
  n=comprobar(n);
  result = fact(n);
  cout << result << endl;
  system("pause");
  return 0;
}

double fact(double k){
  if (k > 0) {
    return k * fact(k - 1);
  } else {
    return 1;
  }
}

int comprobar(int x){
    while(x<0){
        cout<<"Seleccion erronea...\n";
        cout<<"Ingrese nuevamente la opcion: ";
        cin>>x;
    }
    return x;
}