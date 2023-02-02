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
#include <windows.h>
#include <wchar.h>
#include <locale>
#include <cstdio>
using namespace std;

/* | -------------------------- | */
/* | VARIABLES SCOPE GLOBAL     |*/

struct {
    int codigo;
    string nombre;
    string apellido1;
    string apellido2;
    string asignatura;
    float nota_1;
    float nota_2;
    float nota_3;
    float nota_final;
}registro, registroResized;

/* Para una correcta visualizacion por pantalla */
int espaciado[9] = {8, 25, 15, 15, 15, 8, 8, 8, 8};

/* uso concreto que asiste a la funcion buscar para el uso en funcion agregar */
int codNoEncontradoAUX;

/* | -------------------------- | */

/* | ---------------------------------- | */
/* | PROCEDIMIENTOS (DECLARACION)       |*/
/* | --------------------------------- | */

char comprobarChar (char c);
int comprobarNum (int n, int min, int max);

/* | ---------------------------------- | */
/* | FUNCIONES (DECLARACION)            |*/
/* | --------------------------------- | */

void visualizar(void);
int buscar(void);

/* Los argumentos de estas ultimas 3 funciones será propia funcion buscar */
bool agregar(int codeAgregar);
bool modificar (int codeModificar);
bool eliminar (int codeEliminar);

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
            break;

        case 2:
        {
            cout << "2. Buscar alumno\n\n";
            /* Si encuentro al alumno, muestro su informacion. */
            if (buscar())
                {
                cout << "\nInformacion del alumno buscado:\n";
                cout << registro.codigo << ' ' << registro.nombre << ' ' << registro.apellido1 << ' ' << registro.apellido2 << ' ' << registro.asignatura << ' ' << registro.nota_1 << ' ' << registro.nota_2 << ' ' << registro.nota_3 << ' ' << registro.nota_final << ' ' << endl;
                }
            break;
        }

        case 3:
            cout << "3. Modificar alumno\n\n";
            modificar(buscar());
            break;

        case 4:
            cout << "4. Eliminar alumno\n\n";
            eliminar(retBuscar = buscar());

            /* Si buscar encontro algo */
            if (retBuscar != 0)
                {
                cout << "Alumno eliminado, ";
                system("pause");
                /* visualizo la lista como quedo tras la borrada */
                cout << "\nAspecto actual de la base de datos\n";
                cout << "----------------------------------\n\n";
                visualizar();
                }
            break;

        case 5:
            cout << "5. Ver todos los alumnos\n\n";
            visualizar();
            break;

        case 6:
            cout << "\n\t6. Salir. Hasta otra!\n\n";
            Sleep(200);
            return 0;
        
        default:
            /* Al tener controlado opc a [1,6] con comprobarNum(), nunca va a ser posible pasar otro argumento diferente */
            break;
        }

        cout << "\n\nDesea volver al inicio del programa? (S/N): ";
        cin >> repetir;
        repetir = comprobarChar(repetir);
    } while (repetir == 'S' || repetir == 's');

    cout << "Proceso terminado. Hasta otra!";
    Sleep(200);

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
        cout << "\n\tError...Debe introducir un valor dentro del rango [ " << min << ", " << max << "]: ";
        cin >> n;
    }
    return n;
}
/* | ---------------------------------- | */
/* | FUNCIONES (DEFINICION)             |*/
/* | --------------------------------- | */

