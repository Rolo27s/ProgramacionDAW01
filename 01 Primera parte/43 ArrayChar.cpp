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
    char caract[100], search='a';
    string frase="";
    bool noEncontrado=1;

    cout<<"Introduce una frase: ";
    getline(cin,frase);

    for(int i=0;i<frase.length();i++){
        caract[i]=frase[i];
    }

    cout<<"Dime que caracter quieres buscar: ";
    cin>>search;
    for(int i=0;i<frase.length();i++){
        if(search == caract[i]){
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