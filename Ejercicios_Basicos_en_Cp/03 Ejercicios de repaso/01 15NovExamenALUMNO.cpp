#include <iostream>
#include <string.h>
using namespace std;
struct alumno{
    string apellidoEst;
    float nota1;
    float nota2;
    float nota3;
};
const float pondNota1 = 0.25;
const float pondNota2 = 0.30;
const float pondNota3 = 0.45;

char comprobar(char otro);
void infoAlu();
float comprobarNotaParcial(float nota);

int main(){
char otro='S';

while(otro == 'S' || otro == 's'){
    infoAlu();
    cout<<"Desea procesar otro estudiante S o N: ";
    cin>>otro;
    comprobar(otro);
}
    cout<<"\n\n------ FIN DEL PROGRAMA ------";
    return 0;
}

char comprobar(char otro){
    if(otro=='s'||otro=='S'||otro=='n'||otro=='N'){
        return otro;
    }else{
        cout<<"Orden incorrecta. Contestar con S o N: ";
        cin>>&otro;
        return comprobar(otro);
    }
}

void infoAlu(){
    alumno alu;
    cout<<"Programa que calcula la nota final del estudiante!\n";
    cout<<"--------------------------------------------------\n\n";
    cout<<"Digite el apellido del estudiante: ";
    cin>>alu.apellidoEst;
    cout<<"\n\nDigite las tres notas parciales entre 0 y 5\n";
    cout<<"Nota parcial 1: ";
    cin>>alu.nota1;
    alu.nota1=comprobarNotaParcial(alu.nota1);
    cout<<"Nota parcial 2: ";
    cin>>alu.nota2;
    alu.nota2=comprobarNotaParcial(alu.nota2);
    cout<<"Nota parcial 3: ";
    cin>>alu.nota3;
    alu.nota3=comprobarNotaParcial(alu.nota3);
    cout<<"Datos introducidos correctamente. Voy a mostrar los datos por pantalla. ";
    system("pause");
    system("cls");
    cout<<"Programa que calcula la nota final del estudiante!\n";
    cout<<"--------------------------------------------------\n\n";
    cout<<"Digite el apellido del estudiante:\t"<<alu.apellidoEst;
    cout<<"\n\nDigite las tres notas parciales entre 0 y 5\n";
    cout<<alu.nota1<<"\t"<<alu.nota2<<"\t"<<alu.nota3<<"\n\n";
    cout<<"\t\tImprimir datos y resultados\n";
    cout<<"--------------------------------------------------\n\n";
    cout<<"Reporte de calificaciones del estudiante:\t"<<alu.apellidoEst<<endl;
    cout<<"La primera nota parcial y su porcentaje son:\t"<<alu.nota1<<"\t"<<pondNota1<<endl;
    cout<<"La segunda nota parcial y su porcentaje son:\t"<<alu.nota2<<"\t"<<pondNota2<<endl;
    cout<<"La tercera nota parcial y su porcentaje son:\t"<<alu.nota3<<"\t"<<pondNota3<<endl;
    cout<<"La nota final de estudiante es:\t\t\t"<<alu.nota1*pondNota1+alu.nota2*pondNota2+alu.nota3*pondNota3<<endl;
    cout<<"--------------------------------------------------\n\n";
}

float comprobarNotaParcial(float nota){
    while(nota<0||nota>5){
        cout<<"Nota parcial incorrecta. Introduzca nuevamente la nota entre 0 y 5: ";
        cin>>nota;
        }
        return nota;
}