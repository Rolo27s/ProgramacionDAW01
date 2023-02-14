#include <iostream>
#include <stdlib.h>
using namespace std;

/* Clase vehiculo */
class Vehiculo {
    private:
        string propietario;
        string color;
        /* Distancia maxima en Km */
        int autonomia;
    public:
        Vehiculo(string, string, int);
        ~Vehiculo();
        void mostrarVehiculo();
};

Vehiculo::Vehiculo(string _propietario, string _color, int _autonomia) {
    propietario = _propietario;
    color = _color;
    autonomia = _autonomia;
}

Vehiculo::~Vehiculo() {}

void Vehiculo::mostrarVehiculo() {
    cout << "Vehiculo propiedad de " << propietario << endl;
    cout << "Color: " << color << endl;
    cout << "Autonomia: " << autonomia << " Km" << endl;
}

/* Clase VehiculoTerrestre, que hereda de Vehiculo */
class VehiculoTerrestre:public Vehiculo {
    private:
        string fechaITV;
    public:
        VehiculoTerrestre(string, string, int, string);
        ~VehiculoTerrestre();
        void mostrarVehiculoTerrestre();
};

VehiculoTerrestre::VehiculoTerrestre(string _propietario, string _color, int _autonomia, string _fechaITV):Vehiculo(_propietario, _color, _autonomia) {
    fechaITV = _fechaITV;
}

VehiculoTerrestre::~VehiculoTerrestre() {}

void VehiculoTerrestre::mostrarVehiculoTerrestre() {
    mostrarVehiculo();
    cout << "Fecha de proxima ITV: " << fechaITV << endl;
}

/* Clase Coche que hereda de VehiculoTerrestre */
class Coche:public VehiculoTerrestre {
    private:
        bool descapotable;
    public:
        Coche(string, string, int, string, bool);
        ~Coche();
        void mostrarCoche();
};

Coche::Coche(string _propietario, string _color, int _autonomia, string _fechaITV, bool _descapotable):VehiculoTerrestre(_propietario, _color, _autonomia, _fechaITV) {
    descapotable = _descapotable;
}

Coche::~Coche() {}

void Coche::mostrarCoche() {
    mostrarVehiculoTerrestre();
    cout << "El coche es descapotable? (0-False, 1-True): " << descapotable << endl;
}

/* Clase Camion que hereda de VehiculoTerrestre */
class Camion:public VehiculoTerrestre {
    private:
        int cargaMax;
    public:
        Camion(string, string, int, string, int);
        ~Camion();
        void mostrarCamion();
};

Camion::Camion(string _propietario, string _color, int _autonomia, string _fechaITV, int _cargaMax):VehiculoTerrestre(_propietario, _color, _autonomia, _fechaITV) {
    cargaMax = _cargaMax;
}

Camion::~Camion() {}

void Camion::mostrarCamion() {
    mostrarVehiculoTerrestre();
    cout << "Carga maxima: " << cargaMax << endl;
}

/* Clase VehiculoAereo, que hereda de Vehiculo */
class VehiculoAereo:public Vehiculo {
    private:
        /* Ejemplos de utilidad: Comercial, Carga, Militar... */
        string utilidad;
    public:
        VehiculoAereo(string, string, int, string);
        ~VehiculoAereo();
        void mostrarVehiculoAereo();
};

VehiculoAereo::VehiculoAereo(string _propietario, string _color, int _autonomia, string _utilidad):Vehiculo(_propietario, _color, _autonomia) {
    utilidad = _utilidad;
}

VehiculoAereo::~VehiculoAereo() {}

void VehiculoAereo::mostrarVehiculoAereo() {
    mostrarVehiculo();
    cout << "Utilidad: " << utilidad << endl;
}

/* Clase Helicoptero, que hereda de VehiculoAereo */
class Helicoptero:public VehiculoAereo {
    private:
        /* Velocidad en el eje vertical expresada en metros por segundo */
        float velocidadMaxZ;
    public:
        Helicoptero(string, string, int, string, float);
        ~Helicoptero();
        void mostrarHelicoptero();
};

