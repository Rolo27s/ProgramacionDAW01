//Pedir dos cadenas de caracteres por teclado y decir que cadena es mayor
#include <iostream>
#include <string.h>
using namespace std;

int main(){
string cad1, cad2;
cout<<"Dame la primera frase: ";
getline(cin,cad1);
cout<<"Dame la segunda frase: ";
getline(cin,cad2);
    if(cad1.size()>cad2.size()){
        cout<<"La primera frase es mayor";
    }else if(cad1.size()<cad2.size()){
        cout<<"La segunda frase es mayor";
    }else{
        cout<<"La primera frase es igual en tamano que la segunda frase";
    }

return 0;
}