#include <iostream>
using namespace std;
/*
ESTUDIAREMOS SI UN NUMERO INTRODUCIDO POR TECLADO ES MULTIPLO DE 3, 4 O 5. 
El 0 solo es multiplo de 0. 
Los multiplos pueden ser de numeros negativos.
La clave de la resolucion de este problema es el control del acarreo de la division, de tal modo que cuando sea 0, será multiplo de. 
*/
int main(){
    int num=0;
    
    cout<<"Introduce un numero para verificar si es multiplo de 3, 4 y/o 5: ";
    cin>>num;

    for(int i=3;i<=5;i++){
        if(num%i == 0 && num!=0){
            cout<<" ---→ El numero introducido es multiplo de "<<i<<endl;
        }else{
            cout<<"El numero introducido NO es multiplo de "<<i<<"..."<<endl;
        }
    }
    system("pause");
    return 0;
}