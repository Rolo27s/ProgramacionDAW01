#include <stdlib.h>     // Para el uso de funciones system.
#include <iostream>     // Para el uso de cin, cout.
#include <locale.h>     // Para el uso de la funcion setlocale(LC_ALL, "");
#include <string.h>     // Para el uso de funciones relacionadas con strings en versiones antiguas de C++.
#include <string>       // Para el uso de funciones relacionadas con strings en versiones más actuales.

// Controla cantidad de numeros a mostrar con la funcion setprecision().
// cout << setprecision(10);       respeta 10 digitos de la parte entera.
// cout << fixed << setprecision(2); respeta 2 digitos de la parte decimal.
#include <iomanip>      // Para el uso de fixed y setprecision.
using namespace std;

const int N = 25;       // Numero máximo de palabras a insertar.
string palabraEnSingular[N], palabraEnPlural[N];

void ingresaPalabra (int np);
string analizaPalabra (string pal);

int comprobarNum(int a);
string comprobarCHAR(string letra);

int main(){
    string repetirTODO;
    int nPal;

    // Para el uso de todo tipo de caracteres.
    setlocale(LC_ALL, "");

    do
    {
        // Limpio la pantalla al principio del bucle para las N veces que se repetira.
        system("cls");

        cout<<"Programa que obtiene el plural de una serie de palabras\n";
        cout<<"-------------------------------------------------------\n\n";
        cout<<"Cuantas palabras quieres ingresar (min = 1 y max = "<<N<<"): ";
        cin>>nPal;
        nPal = comprobarNum(nPal);   // Compruebo que sea correcto.

        // Llamada a funcion. Descripcion de la misma en su definición.
        ingresaPalabra(nPal);

        // Llamada a funcion. Descripcion de la misma en su definición.
        for(int i=0; i<nPal; i++){
            palabraEnPlural[i] = analizaPalabra(palabraEnSingular[i]);
        }
        // Limpiamos la pantalla antes de mostrar los datos finales
        system("cls");
        // Mostramos la informacion al usuario
        cout<<"Programa que obtiene el plural de una serie de palabras\n";
        cout<<"-------------------------------------------------------\n\n";
        cout<<"Dato"<<"\t"<<"Palabra"<<"\t\t\t"<<" Palabra "<<endl;
        cout<<"    "<<"\t"<<"Inicial"<<"\t\t\t"<<"en Plural"<<endl;
        cout<<"----"<<"\t"<<"-------"<<"\t\t\t"<<"---------"<<endl;

        for(int j=0; j<nPal; j++){
            // La utilidad de este if else es meramente estética para una mejor visualizacion
            if(palabraEnSingular[j].size() < 8){
                cout<<j+1<<"\t"<<palabraEnSingular[j]<<"\t\t\t"<<palabraEnPlural[j]<<endl;
            }else{
                cout<<j+1<<"\t"<<palabraEnSingular[j]<<"\t\t"<<palabraEnPlural[j]<<endl;
            }
        }
        cout<<endl;

        // Pregunto si quiero volver a repetir el programa.
        cout<<"Desea procesar otro grupo de palabras S / N  \n\t";
        cin>>repetirTODO;
        // Nos aseguramos que el datos introducido sea válido.
        repetirTODO = comprobarCHAR(repetirTODO); 
        
        // Limpio los arrays de strings para una posible nueva repeticion efectiva.
        for(int k=0; k<N; k++){
            palabraEnSingular[k]    = "";
            palabraEnPlural[k]      = "";
        }

    } while (repetirTODO == "S" || repetirTODO == "s");
        
    cout<<"Cerrando el programa. ";
    system("pause");

    return 0;
}

// Funcion que se encarga de ingresar todas las palabras que querias en un array de palabras o lista.
void ingresaPalabra (int np){
    for(int c = 0; c < np; c++){
        cout<<"Palabra ("<<c+1<<"/"<<np<<") : ";
        cin>>palabraEnSingular[c];
    }
}

// Analizamos cada palabra ingresada y devolvemos su plural. Una a una.
string analizaPalabra (string pal){
    int tamano;
    char ultimaLetra;
    string plural;

    tamano = pal.size();
    ultimaLetra = pal[tamano - 1];    // Necesito restar uno porque la ultima posicion del string es su tamaño menos uno.

    switch (ultimaLetra)
    {
    case 'a': case 'e': case 'i': case 'o': case 'u':
        plural = pal + "s";         // Añado "s" al final de la palabra
        break;

    case 'z':
        plural = pal;
        plural[tamano - 1] = 'c';   // Modifico el ultimo caracter del string 'z' a 'c'
        plural = plural + "es";     // Añado "es" al final de la palabra
        break;

    default:
        plural = pal + "es";        // Añado "es" al final de la palabra. El default cubre las terminaciones en consonante que no sean 'z'
        break;
    }

    return plural;
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