/* funcion encargada de visualizar el contenido del documento alumnos.txt */
void visualizar(void)
{
    string codigoS, nota_1S, nota_2S, nota_3S, nota_finalS;
    ifstream archivo;
    archivo.open("alumnos.txt", ios::in);
    

    if (archivo.fail())
    {
        cout << "\nHa sucedido algun problema con el archivo\n";
    }
    else
    {
        while (!archivo.eof())
        {
            archivo >> registro.codigo >> registro.nombre >> registro.apellido1 >> registro.apellido2 >> registro.asignatura >> registro.nota_1 >> registro.nota_2 >> registro.nota_3 >> registro.nota_final;

            /* Convierto a strings todos los archivos SOLO para mostrarlos ordenadamente */
            codigoS = to_string(registro.codigo);
            registroResized.nombre = registro.nombre;
            registroResized.apellido1 = registro.apellido1;
            registroResized.apellido2 = registro.apellido2;
            registroResized.asignatura = registro.asignatura;
            nota_1S = to_string(registro.nota_1);
            nota_2S = to_string(registro.nota_2);
            nota_3S = to_string(registro.nota_3);
            nota_finalS = to_string(registro.nota_final);

            /* Empiezo a dar formato a mis nuevos strings. Libreria string, metodo resize */
            codigoS.resize(espaciado[0], ' ');
            registroResized.nombre.resize(espaciado[1], ' ');
            registroResized.apellido1.resize(espaciado[2], ' ');
            registroResized.apellido2.resize(espaciado[3], ' ');
            registroResized.asignatura.resize(espaciado[4], ' ');
            nota_1S.resize(espaciado[5], ' ');
            nota_2S.resize(espaciado[6], ' ');
            nota_3S.resize(espaciado[7], ' ');
            nota_finalS.resize(espaciado[8], ' ');

            /* Muestro por pantalla el contenido ordenadamente */
            cout << codigoS << ' ' << registroResized.nombre << ' ' << registroResized.apellido1 << ' ' << registroResized.apellido2 << ' ' << registroResized.asignatura << ' ' << nota_1S << ' ' << nota_2S << ' ' << nota_3S << ' ' << nota_finalS << endl;

            Sleep(50);
        }
    }

    archivo.close();
}

/* funcion de buscar alumno. Esta funcion será argumento de otras funciones. Retornará 0 en caso de no encontrar la busqueda. */
int buscar(void)
{
    int codigoBuscar;
    ifstream archivo;
    archivo.open("alumnos.txt", ios::in);
    
    if (archivo.fail())
    {
        cout << "\nHa sucedido algun problema con el archivo\n";
    }
    else
    {
        cout << "\nIntroduce codigo: ";
        cin >> codigoBuscar;
        codigoBuscar = comprobarNum(codigoBuscar, 1, 99999);

        while (!archivo.eof())
        {
            archivo >> registro.codigo >> registro.nombre >> registro.apellido1 >> registro.apellido2 >> registro.asignatura >> registro.nota_1 >> registro.nota_2 >> registro.nota_3 >> registro.nota_final;

            if (codigoBuscar == registro.codigo)
            {
                cout << "\n\tCodigo " << codigoBuscar << " encontrado\n";
                system("pause");

                archivo.close();
                return codigoBuscar;
            }
        }
        /* Si la funcion continua hasta este punto significa que no se encontro el codigo y devolvere 0*/
        cout << "\n\tCodigo " << codigoBuscar << " no encontrado\n";
        system("pause");
        /* Guardo en memoria scope global esta informacion de utilidad para el futuro usarla en la funcion agregar */
        codNoEncontradoAUX = codigoBuscar;
    }
    archivo.close();
    return 0;
}

/* A partir de este punto, las 3 funciones que quedan por definir (agregar, modificar, eliminar), contendran a la funcion 'buscar' como argumento a la hora de ejecutar la llamada desde el switch menu principal*/

