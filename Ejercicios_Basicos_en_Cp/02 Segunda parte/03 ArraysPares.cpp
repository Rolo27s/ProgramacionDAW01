#include <iostream>
using namespace std;

int main(){
    int numerosPares[100];
    int cont=0, total=0;

    system("color 0E");
    for(int i=2;i<=200;i+=2){
        numerosPares[cont] = i;
        total += i;
        cont++;
    }

    cout<<"El array es este:\n";
    for(int i=0;i<100;i++){
        cout<<"Posicion "<<i<<" valor: "<<numerosPares[i]<<endl;
    }
    cout<<endl;
    cout<<"La suma de todos esos numeros es "<<total<<endl;

    system("pause");
    return 0;
}
