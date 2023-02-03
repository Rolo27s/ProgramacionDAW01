#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
using namespace std;

class Temperatura {
    private:
        float grados;
    public:
        Temperatura(float gra);
        ~Temperatura();
        void fa();
        void kelvin();
};

/* Definicion de Metodos */
Temperatura::Temperatura(float gra)
{
    grados = gra;
}

Temperatura::~Temperatura(){
    cout << "\n\t--( Soy el destructor )--\n\n";
    system("pause");
}

void Temperatura::fa() {
    float fah;
    fah = (grados * 9/5) + 32;
    cout << "La temperatura en grados fahrenheit es: " << fah << endl;
}

void Temperatura::kelvin() {
    float kel;
    kel = grados + 273.15;
    cout << "La temperatura en kelvin es: " << kel << endl;
}

int main () {
    float gCel;
    char repetir;

    do {
        system("cls");
        cout << "Ingresa grados celsius: ";
        cin >> gCel;
        Temperatura temp1(gCel);
        temp1.fa();
        temp1.kelvin();
        cout << endl;
        cout << "Quieres volver a ingresar otra temperatura? (S/N): ";
        cin >> repetir;
        while (repetir != 'S' && repetir != 's' && repetir != 'N' && repetir != 'n')
        {   
            Sleep(200);
            cout << "Error. Introduce S o N: ";
            cin >> repetir;
        }
    } while (repetir == 'S' || repetir == 's');
    
    return 0;
}