/* funcion que agrega a alumnos. Si devuelve 1, se agrego al alumno correctamente. En caso contrario devolvera 0. */
bool agregar(int codeAgregar)
{
    string codigoS;
    fstream archivo;
    archivo.open("alumnos.txt", ios::app);

    if (archivo.fail())
    {
        cout << "\nHa sucedido algun problema con el archivo\n";
    }
    else
    {
        if (codeAgregar == 0)
        {
            /* Si entro a este condicional significa que el codigo no fue encontrado, por tanto, podre agregar ese codigo como nuevo */
            
            cout << "Codigo: " << codNoEncontradoAUX << endl;
            codigoS = to_string(codNoEncontradoAUX);
            
            while (codigoS.length() < 5)
                codigoS = '0' + codigoS;

            cout << "Nombre: ";
            cin >> registro.nombre;

            cout << "Apellido1: ";
            cin >> registro.apellido1;

            cout << "Apellido2: ";
            cin >> registro.apellido2;
            
            cout << "Asignatura: ";
            cin >> registro.asignatura;

            cout << "Nota_1: ";
            cin >> registro.nota_1;
            registro.nota_1 = comprobarNum(registro.nota_1, 0, 10);

            cout << "Nota_2: ";
            cin >> registro.nota_2;
            registro.nota_2 = comprobarNum(registro.nota_2, 0, 10);
            
            cout << "Nota_3: ";
            cin >> registro.nota_3;
            registro.nota_3 = comprobarNum(registro.nota_3, 0, 10);

            cout << "Nota_final: ";
            cin >> registro.nota_final;
            registro.nota_final = comprobarNum(registro.nota_final, 0, 10);

            archivo << endl << codigoS << ' '<< registro.nombre << ' '<< registro.apellido1 << ' ' << registro.apellido2 << ' ' << registro.asignatura << ' '<< registro.nota_1 << ' '<< registro.nota_2 << ' '<< registro.nota_3 << ' '<< registro.nota_final;
        }
        else
        {
            cout << "\nPara agregar un nuevo alumno, necesitare un codigo que no se este usando en este momento...\n";
            system("pause");
        }
    }
    archivo.close();
    return 1;
}

/* funcion modificar. Devuelve 0 si no modifico nada y 1 si modifico algo. No usado de momento el retorno de estas funciones. */
bool modificar (int codeModificar)
{
    bool firstLineReaded = false;
    int opc;
    ifstream archivo;
    ofstream archivoTemporal;

    archivo.open("alumnos.txt", ios::in);
    archivoTemporal.open("temporal.txt", ios::out);

     if (archivo.fail() || archivoTemporal.fail())
    {
        cout << "\nHa sucedido algun problema con algun archivo\n";
    }
    else
    {
        if (codeModificar == 0)
        {
            /* Si entro a esta condicion significa que no encontre ningun codigo. Entonces no puedo modificar nada */
            cout << "\nPara modificar un alumno necesito que este en la base de datos primero\n";
            system("pause");

            archivo.close();
            archivoTemporal.close();
            return 0;
        }
        else
        {
            while (!archivo.eof())
            {
            /* Empiezo a leer el archivo alumnos.txt */
            archivo >> registro.codigo >> registro.nombre >> registro.apellido1 >> registro.apellido2 >> registro.asignatura >> registro.nota_1 >> registro.nota_2 >> registro.nota_3 >> registro.nota_final;

            if (firstLineReaded)
                archivoTemporal << endl;

            if (registro.codigo == codeModificar)
            {
                /* Muestro por pantalla el contenido ordenadamente */
            cout << "  ------------------------------------------------------------------------------  \n";
            cout << registro.codigo << ' ' << registro.nombre << ' ' << registro.apellido1 << ' ' << registro.apellido2 << ' ' << registro.asignatura << ' ' << registro.nota_1 << ' ' << registro.nota_2 << ' ' << registro.nota_3 << ' ' << registro.nota_final << endl;
            cout << "  ------------------------------------------------------------------------------  \n";

            Sleep(50);
                
                cout << "Que quieres modificar? \n";
                cout << "---------------------- \n";
                cout << "1. Nombre\n";
                cout << "2. Apellido1\n";
                cout << "3. Apellido2\n";
                cout << "4. Asignatura\n";
                cout << "5. Nota_1\n";
                cout << "6. Nota_2\n";
                cout << "7. Nota_3\n";
                cout << "8. Nota_final\n\n";
                cin >> opc;
                opc = comprobarNum(opc, 1, 8);

                switch (opc)
                {
                case 1:
                    cout << "\nModificando nombre...\n";
                    cout << "nombre: ";
                    cin >> registro.nombre;
                    break;
                
                case 2:
                    cout << "\nModificando apellido1...\n";
                    cout << "apellido1: ";
                    cin >> registro.apellido1;
                    break;

                case 3:
                    cout << "\nModificando apellido2...\n";
                    cout << "apellido2: ";
                    cin >> registro.apellido2;
                    break;
                
                case 4:
                    cout << "\nModificando asignatura...\n";
                    cout << "asignatura: ";
                    cin >> registro.asignatura;
                    break;
                
                case 5:
                    cout << "\nModificando nota_1...\n";
                    cout << "nota_1: ";
                    cin >> registro.nota_1;
                    registro.nota_1 = comprobarNum(registro.nota_1, 0, 10);
                    break;

                case 6:
                    cout << "\nModificando nota_2...\n";
                    cout << "nota_2: ";
                    cin >> registro.nota_2;
                    registro.nota_2 = comprobarNum(registro.nota_2, 0, 10);
                    break;

                case 7:
                    cout << "\nModificando nota_3...\n";
                    cout << "nota_3: ";
                    cin >> registro.nota_3;
                    registro.nota_3 = comprobarNum(registro.nota_3, 0, 10);
                    break;

                case 8:
                    cout << "\nModificando nota_final...\n";
                    cout << "nota_final: ";
                    cin >> registro.nota_final;
                    registro.nota_final = comprobarNum(registro.nota_final, 0, 10);
                    break;
                default:
                    /* controlado por el procedimiento comprobarNum */
                    break;
                }
            }
            
            archivoTemporal << registro.codigo << ' ' << registro.nombre << ' ' << registro.apellido1 << ' ' << registro.apellido2 << ' ' << registro.asignatura << ' ' << registro.nota_1 << ' ' << registro.nota_2 << ' ' << registro.nota_3 << ' ' << registro.nota_final;

            /* Ya se que he leido la primera linea del documento y empiezo a agregar saltos de linea */
            firstLineReaded = true;
            }
        }
    }
    archivo.close();
    archivoTemporal.close();

    /* Elimino el archivo antiguo y renombro el nuevo para actualizar de manera manual */
    remove("alumnos.txt");
    rename("temporal.txt", "alumnos.txt");
    return 1;
}

