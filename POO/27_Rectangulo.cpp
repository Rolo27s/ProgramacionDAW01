/*
EJERCICIO 27
Construya una clase llamada Rectángulo que tenga los siguientes atributos: largo y ancho, y los
siguientes métodos: perímetro () y área ().
*/

#include <iostream>
#include <stdio.h>
#include <windows.h>
using namespace std;

class Rectangulo {
    /* Atributos */
    private:
        float largo;
        float ancho;
    
    /* Metodos */
    public:
        Rectangulo(float constr_largo, float constr_ancho);
        float perimetro();
        float area();
        ~Rectangulo();
};

/* defino los metodos */

/* Constructor rectangulo. Argumentos largo y ancho */
Rectangulo::Rectangulo(float constr_largo, float constr_ancho) {
    
    largo = constr_largo;
    ancho = constr_ancho;
}

/* funcion que recibe largo y ancho de rectangulo y devuelve su perimetro */
float Rectangulo::perimetro() {
    return (largo + largo + ancho + ancho);
}

/* funcion que recibe largo y ancho de rectangulo y devuelve su area */
float Rectangulo::area() {
    return (largo * ancho);
}

Rectangulo::~Rectangulo() {
    cout << "\n\tSe ha destruido el objeto Rectangulo\n";
}

/* ------------------------------------------------------------------------------- */

int main() {
    
    float constr_ancho, constr_largo;

    cout << "Ingrese el largo del rectangulo: ";
    cin >> constr_largo;
    while (constr_largo <= 0) {
        cout << "Error...\n";
        Sleep(200);
        cout << "Ingrese el largo del rectangulo: ";
        cin >> constr_largo;
    }

    cout << "Ingrese el ancho del rectangulo: ";
    cin >> constr_ancho;
    while (constr_ancho <= 0) {
        cout << "Error...\n";
        Sleep(200);
        cout << "Ingrese el ancho del rectangulo: ";
        cin >> constr_ancho;
    }

    Rectangulo rectangulo1(constr_largo, constr_ancho);
    cout << "\nPerimetro del rectangulo: " << rectangulo1.perimetro();
    cout << "\nArea del rectangulo: " << rectangulo1.area();

    return 0;
}