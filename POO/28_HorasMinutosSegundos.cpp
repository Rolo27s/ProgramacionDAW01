/* 
Ejercicio 28
Construya una clase Tiempo que contenga los siguientes atributos enteros: horas, minutos y segundos.
Haga que la clase contenga 2 constructores, el primero debe tener 3 parámetros Tiempo(int, int, int) y el
segundo sólo tendrá un campo que serán los segundos y desensamble el número entero largo en horas,
minutos y segundos.
 */

#include <iostream>
#include <stdio.h>
#include <windows.h>
using namespace std;

class Tiempo {
    /* Atributos */
    private:
        int horas;
        int minutos;
        int segundos;

    /* Metodos */
    public:
        Tiempo(int constr_hora, int constr_min, int constr_seg);
        Tiempo(int constr_solo_seg);
        ~Tiempo();
};


Tiempo::Tiempo(int constr_hora, int constr_min, int constr_seg) {
    int segundosTot;
     segundosTot = constr_hora * 3600 + constr_min * 60 + constr_seg;

     cout << "Segundos totales: " << segundosTot << endl << endl;
}

Tiempo::Tiempo(int constr_solo_seg) {
    int segundosP, minutosP, horasP;

    segundosP = constr_solo_seg;
    horasP = segundosP / 3600;
    segundosP %= 3600;
    minutosP = segundosP / 60;
    segundosP %= 60;

    cout << "Horas: " << horasP << endl;
    cout << "Minutos: " << minutosP << endl;
    cout << "Segundos: " << segundosP << endl;
}

Tiempo::~Tiempo() {
    cout << "\n\tSe ha destruido el objeto Tiempo\n";
}

/* ------------------------------------------------------------------------------- */


int main() {
    Tiempo timehms(4, 22, 50);
    Tiempo times(2550);
    return 0;
}