#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

/* Constante que indica el numero de objetos asesores. Recomendable N = 2 para pruebas y N = 12 para version final */
const int N = 12;

/* Informacion inventada agregada para facilitar el uso del programa.
	Generado por el Alumno Fco. Jose Rodriguez Lopez. */
struct Registro {
    int numNif;
    char letraNif;
    string nombre;
    char genero;
    int edad;
    string actividad;
    string consulta;
    int valor;
    int sesiones;
    int total;
};

Registro registros[12] = {
    {23456789, 'Z', "Ana Pérez", 'F', 32, "Yoga", "Masaje relajante", 50, 2, 100},
    {34567890, 'X', "Juan García", 'M', 45, "Entrenamiento", "Asesoramiento", 80, 3, 240},
    {45678901, 'Y', "Laura Martínez", 'F', 28, "Pilates", "Fisioterapia", 60, 5, 300},
    {56789012, 'Z', "Pablo Rodríguez", 'M', 50, "Running", "Nutricionista", 70, 4, 280},
    {67890123, 'X', "Marta Sánchez", 'F', 39, "Spinning", "Entrenamiento", 60, 8, 480},
    {78901234, 'Y', "David López", 'M', 25, "Natación", "Masaje deportivo", 70, 2, 140},
    {89012345, 'Z', "Raquel Jiménez", 'F', 42, "Entrenamiento", "Asesoramiento", 80, 6, 480},
    {90123456, 'X', "Carlos García", 'M', 31, "Crossfit", "Fisioterapia", 70, 4, 280},
    {12345678, 'A', "Lucía Pérez", 'F', 29, "Boxeo", "Nutricionista", 90, 3, 270},
    {12345678, 'B', "Manuel Ruiz", 'M', 36, "Entrenamiento", "Asesoramiento", 80, 10, 800},
    {23456789, 'C', "Ana Gómez", 'F', 40, "Zumba", "Entrenamiento", 60, 6, 360},
    {34567890, 'D', "Jorge López", 'M', 27, "Pilates", "Masaje deportivo", 50, 5, 250}
};
/* ---------------------------------------------------------------------------------------------- */

class AsesoriaFinanciera {
    private:
        int dniNum;
        char dniLetra;
        string nombre;
        char genero;
        int edad;
        string actividad;
        string consulta;
        float valor;
        int sesiones;
        float total;
    public:
        AsesoriaFinanciera();
        ~AsesoriaFinanciera();
        void setAsesoriaFinanciera(int, char, string, char, int, string, string, float, int);
        void getMostrarAsesoriaFinanciera();
        void getLineFromTxt(int);
};

AsesoriaFinanciera::AsesoriaFinanciera() {}
AsesoriaFinanciera::~AsesoriaFinanciera() {}
void AsesoriaFinanciera::setAsesoriaFinanciera(int _dniNum, char _dniLetra, string _nombre, char _genero, int _edad, string _actividad, string _consulta, float _valor, int _sesiones) {
    dniNum = _dniNum;
    dniLetra = _dniLetra;
    nombre = _nombre;
    genero = _genero;
    edad = _edad;
    actividad = _actividad;
    consulta = _consulta;
    valor = _valor;
    sesiones = _sesiones;
    total = _sesiones * _valor;
}

void AsesoriaFinanciera::getMostrarAsesoriaFinanciera() {
    cout << dniNum << "\t " << dniLetra << "\t " << nombre << "\t " << genero << "\t " << edad << "\t " << actividad << "\t " << consulta << "\t " << valor << "\t " << sesiones << "\t " << total;
}

void AsesoriaFinanciera::getLineFromTxt(int numReg) {
    fstream archivo;
    archivo.open("DatosAsesoria.txt", ios::app);
    if (archivo.fail()) {
    	cout << "\nHa sucedido algun problema con el archivo\n";
    	archivo.close();
    	return;
    } else {
    	archivo << registros[numReg].numNif << " " << registros[numReg].letraNif << " " << registros[numReg].nombre << " " << registros[numReg].genero << " " << registros[numReg].edad << " " << registros[numReg].actividad << " " << registros[numReg].consulta << " " << registros[numReg].valor << " " << registros[numReg].sesiones  << " " << registros[numReg].valor * registros[numReg].sesiones;
    	if (!archivo.eof()) {
    		archivo << endl;
		}
	}
	archivo.close();
    return;
}

int main() {
	AsesoriaFinanciera asesor[N];
	
	/* SETEO el objeto asesor */
	for (int i = 0; i < N; i++) {
		asesor[i].setAsesoriaFinanciera(registros[i].numNif, registros[i].letraNif, registros[i].nombre, registros[i].genero, registros[i].edad, registros[i].actividad, registros[i].consulta, registros[i].valor, registros[i].sesiones);
	}
	
	/* Muestro en consola el objeto asesor */
	for (int i = 0; i < N; i++) {
		asesor[i].getMostrarAsesoriaFinanciera();
		cout << endl;
	}
	
	/* Creo el archivo "DatosAsesoria.txt" con la informacion que contiene el objeto asesor linea a linea */
	for (int i = 0; i < N; i++) {
		asesor[i].	getLineFromTxt(i);
	}
	
	return 0;
}
