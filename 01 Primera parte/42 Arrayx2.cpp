#include <iostream>
using namespace std;
// Meter por teclado 5 num, guardarlos en un array, y luego ver ese array y otro que este todo multiplicado por dos.
int main(){
int arr1[5], arr2[5];
    cout<<"Listado de 5 numeros pedidos al usuario:\n";
    //Definimos los arrays
    for(int i=0;i<5;i++){
        cout<<"Numero en la posicion "<<i<<" del array: ";
        cin>>arr1[i];
        arr2[i] = arr1[i]*2;
    }
    //Los mostramos por pantalla
    cout<<"Array original introducido en teclado por el usuario.\n";
    for(int i=0;i<5;i++){
        cout<<arr1[i]<<", ";
    }
    cout<<""<<endl;
    
    cout<<"Array original multiplicado por dos.\n";
    for(int i=0;i<5;i++){
        cout<<arr2[i]<<", ";
    }
    cout<<""<<endl;
    system("pause");
    return 0;
}