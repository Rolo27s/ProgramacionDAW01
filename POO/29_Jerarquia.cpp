#include <iostream>
#include <stdlib.h>
using namespace std;

/* Clase Padre (raiz - adan) */
class Persona {
    private:
        string nombre;
        int edad;
    public:
        Persona(string, int);
        ~Persona();
        void mostrarPersona();
};

/* --------------------------------------------- */ 
Persona::Persona(string _nombre, int _edad) {
    nombre = _nombre;
    edad = _edad;
}

Persona::~Persona() {}

void Persona::mostrarPersona() {
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
}

/* ------------------------------------------------- */
/* Herencia. Genero clase Empleado que hereda de Persona */
class Empleado:public Persona {
    private:
        float salario;
    public:
        Empleado(string, int, float);
        ~Empleado();
        void mostrarEmpleado();
};

/* --------------------------------------------- */
Empleado::Empleado(string _nombre, int _edad, float _salario):Persona(_nombre, _edad) {
    salario = _salario;
}

Empleado::~Empleado() {}

void Empleado::mostrarEmpleado() {
    mostrarPersona();
    cout << "Salario: " << salario << endl;
}

/* ------------------------------------------------- */
/* Herencia. Genero clase Empleado que hereda de Persona */
class Estudiante:public Persona {
    private:
        float notaFinal;
    public:
        Estudiante(string, int, float);
        ~Estudiante();
        void mostrarEstudiante();
};

/* --------------------------------------------- */
Estudiante::Estudiante(string _nombre, int _edad, float _notaFinal):Persona(_nombre, _edad) {
    notaFinal = _notaFinal;
}

Estudiante::~Estudiante() {}

void Estudiante::mostrarEstudiante() {
    mostrarPersona();
    cout << "Nota Final: " << notaFinal << endl;
}

/* ------------------------------------------------- */
/* Herencia. Genero clase Universitario que hereda de Estudiante */
class Universitario:public Estudiante {
    private:
        string carrera;
    public:
        Universitario(string, int, float, string);
        ~Universitario();
        void mostrarUniversitario();
};

/* --------------------------------------------- */
Universitario::Universitario(string _nombre, int _edad, float _notaFinal, string _carrera):Estudiante(_nombre, _edad, _notaFinal) {
    carrera = _carrera;
}

Universitario::~Universitario() {}

void Universitario::mostrarUniversitario() {
    mostrarEstudiante();
    cout << "Carrera: " << carrera << endl;
}

/*--------------------------------------------------*/

int main() {
    /* Pondre un ejemplo de cada clase para ver por pantalla */

    /* Persona */
    cout << "Clase persona\n";
    Persona persona1("Pablo", 20);
    persona1.mostrarPersona();
    cout << endl;

    /* Empleado */
    cout << "Clase empleado\n";
    Empleado empleado1("Pablo", 20, 845.51);
    empleado1.mostrarEmpleado();
    cout << endl;

    /* Estudiante */
    cout << "Clase estudiante\n";
    Estudiante estudiante1("Pablo", 20, 4.9);
    estudiante1.mostrarEstudiante();
    cout << endl;

    /* Universitario */
    cout << "Clase universitario\n";
    Universitario universitario1("Pablo", 20, 4.9, "Periodismo");
    universitario1.mostrarUniversitario();
    cout << endl;

    return 0;
}