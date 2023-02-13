/* Funciones virtuales.
    DEFINICION
    Una funci�n virtual es una funci�n miembro que se espera volver a definir en clases derivadas. 
    Cuando se hace referencia a un objeto de clase derivada mediante un puntero o una referencia a la clase base, 
    se puede llamar a una funci�n virtual para ese objeto y ejecutar la versi�n de la clase derivada de la funci�n.

    Las funciones virtuales garantizan que se llame a la funci�n correcta para un objeto, con independencia de la expresi�n utilizada para llamarla.
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