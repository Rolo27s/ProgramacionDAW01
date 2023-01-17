#include <stdlib.h>     // Para el uso de funciones system
#include <iostream>     // Para el uso de cin, cout
#include <locale.h>     // Para el uso de la funcion setlocale(LC_ALL, "");
#include <string.h>     // Para el uso de funciones relacionadas con strings en versiones antiguas de C++
#include <string>       // Para el uso de funciones relacionadas con strings en versiones más actuales

// Controla cantidad de numeros a mostrar con la funcion setprecision().
// cout << setprecision(10);       respeta 10 digitos de la parte entera
// cout << fixed << setprecision(2); respeta 2 digitos de la parte decimal
#include <iomanip>      // Para el uso de fixed y setprecision
using namespace std;
const int N = 20;
const int L = 32;

int comprobarNum(int a);
string comprobarCHAR(string letra);

int main(){
    string repetirTODO, frase[N];
    int nf, size[N], longInf, longSup;


    // Para el uso de todo tipo de caracteres.
    setlocale(LC_ALL, "");

    do
    {
        // Limpio la pantalla al principio del bucle para las N veces que se repetira.
        system("cls");

        cout << "Programa que muestra frases cuya longitud esta en un rango\n";
        cout << "----------------------------------------------------------\n\n";

        cout << "Cuantas frases quieres escribir? (min = 1, max = 16): ";
        cin  >> nf;
        nf = comprobarNum(nf);

        for(int i = 0; i < nf; i++){
            cout << "Frase numero " << i+1 << " : ";
            getline(cin >> std::ws, frase[i]);  // Con "cin >> std::ws" absorbo espacios en blanco y puedo trabajar con array de string
            size[i] = frase[i].size(); // Los espacios en blanco si los cuenta para el tamano total
        }
        cout << "Ingrese longitud inferior de la frase a mostrar < 32 ";
        cin>>longInf;
        while(longInf < 0 || longInf >= L){
            cout << "\nError. Ingrese longitud inferior de la frase a mostrar < 32 ";
            cin >> longInf;
        }

        cout << "Ingrese longitud superior de la frase a mostrar <= 32 ";
        cin>>longSup;
        while(longSup < 0 || longSup >= L){
            cout << "\nError. Ingrese longitud inferior de la frase a mostrar < 32 ";
            cin >> longSup;
        }

        // Limpio la pantalla y empiezo a mostrar toda la informacion
        system("cls");

        cout << "Programa que muestra frases cuya longitud esta en un rango\n";
        cout << "----------------------------------------------------------\n\n";
        cout << "Longitud inferior:\t" << longInf << endl;
        cout << "Longitud superior:\t" << longSup << endl;
        cout << "Dato  \t     Frase o cadena de inicial  \n";
        cout << "----  \t    --------------------------- \n";

        for(int i = 0; i < nf; i++){
            if(size[i] >= longInf && size[i] <= longSup){
                cout << i+1 << "\t\t" << frase[i] << endl;            
            }
        }
        cout << endl;

        // Pregunto si quiero volver a repetir el programa
        cout << "Desea procesar otro grupo de frases S / N  \t";
        cin  >> repetirTODO;
        // Nos aseguramos que el datos introducido sea válido.
        repetirTODO = comprobarCHAR(repetirTODO); 
    
    } while (repetirTODO == "S" || repetirTODO == "s");
    
    system("cls");
    cout << "Cerrando el programa. ";
    system("pause");

    return 0;
}

// << --- FUNCIONES AUXILIARES PARA COMPROBAR LOS INPUTS --- >>
//Comprueba que el numero este en el rango correcto para el buen funcionamiento del programa
int comprobarNum(int a){
    while(a<1 || a>N){
        cout<<"Error. Ingrese nuevamente el valor: ";
        cin>>a;
    }
    return a;
}
//Comprueba para procesar otro grupo y que solo se usen 4 caracteres ('S', 's', 'N', 'n')
string comprobarCHAR(string letra){
    while(letra != "s" && letra != "S" && letra != "n" && letra != "N"){
        cout<<"Error. Ingrese nuevamente S o N: ";
        cin>>letra;
    }
    return letra;
}