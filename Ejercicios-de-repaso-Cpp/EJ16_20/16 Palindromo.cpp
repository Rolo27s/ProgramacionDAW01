
#include <iostream>     // Para el uso de cin, cout
#include <locale.h>     // Para el uso de la funcion setlocale(LC_ALL, "");

#include <stdio.h>
// Controla cantidad de numeros a mostrar con la funcion setprecision().
// cout << setprecision(10);       respeta 10 digitos de la parte entera
// cout << fixed << setprecision(2); respeta 2 digitos de la parte decimal

using namespace std;
const int N = 30;
const string solucion[2] = {"No cumple", "Es palindromo"};

float comprobarNum(float a);
string comprobarCHAR(string letra);

int main(){
    string repetirTODO, palabra[N], palabraAUX[N];
    int np, size[N];
    bool es_o_no[N]; // 0 no es palindromo, 1 si es palindromo.

    // Para el uso de todo tipo de caracteres.
    setlocale(LC_ALL, "");

    do
    {
        // Limpio la pantalla al principio del bucle para las N veces que se repetira.
        system("cls");

        cout << "Programa que comprueba palabras palindromo\n";
        cout << "------------------------------------------\n\n";

        cout << "Cuantas palabras quieres escribir? (min = 1, max = 30): ";
        cin  >> np;
        np = comprobarNum(np);

        for(int i = 0; i < np; i++){
            cout << "Palabra numero " << i+1 << " : ";
            getline(cin >> std::ws, palabra[i]);  // Con "cin >> std::ws" absorbo espacios en blanco y puedo trabajar con array de string
            size[i] = palabra[i].size(); // Los espacios en blanco si los cuenta para el tamano total
            palabraAUX[i] = palabra[i]; // Copio el array de palabras para compararlas luego
        }
        for(int i = 0; i < np; i++){
            for(int j = size[i], k=0; j >= 0; j--, k++){
                if(palabra[i][j-1] == palabraAUX[i][k]) es_o_no[i] = 1;
                else{
                    es_o_no[i] = 0;
                    break;
                }
                
            }
        }
        // Limpio la pantalla y empiezo a mostrar toda la informacion
        system("cls");

        cout << "Programa que comprueba palabras palindromo\n";
        cout << "------------------------------------------\n\n";
        cout << "Dato\t     Palabra             \t    Palindromo  \n";
        cout << "----\t-----------------------  \t  --------------  \n";

        for(int i = 0; i < np; i++){
            cout << i+1 << "\t\t" << palabra[i] << "  \t\t\t  " << solucion[es_o_no[i]] << endl;
        }

        cout << endl;

        // Pregunto si quiero volver a repetir el programa
        cout << "Desea procesar otro grupo de palabras S / N  \t";
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