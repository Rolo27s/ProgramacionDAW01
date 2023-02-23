/* ENUNCIADO - Ejercicio 27
Generar un programa que tenga un menú repetitivo:
    1. Agregar alumno.
    2. Buscar alumno.
    3. Modificar alumno.
    4. Eliminar alumno.
    5. Ver todos los alumnos.
    6. Salir.
Se podrá hacer cualquier opción del menú en el archivo alumno.txt. 
Los campos del archivo alumno son: 
    código, 
    nombres, 
    apellido1,
    apellido2, 
    asignatura, 
    nota_1, 
    nota_2, 
    nota_3, 
    nota_final. */
/* ----------------------------------------------------------------------------------------------------- */
/* LIBRERIAS */
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <wchar.h>
#include <locale>
#include <cstdio>
using namespace std;

/* | -------------------------- | */
/* | VARIABLES SCOPE GLOBAL     |*/
struct info {
    int codigo;
    string nombre;
    string apellido1;
    string apellido2;
    string asignatura;
    float nota_1;
    float nota_2;
    float nota_3;
    float nota_final;
};
info campo;


/* | ---------------------------------- | */
/* | PROCEDIMIENTOS (DECLARACION)       |*/
/* | --------------------------------- | */
char comprobarChar (char c);
int comprobarNum (int n, int min, int max);

const int notaMin = 0;
const int notaMax = 10;
/* | ---------------------------------- | */
/* | FUNCIONES (DECLARACION)            |*/
/* | --------------------------------- | */
void visualizar(void);
int buscar(void);
/* Vble scope global usada por la funcion buscar */
int buscaCod;
bool codEncontrado;
/* Los argumentos de estas ultimas 3 funciones será el return de la funcion buscar */
void agregar(int codeAgregar);
void modificar (int codeModificar);
void eliminar (int codeEliminar);

/* | ---------------------------------- | */
/* | FUNCION MAIN                       |*/
/* | --------------------------------- | */
int main()
{
    setlocale(LC_ALL, "");
    /* Mis variables en el main*/
    char repetir;
    int opc, retBuscar;
    /* ------------------- */
    do
    {
        system("cls");
        /* Inicio del programa     
            1. Agregar alumno.
            2. Buscar alumno.
            3. Modificar alumno.
            4. Eliminar alumno.
            5. Ver todos los alumnos.
            6. Salir.*/

        cout << "|-------------------------------|\n";
        cout << "|       MENU DEL PROGRAMA       |\n";
        cout << "|-------------------------------|\n";
        cout << "|  1. Agregar alumno            |\n";
        cout << "|  2. Buscar alumno             |\n";
        cout << "|  3. Modificar alumno          |\n";
        cout << "|  4. Eliminar alumno           |\n";
        cout << "|  5. Ver todos los alumnos     |\n";
        cout << "|  6. Salir                     |\n";
        cout << "|-------------------------------|\n";
        cout << "Elige la opcion del menu deseada: ";
        cin >> opc;
        opc = comprobarNum(opc, 1, 6);

        switch (opc)
        {
        case 1:
            cout << "1. Agregar alumno\n\n";
            agregar(buscar());
            
			if(codEncontrado == 1)
			{
				cout << "\nNo puedo agregar a un alumno si el codigo del alumno ya existe\n";
			}
			else
			{
				cout << "\nAlumno agregado\n";
			}
            break;

        case 2:
        {
            cout << "2. Buscar alumno\n\n";
			buscar();
            break;
        }

        case 3:
            cout << "3. Modificar alumno\n\n";
			modificar(buscar());
            break;

        case 4:
            cout << "4. Eliminar alumno\n\n";
			eliminar(buscar());
            break;

        case 5:
            cout << "5. Ver todos los alumnos\n\n";
			visualizar();
            break;

        case 6:
            cout << "\n\t6. Salir. Hasta otra!\n\n";

            return 0;
        
        default:
            /* Al tener controlado opc a [1,6] con comprobarNum(), nunca va a ser posible pasar otro argumento diferente */
            break;
        }

        cout << "\n\nDesea volver al Menu inicial del programa? (S/N) (En caso de elegir 'N' se cerrara el programa): ";
        cin >> repetir;
        repetir = comprobarChar(repetir);
    } while (repetir == 'S' || repetir == 's');

    cout << "Proceso terminado. Hasta otra!\n";
    return 0;
}
/* ------------------------------------- */


