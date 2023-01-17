#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h> // Libreria necesaria para el uso de comandos tipo system
#include <iomanip> //  Controla decimales con la funcion setprecision()
using namespace std;

const float PONDERACION_NOTA_1=0.15;
const float PONDERACION_NOTA_2=0.2;
const float PONDERACION_NOTA_3=0.25;
const float PONDERACION_NOTA_4=0.4;
const int ALU=20; //La clase tendrá 20 alumnos.

struct alumno{
    int id;
    int code;
    float nota1;
    float nota2;
    float nota3;
    float nota4;
    float notaDefinitiva;
};
alumno listaAlu[ALU]; //Cada grupo tendrá un máximo de 20 listaAlu

void insertarInfo(int n);
float comprobarNum(float a);
string comprobarCHAR(string letra);
void verInfo(int n);

int main(){
    string opcion;
    int nalumno=0;
    
    do{
        system("cls");
        cout<<"Programa que aplica funciones para calcular la nota final ponderada!\n";
        cout<<"--------------------------------------------------------------------\n\n";
        //En este apartado introducimos toda la informacion de un grupo de listaAlu
        do{
            cout<<"\nAlumno ("<<nalumno+1<<"/"<<ALU<<")...\n";
            insertarInfo(nalumno);
            nalumno++;
        }while(nalumno<ALU);

        //Cuando pare de procesar Alumnos, que muestre el listado de la informacion recopilada
        verInfo(nalumno);
        //Desea procesar otro grupo¿? Si si, vuelve a empezar, si no, sale del programa.
        cout<<"\nDesea procesar otro grupo: S o N  ";
        cin>>opcion;
        opcion=comprobarCHAR(opcion); //Llama a la funcion comprobar Char
        nalumno=0; //Reseteo el contador de Alumnos para empezar a sobreescribir informacion si fuera necesario.
    }while(opcion=="S"||opcion=="s");

    return 0;
}

//Comprueba que el numero sea mayor o igual a 0 y menor o igual a 5 para el buen funcionamiento del programa
float comprobarNum(float a){
    while(a<0||a>5){
        cout<<"Error... Ingrese nuevamente el valor: ";
        cin>>a;
    }
    return a;
}

//Defines los valores de un usuario
void insertarInfo(int n){
    listaAlu[n].id=n+1;
    cout<<"Codigo: ";
    cin>>listaAlu[n].code;
    
    cout<<"Nota1: ";
    cin>>listaAlu[n].nota1;
    listaAlu[n].nota1=comprobarNum(listaAlu[n].nota1); // Llamamos a la funcion para controlar Nota1.
    
    cout<<"Nota2: ";
    cin>>listaAlu[n].nota2;
    listaAlu[n].nota2=comprobarNum(listaAlu[n].nota2); // Llamamos a la funcion para controlar Nota2.
   
    cout<<"Nota3: ";
    cin>>listaAlu[n].nota3;
    listaAlu[n].nota3=comprobarNum(listaAlu[n].nota3); // Llamamos a la funcion para controlar Nota3.
    
    cout<<"Nota4: ";
    cin>>listaAlu[n].nota4;
    listaAlu[n].nota4=comprobarNum(listaAlu[n].nota4); // Llamamos a la funcion para controlar Nota4.
    listaAlu[n].notaDefinitiva=listaAlu[n].nota1*PONDERACION_NOTA_1+listaAlu[n].nota2*PONDERACION_NOTA_2+listaAlu[n].nota3*PONDERACION_NOTA_3+listaAlu[n].nota4*PONDERACION_NOTA_4;
    cout<<"---------------------------------------------------------\n\n";
}

//Esta funcion imprime por pantalla toda la informacion de un grupo de usuarios.
void verInfo(int n){
    float maxNOTA=listaAlu[0].nota1, minNOTA=listaAlu[0].nota1, sumatoriaNOTA=0;
    int codigoMaxNOTA=listaAlu[0].code, codigoMinNOTA=listaAlu[0].code;
    cout<<"---------------------------------------\n";
    cout<<"No.\tCodigo     \tNota1    \tNota2    \tNota3    \tNota4    \tDefinitiva\n";
    cout<<"---\t-----------\t---------\t---------\t---------\t---------\t----------\n";
    for(int i=0;i<n;i++){
        //Imprimo por pantalla los registros de los Alumnos
        cout<<listaAlu[i].id<<"\t"<<listaAlu[i].code<<setprecision(2)<<"\t\t"<<listaAlu[i].nota1<<"\t\t"<<listaAlu[i].nota2<<"\t\t"<<listaAlu[i].nota3<<"\t\t"<<listaAlu[i].nota4<<"\t\t"<<listaAlu[i].notaDefinitiva;
        //Controlo la máxima nota
        if(listaAlu[i].nota1 > maxNOTA){
           maxNOTA=listaAlu[i].nota1;
           codigoMaxNOTA=listaAlu[i].code;
        }
        if(listaAlu[i].nota2 > maxNOTA){
            maxNOTA=listaAlu[i].nota2;
            codigoMaxNOTA=listaAlu[i].code;
        }
        if(listaAlu[i].nota3 > maxNOTA){
            maxNOTA=listaAlu[i].nota3;
            codigoMaxNOTA=listaAlu[i].code;
        }
        if(listaAlu[i].nota4 > maxNOTA){
            maxNOTA=listaAlu[i].nota4;
            codigoMaxNOTA=listaAlu[i].code;
        }
        //Controlo la mínima nota
        if(listaAlu[i].nota1 < minNOTA){
           minNOTA=listaAlu[i].nota1;
           codigoMinNOTA=listaAlu[i].code;
        }
        if(listaAlu[i].nota2 < minNOTA){
            minNOTA=listaAlu[i].nota2;
            codigoMinNOTA=listaAlu[i].code;
        }
        if(listaAlu[i].nota3 < minNOTA){
            minNOTA=listaAlu[i].nota3;
            codigoMinNOTA=listaAlu[i].code;
        }
        if(listaAlu[i].nota4 < minNOTA){
            minNOTA=listaAlu[i].nota4;
            codigoMinNOTA=listaAlu[i].code;
        }
        //Sumo todas las notas para luego poder hacer el promedio general
        sumatoriaNOTA += listaAlu[i].notaDefinitiva;
        cout<<endl;
    }
    cout<<"\n\nEstadisticas del curso\n";
    cout<<"----------------------------------------\n";
    cout<<"El codigo del estudiante que obtivo la menor nota fue:\t"<<codigoMinNOTA<<" con: "<<setprecision(2)<<minNOTA<<endl;
    cout<<"El codigo del estudiante que obtivo la mayor nota fue:\t"<<codigoMaxNOTA<<" con: "<<setprecision(2)<<maxNOTA<<endl;
    cout<<"El promedio general del grupo fue:\t"<<setprecision(3)<<sumatoriaNOTA/n<<endl;
}

//Comprueba para procesar otro grupo y que solo se usen 4 caracteres ('S', 's', 'N', 'n')
string comprobarCHAR(string letra){
    do{
        if(letra!="s" && letra!="S" && letra!="n" && letra!="N"){
            cout<<"Opcion erronea, introduzca otra vez S o N: ";
            cin>>letra;
        }
    }while(letra!="s" && letra!="S" && letra!="n" && letra!="N");
    return letra;
}