#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
    char nombre[20]="Paqui";
    int edad=20;
    float estatura=1.75256;

    printf("introduzca su edad: ");
    scanf("%d", &edad);

    printf("Hola %s, tienes %d anos\n",nombre,edad); //https://cplusplus.com/reference/cstdio/printf/

    printf("Tu estatura es %f \n", estatura);
    printf("Tu estatura es %.2f \n", estatura); // imprime solo dos decimales

    return 0;
}