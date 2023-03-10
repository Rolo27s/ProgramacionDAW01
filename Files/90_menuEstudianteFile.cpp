/* ENUNCIADO DEL PROBLEMA */
/* ----------------------------------------------------------------------------------- */
/*
    Generar un programa que manipule los registros del archivo estudiante.txt
    (visualizar, buscar, modificar, eliminiar y agregar).
    Los campos del archivo estudiante son:
    codigo, nombres, apellidos, edad, carrera, semestre, promedio y valora.
*/
#include <iostream>  /* cin, cout */
#include <fstream>   /*ifstream, ofstream, fstream*/
#include <stdlib.h>  /* system("pause"), system ("cls")*/
#include <windows.h> /* Sleep*/
#include <locale.h>  /* Para caracteres especiales. setlocale(LC_ALL, ""); */
#include <wchar.h>   /* Para caracteres especiales. setlocale(LC_ALL, ""); */
#include <string>    /* para cadena de caracteres... substr() etc */
#include <iomanip>   /* fixed, setprecision()*/
#include <cstdio>    /* rename, remove */
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
bool buscar(int code);
void modificar(void);
void eliminar(void);
bool agregar(void);

/* PROCEDIMIENTOS (DECLARACION)*/
/* ----------------------------------------------------------------------------------- */
void opcionSiNo(char &c);
void ingresaNum(int &opc, int min, int max);
void header(void);
void headerFunction(string accion);

/* FUNCION MAIN */
/* ----------------------------------------------------------------------------------- */
int main()
{
    setlocale(LC_ALL, "");
    char again;
    int id;
    do
    {
        system("cls");
        int opc;
        header();

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
        {
            cout << "Que codigo quieres buscar?: ";
            cin >> id;
            buscar(id);
            break;
        }
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
            /* Al tener controlado opc a [1,6] con ingresaNum(), nunca va a ser posible pasar otro argumento diferente */
            break;
        }

        cout << "\nDesea volver al menu principal? (S/N): ";
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
    ifstream est; /* Lectura. Nemot??cnica: i - in - input - recibo informacion del archivo */

    header();
    headerFunction("visualiza");

    if (!est.is_open())
        est.open("estudiante.txt", ios::in);

    if (est.fail())
    {
        cout << "\nNo se encontr?? el archivo\n";
    }
    else
    {
        /* Defino que voy a hacer si abr?? el archivo y no di?? errores */

        /* Podemos usar el m??todo de end_of_file para leer linea por linea hasta el final del archivo
                ??? while(!est.eof())
        Otra opci??n ser??a localizar cada variable y poder guardarla temporalmente de manera separada:
                ??? while (var1 >> var2 >> var 3 ...)
                De esta manera le estar??as dando la informaci??n al while de la composici??n de cada l??nea o registro,
                y tendr??amos posibilidad de tener la informaci??n separada directamente.
                El primer parametro que tendr??amos que escribir es el nombre del archivo, en mi caso "est". Y ahora las variables.
        */
        cout << "\t"
             << "codigo"
             << "\t"
             << "nombres"
             << "\t\t"
             << "apellidos"
             << "\t"
             << "edad"
             << "\t"
             << "carrera"
             << "\t\t    "
             << "semestre"
             << "\t"
             << "promedio"
             << "\t"
             << "valora" << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------\n";

        while (est >> codigo >> nombres >> apellidos >> edad >> carrera >> semestre >> promedio >> valora)
        {
            cout << "\t" << codigo << "\t" << nombres << "\t" << apellidos << "\t" << edad << "\t" << carrera << "\t\t" << semestre << "\t" << fixed << setprecision(1) << promedio << "\t\t" << valora << endl;
            Sleep(125);
        }
        cout << "-------------------------------------------------------------------------------------------------------------------------";
        est.close();
        cout << endl;
    }
}

