/* ENUNCIADO DEL PROBLEMA */
/* ----------------------------------------------------------------------------------- */
/*
    Generar un programa que manipule los registros del archivo estudiante.txt
    (visualizar, buscar, modificar, eliminiar y agregar).
    Los campos del archivo estudiante son:
    codigo, nombres, apellidos, edad, carrera, semestre, promedio y valora.
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <wchar.h>
#include <string>
#include <iomanip>
using namespace std;

/* VARIABLES SCOPE GLOBAL */
/* ----------------------------------------------------------------------------------- */
int codigo;
string nombres, apellidos, carrera, valora;
int edad, semestre;
float promedio;

/* FUNCIONES (DECLARACION)*/
/* ----------------------------------------------------------------------------------- */
void visualizar(void);
void buscar(void);
void modificar(void);
void eliminar(void);
void agregar(void);

/* PROCEDIMIENTOS (DECLARACION)*/
/* ----------------------------------------------------------------------------------- */
void opcionSiNo(char &c);
void ingresaNum(int &opc, int min, int max);

/* FUNCION MAIN */
/* ----------------------------------------------------------------------------------- */
int main()
{
    setlocale(LC_ALL, "");
    char again;
    do
    {
        system("cls");
        int opc;
        cout << "Programa que manipula registros del archivo estudiante\n";
        cout << "------------------------------------------------------\n\n";

        cout << "|-------------------------------|\n";
        cout << "|       MENU DEL PROGRAMA       |\n";
        cout << "|-------------------------------|\n";
        cout << "|  1. Visualizar registros      |\n";
        cout << "|  2. Buscar registros          |\n";
        cout << "|  3. Modificar registros       |\n";
        cout << "|  4. Eliminar registros        |\n";
        cout << "|  5. Agregar registros         |\n";
        cout << "|  6. Terminar proceso          |\n";
        cout << "|-------------------------------|\n";
        cout << "Elige la opcion del menu deseada: ";
        ingresaNum(opc, 1, 6);

        switch (opc)
        {
        case 1:
            visualizar();
            break;
        case 2:
            buscar();
            break;
        case 3:
            modificar();
            break;
        case 4:
            eliminar();
            break;
        case 5:
            agregar();
            break;
        case 6:
            cout << "Proceso terminado. Hasta otra!";
            Sleep(200);
            return 0;
        default:
            cout << "Opcion no valida...\n";
            Sleep(200);
            break;
        }

        cout << "\n------------------------\n";
        cout << "Desea procesar nuevamente? (S/N): ";
        opcionSiNo(again);

        if (again == 'N' || again == 'n')
        {
            cout << "Proceso terminado. Hasta otra!";
            Sleep(200);
        }

    } while (again == 'S' || again == 's');

    return 0;
}

/* FUNCIONES (DEFINICION)*/
/* ----------------------------------------------------------------------------------- */
void visualizar(void)
{
    cout << "De momento solo soy una funcion que visualiza elementos\n";
}
void buscar(void)
{
    cout << "De momento solo soy una funcion que busca elementos\n";
}
void modificar(void)
{
    cout << "De momento solo soy una funcion que modifica elementos\n";
}
void eliminar(void)
{
    cout << "De momento solo soy una funcion que elimina elementos\n";
}
void agregar(void)
{
    cout << "De momento solo soy una funcion que agrega elementos\n";
}

/* PROCEDIMIENTOS (DEFINICION)*/
/* ----------------------------------------------------------------------------------- */
void opcionSiNo(char &c)
{
    cin >> c;
    while (c != 'S' && c != 's' && c != 'N' && c != 'n')
    {
        cout << "\nOpcion no válida.\n";
        Sleep(200);
        cout << "Debe pulsar la tecla [S] o la tecla [N]: ";
        cin >> c;
    }
}

void ingresaNum(int &opc, int min, int max)
{
    cin >> opc;
    while (opc < min || opc > max)
    {
        cout << "\nOpcion erronea...\n";
        Sleep(200);
        cout << "Debe elegir un numero entre el " << min << " y el " << max << endl;
        cout << "Eliga una opcion: ";
        cin >> opc;
        /* Si ingresamos un char o string se rompe el codigo...
        Investigar si podemos controlar este error con codigoASCII */
    }
}