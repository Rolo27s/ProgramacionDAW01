#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

float diagnostico();
float comprobarNum(float a);
void comprobarCHAR(string &letra);
string estado(float imc);

int main(){
    string opcion="S";
    while(opcion=="S"||opcion=="s"){ // Mejor hacer un do --- while
        diagnostico();
        cout<<"Desea procesar otro paciente: S o N  ";
        comprobarCHAR(opcion);
    }
    return 0;
}

float comprobarNum(float a){
    while(a<=0){
        cout<<"Error... Ingrese nuevamente el valor: ";
        cin>>a;
    }
    return a;
}

float diagnostico(){
    string nombre;
    float masa=0, talla=0, imc=0;
    cout<<"Programa que calcula y valora el indice de masa corporal!\n";
    cout<<"---------------------------------------------------------\n\n";
    cout<<"Captura y validacion de datos";
    cout<<"---------------------------------------------------------\n\n";
    cout<<"Digite el nombre del paciente: ";
    cin>>nombre;
        cout<<"\n";
    cout<<"Digite la masa en Kg: ";
    cin>>masa;
    masa=comprobarNum(masa);
        cout<<"\n";

    cout<<"Digite la talla en m: ";
    cin>>talla;
    talla=comprobarNum(talla);
        cout<<"\n";
    cout<<"Calculando y valorando el I.M.C....\n\n";
    cout<<"Imprimir datos y resultados\n";
    cout<<"---------------------------------------------------------\n\n";
    cout<<"Nombre del paciente: \t"<<nombre<<endl;
    cout<<"Masa del paciente en Kg: \t"<<masa<<endl;
    cout<<"Talla del paciente en m: \t"<<talla<<endl;
    imc=masa/pow(talla,2);
    cout<<"Indice de masa corporal en Kg / m2: \t"<<imc<<endl;
    cout<<"Valoracion del indice IMC: \t"<< estado(imc)<<endl;
    cout<<"---------------------------------------------------------\n\n";

    return imc;
}
string estado(float imc){
    if(imc < 18.5){
        return "Insuficiencia ponderal";
    }else if(imc>=18.5 && imc<25){
        return "Intervalo normal";
    }else if(imc>=25 && imc<30){
        return "Preobesidad";
    }else if(imc>=30 && imc<35){
        return "Obesidad clase I";
    }else if(imc>=35 && imc<40){
        return "Obesidad clase II";
    }else{
        return "Obesidad clase III";
    }
}

void comprobarCHAR(string &letra){
    do{
        cin>>letra;
        if(letra!="s"&&letra!="S"&&letra!="n"&&letra!="N"){
            cout<<"Opcion erronea, introduzca otra vez S o N: ";
        }
    }while(letra!="s"&&letra!="S"&&letra!="n"&&letra!="N");
}