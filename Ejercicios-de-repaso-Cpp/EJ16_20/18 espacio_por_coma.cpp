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
const int N = 15;

float comprobarNum(float a);
string comprobarCHAR(string letra);

int main(){
    string repetirTODO, frase[N], fraseSeg[N];
    int nf, size[N];

    // Para el uso de todo tipo de caracteres.
    setlocale(LC_ALL, "");

    do
    {
        // Limpio la pantalla al principio del bucle para las N veces que se repetira.
        system("cls");

        cout << "Programa que reemplaza espacios por comas en una serie de frases\n";
        cout << "----------------------------------------------------------------\n\n";

        cout << "Cuantas frases quieres escribir? (min = 1, max = 15): ";
        cin  >> nf;
        nf = comprobarNum(nf);

        for(int i = 0; i < nf; i++){
            cout << "Frase numero " << i+1 << " : ";
            getline(cin >> std::ws, frase[i]);  // Con "cin >> std::ws" absorbo espacios en blanco y puedo trabajar con array de string
            size[i] = frase[i].size(); // Los espacios en blanco si los cuenta para el tamano total
            fraseSeg[i] = frase[i];

            for(int j = 0; j < size[i]; j++){
                switch(frase[i][j]){
                    case ' ':
                        frase[i][j] = ',';
                        break;
                    default:
                        break;
                }
            }
        }
        // Limpio la pantalla y empiezo a mostrar toda la informacion
        system("cls");

        cout << "Programa que reemplaza espacios por comas en una serie de frases\n";
        cout << "----------------------------------------------------------------\n\n";
        cout << "Nro.  \t    Frase o cadena de inicial  \t  Frase o cadena de final  \n";
        cout << "----  \t    -------------------------  \t  -----------------------  \n";

        for(int i = 0; i < nf; i++){
            cout << i+1 << "\t\t" << fraseSeg[i] << "  \t  " <<  frase[i] << endl;
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
float comprobarNum(float a){
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