/* | ---------------------------------- | */
/* | PROCEDIMIENTOS (DEFINICION)        |*/
/* | --------------------------------- | */

/* Comprueba si el caracter introducido es 'S', 's', 'N', 'n' */
char comprobarChar (char c)
{
    while (c != 'S' && c != 's' && c != 'N' && c != 'n')
        {
            cout << "\n\tError...Debe introducir S o N: ";
            cin >> c;
        }
    return c;
}

/* Comprueba si un numero esta entre min y max (incluidos) */
int comprobarNum (int n, int min, int max)
{
    while (n < min || n > max)
    {
        cout << "\n\tError...Debe introducir un valor dentro del rango [" << min << ", " << max << "]: ";
        cin >> n;
    }
    return n;
}

/* | ---------------------------------- | */
/* | FUNCIONES (DEFINICION)             |*/
/* | --------------------------------- | */

/* funcion visualizar, encargada de visualizar el contenido del documento alumnos.txt. No tiene parametros ni retorno. */
void visualizar(void)
{
    ifstream archivo;
    archivo.open("alumnos.txt", ios::in);
    

    if (archivo.fail())
    {
        cout << "\nHa sucedido algun problema con el archivo\n";
        archivo.close();
        return;
    }
    else
    {
        while (!archivo.eof())
        {
            archivo >> campo.codigo >> campo.nombre >> campo.apellido1 >> campo.apellido2 >> campo.asignatura >> campo.nota_1 >> campo.nota_2 >> campo.nota_3 >> campo.nota_final;

            /* Muestro por pantalla el contenido al completo */
			cout << campo.codigo << " " << campo.nombre << " " << campo.apellido1 << " " << campo.apellido2 << " " << campo.asignatura << " " << campo.nota_1 << " " << campo.nota_2 << " " << campo.nota_3 << " " << campo.nota_final;
			
			if(!archivo.eof())
			{
				cout << endl;
			}	
        }
    }
    archivo.close();
}

/* funcion buscar, encargada de buscar el codigo del alumno. 
No tiene parametros y devuelve el int codigo buscado.
Tambien usaremos una variable bool global que sera importante porque indicara
si el codigo buscado se encontro o no se encontro. Dicha variable inicializara con valor 0 (no encontrado)
por defecto en la funcion, he ira evolucionando a 1, o no, segun los sucesos */
int buscar(void)
{
	/* Vble scope global. Es necesaria en ese ambito porque será usada por más funciones. Por defecto 0, no encontrado */
	codEncontrado = 0;
	/* ----------------- */
	
	ifstream archivo;
	archivo.open("alumnos.txt", ios::in);
	
	if(archivo.fail())
	{
		cout << "\nHa sucedido algun problema con el archivo\n";
		archivo.close();
		return 0;
	}
	else
	{
		cout << "\nIngresa codigo a buscar [1-9999]: ";
		/* buscaCod es una variable global. Es necesaria en ese ambito porque será usada por más funciones. */
		cin >> buscaCod;
		/* Controlo el codigo a buscar */
		buscaCod = comprobarNum (buscaCod, 1, 9999);
		while(!archivo.eof())
		{
			archivo >> campo.codigo >> campo.nombre >> campo.apellido1 >> campo.apellido2 >> campo.asignatura >> campo.nota_1 >> campo.nota_2 >> campo.nota_3 >> campo.nota_final;
			if(buscaCod == campo.codigo)
			{
				cout << "\nCodigo encontrado!\n";
				/* Muestro por pantalla el contenido del codigo que se buscaba */
				cout << campo.codigo << " " << campo.nombre << " " << campo.apellido1 << " " << campo.apellido2 << " " << campo.asignatura << " " << campo.nota_1 << " " << campo.nota_2 << " " << campo.nota_3 << " " << campo.nota_final << endl;
				system("pause");
				/* Actualizo la variable global a 1 que significa que se ha encontrado */
				codEncontrado = 1;
				/* Si encuentro el codigo, lo retorno y me salgo de la funcion antes de que se termine de leer el fichero */
				return buscaCod;
			}
		}
		/* Si llegue a esta parte de la funcion quiere decir que el codigo no se encontro, entonces codEncontrado seguira valiendo 0, no se encontro */
		cout << "\nCodigo no encontrado!\n";
		system("pause");
	}
	
	archivo.close();
	/* Retornare en este caso el codigo que se buscaba y no se encontro */
	return buscaCod;
}

