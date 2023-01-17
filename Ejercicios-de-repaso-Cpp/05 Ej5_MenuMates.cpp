#include <iostream>
#include <math.h>
#include <stdlib.h> //Necesario para usar system
using namespace std;
int comprobarOpcion(int a);
float comprobarNoNegativoF(float b);
char comprobarRepetir(char c);

//Programa que procesa funciones matemáticas
int main(){
    int opcion=0, n=0;
    float numero=0;
    char repetir='S';

    do{
        system("cls");
        cout<<"Programa que procesa funciones matematicas!\n";
        cout<<"-------------------------------------------\n\n\n";
        cout<<"|-------------------------------|\n";
        cout<<"| *** Funciones matematicas *** |\n";
        cout<<"|-------------------------------|\n";
        cout<<"| 1. Raiz cuadrada              |\n";
        cout<<"| 2. Raiz cubica                |\n";
        cout<<"| 3. Potencia                   |\n";
        cout<<"| 4. Logaritmo decimal          |\n";
        cout<<"| 5. Logaritmo natural          |\n";
        cout<<"| 6. Salida                     |\n";
        cout<<"|-------------------------------|\n\n";

        cout<<"Digite el numero de la opcion a procesar: ";
        cin>>opcion;
        opcion = comprobarOpcion(opcion);
        switch(opcion){
            case 1:
                cout<<"Calculo de la raiz cuadrada\n";
                cout<<"---------------------------\n\n";
                cout<<"Digite el numero a procesar: ";
                cin>>numero;
                numero=comprobarNoNegativoF(numero);
                cout<<"Numero ingresado: \t"<<numero<<endl;
                cout<<"Raiz cuadrada: \t\t"<<sqrt(numero)<<endl<<endl;
                    break;
            case 2:
                cout<<"Calculo de la raiz cubica\n";
                cout<<"-------------------------\n\n";
                cout<<"Digite el numero a procesar: ";
                cin>>numero;
                numero=comprobarNoNegativoF(numero);
                cout<<"Numero ingresado: \t"<<numero<<endl;
                cout<<"Raiz cubica: \t\t"<<cbrt(numero)<<endl<<endl;
                    break;
            case 3:
                cout<<"Calculo de la potencia\n";
                cout<<"---------------------------\n\n";
                cout<<"Digite el numero a procesar (base): ";
                cin>>numero;
                cout<<"Digite el numero a procesar (exponente): ";
                cin>>n;
                n=comprobarNoNegativoF(n);
                cout<<"Numero ingresado (base): \t"<<numero<<endl;
                cout<<"Numero ingresado (exponente): \t"<<n<<endl;
                cout<<"Potencia: \t\t\t"<<pow(numero,n)<<endl<<endl;
                    break;
            case 4:
                cout<<"Calculo del logaritmo decimal\n";
                cout<<"-------------------------\n\n";
                cout<<"Digite el numero a procesar: ";
                cin>>numero;
                numero=comprobarNoNegativoF(numero);
                cout<<"Numero ingresado: \t"<<numero<<endl;
                cout<<"Logaritmo decimal: \t"<<log10(numero)<<endl<<endl;
                    break;
            case 5:
                cout<<"Calculo del logaritmo natural\n";
                cout<<"-------------------------\n\n";
                cout<<"Digite el numero a procesar: ";
                cin>>numero;
                numero=comprobarNoNegativoF(numero);
                cout<<"Numero ingresado: \t"<<numero<<endl;
                cout<<"Logaritmo natural: \t"<<log(numero)<<endl<<endl;
                    break;
            case 6:
                repetir='N';
                cout<<"Saliendo del programa...\n";
                    break;
        }
        cout<<endl;
        if(opcion!=6){
            cout<<"Desea realizar otra conversion: S o N   ";
            cin>>repetir;
            repetir = comprobarRepetir(repetir);
        }
    }while(repetir=='S');
    return 0;
}

int comprobarOpcion(int a){
    while(a<1||a>6){
        cout<<"\nNumero incorrecto...\n";
        cout<<"Digite el numero de la opcion a procesar: ";
        cin>>a;
    }
    return a;
}

float comprobarNoNegativoF(float b){
    while(b<0){
        cout<<"\nNumero incorrecto...\n";
        cout<<"Digite el numero mayor o igual a 0: ";
        cin>>b;
    }
    return b;
}

char comprobarRepetir(char c){
    while(c!='S'&&c!='s'&&c!='N'&&c!='n'){
        cout<<"\nNo le he entendido...\n";
        cout<<"Desea realizar otra conversion: S o N   ";
        cin>>c;
    }
    if(c=='s') c='S'; //Como hago el if en una sola línea y es muy simple, no necesito llaves.
    return c;
}