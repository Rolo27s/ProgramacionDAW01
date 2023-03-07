/* 
METODOLOGÍA:
	
	Ejemplo de info de entrada: 
    {23456789, 'Z', "Ana.Pérez", 'F', 32, "Yoga", "Contable", 2}
    dniNum, dniLetra, nombre, genero, edad, actividad, consulta, sesiones.
    Valor y total son atributos derivados de consulta, valor y sesiones.
	
	Reglas para info de entrada:
	- Genero tendrá valor M o F
	- Consulta tendrá valor Contable, Finanzas, Inversion u Otra
	- Segun la consulta seleccionada, esta tendra un valor definido. Los diferentes valores son:
		- Contable: 50000
		- Finanzas: 65000
		- Inversion: 60000
		- Otra: 55000
	
	Los controles a tener en cuenta estarán controlados por la funcion main y serán:
	DNI no repetido (funcionará similar a una PRIMARY KEY)
	Control de letra de DNI por formula:
		dniNum <= 99999999
		dniNum % 23. Esta cuenta dará un numero entre el 0 y el 22. Coincidirá con la posicion del siguiente array:
		dniLetra[23] = {'T', 'R', 'W', 'A', 'G', 'M', 'Y', 'F',	'P', 'D', 'X', 'B',	'N', 'J', 'Z', 'S',	'Q', 'V', 'H', 'L',	'C', 'K', 'E'};
		Genero: 'M', 'm', 'F' o 'f'. Pasarlo a uppercase.
		Consulta: "Contable", "contable", "Finanzas", "finanzas", "Inversion", "inversion", "Otra", "otra". Pasar el formato a la primera letra siempre en mayus.
		Sesiones y edad: Que sea mayor a cero.
		
La información introducida quedará reflejada en el archivo txt, llamado "DatosAsesoria.txt"
*/
/* ---------------------------------------------------------------------------------------------- */
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <fstream>
#include <locale.h>
#include <wchar.h>
using namespace std;

/* Constante que indica el numero de objetos asesores. Recomendable N = 2 o N = 1 para pruebas en version alpha, y N = 12 para pruebas en version beta */
const int N = 2;

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
        int getDNI();
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

/* Muestra por pantalla la informacion del asesor */
void AsesoriaFinanciera::getMostrarAsesoriaFinanciera() {
    cout << dniNum << "-" << dniLetra << "\t " << nombre << "\t " << genero << "\t " << edad << "\t " << actividad << "\t " << consulta << "\t " << valor << "\t " << sesiones << "\t " << total;
}

/* Método que se encarga de generar el archivo DatosAsesoria.txt */
void AsesoriaFinanciera::getLineFromTxt(int numReg) {
   fstream archivo;
    archivo.open("DatosAsesoria.txt", ios::app);
    if (archivo.fail()) {
    	cout << "\nHa sucedido algun problema con el archivo\n";
    	archivo.close();
    	return;
    } else {
    	/* Revisar condicion de salto de linea, porque al principio del fichero me pone un salto que no sirve */
    		archivo << endl;	
	
    	archivo << dniNum << " " << dniLetra << " " << nombre << " " << genero << " " << edad << " " << actividad << " " << consulta << " " << valor << " " << sesiones << " " << total;
	}
	archivo.close();
    return;
}

/* Con este método comprobaremos que el DNI no este repetido */
int AsesoriaFinanciera::getDNI() {
	return dniNum;
}