/* ----------------------------------------------------------------------------------- */
bool buscar(int code)
{
    ifstream est;
    bool encontrado = false;

    header();
    headerFunction("busca");

    if (!est.is_open())
        est.open("estudiante.txt", ios::in);

    if (est.fail())
    {
        cout << "\nNo se encontr?? el archivo\n";
    }
    else
    {

        while (!est.eof() && !encontrado)
        {
            est >> codigo >> nombres >> apellidos >> edad >> carrera >> semestre >> promedio >> valora;
            if (codigo == code)
            {
                cout << "\t"
                     << "codigo"
                     << "\t"
                     << "nombres"
                     << "\t\t"
                     << "apellidos"
                     << "\t"
                     << "edad"
                     << "\t"
                     << "carrera"
                     << "\t\t    "
                     << "semestre"
                     << "\t"
                     << "promedio"
                     << "\t"
                     << "valora" << endl;
                cout << "-------------------------------------------------------------------------------------------------------------------------\n";
                cout << "\t" << codigo << "\t" << nombres << "\t" << apellidos << "\t" << edad << "\t" << carrera << "\t\t" << semestre << "\t" << fixed << setprecision(1) << promedio << "\t\t" << valora << endl;
                Sleep(125);
                est.close();
                encontrado = true;
                return encontrado;
            }
        }
        est.close();

        if (!encontrado)
        {
            cout << "\nEstudiante con codigo " << code << " no encontrado...\n";
            Sleep(200);
        }

        cout << endl;
    }
    return encontrado;
}

/* ----------------------------------------------------------------------------------- */
/* Como voy a hacer una funcion que modifica un archivo de texto necesitar?? leer el archivo y escribir, por tanto usar?? ifstream y ofstream con ios::in e ios::out.
Usare un archivo temporal como puente entre el archivo antiguo y el nuevo*/
void modificar(void)
{
    ifstream est;
    ofstream temp;
    int id;
    bool encontrado = false;

    int codigoTemp;
    string nombresTemp, apellidosTemp, carreraTemp, valoraTemp;
    int edadTemp, semestreTemp;
    float promedioTemp;

    header();
    headerFunction("modifica");

    if (!temp.is_open())
        temp.open("temp.txt", ios::out);

    if (temp.fail())
        cout << "\nNo se encontr?? el archivo temp.txt\n";

    if (!est.is_open())
        est.open("estudiante.txt", ios::in);

    if (est.fail())
    {
        cout << "\nNo se encontr?? el archivo estudiante.txt\n";
    }
    else
    {
        cout << "Que alumno quieres modificar? Ingrese el codigo del alumno: ";
        cin >> id;

        while (!est.eof())
        {
            est >> codigo >> nombres >> apellidos >> edad >> carrera >> semestre >> promedio >> valora;

            if (codigo != id)
            {
                temp << codigo << " " << nombres << " " << apellidos << " " << edad << " " << carrera << " " << semestre << " " << promedio << " " << valora << endl;
            }

            if (codigo == id)
            {
                cout << "Informaci??n actual del alumno:\n";
                cout << "\t"
                     << "codigo"
                     << "\t"
                     << "nombres"
                     << "\t\t"
                     << "apellidos"
                     << "\t"
                     << "edad"
                     << "\t"
                     << "carrera"
                     << "\t\t    "
                     << "semestre"
                     << "\t"
                     << "promedio"
                     << "\t"
                     << "valora" << endl;
                cout << "-------------------------------------------------------------------------------------------------------------------------\n";
                cout << "\t" << codigo << "\t" << nombres << "\t" << apellidos << "\t" << edad << "\t" << carrera << "\t\t" << semestre << "\t" << fixed << setprecision(1) << promedio << "\t\t" << valora << endl;
                Sleep(125);
                encontrado = true;

                /* Como ya encontre al alumno a editar, ahora comenzar?? a sobreescribir informaci??n */
                cout << "Informaci??n NUEVA del alumno:\n";

                cout << "codigo: ";
                cin >> codigoTemp;

                cout << "nombres: ";
                cin >> nombresTemp;

                cout << "apellidos: ";
                cin >> apellidosTemp;

                cout << "edad: ";
                cin >> edadTemp;

                cout << "carrera: ";
                cin >> carreraTemp;

                cout << "semestre: ";
                cin >> semestreTemp;

                cout << "promedio: ";
                cin >> promedioTemp;

                cout << "valora: ";
                cin >> valoraTemp;

                cout << endl;

                temp << codigoTemp << " " << nombresTemp << " " << apellidosTemp << " " << edadTemp << " " << carreraTemp << " " << semestreTemp << " " << promedioTemp << " " << valoraTemp << endl;
            }
        }
        cout << "-------------------------------------------------------------------------------------------------------------------------\n";
        est.close();
        temp.close();

        remove("estudiante.txt");
        rename("temp.txt", "estudiante.txt");

        if (!encontrado)
        {
            cout << "\nEstudiante con codigo " << id << " no encontrado...\n";
            Sleep(200);
        }
    }
}

