//Pedir dos cadenas de caracteres por teclado y decir que cadena es mayor
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main(){
char cad1[50], cad2[50];
printf("Dame la primera frase: ");
scanf("%s", cad1);
printf("Dame la segunda frase: ");
scanf("%s", cad2);
    if(strlen(cad1)>strlen(cad2)){
        printf("La primera frase es mayor\n");
    }else if(strlen(cad1)<strlen(cad2)){
        printf("La segunda frase es mayor\n");
    }else{
        printf("La primera frase es igual en tamano que la segunda frase\n");
    }

system("pause");
return 0;
}