int main() {
	setlocale(LC_ALL, "");
	AsesoriaFinanciera asesor[N];
	int opcionConsulta;
	
	/* DECLARACION, INICIALIZACIÓN DE CONTROLES DE ENTRADA */
	char dniLetraM[23] = {'T', 'R', 'W', 'A', 'G', 'M', 'Y', 'F', 'P', 'D', 'X', 'B', 'N', 'J', 'Z', 'S', 'Q', 'V', 'H', 'L', 'C', 'K', 'E'};
	char dniLetram[23] = {'t', 'r', 'w', 'a', 'g', 'm', 'y', 'f', 'p', 'd', 'x', 'b', 'n', 'j', 'z', 's', 'q', 'v', 'h', 'l', 'c', 'k', 'e'};
	
	/* Hago uso de struct asesorTemp para control de parámetros de entrada */
	struct {
		int dniNum;
        char dniLetra;
        string nombre;
        char genero;
        int edad;
        string actividad;
        string consulta;
        int valor;
        int sesiones;
	} asesorTemp;
	/* ---------------------------------------------------------------------------------------------- */

	/* SETEO el objeto asesor con el metodo de la clase AsesoriaFinanciera */
	for (int i = 0; i < N; i++) {
		cout << "Asesor (" << i+1 << "/" << N << ")" << endl;
		
		cout << "Introduce DNI (solo el numero): ";
		cin >> asesorTemp.dniNum;
		/* En este control existe un posible desbordamiento del int si se intenta añadir un numero muy grande.
		La solucion sería cambiar el tipo de variable a long long o int64_t, o controlar el error de otra manera */
		while (asesorTemp.dniNum < 1 || asesorTemp.dniNum > 99999999) {
			cout << endl << "DNI erroneo. Introduce DNI: ";
			cin >> asesorTemp.dniNum;
		}
		for (int j = 0; j < i; j++) {
			while (asesor[j].getDNI() == asesorTemp.dniNum) {
				cout << endl << "Error. DNI ya registrado. Ingrese otro DNI: ";
				cin >> asesorTemp.dniNum;
				while (asesorTemp.dniNum < 1 || asesorTemp.dniNum > 99999999) {
					cout << endl << "DNI erroneo. Introduce DNI: ";
					cin >> asesorTemp.dniNum;
				}
			}
		}
		
		cout << "Letra del DNI: ";
		cin >> asesorTemp.dniLetra;
		while (asesorTemp.dniLetra != dniLetraM[asesorTemp.dniNum % 23] && asesorTemp.dniLetra != dniLetram[asesorTemp.dniNum % 23]) {
			cout << endl << "Letra del DNI erronea. Introduce letra del DNI: ";
			cin >> asesorTemp.dniLetra;
		}
		
		cout << "(El nombre no puede contener espacios. En caso de nombre compuesto usar . )" << endl;
		cout << "Nombre: ";
		cin >> asesorTemp.nombre;
		
		cout << "Genero (M/F): ";
		cin >> asesorTemp.genero;
		while (asesorTemp.genero != 'M' && asesorTemp.genero != 'm' && asesorTemp.genero != 'F' && asesorTemp.genero != 'f') {
			cout << "Genero erroneo. Introduce genero (M/F): ";
			cin >> asesorTemp.genero;
		}
		
		cout << "Edad: ";
		cin >> asesorTemp.edad;
		while (asesorTemp.edad <= 0) {
			cout << "Edad erronea. Introduce edad: ";
			cin >> asesorTemp.edad;
		}
		
		cout << "(La actividad no puede contener espacios. En caso de necesitar espacios, usar . )" << endl;
		cout << "Actividad: ";
		cin >> asesorTemp.actividad;
		
		cout << "Consulta" << endl;
		cout << "\t1.Contable" << endl;
		cout << "\t2.Finanzas" << endl;
		cout << "\t3.Inversion" << endl;
		cout << "\t4.Otra" << endl;
		cout << "Selecciona una opcion: ";
		cin >> opcionConsulta;
		
		while (opcionConsulta < 1 || opcionConsulta > 4) {
			cout << "Consulta erronea. Introduce una opcion (1, 2, 3 o 4)" << endl;
			cout << "\t1.Contable" << endl;
			cout << "\t2.Finanzas" << endl;
			cout << "\t3.Inversion" << endl;
			cout << "\t4.Otra" << endl;
			cout << "Selecciona una opcion: ";
			cin >> opcionConsulta;
		}
		
		/* Agrego el valor adecuado en funcion de la consulta elegida */
		switch (opcionConsulta) {
			case 1:
				asesorTemp.consulta = "Contable";
				asesorTemp.valor = 50000;
				break;
			case 2:
				asesorTemp.consulta = "Finanzas";
				asesorTemp.valor = 65000;
				break;
			case 3:
				asesorTemp.consulta = "Inversion";
				asesorTemp.valor = 60000;
				break;
			case 4:
				asesorTemp.consulta = "Otra";
				asesorTemp.valor = 55000;
				break;
			default:
				break;
		}
		
		cout << "Sesiones: ";
		cin >> asesorTemp.sesiones;
		while (asesorTemp.sesiones <= 0) {
			cout << "Numero de sesiones erronea. Introducir sesiones: ";
			cin >> asesorTemp.sesiones;
		}
		cout << endl;
		
		/* En este punto tenemos toda la informacion necesaria en la estructura.
		Usamos el metodo setAsesoriaFinanciera de la clase AsesoriaFinanciera para añadir la informacion filtrada al objeto asesor */
		asesor[i].setAsesoriaFinanciera(asesorTemp.dniNum, asesorTemp.dniLetra, asesorTemp.nombre, asesorTemp.genero, asesorTemp.edad, asesorTemp.actividad, asesorTemp.consulta, asesorTemp.valor, asesorTemp.sesiones);
		system("cls");
	}
	
	/* Muestro en consola el objeto asesor */
	for (int i = 0; i < N; i++) {
		asesor[i].getMostrarAsesoriaFinanciera();
		cout << endl;
	}
	
	/* Creo el archivo "DatosAsesoria.txt" con la informacion que contiene el objeto asesor linea a linea */
	for (int i = 0; i < N; i++) {
		asesor[i].getLineFromTxt(i);
	}
	
	return 0;
}