Helicoptero::Helicoptero(string _propietario, string _color, int _autonomia, string _utilidad, float _velocidadMaxZ):VehiculoAereo(_propietario, _color, _autonomia, _utilidad) {
    velocidadMaxZ = _velocidadMaxZ;
}

Helicoptero::~Helicoptero() {};

void Helicoptero::mostrarHelicoptero() {
    mostrarVehiculoAereo();
    cout << "Velocidad maxima en vertical: " << velocidadMaxZ << endl;
}

/* Clase Avion, que hereda de VehiculoAereo */
class Avion:public VehiculoAereo {
    private:
        /* Velocidad en el eje Y expresada en metros por segundo */
        float velocidadMaxAlabeo;
    public:
        Avion(string, string, int, string, float);
        ~Avion();
        void mostrarAvion();
};

Avion::Avion(string _propietario, string _color, int _autonomia, string _utilidad, float _velocidadMaxAlabeo):VehiculoAereo(_propietario, _color, _autonomia, _utilidad) {
    velocidadMaxAlabeo = _velocidadMaxAlabeo;
}

Avion::~Avion() {}

void Avion::mostrarAvion() {
    mostrarVehiculoAereo();
    cout << "Velocidad maxima de alabeo: " << velocidadMaxAlabeo << endl;
}

/* --------------------------------------- */
int main() {  
    cout << "Programa que muestra una serie de objetos que heredan unos de otros.\n\n";
    cout << endl;
    /* La clase vehiculo requiere de 3 argumentos:
        string propietario
        string color
        int autonomia en Km
    */
    cout << "Clase Vehiculo:\n";
    Vehiculo vehiculo1("Antonio", "Verde", 420);
    vehiculo1.mostrarVehiculo();
    cout << endl;
    /* La clase vehiculoTerrestre requiere de 4 argumentos:
        string propietario
        string color
        int autonomia en Km
        string fechaITV
    */
    cout << "Clase Vehiculo Terrestre:\n";
    VehiculoTerrestre vehiculoTerrestre1("Ruben", "Rojo", 220, "2024");
    vehiculoTerrestre1.mostrarVehiculoTerrestre();
    cout << endl;
    /* La clase Coche requiere de 5 argumentos:
        string propietario
        string color
        int autonomia en Km
        string fechaITV
        bool descapotable (true or false)
    */
    cout << "Clase Coche:\n";
    Coche coche1("Juan", "Negro", 234, "2025", false);
    coche1.mostrarCoche();
    cout << endl;
    /* La clase vehiculoAereo requiere de 4 argumentos:
        string propietario
        string color
        int autonomia en Km
        string utilidad. (Ejemplos de utilidad: Comercial, Carga, Militar...)
    */
    cout << "Clase Vehiculo Aereo:\n";
    VehiculoAereo vehiculoAereo1("Adriana", "Blanco", 923, "Comercial");
    vehiculoAereo1.mostrarVehiculoAereo();
    cout << endl;
    /* La clase Helicoptero requiere de 5 argumentos:
        string propietario
        string color
        int autonomia en Km
        string utilidad. (Ejemplos de utilidad: Comercial, Carga, Militar...)
        float velocidadMaxZ
    */
    cout << "Clase Helicoptero:\n";
    Helicoptero helicoptero1("Ernesto", "Verde Militar", 770, "Carga", 22.4);
    helicoptero1.mostrarHelicoptero();
    cout << endl;
    /* La clase Avion requiere de 5 argumentos:
        string propietario
        string color
        int autonomia en Km
        string utilidad. (Ejemplos de utilidad: Comercial, Carga, Militar...)
        float velocidadMaxAlabeo
    */
    cout << "Clase Avion:\n";
    Avion avion1("Jimenez", "Blanco", 1420, "Comercial", 12.54);
    avion1.mostrarAvion();
    cout << endl;
    return 0;
}