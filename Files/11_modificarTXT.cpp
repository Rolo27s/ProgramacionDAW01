/* TAREA PENDIENTE PARA MA�ANA
HACER UNA COPIA DE SEGURIDAD DE asesoria.txt que se llame asesoria_old.txt, y luego renombrar el arhivo asesoria_update a asesoria, de tal manera que termine sobreescribiendo el archivo principal. */

/* Como novedad usaremos para resolver el problema la herramienta substr de la libreria string.h
Ejemplo de uso:
    string str1 = "Apples are red";
    string str2 = str1.substr(11, 3);
    El primer d�gito marca la posicion de inicio del substring y el segundo la longitud a partir de ah� y contando esa misma)
 */
/* ENCODING USED: windows-1252 to solve special characters*/
#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <fstream>
#include <string.h>
#include <cstdio> /* Necesario para rename */
using namespace std;
const int N = 100; // Mi listado tendra de momento 100 registros como m�ximo

struct user
{
    string id;
    string nombre;
    string apellido;
    string ciudad;
    string edad;
    string genero;
    string consulta;
};

user registro[N];

float comprobarNum(float a);
char comprobarChar(char c);
void consoleLogCpp(int rows);
/* La funcion leerGuardar me devuelve el numero de filas leidas (int)*/
int leerGuardar(string name);
void buscarId(string code);
bool editarID(string code, int rows);

int main()
{
    setlocale(LC_ALL, "");
    char again, editAsesor;
    string idCode, idCodeEdit;

    do
    {
        system("cls");

        leerGuardar("asesoria.txt");
        consoleLogCpp(leerGuardar("asesoria.txt"));

        /* Contenido nuevo desarrollado para el ejercicio 25 */
        cout << "\nQuieres editar algun asesor? (S/N): ";
        cin >> editAsesor;
        editAsesor = comprobarChar(editAsesor);
        if (editAsesor == 'S' || editAsesor == 's')
        {
            cout << "\nIntroduce ID del asesor que quieres editar: ";
            cin >> idCodeEdit;

            /* Al usar una funcion como argumento condicional, ejecuto una vez al menos dicha funcion. No necesito hacer llamada explicita, ya que est� llamandose una ve de manera impl�cita */
            if (editarID(idCodeEdit, leerGuardar("asesoria.txt")) == true)
            {
                /* Muestro en consola la info */
                cout << "\nEl aspecto actualizado del listado de asesores es el siguiente...\n";
                consoleLogCpp(leerGuardar("asesoria.txt"));
            }
        }

        cout << "\n\nDesea procesar nuevamente: S o N:";
        cin >> again;
        again = comprobarChar(again);
    } while (again == 'S' || again == 's');
    return 0;
}

// Comprueba si el char es S, S, N o n para un correcto funcionamiento del programa.
char comprobarChar(char c)
{
    while (c != 'S' && c != 's' && c != 'N' && c != 'n')
    {
        cout << "Opcion incorrecta\n";
        cout << "Elige (S/N): ";
        cin >> c;
    }
    return c;
}

// Funcion que comprueba que el n�mero introducido sea mayor a 0 para el uso correcto del programa
float comprobarNum(float a)
{
    while (a <= 0)
    {
        cout << "Opcion incorrecta\n";
        cout << "Introduce valor: ";
        cin >> a;
    }
    return a;
}

// Funcion que lee el archivo asesoria.txt y guarda informacion del mismo en programa.
//  Devuelve el numero de filas leidas. Variable tipo int.
int leerGuardar(string name)
{
    ifstream archivo;
    string nombreArchivo = name, texto, subString;
    int infoid, tamanoFrase, spaceCount = 0, marker = 0, rowCount = 0;

    /* La propiedad .c_str() sirve para cuando le introduces el nombre por teclado. En este caso nombreArchivo.c_str() no ser�a necesario porque se lo estoy dando desde el codigo fuente */
    archivo.open(nombreArchivo, ios::in);

    if (archivo.fail())
    {
        cout << "No se encontro el archivo " << nombreArchivo << endl;
    }
    else
    {
        /* eof (end of file). El while estar� activo hasta el final del archivo */
        while (!archivo.eof())
        {
            /* Leemos la primera linea de texto y la guardamos en el string texto */
            getline(archivo, texto);

            /* Controlo el tama�o de la frase */
            tamanoFrase = texto.length();

            for (int i = 0; i < tamanoFrase; i++)
            {
                if (texto[i] == ' ')
                {
                    subString = texto.substr(marker, i - marker);
                    switch (spaceCount)
                    {
                    case 0:
                        registro[rowCount].id = subString;
                        break;
                    case 1:
                        registro[rowCount].nombre = subString;
                        break;
                    case 2:
                        registro[rowCount].apellido = subString;
                        break;
                    case 3:
                        registro[rowCount].ciudad = subString;
                        break;
                    case 4:
                        registro[rowCount].edad = subString;
                        break;
                    case 5:
                        registro[rowCount].genero = subString;
                        break;
                    default:
                        break;
                    }

                    spaceCount++;
                    marker = i + 1;
                }
                /* Uso este else if porque en este punto del c�digo ya tengo el contador y el marcador actualizado y puedo reaccionar a partir del ultimo espacio */
                else if (spaceCount == 6)
                {
                    subString = texto.substr(marker, tamanoFrase - marker);
                    registro[rowCount].consulta = subString;
                }
            }
            /* Actualizo fila a fila y reseteo los contadores locales de cada fila */
            rowCount++;
            marker = 0;
            spaceCount = 0;
        }
    }
    cout << endl;
    archivo.close();

    return (rowCount + 1);
}

