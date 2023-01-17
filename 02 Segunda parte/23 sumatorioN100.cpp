//Problema de sumatoria de numeros de 0 a n.
//La fórmula de la sumatoria de Gauss es (n(n+1)) / 2.
#include <iostream>
using namespace std;
int comprobar(int x);
int sumatoria(int k);

int main(){
    int n=0;
    cout<<"Sumatoria de los primeros n numeros.\n";
    cout<<"introduce el valor de n: ";
    cin>>n;
    n = comprobar(n);
    cout<<"La sumatoria de 0 a "<<n<<" es: ";
    cout<<sumatoria(n)<<endl;
    system("pause");
    return 0;
}

int comprobar(int x){
    while(x<0){
        cout<<"Seleccion erronea...\n";
        cout<<"Ingrese nuevamente la opcion: ";
        cin>>x;
    }
    return x;
}

int sumatoria(int k){
    if(k<=0){
        return 0;
    }else{
        return k + sumatoria(k-1);
    }
}

