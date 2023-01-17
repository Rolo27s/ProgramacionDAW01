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
const int N = 10;

float comprobarNum(float a);
string comprobarCHAR(string letra);

int main(){
    string repetirTODO, frase[N];
    int nf, nv[N], nc[N], size[N];

    // Para el uso de todo tipo de caracteres.
    setlocale(LC_ALL, "");

    do
    {
        // Limpio la pantalla al principio del bucle para las N veces que se repetira.
        system("cls");

        cout << "Programa que cuenta vocales y consonantes en una serie de frases\n";
        cout << "----------------------------------------------------------------\n\n";

        cout << "Cuantas frases quieres escribir? (min = 1, max = 10): ";
        cin  >> nf;
        nf = comprobarNum(nf);

        for(int i = 0; i < nf; i++){
            cout << "Frase numero " << i+1 << " : ";
            getline(cin >> std::ws, frase[i]);  // Con "cin >> std::ws" absorbo espacios en blanco y puedo trabajar con array de string
            size[i] = frase[i].size(); // Los espacios en blanco si los cuenta para el tamano total
            nv[i] = 0; nc[i] = 0;

            for(int j = 0; j < size[i]; j++){
                switch(frase[i][j]){
                    case 'a': case 'e': case 'i': case 'o': case 'u': case 'A': case 'E': case 'I': case 'O': case 'U':
                        nv[i]++;
                        break;
                    case ' ':
                        break;
                    default:
                        nc[i]++;
                        break;
                }
            }
        }
        // Limpio la pantalla y empiezo a mostrar toda la informacion
        system("cls");

        cout << "Programa que cuenta vocales y consonantes en una serie de frases\n";
        cout << "----------------------------------------------------------------\n\n";
        cout << "Nro.\tFrase o cadena de texto  \t  Vocales  \t  Consonantes\n";
        cout << "----\t-----------------------  \t  -------  \t  -----------\n";

        for(int i = 0; i < nf; i++){
            cout << i+1 << "\t" << frase[i] << "  \t\t  " << nv[i] << "  \t\t  " << nc[i] << endl;
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
    while(a<1 || a>10){
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