/* Funcion que ense�a por pantalla informaci�n sobre la estructura */
void consoleLogCpp(int rows)
{
    cout << "\t\t Datos de Asesores\n";
    cout << "\t\t-----------------------\n\n";

    cout << " Id "
         << "\t  Nombre  "
         << "\t  Apellidos  "
         << "\tCiudad"
         << "\tEdad "
         << " \tGenero "
         << "\tConsulta\n";
    cout << "----"
         << "\t  ------  "
         << "\t  ---------  "
         << "\t------"
         << " \t---- "
         << " \t------ "
         << "\t---------\n";
    for (int i = 0; i < rows; i++)
    {
        cout << registro[i].id << "\t" << registro[i].nombre << "\t" << registro[i].apellido << "\t" << registro[i].ciudad << "\t" << registro[i].edad << "\t" << registro[i].genero << "\t\t" << registro[i].consulta;
        cout << endl;
    }
    cout << "----"
         << "\t  -------  "
         << "\t  ---------  "
         << "\t------"
         << " \t---- "
         << " \t------ "
         << "\t---------\n\n";
}

/* Busca el id que pasa por referencia el usuario */
void buscarId(string code)
{
    bool codeOK = 0;
    for (int i = 0; i < N; i++)
    {
        if (registro[i].id == code)
        {
            /* Codigo = 1 significa id encontrada */
            codeOK = 1;
            cout << "\nInformacion del asesor:\n";
            cout << "-----------------------------\n";
            cout << "\tId: \t\t" << registro[i].id << endl;
            cout << "\tNombre: \t" << registro[i].nombre << endl;
            cout << "\tApellido: \t" << registro[i].apellido << endl;
            cout << "\tCiudad: \t" << registro[i].ciudad << endl;
            cout << "\tEdad: \t\t" << registro[i].edad << endl;
            cout << "\tGenero: \t" << registro[i].genero << endl;
            cout << "\tConsulta: \t" << registro[i].consulta << endl;
        }
    }
    /* 0 como codigo de error, id no encontrada */
    if (codeOK == 0)
        cout << "\nId no registrada...\n";
}

bool editarID(string code, int rows)
{
    bool here = false;
    ofstream newFileTxt; /* ofstream sirve para crear y escribir */
    for (int i = 0; i < N; i++)
    {
        if (registro[i].id == code)
        {
            cout << "\nID encontrada..." << endl;
            cout << "\tId: \t\t" << registro[i].id << endl;
            cout << "\n\tNombre a modificar: \t" << registro[i].nombre << endl;
            cout << "\n\tNombre NUEVO: \t";
            cin >> registro[i].nombre;

            cout << "\n\tApellido a modificar: \t" << registro[i].apellido << endl;
            cout << "\n\tApellido NUEVO: \t";
            cin >> registro[i].apellido;

            cout << "\n\tCiudad a modificar: \t" << registro[i].ciudad << endl;
            cout << "\n\tCiudad NUEVA: \t";
            cin >> registro[i].ciudad;

            cout << "\n\tEdad a modificar: \t\t" << registro[i].edad << endl;
            cout << "\n\tEdad NUEVA: \t\t";
            cin >> registro[i].edad;

            cout << "\n\tGenero a modificar: \t" << registro[i].genero << endl;
            cout << "\n\tGenero NUEVO: \t";
            cin >> registro[i].genero;

            cout << "\n\tConsulta a modificar: \t" << registro[i].consulta << endl;
            cout << "\n\tConsulta NUEVA: \t";
            cin >> registro[i].consulta;

            here = true;
            /* Renombro los archivos txt */
            rename("asesoria.txt", "asesoria_backup.txt");

            /* Toda la informacion recopilada en el programa la copio a un nuevo .txt, en este caso asesoria_update.txt */
            newFileTxt.open("asesoria.txt", ios::out);
            for (int i = 0; i < rows; i++)
            {
                newFileTxt << registro[i].id + " " + registro[i].nombre + " " + registro[i].apellido + " " + registro[i].ciudad + " " + registro[i].edad + " " + registro[i].genero + " " + registro[i].consulta << endl;
            }

            newFileTxt.close();
        }
    }
    if (!here)
    {
        cout << "ID NO encontrada...";
        here = false;
    }
    return here;
}