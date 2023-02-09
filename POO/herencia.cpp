#include <iostream>
#include <stdlib.h>
using namespace std;

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
/* Herencia. Genero clase Alumno que hereda de Persona */

class Alumno:public Persona {
    private:
        string codAlumno;
        float nota;
    public:
        Alumno(string, int, string, float);
        ~Alumno();
        void mostrarAlumno();
};

/* Los dos puntos finales seguido de la clase persona significa que la clase Alumno tendra el nombre y la edad de la clase Persona */
Alumno::Alumno(string _nombre, int _edad, string _codAlumno, float _nota):Persona(_nombre, _edad) {
    codAlumno = _codAlumno;
    nota = _nota;
}

Alumno::~Alumno() {}

void Alumno::mostrarAlumno() {
    mostrarPersona();
    cout << "Codigo Alumno: " << codAlumno << endl;
    cout << "Nota: " << nota << endl;
}

/* ----------------------------------------------- */
int main() {
    
    Alumno alumno1("Pablo", 20, "0015", 5);

    /*  
        Muestro alumnos, que lleva implicito que tambien uso mostrarPersona().
        Entonces veo toda la informacion: Nombre, edad, codigo, nota.
        Nombre y edad es de la clase Personas.
        Codigo y nota es de la clase Alumno.
    */
   
    alumno1.mostrarAlumno();
    return 0;
}