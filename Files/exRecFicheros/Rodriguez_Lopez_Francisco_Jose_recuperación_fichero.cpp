/* Examende recuperacion de ficheros - 24 Febr 2023 */
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <locale>
#include <wchar.h>
using namespace std;

/* ------------------------------ */
/* Variables en el ambito global */
struct info {
	string numero_atomico;
	string nombre;
	string simbolo;
	string grupo;
	string masa_atomica;
};
info campo;

/* Inicializo con false porque en principio parto del hecho de que no existen fallos */
bool archivoFail = false;

/* Defino estas variables en global usadas por la funcion buscar, porque seran usadas por mas funciones */
bool numEncontrado;
string numBuscado;

/* ------------------------------------- */
/* Funciones de control (declaraciones) */
int comprobarMenu(int num);

/* -------------------------------------- */
/* Funciones principales (declaraciones) */
void consultar(void);
string buscar(void);
void agregar(string numAgregar);
void modificar(string numModificar);
void eliminar(string numEliminar);

/* -------------------------------------- */
/* Funcion main */
int main () {
	setlocale(LC_ALL, "");
	int opc;
	bool repetir = true;
	do {
		system("cls");
		cout << "|-----------------------|" << endl;
		cout << "|---  MENU PRINCIPAL ---|" << endl;
		cout << "|-----------------------|" << endl;
		cout << "|---  1. Consultar  ----|" << endl;
		cout << "|---  2. Buscar     ----|" << endl;
		cout << "|---  3. Agregar    ----|" << endl;
		cout << "|---  4. Modificar  ----|" << endl;
		cout << "|---  5. Eliminar   ----|" << endl;
		cout << "|---  6. Salir      ----|" << endl;
		cout << "|-----------------------|" << endl;
		cout << "Eliga una opcion del menu: ";
		cin >> opc;
		/* Control de la opcion del menu */
		while (opc != 1 && opc != 2 && opc != 3 && opc != 4 && opc != 5 && opc != 6) {
			cout << "\nOpcion incorrecta.\n";
			cout << "Eliga una opcion del menu: ";
			cin >> opc;
		}
		cout << endl << endl;
		
		switch(opc) {
			case 1:
				cout << "Consulta de todos los elementos\n";
				cout << "-------------------------------\n";
				consultar();
				break;
			case 2:
				cout << "Busqueda de un elemento\n";
				cout << "-----------------------\n";
				buscar();
				/* Aunque la funcion buscar tenga un retorno, no lo uso en el caso de una busqueda simple */
				break;
			case 3:
				cout << "Agregar un elemento\n";
				cout << "-------------------\n";
				agregar(buscar());
				break;
			case 4:
				cout << "Modificar un elemento\n";
				cout << "---------------------\n";
				modificar(buscar());
				break;
			case 5:
				cout << "Eliminar un elemento\n";
				cout << "--------------------\n";
				eliminar(buscar());
				break;
			case 6:
				cout << "Fin del programa\n";
				repetir = false;
			default:
				break;
		}
	system("pause");
	}while(repetir);
	
	return 0;
}

/* -------------------------------------- */
/* Definicion de funciones */

/* funcion consulta, sin parametros de entrada ni retorno. Muestra el contenido del archivo "elementos.txt" */
void consultar(void) {
	ifstream archivo;
	archivo.open("elementos.txt", ios::in);
	
	if(archivo.fail()) {
		cout << "\nEl archivo ha fallado\n";
		archivoFail = true;
	}
	
	if (!archivoFail)
	{
		while(!archivo.eof()) {
			archivo >> campo.numero_atomico >> campo.nombre >> campo.simbolo >> campo.grupo >> campo.masa_atomica;
			cout << campo.numero_atomico << " " << campo.nombre << " " << campo.simbolo << " " << campo.grupo << " " << campo.masa_atomica << endl;
		}
	}
	archivo.close();
}

