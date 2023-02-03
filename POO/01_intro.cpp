#include <iostream>
#include <stdio.h>
using namespace std;

/* Declaramos la clase Automovil */
class Automovil {
    /* Atributos (declaracion) */
    public:
        int combustible;
        int velocidad_max;
        string color;
    
    private:
        int cv;
        void pintar();

    /* Metodos (declaracion) */
    public:
        Automovil();
        void arrancar();
        void acelerar();
        void acelerar(int a);
        void apagar();
        ~Automovil();
};

/* Para hacer un contructor de una clase, necesito que el constructor se llame exactamente igual que la clase a crear */
Automovil::Automovil() {
    cout << "\nSe ha creado un objeto de tipo Automovil\n";

    /* Para usar zonas de clases privadas tengo que interactuar desde el constructor */
    cv = 15;
    cout << cv << endl;
}

/* Metodos (definicion) */
void Automovil::arrancar(){
    cout << "\nEl automovil esta arrancado\n";
}

void Automovil::acelerar(){
    cout << "\nEl automovil esta acelerando\n";
}

/* Ejemplo de sobrecarga de Metodo */
void Automovil::acelerar(int a){
    cout << "\nEl automovil ha acelerado " << a << "\n";
}

void Automovil::apagar(){
    cout << "\nEl automovil esta apagado\n";
}

void Automovil::pintar() {
    cout << "\nEl automovil se ha pintado\n";
}

/* Ahora declaramos el destructor con la virgulilla ~ (alt gr + 4 + space, alt + 126) 
El destructor sirve para liberar memoria */
Automovil::~Automovil() {
    cout << "\nSe ha destruido un objeto de tipo automovil\n";
}

/* El constructor y el destructor no retorna nada */


/* Generamos una nueva clase */
class Ferrari:public Automovil {
};

int main ()
{
    Automovil seat;
    Ferrari ferrari1;

    seat.color = "rojo";
        cout << "\nMi coche seat es de color " << seat.color << "\n";

    seat.apagar();
    seat.acelerar();
    seat.acelerar(5);

    ferrari1.apagar();

    return 0;
}