#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h> // Libreria necesaria para el uso de comandos tipo system
using namespace std;

struct user{
    int id;
    string name;
    float weight;
    float height;
    float imc;
    string valoration;
};
user cliente[100]; //Cada grupo tendrá un máximo de 100 clientes.

void insertarInfo(int n);
float comprobarNum(float a);
void comprobarCHAR(string &letra);
string estado(float imc);
void verInfo(int n);

int main(){
    string opcion="A", opcion2="B";
    int nUser=0;
    
    do{
        system("cls");
        cout<<"Programa que calcula estadisticas del IMC de n usuarios!\n";
        cout<<"--------------------------------------------------------\n\n";
        //En este apartado introducimos toda la informacion de un grupo de clientes
        do{
            insertarInfo(nUser);
            nUser++;
            cout<<"Desea procesar otro usuario: S o N  ";
            comprobarCHAR(opcion);
        }while(opcion=="S"||opcion=="s");

        //Cuando pare de procesar usuarios, que muestre el listado de la informacion recopilada
        verInfo(nUser);
        //Desea procesar otro grupo¿? Si si, vuelve a empezar, si no, sale del programa.
        cout<<"\nDesea procesar otro grupo: S o N  ";
        comprobarCHAR(opcion2);
        nUser=0; //Reseteo el contador de usuarios para empezar a sobreescribir informacion.
    }while(opcion2=="S"||opcion2=="s");

    return 0;
}

//Comprueba que el numero sea mayor a 0 para el buen funcionamiento del programa
float comprobarNum(float a){
    while(a<=0){
        cout<<"Error... Ingrese nuevamente el valor: ";
        cin>>a;
    }
    return a;
}

//Defines los valores de un usuario
void insertarInfo(int n){
    cliente[n].id=n+1;
    cout<<"Nombre del cliente: ";
    cin>>cliente[n].name;
    cout<<"Peso del cliente en Kg: ";
    cin>>cliente[n].weight;
    cliente[n].weight=comprobarNum(cliente[n].weight); // Llamamos a la funcion para controlar el peso.
    cout<<"Altura del cliente en m: ";
    cin>>cliente[n].height;
    cliente[n].height=comprobarNum(cliente[n].height); // Llamamos a la funcion para controlar la altura.
    cliente[n].imc=cliente[n].weight/pow(cliente[n].height,2);
    cliente[n].valoration=estado(cliente[n].imc);       // Llamamos a la funcion estado para saber la valoracion del IMC
    cout<<"---------------------------------------------------------\n\n";
}

//Esta funcion imprime por pantalla toda la informacion de un grupo de usuarios.
void verInfo(int n){
    float maxIMC=cliente[0].imc, minIMC=cliente[0].imc, sumatoriaIMC=0;
    string userMaxIMC=cliente[0].name, userMinIMC=cliente[0].name;
    cout<<"Imprimir datos de usuarios y resultados\n";
    cout<<"---------------------------------------\n";
    cout<<"No.\tNombre     \tMasa (Kg)\tTalla (m)\tI.M.C \t\tValora IMC\n";
    cout<<"---\t-----------\t---------\t---------\t------\t\t----------\n";
    for(int i=0;i<n;i++){
        cout<<cliente[i].id<<"\t"<<cliente[i].name<<"\t"<<cliente[i].weight<<"\t\t"<<cliente[i].height<<"\t\t"<<cliente[i].imc<<"\t\t"<<cliente[i].valoration;
        if(cliente[i].imc > maxIMC){
           maxIMC=cliente[i].imc;
           userMaxIMC=cliente[i].name;
        }
        if(cliente[i].imc < minIMC){
            minIMC=cliente[i].imc; 
            userMinIMC=cliente[i].name;
        }
        sumatoriaIMC += cliente[i].imc;
        cout<<endl;
    }
    cout<<"\n\nEstadisticas del indice de masa corporal\n";
    cout<<"----------------------------------------\n";
    cout<<"Numero de usuarios procesados: \t"<<n<<endl;
    cout<<"Usuario con mayor imc          \t"<<userMaxIMC<<"\tcon\t"<<maxIMC<<endl;
    cout<<"Usuario con menor imc          \t"<<userMinIMC<<"\tcon\t"<<minIMC<<endl;
    cout<<"Sumatoria de imc del grupo     \t"<<sumatoriaIMC<<endl;
    cout<<"Promedio de imc del grupo      \t"<<sumatoriaIMC/n<<endl;
}

//Dependiendo de que IMC tenga el usuario, devolvera la valoracion.
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

//Ingresa y comprueba para procesar otro usuario, u otro grupo, que solo se usen 4 caracteres ('S', 's', 'N', 'n')
void comprobarCHAR(string &letra){
    do{
        cin>>letra;
        if(letra!="s" && letra!="S" && letra!="n" && letra!="N"){
            cout<<"Opcion erronea, introduzca otra vez S o N: ";
        }
    }while(letra!="s" && letra!="S" && letra!="n" && letra!="N");
}