/* Funcion buscar. Clave en el desarrollo del programa. 
Las funciones Agregar, modificar y eliminar la usarán para su funcionamiento */
string buscar(void) {
	/* Reinicio siempre al principio de la funcion buscar la vble numEncontrado como false porque se asumira que antes de la busqueda no se encontro */
	numEncontrado = false;
	ifstream archivo;
	archivo.open("elementos.txt", ios::in);
	
	if(archivo.fail()) {
		cout << "\nEl archivo ha fallado\n";
		archivoFail = true;
	}
	
	if (!archivoFail)
	{
		cout << "Introduce numero atomico: ";
		/* Recuerdo que numbuscado es una vble de tipo string declarada en el ambito global */
		cin >> numBuscado;
		
		while(!archivo.eof()) {
			archivo >> campo.numero_atomico >> campo.nombre >> campo.simbolo >> campo.grupo >> campo.masa_atomica;
			if (numBuscado == campo.numero_atomico) {
				numEncontrado = true;
				cout << "\nNumero atomico " << numBuscado << " encontrado\n";
				/* Muestro la informacion de dicho numero atomico por pantalla */
				cout << campo.numero_atomico << " " << campo.nombre << " " << campo.simbolo << " " << campo.grupo << " " << campo.masa_atomica << endl;
				/* Una vez se encontro el numero atomico dentro del archivo, dejo de buscar mas y sigo con la tarea */
				archivo.close();
				return numBuscado;
			}
		}
		/* Si se llego a este punto de la funcion buscar, significa que el numero atomico no ha sido encontrado */
		cout << "\nNumero atomico " << numBuscado << " NO encontrado\n";
	}
	archivo.close();
	return numBuscado;
}

/* Funcion agregar. El parametro numAgregar sera facilitado por el return de la funcion buscar. 
No devolvera nada.
Se comprobara que para agregar un numero atomico nuevo, este no debe existir.
En caso de ser posible agregar el numero atomico, sera agregado al archivo 
"elementos.txt" al final del mismo. */
void agregar(string numAgregar) {
	fstream archivo;
	archivo.open("elementos.txt", ios::app);
	
	if(archivo.fail()) {
		cout << "\nEl archivo ha fallado\n";
		archivoFail = true;
	}
	
	if (!archivoFail)
	{
		if (numEncontrado) {
			cout << "\nEl numero atomico ya existe en el fichero. Eliga un numero atomico no registrado.\n";
		} else {
			archivo << endl << numBuscado << " ";
			cout << "Agrege nombre: ";
			cin >> campo.nombre;
			archivo << campo.nombre << " ";
			
			cout << "Agrege simbolo: ";
			cin >> campo.simbolo;
			archivo << campo.simbolo << " ";
			
			cout << "Agrege grupo: ";
			cin >> campo.grupo;
			archivo << campo.grupo << " ";
			
			cout << "Agrege masa atomica: ";
			cin >> campo.masa_atomica;
			archivo << campo.masa_atomica;
		}
	}
	archivo.close();
}

