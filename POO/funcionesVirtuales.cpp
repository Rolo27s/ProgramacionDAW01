/* Funciones virtuales.
    DEFINICION
    Una función virtual es una función miembro que se espera volver a definir en clases derivadas. 
    Cuando se hace referencia a un objeto de clase derivada mediante un puntero o una referencia a la clase base, 
    se puede llamar a una función virtual para ese objeto y ejecutar la versión de la clase derivada de la función.

    Las funciones virtuales garantizan que se llame a la función correcta para un objeto, con independencia de la expresión utilizada para llamarla.
*/

#include <iostream>
using namespace std;

class ClaseA {
    private:
        int A;
    public:
        ClaseA();
        void mostrar();
        ~ClaseA();
};


ClaseA::ClaseA() {
    A = 10;
}

void ClaseA::mostrar() {
    cout << "A = " << A << endl;
}

ClaseA::~ClaseA() {}

class ClaseB:public ClaseA {
    private:
        int B;
    public:
        ClaseB();
        void mostrar();
        ~ClaseB();
};

ClaseB::ClaseB() {
    B = 30;
}

void ClaseB::mostrar() {
    cout << "B = " << B << endl;
}

int main() {
    ClaseB objetob;

    objetob.ClaseA::mostrar();
    objetob.mostrar();

    return 0;
}