/*EXTRA
    Podemos complicar la funcion modificar con los siguientes par??metros de control
        - que el id pueda ser entre [1 y 9999]
        - a??adir la posibilidad de introducir un caracter en la info nueva (por ejemplo la letra 'p') para decidir que no quiero modificar ese campo en concreto
        - Semestre entre [1 y 9]
        - Promedio entre [0 y 5]
        - Automatizar la variable valora segun el promedio
            [0 a 3) - Insuficiente
            [3 a 4) - Aceptable
            [4 a 4.5] - Sobresaliente
            (4.5 a 5] - Excelente
*/

/* ----------------------------------------------------------------------------------- */
/* Por eliminar nos referimos a eliminar un registros de nuestra lista estudiantes */
/* La funcion eliminar funciona exactamente igual que la funcion modificar, con la unica diferencia que,
cuando encuentra la id que, en este caso, queremos eliminar, simplemente no guardamos nada sobre ella en el archivo temporal. La eliminar??amos por omisi??n y no la escribir??amos en el archivo temporal. */
void eliminar(void)
{
    ifstream est;
    ofstream temp;
    int id;
    bool encontrado = false;

    int codigoTemp;
    string nombresTemp, apellidosTemp, carreraTemp, valoraTemp;
    int edadTemp, semestreTemp;
    float promedioTemp;

    header();
    headerFunction("elimina");

    if (!temp.is_open())
        temp.open("temp.txt", ios::out);

    if (temp.fail())
        cout << "\nNo se encontr?? el archivo temp.txt\n";

    if (!est.is_open())
        est.open("estudiante.txt", ios::in);

    if (est.fail())
    {
        cout << "\nNo se encontr?? el archivo estudiante.txt\n";
    }
    else
    {
        cout << "Que alumno quieres eliminar? Ingrese el codigo del alumno: ";
        cin >> id;

        while (!est.eof())
        {
            est >> codigo >> nombres >> apellidos >> edad >> carrera >> semestre >> promedio >> valora;

            if (codigo != id)
            {
                temp << codigo << " " << nombres << " " << apellidos << " " << edad << " " << carrera << " " << semestre << " " << promedio << " " << valora << endl;
            }

            if (codigo == id)
            {
                cout << "Informaci??n del alumno que esta siendo borrado...\n";
                Sleep(200);
                cout << "\t"
                     << "codigo"
                     << "\t"
                     << "nombres"
                     << "\t\t"
                     << "apellidos"
                     << "\t"
                     << "edad"
                     << "\t"
                     << "carrera"
                     << "\t\t    "
                     << "semestre"
                     << "\t"
                     << "promedio"
                     << "\t"
                     << "valora" << endl;
                cout << "-------------------------------------------------------------------------------------------------------------------------\n";
                cout << "\t" << codigo << "\t" << nombres << "\t" << apellidos << "\t" << edad << "\t" << carrera << "\t\t" << semestre << "\t" << fixed << setprecision(1) << promedio << "\t\t" << valora << endl;
                Sleep(1000);
                encontrado = true;

                /* Como ya encontre al alumno a eliminar, no tratar?? esta informaci??n y caer?? en el olvido */
                cout << "\n\tAlumno eliminado del registro alumno.txt con exito!\n";
            }
        }
        est.close();
        temp.close();

        remove("estudiante.txt");
        rename("temp.txt", "estudiante.txt");

        if (!encontrado)
        {
            cout << "\nEstudiante con codigo " << id << " no encontrado...\n";
            Sleep(200);
        }
    }
}

