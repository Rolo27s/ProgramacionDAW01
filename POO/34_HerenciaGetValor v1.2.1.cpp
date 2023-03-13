/* 
Enunciado ejercicio 34
Elaborar un programa que aplique el concepto de herencia para obtener el valor de venta de acuerdo con
el medio de pago (efectivo o tarjeta de crédito) en un almacén de grandes superficies. 

La clase padre venta tiene como atributos: 
DNI, 
nombre, 
móvil, 
ciudad, 
edad y 
actividad. 

Los atributos de la clase hija efectivo son 
total venta, 
descuento (5% del total sí este es menor de 1.000.000, de lo contrario se aplica
el 10% del total) y 
valor a pagar, 

y para la clase hija tarjeta de crédito son 
venta y 
número de cuotas.

------------------------------------------------------------
INFO adicional:
- Veo en el ejemplo que el main esta dentro de un do-while con la pregunta:
	Desea procesar otra venta S o N: 
	
- La clase padre "venta" siempre se vera por pantalla y segun sea la modalidad de venta (efectivo/tarjeta),
se verá una información u otra.
*/

#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
using namespace std;

/* Clase padre venta*/
class Venta {
	private:
		string DNI;
		string nombre;
		string movil;
		string ciudad;
		int edad;
		string actividad;
	public:
		Venta();
		~Venta();
		void setVenta(string, string, string, string, int, string);
		void getMostrarVenta();
};

Venta::Venta() {
}

Venta::~Venta() {
}

void Venta::setVenta(string _DNI, string _nombre, string _movil, string _ciudad, int _edad, string _actividad) {
	DNI = _DNI;
	nombre = _nombre;
	movil = _movil;
	ciudad = _ciudad;
	edad = _edad;
	actividad = _actividad;
}

void Venta::getMostrarVenta() {
	cout << "\n\tDATOS BÁSICOS DE VENTA\t";
	cout << "\n---------------------------------------------------\n";
	cout << "DNI: " << DNI << "\t\t";
	cout << "Nombre: " << nombre << endl;
	cout << "Movil: " << movil << "\t\t";
	cout << "Ciudad: " << ciudad << endl;
	cout << "Edad: " << edad << "\t\t";
	cout << "Actividad: " << actividad << endl;
}

/* clase hija efectivo que hereda de venta */
class Efectivo:public Venta {
	private:
		float totalVenta;
		float descuento;
		float totalAPagar;
	public:
		Efectivo();
		~Efectivo();
		void setEfectivo(float);
		void getMostrarVentaEfectivo();
};

Efectivo::Efectivo() {
}

Efectivo::~Efectivo() {
}

void Efectivo::setEfectivo(float _totalVenta) {
	totalVenta = _totalVenta;
	if (_totalVenta < 1000000) {
		descuento = _totalVenta * 0.05;
		totalAPagar = _totalVenta * 0.95;
	} else {
		descuento = _totalVenta * 0.1;
		totalAPagar = _totalVenta * 0.9;
	}
}

void Efectivo::getMostrarVentaEfectivo() {
	getMostrarVenta();
	cout << "Modalidad de venta: Efectivo" << endl;
	cout << "---------------------------------------------------\n";
	cout << endl;
	cout << "\n\tREPORTE DE LA MODALIDAD DE VENTA EFECTIVO\t";
	cout << "\n---------------------------------------------------\n";
	cout << "Total venta: " << totalVenta << "\t\t";
	cout << "Descuento: " << descuento << endl;
	cout << "Valor a pagar: " << totalAPagar << endl;
	cout << "---------------------------------------------------\n";
}

/* clase hija tarjeta que hereda de venta */
class Tarjeta:public Venta {
	private:
		float totalVenta;
		int numeroDeCuotas;
	public:
		Tarjeta();
		~Tarjeta();
		void setTarjeta(float, int);
		void getMostrarVentaTarjeta();
};

