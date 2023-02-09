#include <iostream>
#include <stdlib.h>
using namespace std;

class Punto {
    private:
        int x, y;
    public:
        Punto();
        ~Punto();
        void setPunto(int,int);
        int getPuntox();
        int getPuntoy();
};

/* ------------------------------------------- */

Punto::Punto() {}
Punto::~Punto() {}

void Punto::setPunto (int _x, int _y) {
    x = _x;
    y = _y;
}

int Punto::getPuntox() {
    return x;
}

int Punto::getPuntoy() {
    return y;
}

/* El set trabaja como constructor. El get trabaja como modificador */

int main() {
    Punto punto1;

    /* Metodo public que interacciona con los atributos private */
    punto1.setPunto(15,20);

    /* Metodos public que devuelve los valores de x e y de la clase Punto */
    cout << "Punto x: " << punto1.getPuntox()  << endl;
    cout << "Punto y: " << punto1.getPuntoy()  << endl;

    return 0;
}