#include <iostream>
#include <string.h>
using namespace std;
/*
1)Pedimos que el usuario introduzca una frase de menos de 100 caracteres.
2)Guardamos el iniput en vble tipo char arr[100];
3)Pedimos que busque un caracter que metemos por pantalla
4)Nos muestra si se encontro o no. En caso de que si, que posicion era del array.
*/
int main(){
    char frase[100], search='a';
    bool noEncontrado=1;

    cout<<"Introduce una frase: ";
    gets(frase);

    cout<<"Dime que caracter quieres buscar: ";
    cin>>search;
    for(int i=0;i<=99;i++){
        if(search == frase[i]){
            cout<<"Caracter '"<<search<<"' encontrado en la posicion "<<i<<endl;
            noEncontrado = 0;
        }
    }
    if(noEncontrado){
        cout<<"Caracter'"<<search<<"' NO encontrado"<<endl;
    }
    system("pause");
    return 0;
}