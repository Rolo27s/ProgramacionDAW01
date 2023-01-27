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
void buscar(void);
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
    ifstream est; /* Lectura. Nemotécnica: i - in - input - recibo informacion del archivo */

    header();
    headerFunction("visualiza");

    if (!est.is_open())
        est.open("estudiante.txt", ios::in);

    if (est.fail())
    {
        cout << "\nNo se encontró el archivo\n";
    }
    else
    {
        /* Defino que voy a hacer si abrí el archivo y no dió errores */

        /* Podemos usar el método de end_of_file para leer linea por linea hasta el final del archivo
                → while(!est.eof())
        Otra opción sería localizar cada variable y poder guardarla temporalmente de manera separada:
                → while (var1 >> var2 >> var 3 ...)
                De esta manera le estarías dando la información al while de la composición de cada línea o registro,
                y tendríamos posibilidad de tener la información separada directamente.
                El primer parametro que tendríamos que escribir es el nombre del archivo, en mi caso "est". Y ahora las variables.
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
void buscar(void)
{
    ifstream est;
    int id;
    bool encontrado = false;

    header();
    headerFunction("busca");

    if (!est.is_open())
        est.open("estudiante.txt", ios::in);

    if (est.fail())
    {
        cout << "\nNo se encontró el archivo\n";
    }
    else
    {
        cout << "Que codigo quieres buscar?: ";
        cin >> id;

        while (!est.eof() && !encontrado)
        {
            est >> codigo >> nombres >> apellidos >> edad >> carrera >> semestre >> promedio >> valora;
            if (codigo == id)
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
                encontrado = true;
                break;
            }
        }
        est.close();

        if (!encontrado)
        {
            cout << "\nEstudiante con codigo " << id << " no encontrado...\n";
            Sleep(200);
        }

        cout << endl;
    }
}

/* ----------------------------------------------------------------------------------- */
/* Como voy a hacer una funcion que modifica un archivo de texto necesitaré leer el archivo y escribir, por tanto usaré ifstream y ofstream con ios::in e ios::out.
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
        cout << "\nNo se encontró el archivo temp.txt\n";

    if (!est.is_open())
        est.open("estudiante.txt", ios::in);

    if (est.fail())
    {
        cout << "\nNo se encontró el archivo estudiante.txt\n";
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
                cout << "Información actual del alumno:\n";
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

                /* Como ya encontre al alumno a editar, ahora comenzaré a sobreescribir información */
                cout << "Información NUEVA del alumno:\n";

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
    Podemos complicar la funcion modificar con los siguientes parámetros de control
        - que el id pueda ser entre [1 y 9999]
        - añadir la posibilidad de introducir un caracter en la info nueva (por ejemplo la letra 'p') para decidir que no quiero modificar ese campo en concreto
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
cuando encuentra la id que, en este caso, queremos eliminar, simplemente no guardamos nada sobre ella en el archivo temporal. La eliminaríamos por omisión y no la escribiríamos en el archivo temporal. */
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
        cout << "\nNo se encontró el archivo temp.txt\n";

    if (!est.is_open())
        est.open("estudiante.txt", ios::in);

    if (est.fail())
    {
        cout << "\nNo se encontró el archivo estudiante.txt\n";
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
                cout << "Información del alumno que esta siendo borrado...\n";
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

                /* Como ya encontre al alumno a eliminar, no trataré esta información y caerá en el olvido */
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
/* La funcion agregar funcionará de manera muy parecida a la función modificar. La diferencia principal es que la informacion nueva aparecera añadida (append) al final del documento.
Del mismo modo, podemos complicar el programa implementando los mismos parámetros de control de introduccion de información. */
/* El retorno de la funcion será un bool que dirá si se ha agregado con exito el alumno o no
    return 0 → El alumno NO se ha agregado (false)
    return 1 → El alumno SI se ha agregado correctamente (true)*/
bool agregar(void)
{
    {
        ifstream est;
        fstream temp;
        int id;
        bool encontrado = false;

        header();
        headerFunction("agrega");

        if (!temp.is_open())
            temp.open("temp.txt", ios::out | ios::app);

        if (temp.fail())
            cout << "\nNo se encontró el archivo temp.txt\n";

        if (!est.is_open())
            est.open("estudiante.txt", ios::in);

        if (est.fail())
        {
            cout << "\nNo se encontró el archivo estudiante.txt\n";
        }
        else
        {
            cout << "Agregando un alumno nuevo...\n";
            Sleep(200);
            cout << "\tIngrese el codigo nuevo del alumno : ";
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
                    cout << "Codigo de alumno ya existente!\n";
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

                    est.close();
                    temp.close();
                    remove("temp.txt");
                    cout << "Debe elegir un codigo no existente para poder agregar un nuevo alumno...\n\n";
                    return 0;
                    /* Encontre un alumno con ese codigo y no puede ser, porque no estamos en sobreescribir, estamos en agregar. Retorno 0 que es false porque no se ha agregado el alumno */
                }
            }

            /* Si hemos llegado a esta parte del codigo, queda implicito que el alumno no ha sido encontrado.
            Igualmente dejo escrito este pequeño trozo de codigo por posibles futuras modificaciones */
            if (!encontrado)
            {
                cout << "\nEstudiante con codigo " << id << " no encontrado, perfecto!\n";
                Sleep(200);
                cout << "Comenzamos a introducir la información del nuevo alumno:\n";

                codigo = id;

                cout << "nombres: ";
                cin >> nombres;

                cout << "apellidos: ";
                cin >> apellidos;

                cout << "edad: ";
                cin >> edad;

                cout << "carrera: ";
                cin >> carrera;

                cout << "semestre: ";
                cin >> semestre;

                cout << "promedio: ";
                cin >> promedio;

                cout << "valora: ";
                cin >> valora;

                cout << endl;

                temp << codigo << " " << nombres << " " << apellidos << " " << edad << " " << carrera << " " << semestre << " " << promedio << " " << valora << endl;
            }

            est.close();
            temp.close();

            remove("estudiante.txt");
            rename("temp.txt", "estudiante.txt");
        }
    }
    return 1;
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
/* El parámetro solicitado es la accion que hace esa funcion.
Por ejemplo si es la funcion modificar, su acción será modifica y deberíamos pasarle como parámetro */
void headerFunction(string accion)
{
    cout << "\nFunción que " << accion << " registros del archivo estudiantes.txt\n";
    cout << "----------------------------------------------------------------\n\n";
}