/* funcion que agrega un registro. Se pasara como parametro el return de la funcion buscar, es decir, el codigo que se pretende agregar. */
void agregar(int codeAgregar)
{
	fstream archivo;
	archivo.open("alumnos.txt", ios::app);
	
	if(archivo.fail())
	{
		cout << "\nHa sucedido algun problema con el archivo\n";
		archivo.close();
		return;
	}
	else
	{
		if (codEncontrado == 0)
		{
			campo.codigo = codeAgregar;
			
			cout << "Dame el nombre del alumno a agregar: ";
			cin >> campo.nombre;
			
			cout << "Dame el apellido1 del alumno a agregar: ";
			cin >> campo.apellido1;
			
			cout << "Dame el apellido2 del alumno a agregar: ";
			cin >> campo.apellido2;
			
			cout << "Dame la asignatura del alumno a agregar: ";
			cin >> campo.asignatura;
			
			cout << "Dame la nota_1 del alumno a agregar: ";
			cin >> campo.nota_1;
			/* Control de entrada de nota de 0 a 10*/
			campo.nota_1 = comprobarNum(campo.nota_1, notaMin, notaMax);
			
			cout << "Dame la nota_2 del alumno a agregar: ";
			cin >> campo.nota_2;
			/* Control de entrada de nota de 0 a 10*/
			campo.nota_2 = comprobarNum(campo.nota_2, notaMin, notaMax);
			
			cout << "Dame la nota_3 del alumno a agregar: ";
			cin >> campo.nota_3;
			/* Control de entrada de nota de 0 a 10*/
			campo.nota_3 = comprobarNum(campo.nota_3, notaMin, notaMax);
			
			cout << "Dame la nota_final del alumno a agregar: ";
			cin >> campo.nota_final;
			/* Control de entrada de nota de 0 a 10*/
			campo.nota_final = comprobarNum(campo.nota_final, notaMin, notaMax);
			
			archivo << endl << campo.codigo << " " << campo.nombre << " " << campo.apellido1 << " " << campo.apellido2 << " " << campo.asignatura << " " << campo.nota_1 << " " << campo.nota_2 << " " << campo.nota_3 << " " << campo.nota_final;
		}
	}
	archivo.close();
}

