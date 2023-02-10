/* EJERCICIO 30. 
Elaborar un programa que genere la clase Conductor (aplicando la ley de Ohm R =
V / I) cuyos atributos son: nombre, voltaje, intensidad, resistencia, calcule el valor
de la resistencia (Ohm) en función de la diferencia de voltaje (Voltios) y de la
intensidad de corriente aplicada (Amperios) por el conductor para diez objetos
cargados mediante un vector. */

#include <iostream>
#include <stdlib.h>
using namespace std;

/* Funcionare de momento con 10 elementos */
const int N = 2;

class Conductor {
    private:
        string nombre;
        /* voltaje (V), intensidad (A), resistencia (?)*/
        float voltaje, intensidad, resistencia;
    public:
        Conductor();
        ~Conductor();
        void calculoDeR(string, float, float);
        void mostrar();
};

Conductor::Conductor() {}
Conductor::~Conductor() {}

/* Setter */
void Conductor::calculoDeR(string _nombre, float _voltaje, float _intensidad) {
    nombre = _nombre;
    voltaje = _voltaje;
    intensidad = _intensidad;
    resistencia = voltaje / intensidad;
}

/* Getter */
void Conductor::mostrar() {
    string cad1, cad2, cad3, cad4;
    
    cad1 = nombre;
    cad2 = to_string(voltaje);
    cad3 = to_string(intensidad);
    cad4 = to_string(resistencia);
    
    cad1.resize(15, ' ');
    cad2.resize(15, ' ');
    cad3.resize(15, ' ');
    cad4.resize(15, ' ');

    cout << cad1 << cad2 << cad3 << cad4 << endl;
}

/* ------------------------------------------------------------------------- */

int main() {
    Conductor objeto[N];
    string nombre;
    float voltaje, intensidad;

    cout << "Programa que calcula la resistencia de un elemento\n";
    cout << "--------------------------------------------------\n";

    /* Ingreso los valores */
    for (int i = 0; i < N; i++) {
        cout << "Declarando el objeto " << i+1 << endl;
        cout << "Nombre: ";
        cin >> nombre;
        cout << "Voltaje: ";
        cin >> voltaje;
        cout << "Intensidad: ";
        cin >> intensidad;

        objeto[i].calculoDeR(nombre, voltaje, intensidad);
    }

    /* Muestro la informacion */
    cout << "\nNombre          Voltaje       Intensidad     Resistencia\n";
    cout << "------          -------       ----------     -----------\n";
    for (int i = 0; i < N; i++) {
        objeto[i].mostrar();
    }
    
    cout << endl;
    return 0;
}