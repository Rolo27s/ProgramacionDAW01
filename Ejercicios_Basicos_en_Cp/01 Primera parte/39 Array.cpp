#include <iostream>
#include <string.h>
using namespace std;
//GUARDAR 5 TITULOS Y 5 AUTORES EN DOS ARRAY
int main(){
string title[5], author[5];
    for(int i=0; i<5; i++){
        cout<<"Introduce el titulo del libro "<<i+1<<": ";
        getline(cin,title[i]);
        cout<<"Introduce el autor del libro "<<i+1<<": ";
        getline(cin,author[i]);
    }
    cout<<"\nInformacion recopilada...\n";
    cout<<"Mostraremos la informacion obtenida hasta ahora\n";
    system("pause");
    system("cls");
    for(int i=0; i<5; i++){
        cout<<"Archivo numero "<<i+1<<": Autor: "<<author[i]<<" - Titulo de la obra: "<<title[i]<<endl;
    }
    system("pause");
    return 0;
}