Tarjeta::Tarjeta() {
}

Tarjeta::~Tarjeta() {
}

void Tarjeta::setTarjeta(float _totalVenta, int _numeroDeCuotas) {
	totalVenta = _totalVenta;
	numeroDeCuotas = _numeroDeCuotas;
}

void Tarjeta::getMostrarVentaTarjeta() {
	getMostrarVenta();
	cout << "Modalidad de venta: Tarjeta" << endl;
	cout << "---------------------------------------------------\n";
	cout << endl;
	cout << "\n\tREPORTE DE LA MODALIDAD DE VENTA TARJETA\t";
	cout << "\n---------------------------------------------------\n";
	cout << "Valor de venta: " << totalVenta << "\t\t";
	cout << "Número de cuotas: " << numeroDeCuotas << endl;
	cout << "---------------------------------------------------\n";
}

/* FUNCION MAIN */
int main() {
	setlocale(LC_ALL, "");
	
	/* Estructura creada con la intencion de controlar la informacion de entrada */
	struct {
		string dniControl;
		string nombreControl;
		string movilControl;
		string ciudadControl;
		int edadControl;
		bool edadControlMayorDeEdad;
		string actividadControl;
	} controlVenta;
	
	int opcPago;
	string modVenta;
	char otra;
	Venta venta1;
	Efectivo efectivo1;
	Tarjeta tarjeta1;
	
	cout << "Hola, soy un programa de ventas." << endl;
	cout << "Vamos a introducir algunos datos básicos del cliente." << endl;
	do {
		/* Introduce DNI */
		cout << "DNI (Formato ej: 12345678A): "; 
		cin >> controlVenta.dniControl;
		while (controlVenta.dniControl.length() != 9) {
			cout << endl << "Error. Vamos a tratar de introducir nuevamente la información." << endl;
			cout << "DNI (Formato ej: 12345678A): "; 
			cin >> controlVenta.dniControl;
		}
		
		/* Introduce Nombre */
		cout << endl << "Introduciremos el nombre. Para el nombre no usar espacios." << endl;
		cout << "En caso de necesidad usar el caracter . " << endl;
		cout << "Nombre: ";
		cin >> controlVenta.nombreControl;
		while (controlVenta.nombreControl.length() > 18) {
			cout << endl << "Error. El nombre introducido es demasiado largo." << endl;
			cout << "Trate de reducir el tamaño del nombre, obvie su segundo nombre o ponga un nombre temporal mas corto" << endl;
			cout << "Nombre: ";
			cin >> controlVenta.nombreControl;
		}
		
		/* Introduce movil */
		cout << "Movil (Formato ej: 610343536): ";
		cin >> controlVenta.movilControl;
		while (controlVenta.movilControl.length() != 9) {
			cout << endl << "Error. Vamos a tratar de introducir nuevamente la información." << endl;
			cout << "Movil (Formato ej: 610343536): ";
			cin >> controlVenta.movilControl;
		}
		
		/* Introduce ciudad */
		cout << "Ciudad: ";
		cin  >> controlVenta.ciudadControl;
		/* Espacio para introducir control concreto de ciudad */
		
		/* Introduce edad */
		cout << "Edad: ";
		cin >> controlVenta.edadControl;
		while (controlVenta.edadControl <= 0) {
			cout << endl << "Error. La edad debe tener un valor positivo mayor a 0." << endl;
			cout << "Edad: ";
			cin >> controlVenta.edadControl;
		}
		/* Control adicional de la edad para saber si es mayor de edad o no.
		En caso de no ser mayor de edad, no se le permitirá ejecutar la compra con tarjeta */
		
		if (controlVenta.edadControl >= 18 ) {
			cout << "Perfecto, eres mayor de edad." << endl;
			controlVenta.edadControlMayorDeEdad = true;
		} else {
			cout << "Perfecto, eres menor de edad." << endl;
			controlVenta.edadControlMayorDeEdad = false;
		}
		
		/* Introduce actividad */
		cout << "Actividad: ";
		cin >> controlVenta.actividadControl;
		/* Espacio para introducir control concreto de actividad */
		
		/* Inicio venta1 con su metodo set */
		venta1.setVenta(controlVenta.dniControl, controlVenta.nombreControl, controlVenta.movilControl, controlVenta.ciudadControl, controlVenta.edadControl, controlVenta.actividadControl);
		
		/* Pregunto si quiere hacer el pago en efectivo o con tarjeta */
		cout << endl << "Como desea hacer el pago" << endl;
		cout << "1. Efectivo" << endl;
		cout << "2. Tarjeta" << endl;
		cout << "Opcion: ";
		cin >> opcPago;
		while (opcPago != 1 && opcPago != 2) {
			cout << endl << "Error en la seleccion del pago." << endl;
			cout << "Ingrese 1 o 2 para elegir un tipo de pago correcto" << endl;
			cout << endl << "Como desea hacer el pago" << endl;
			cout << "1. Efectivo" << endl;
			cout << "2. Tarjeta" << endl;
			cout << "Opcion: ";
			cin >> opcPago;
		}
		
		if (opcPago == 2 && controlVenta.edadControlMayorDeEdad) {
			cout << endl << "Modalidad de venta: Tarjeta";
			modVenta = "Tarjeta";
			
		} else if (opcPago == 2 && !controlVenta.edadControlMayorDeEdad) {
			cout << "Ud. quiere hacer un pago con tarjeta, pero es menor de edad...\n";
			cout << "Nuestro control interno impide esta operación\n Se asignará por defecto el pago en efectivo";
			opcPago = 1;
			cout << endl << "Modalidad de venta: Efectivo";
			modVenta = "Efectivo";
			
		} else {
			cout << endl << "Modalidad de venta: Efectivo";
			modVenta = "Efectivo";
		}
		
		/* En caso de modalidad de venta en efectivo */
		if (opcPago == 1) {
			float controlEfectivo;
			
			cout << endl << "Total venta: ";
			cin >> controlEfectivo;
			while (controlEfectivo <= 0) {
				cout << "El total de la venta debe ser superior a 0" << endl;
				cout << endl << "Total venta: ";
				cin >> controlEfectivo;
			}
			
			efectivo1.setEfectivo(controlEfectivo);
		} 
		
		/* En caso de modalidad de venta en tarjeta */
		else {
			float controlTarjeta;
			int controlCuotas;
			
			cout << endl << "Valor de venta: ";
			cin >> controlTarjeta;
			while (controlTarjeta <= 0) {
				cout << "El total de la venta debe ser superior a 0" << endl;
				cout << endl << "Valor de venta: ";
				cin >> controlTarjeta;
			}
			
			cout << endl << "Numero de cuotas: ";
			cin >> controlCuotas;
			while (controlCuotas <= 0) {
				cout << "El numero de cuotas debe ser superior a 0" << endl;
				cout << endl << "Numero de cuotas: ";
				cin >> controlCuotas;
			}
			
			tarjeta1.setTarjeta(controlTarjeta, controlCuotas);		
		}
		
		/* Muestro la informacion por consola */
		system("cls");
		
		if (opcPago == 1) {
			efectivo1.getMostrarVentaEfectivo();
		} else {
			tarjeta1.getMostrarVentaTarjeta();
		}
		
		cout << "Desea procesar otra venta S o N: ";
		cin >> otra;
		while (otra != 'S' && otra != 's' && otra != 'N' && otra != 'n') {
			cout << "\nOpcion incorrecta. Eliga 'S', 's', 'N o 'n'" << endl;
			cout << "Desea procesar otra venta S o N: ";
			cin >> otra;
		}
		system("cls");
	}while(otra == 'S' || otra == 's');
	return 0;
}
