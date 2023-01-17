/*
EJERCICIO 12
Escriba, compile y ejecute un programa en C++ que aplique la recursividad para
obtener el menor, mayor, suma y promedio de los elementos generados en
forma aleatoria entre 10 y 100 de una matriz de dimensiones 5 x 10*/

#include <iostream>
#include <stdlib.h> // Libreria necesaria para el uso de comandos tipo system
#include <time.h> 
//Para generar numeros aleatorios necesitamos de las librerias stdlib y time.
//Al principio del main declaramos: srand(time (NULL)); para resetear la semilla. 
/*
La forma mas comoda de trabajar con rand() es  declarar dos constantes MAX_RAND y MIN_RAND
rand() % (MAX_RAND - MIN_RAND + 1) + MIN_RAND;
*/
//Controla cantidad de numeros a mostrar con la funcion setprecision().
// cout << setprecision(10);       respeta 10 digitos de la parte entera
// cout << fixed << setprecision(2); respeta 2 digitos de la parte decimal
#include <iomanip>
using namespace std;

const int MAX_RAND = 100;
const int MIN_RAND = 10;
const int X = 5;
const int Y = 10;

void funcionRecursivaVer(int matriz[5][10], int &x, int &y, int &max, int &min, int &sumatoria);
string comprobarCHAR(string letra);

int main(){
    int matrixAleat[X][Y];
    string opcion;
    int cont_x=0, cont_y=0, max=0, min=0, sumatoria=0; // Inicializo el contador a 0 para uso de la funcion recursiva.
    float promedio=0, sumatoriaFloat=0;
        do{
            srand(time (NULL)); // Genero una nueva semilla por cada iteracion
            system("cls"); //Primero limpio la pantalla para cuando el programa quiera generar otra matriz nueva.
            cout<<"   Programa que genera y procesa elementos de una matriz 5 x 10\n";
            cout<<"   ------------------------------------------------------------\n";
            cout<<endl;
            cout<<"   Genera y visualiza elementos de la matriz\n";
            
            //REPETICION 1 Genera y muestra la matriz aleatoria de 5x10
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 10; j++){
                    matrixAleat[i][j] = rand() % (MAX_RAND - MIN_RAND + 1) + MIN_RAND; // Genera un numero aleatorio entre en 10 y el 100
                    cout<<matrixAleat[i][j]<<"\t";
                }
                cout<<endl;
            }
            cout<<endl;
            cout<<"   Imprimir empleando iteraciones con For\n";
            
            //REPETICION 2 solo muestra la matriz aleatoria de 5x10 con for
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 10; j++){
                    cout<<matrixAleat[i][j]<<"\t";
                }
                cout<<endl;
            }
            cout<<endl;
            cout<<"   Imprimir y procesar estadisticas empleando recursividad\n";
            
            //REPETICION 3 imprimir y procesar estadsticas empleando recursividad
            //Declaro el primer numero de la matriz como maximo y como minimo para empezar a trabajar a partir de ahi
            max=matrixAleat[0][0];
            min=matrixAleat[0][0]; 
            for(cont_x=0; cont_x < 5; cont_x++){
                funcionRecursivaVer(matrixAleat, cont_x, cont_y, max, min, sumatoria);
            }
            cout<<endl;
            cout<<"El mayor numero generado es: "<<max<<endl;
            cout<<"El menor numero generado es: "<<min<<endl;
            cout<<"La sumatoria de los elementos es : "<<sumatoria<<endl;
            sumatoriaFloat = sumatoria; //Guardo la variable sumatoria en formato float para poder tener el promedio con decimales.
            promedio = sumatoriaFloat/(X*Y);
            cout << setprecision(6);
            cout << fixed << setprecision(4);
            cout<<"El promedio de los elementos es: "<<promedio<<endl;
        
        //Preguntamos si queremos generar y procesar otra matriz y volver a empezar el programa y reseteo los contadores por si sucede.
            cont_x=0; 
            cont_y=0; 
            max=0; 
            min=0; 
            sumatoria=0;
            sumatoriaFloat=0;
            promedio=0;
        cout<<"\nDesea generar y procesar otra matriz: S o N  ";
        cin>>opcion;
        opcion = comprobarCHAR(opcion); //Llama a la funcion comprobar Char
        }while(opcion == "S" || opcion == "s");
    return 0;
}

//Funcion recursiva imprimir
void funcionRecursivaVer(int matriz[5][10], int &x, int &y, int &max, int &min, int &sumatoria){     
    if(y < 10){
        cout<<matriz[x][y]<<"\t";
        if(matriz[x][y] > max) max = matriz[x][y];
        if(matriz[x][y] < min) min = matriz[x][y];
        sumatoria += matriz[x][y];
        y++;
        funcionRecursivaVer(matriz, x, y, max, min, sumatoria);
    }else if(y == 10){
        y=0;
        cout<<endl;
    }
}

// <-- CONTROL DE INFORMACION DE ENTRADA -->
//Comprueba para procesar otro grupo y que solo se usen 4 caracteres ('S', 's', 'N', 'n')
string comprobarCHAR(string letra){
    do{
        if(letra != "s" && letra != "S" && letra != "n" && letra != "N"){
            cout<<"Opcion erronea, introduzca otra vez S o N: ";
            cin>>letra;
        }
    }while(letra != "s" && letra != "S" && letra != "n" && letra != "N");
    return letra;
}