/* Funcion modificar. El parametro numModificar sera facilitado por el return de la funcion buscar. 
No devolvera nada.
Se comprobara que para modificar un numero atomico nuevo, este debe existir.
En caso de existir el numero atomico, sera posible modificarlo. 
Se hara uso de un fichero temporal (temporal.txt) */
void modificar(string numAgregar) {
	/* uso de bool para control de la primera linea. Una vez se lea, pasara al valor false. */
	bool primeraLinea = true;
	bool repetirSubOpc = true;
	int subOpc;
	ifstream archivo;
	ofstream archivoTemporal;
	archivo.open("elementos.txt", ios::in);
	archivoTemporal.open("temporal.txt", ios::out);
	
	if(archivo.fail()) {
		cout << "\nEl archivo ha fallado\n";
		archivoFail = true;
	}
	
	if (!archivoFail)
	{
		if (!numEncontrado) {
			cout << "\nEl numero atomico NO existe en el fichero. Eliga un numero atomico registrado para poder modificarlo.\n";
			archivo.close();
			archivoTemporal.close();
			remove("temporal.txt");
			return;
		} else {
			while(!archivo.eof()) {
				archivo >> campo.numero_atomico >> campo.nombre >> campo.simbolo >> campo.grupo >> campo.masa_atomica;
				
				if(numBuscado == campo.numero_atomico) {
					do {
						system("cls");
						cout << "Informacion de modificacion\n";
						cout << numBuscado << " " << campo.nombre << " " << campo.simbolo << " " << campo.grupo << " " << campo.masa_atomica << endl;
						cout << "|-----------------------|" << endl;
						cout << "|---  MENU MODIFICAR ---|" << endl;
						cout << "|-----------------------|" << endl;
						cout << "|---  1. Nombre     ----|" << endl;
						cout << "|---  2. Simbolo    ----|" << endl;
						cout << "|---  3. Grupo      ----|" << endl;
						cout << "|---  4. Masa atomica  -|" << endl;
						cout << "|---  5. Salir      ----|" << endl;
						cout << "|-----------------------|" << endl;
						cout << "Eliga una opcion del menu: ";
						cin >> subOpc;
						/* Control de la opcion del menu */
						while (subOpc != 1 && subOpc != 2 && subOpc != 3 && subOpc != 4 && subOpc != 5) {
							cout << "\nOpcion incorrecta.\n";
							cout << "Eliga una opcion del menu: ";
							cin >> subOpc;
						}
						cout << endl << endl;
						
						switch(subOpc) {
						case 1:
							cout << "Modifique nombre: ";
							cin >> campo.nombre;
							break;
						case 2:
							cout << "Modifique simbolo: ";
							cin >> campo.simbolo;
							break;
						case 3:
							cout << "Modifique grupo: ";
							cin >> campo.grupo;
							break;
						case 4:
							cout << "Modifique masa atomica: ";
							cin >> campo.masa_atomica;
							break;
						case 5:
							repetirSubOpc = false;
							break;
						default:
							break;
						}				
					}while(repetirSubOpc);	
				}
				/* Ingreso en temporal.txt la informacion */
				if (!primeraLinea) {
					archivoTemporal << endl;
					}
				/* Una vez llegados a este punto, se habra leido la primera linea del fichero */
				archivoTemporal << campo.numero_atomico << " " << campo.nombre << " " << campo.simbolo << " " << campo.grupo << " " << campo.masa_atomica;
				primeraLinea = false;
				}
			}
			archivo.close();
			archivoTemporal.close();
			/* CLAVE PARA CONTROL DE FICHERO Y NO ELIMINACION POR ERROR */
			if(numEncontrado)
			{
				remove("elementos.txt");
			}
			rename("temporal.txt", "elementos.txt");	
	}
}

/* Funcion eliminar. El parametro numEliminar sera facilitado por el return de la funcion buscar. 
No devolvera nada.
Se comprobara que para eliminar un numero atomico nuevo, este debe existir.
Se hara uso de un fichero temporal (temporal.txt) */
void eliminar(string numAgregar) {
	/* uso de bool para control de la primera linea. Una vez se lea, pasara al valor false. */
	bool primeraLinea = true;
	bool repetirSubOpc = true;
	int subOpc;
	ifstream archivo;
	ofstream archivoTemporal;
	archivo.open("elementos.txt", ios::in);
	archivoTemporal.open("temporal.txt", ios::out);
	
	if(archivo.fail()) {
		cout << "\nEl archivo ha fallado\n";
		archivoFail = true;
	}
	
	if (!archivoFail)
	{
		if (!numEncontrado) {
			cout << "\nEl numero atomico NO existe en el fichero. Eliga un numero atomico registrado para poder eliminarlo.\n";
			archivo.close();
			archivoTemporal.close();
			remove("temporal.txt");
			return;
		} else {
			while(!archivo.eof()) {
				archivo >> campo.numero_atomico >> campo.nombre >> campo.simbolo >> campo.grupo >> campo.masa_atomica;
				
				if(numBuscado != campo.numero_atomico) {
					/* Ingreso en temporal.txt la informacion */
					if (!primeraLinea) {
						archivoTemporal << endl;
						}
					/* Una vez llegados a este punto, se habra leido la primera linea del fichero */
					archivoTemporal << campo.numero_atomico << " " << campo.nombre << " " << campo.simbolo << " " << campo.grupo << " " << campo.masa_atomica;
					primeraLinea = false;
				}
			}
		}
		archivo.close();
		archivoTemporal.close();
		/* CLAVE PARA CONTROL DE FICHERO Y NO ELIMINACION POR ERROR */
		if(numEncontrado)
		{
			remove("elementos.txt");
		}
		rename("temporal.txt", "elementos.txt");
	}
}
