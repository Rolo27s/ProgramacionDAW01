#include <iostream>
#include <string>
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
    Temperatura temp1(4);
    temp1.fa();
    temp1.kelvin();

    return 0;
}