/* funcion que modifica campos. Se pasara como parametro el return de la funcion buscar, es decir, el registro que se pretende modificar.
Se hará uso de un archivo temporal "temporal.txt" para las modificaciones */
void modificar (int codeModificar)
{
	ifstream archivo;
	ofstream archivoTemporal;
	int opc;
	char repetir;
	bool firstLine = 1;
	
	archivo.open("alumnos.txt", ios::in);
	archivoTemporal.open("temporal.txt", ios::out);
	
	if (archivo.fail() || archivoTemporal.fail())
	{
		cout << "\nHa sucedido algun problema con el archivo\n";
		archivo.close();
		archivoTemporal.close();
		remove("temporal.txt");
		return;
	}
	else
	{
		if (codEncontrado == 0)
		{
			cout << "\nNecesito un codigo de un alumno que exista para poder modificarlo\n";
			archivo.close();
			archivoTemporal.close();
			remove("temporal.txt");
			return;
		}
		else
		{
			while(!archivo.eof())
			{
				archivo >> campo.codigo >> campo.nombre >> campo.apellido1 >> campo.apellido2 >> campo.asignatura >> campo.nota_1 >> campo.nota_2 >> campo.nota_3 >> campo.nota_final;
				
				if(buscaCod == campo.codigo)
				{
					do{
					system("cls");	
					cout << "\n|-------------------------------|\n";
			        cout << "|       MENU DE MODIFICACION    |\n";
			        cout << "|-------------------------------|\n";
			        cout << "|  1. Modificar nombre          |\n";
			        cout << "|  2. Modificar apellido1       |\n";
			        cout << "|  3. Modificar apellido2       |\n";
			        cout << "|  4. Modificar asignatura      |\n";
			        cout << "|  5. Modificar nota_1          |\n";
			        cout << "|  6. Modificar nota_2          |\n";
			        cout << "|  7. Modificar nota_3          |\n";
			        cout << "|  8. Modificar nota_final      |\n";
			        cout << "|  9. Salir de modificar        |\n";
			        cout << "|-------------------------------|\n";
			        cout << "Elige la opcion del menu deseada: ";
			        cin >> opc;
			        opc = comprobarNum(opc, 1, 9);
					
					switch(opc)
					{
						case 1:
						cout << "Introduce campo nuevo: ";
						cin >> campo.nombre;
						break;
						
						case 2:
						cout << "Introduce campo nuevo: ";
						cin >> campo.apellido1;
						break;
						
						case 3:
						cout << "Introduce campo nuevo: ";
						cin >> campo.apellido2;
						break;
						
						case 4:
						cout << "Introduce campo nuevo: ";
						cin >> campo.asignatura;
						break;
						
						case 5:
						cout << "Introduce campo nuevo: ";
						cin >> campo.nota_1;
						campo.nota_1 = comprobarNum(campo.nota_1, notaMin, notaMax);
						break;
						
						case 6:
						cout << "Introduce campo nuevo: ";
						cin >> campo.nota_2;
						campo.nota_2 = comprobarNum(campo.nota_2, notaMin, notaMax);
						break;
						
						case 7:
						cout << "Introduce campo nuevo: ";
						cin >> campo.nota_3;
						campo.nota_3 = comprobarNum(campo.nota_3, notaMin, notaMax);
						break;
						
						case 8:
						cout << "Introduce campo nuevo: ";
						cin >> campo.nota_final;
						campo.nota_final = comprobarNum(campo.nota_final, notaMin, notaMax);
						break;
						
						case 9:
							/* Saliendo de modificar */
							repetir = 'N';
						break;
						
						default:
							/* Controlado por funcion comprobarNum */
							break;
					}
					if(opc != 9){
						cout << "\n\nDesea volver al menu modificar? (S/N): ";
				        cin >> repetir;
				        repetir = comprobarChar(repetir);
					}
					
					} while (repetir == 'S' || repetir == 's');
					/* Se termina de editar campos de momento. Actualizo el archivo temporal con la informacion nueva controlada */	
				}
				if (firstLine == 1)
					{
						firstLine = 0;
					}
				else
					{
						archivoTemporal << endl;
					}
					
				archivoTemporal << campo.codigo << " " << campo.nombre << " " << campo.apellido1 << " " << campo.apellido2 << " " << campo.asignatura << " " << campo.nota_1 << " " << campo.nota_2 << " " << campo.nota_3 << " " << campo.nota_final;	
			}
		}
	}
	archivo.close();
	archivoTemporal.close();
	remove("alumnos.txt");
	rename("temporal.txt", "alumnos.txt");
}

/* funcion que elimina el registro. Se pasara como parametro el return de la funcion buscar, es decir, el registro que se pretende eliminar.
Se hará uso de un archivo temporal "temporal.txt" */
void eliminar (int codeModificar)
{
	ifstream archivo;
	ofstream archivoTemporal;
	int opc;
	char repetir;
	bool firstLine = 1;
	
	archivo.open("alumnos.txt", ios::in);
	archivoTemporal.open("temporal.txt", ios::out);
	
	if (archivo.fail() || archivoTemporal.fail())
	{
		cout << "\nHa sucedido algun problema con el archivo\n";
		archivo.close();
		archivoTemporal.close();
		remove("temporal.txt");
		return;
	}
	else
	{
		if (codEncontrado == 0)
		{
			cout << "\nNecesito un codigo de un alumno que exista para poder eliminarlo\n";
			archivo.close();
			archivoTemporal.close();
			remove("temporal.txt");
			return;
		}
		else
		{
			while(!archivo.eof())
			{
				archivo >> campo.codigo >> campo.nombre >> campo.apellido1 >> campo.apellido2 >> campo.asignatura >> campo.nota_1 >> campo.nota_2 >> campo.nota_3 >> campo.nota_final;
				
													
				if(buscaCod != campo.codigo)
				{
					if (firstLine == 0 )
					{
						archivoTemporal << endl;
					}
					archivoTemporal << campo.codigo << " " << campo.nombre << " " << campo.apellido1 << " " << campo.apellido2 << " " << campo.asignatura << " " << campo.nota_1 << " " << campo.nota_2 << " " << campo.nota_3 << " " << campo.nota_final;
				}
				
				if (firstLine == 1 && buscaCod != campo.codigo)
				{
					firstLine = 0;
				}	
			}
		}
	}
	archivo.close();
	archivoTemporal.close();
	remove("alumnos.txt");
	rename("temporal.txt", "alumnos.txt");
}