/* funcion eliminar. Retorna 1 en caso de eliminacion realizada. Retorna 0 en caso de fallo. */
bool eliminar (int codeEliminar)
{
    bool firstLineReaded = false;
    int opc;
    ifstream archivo;
    ofstream archivoTemporal;

    archivo.open("alumnos.txt", ios::in);
    archivoTemporal.open("temporal.txt", ios::out);

     if (archivo.fail() || archivoTemporal.fail())
    {
        cout << "\nHa sucedido algun problema con algun archivo\n";
    }
    else
    {
        /* Todo va bien de momento con los archivos si llegamos aqui*/
        if (codeEliminar == 0)
        {
            /* Si entro a esta condicion significa que no encontre ningun codigo. Entonces no puedo eliminar nada */
            cout << "\nPara eliminar un alumno necesito que este en la base de datos primero\n";
            system("pause");

            archivo.close();
            archivoTemporal.close();
            return 0;
        }
        else
        {
            while (!archivo.eof())
            {
                /* Empiezo a leer el archivo alumnos.txt */
            archivo >> registro.codigo >> registro.nombre >> registro.apellido1 >> registro.apellido2 >> registro.asignatura >> registro.nota_1 >> registro.nota_2 >> registro.nota_3 >> registro.nota_final;

            

            if (registro.codigo == codeEliminar)
                {
                    /* No hago guardo nada en esa linea */
                }

            if (registro.codigo != codeEliminar)
                {
                    if (firstLineReaded)
                        archivoTemporal << endl;

                    archivoTemporal << registro.codigo << ' ' << registro.nombre << ' ' << registro.apellido1 << ' ' << registro.apellido2 << ' ' << registro.asignatura << ' ' << registro.nota_1 << ' ' << registro.nota_2 << ' ' << registro.nota_3 << ' ' << registro.nota_final;
                }

            /* Ya se que he leido la primera linea del documento y empiezo a agregar saltos de linea */
            firstLineReaded = true;
            }
        }
    }
    archivo.close();
    archivoTemporal.close();

    /* Elimino el archivo antiguo y renombro el nuevo para actualizar de manera manual */
    remove("alumnos.txt");
    rename("temporal.txt", "alumnos.txt");
    return 1;
}