#include <iostream>
#include <string.h>
using namespace std;

int main(){
    char nombre[20]="Paqui";
    char apellido[20]="Bustamante";
    int i;

    strcat(nombre,apellido); //concatenar
    cout<<"Tu nombre completo es "<<nombre<<endl;
    
    strcpy(nombre, apellido); //copia apellido en nombre
    cout<<"Tu nombre completo es "<<nombre<<endl;

    i=strcmp(nombre,apellido);
    cout<<"El valor de i es "<<i<<endl; //Devuelve 0 si es verdad
    cout<<"Tu nombre es "<<nombre<<endl;
    cout<<"Tu apellido es "<<apellido<<endl;

    return 0;
}