/* ----------------------------------------------------------------------------------- */
/* La funcion agregar funcionar?? de manera muy parecida a la funci??n modificar. La diferencia principal es que la informacion nueva aparecera a??adida (append) al final del documento.
Del mismo modo, podemos complicar el programa implementando los mismos par??metros de control de introduccion de informaci??n. */
/* El retorno de la funcion ser?? un bool que dir?? si se ha agregado con exito el alumno o no
    return 0 ??? El alumno NO se ha agregado (false)
    return 1 ??? El alumno SI se ha agregado correctamente (true)*/
bool agregar(void)
{
    fstream est;
    int id;
    bool encontrado;

    header();
    headerFunction("agrega");

    cout << "Vamos a agregar un nuevo alumno. Ingrese el codigo del nuevo alumno: ";
    cin >> id;
    /* Llamo a la funcion buscar para comprobar que no exista y repetir el codigo
    encontrado = 0 es no encontrado. La funcion buscar necesita del argumento codigo, para saber que codigo buscar */
    encontrado = buscar(id);

    if (encontrado)
    {
        cout << "\nCodigo de alumno ya existente. Necesita ingresar un codigo disponible\n";
        Sleep(250);
        return encontrado;
    }
    else
    {
        if (!est.is_open())
            est.open("estudiante.txt", ios::app);

        if (est.fail())
        {
            cout << "\nNo se encontr?? el archivo estudiante.txt\n";
        }
        else
        {
            cout << "Ingresando informaci??n del alumno nuevo al final del fichero... \n";
            Sleep(200);

            cout << "\tcodigo (auto): " << id << endl;
            codigo = id;
            Sleep(500);

            cout << "\tnombres: ";
            cin >> nombres;

            cout << "\tapellidos: ";
            cin >> apellidos;

            cout << "\tedad: ";
            cin >> edad;

            cout << "\tcarrera: ";
            cin >> carrera;

            cout << "\tsemestre: ";
            cin >> semestre;

            cout << "\tpromedio: ";
            cin >> promedio;

            cout << "\tvalora: ";
            cin >> valora;

            Sleep(1000);

            est << codigo << " " << nombres << " " << apellidos << " " << edad << " " << carrera << " " << semestre << " " << promedio << " " << valora << endl;
            cout << "\n\tAlumno agregado al registro alumno.txt con exito!\n";

            est.close();
        }
    }
    return encontrado;
}

/* PROCEDIMIENTOS (DEFINICION)*/
/* ----------------------------------------------------------------------------------- */
void opcionSiNo(char &c)
{
    cin >> c;
    while (c != 'S' && c != 's' && c != 'N' && c != 'n')
    {
        cout << "\nOpcion no v??lida.\n";
        Sleep(200);
        cout << "Debe pulsar la tecla [S] o la tecla [N]: ";
        cin >> c;
    }
}

/* ----------------------------------------------------------------------------------- */
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

/* ----------------------------------------------------------------------------------- */
void header(void)
{
    system("cls");
    cout << "\nPrograma que manipula registros del archivo estudiante\n";
    cout << "------------------------------------------------------\n\n";
}

/* ----------------------------------------------------------------------------------- */
/* El par??metro solicitado es la accion que hace esa funcion.
Por ejemplo si es la funcion modificar, su acci??n ser?? modifica y deber??amos pasarle como par??metro */
void headerFunction(string accion)
{
    cout << "\nFunci??n que " << accion << " registros del archivo estudiantes.txt\n";
    cout << "----------------------------------------------------------------\n\n";
}