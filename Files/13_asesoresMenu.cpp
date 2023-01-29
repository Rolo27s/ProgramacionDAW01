/* Programa con menu que facilita el uso del arhivo asesoria.txt */
/* El menu tendrá la siguiente forma: */
/*
    |---------------------------|
    | Menu principal - Asesoria |
    |---------------------------|
    | 1. Visualizar documento   |
    | 2. Buscar asesor          |
    | 3. Agregar asesor         |
    | 4. Modificar asesor       |
    | 5. Eliminar asesor        |
    | 6. Cerrar el programa     |
    |---------------------------|

        cout << "| ---------------------------------------- |\n";
        cout << "|       Menu principal - Asesoria          |\n";
        cout << "| ---------------------------------------- |\n";
        cout << "| 1. Visualizar documento                  |\n";
        cout << "| 2. Buscar asesor                         |\n";
        cout << "| 3. Agregar asesor                        |\n";
        cout << "| 4. Modificar asesor                      |\n";
        cout << "| 5. Eliminar asesor                       |\n";
        cout << "| 6. Cerrar el programa                    |\n";
        cout << "| ---------------------------------------- |\n";
*/
/*  El archivo asesoria.txt contiene n registros de 7 campos.
    Los campos son los siguientes:
        codigo INT (4 digitos obligatorio) PRIMARY KEY,
        Nombre VARCHAR(20),
        Apellidos VARCHAR(25),
        Ciudad VARCHAR(15),
        edad INT( 18 - 80),
        genero ENUM ('M', 'F') (10),
        consulta VARCHAR(20)
    El separador de cada campo es un espacio en blanco.
    No se permite el uso del espacio en blanco en un campo (controlar)
    (En caso de necesidad se usará en su lugar un punto ".")

    Para una visualizacion limpia controlar la longitud de cada campo.
        Si miden distinto, rellenar hasta su máximo permitido con espacios,
        de tal manera que se vean siempre las columnas definidas.
 */

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <locale.h>
#include <wchar.h>
#include <windows.h>
#include <string>
/* rename, remove */
#include <cstdio>
using namespace std;

/*---------------------------------------------------------------------*/
/* VARIABLES_GLOBALES */
/*---------------------------------------------------------------------*/
struct registro
{
    int codigo;
    string nombre;
    string apellido;
    string ciudad;
    int edad;
    /* A la hora de agregar genero será interesante que el usuario eliga 'M' o 'F'
    y se guarde en memoria "Masculino" o "Femenino" */
    string genero;
    string consulta;
};

// Mi registro tendrá una capacidad máxima de N
const int N = 100;
registro asesor[N];

int codigoAux;

/*---------------------------------------------------------------------*/
/* FUNCIONES_DECLARACION */
/*---------------------------------------------------------------------*/
/* La funcion info es vital para el uso del programa. */
int info(void);
void verInfo(void);
/* La funcion buscar será metodo de agregar, modificar y eliminar.
El retorno será el codigo buscado y en caso de que no lo encuentre devolverá 0 */
int buscar(void);
void agregar(void);
void modificar(void);
void eliminar(void);
/*---------------------------------------------------------------------*/
/* PROCEDIMIENTOS_DECLARACION */
/*---------------------------------------------------------------------*/

/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/
/* FUNCION_MAIN */
/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/
int main()
{
    setlocale(LC_ALL, "");
    char repetir = 'N';
    int opc;
    do
    {
        system("cls");
        cout << "| ---------------------------------------- |\n";
        cout << "|       Menu principal - Asesoria          |\n";
        cout << "| ---------------------------------------- |\n";
        cout << "| 1. Visualizar documento                  |\n";
        cout << "| 2. Buscar asesor                         |\n";
        cout << "| 3. Agregar asesor                        |\n";
        cout << "| 4. Modificar asesor                      |\n";
        cout << "| 5. Eliminar asesor                       |\n";
        cout << "| 6. Cerrar el programa                    |\n";
        cout << "| ---------------------------------------- |\n";

        cout << "\n\tElige una opcion: ";
        cin >> opc;
        while (opc < 1 || opc > 6)
        {
            Sleep(250);
            cout << "\nOpcion incorrecta...\nEliga una opcion [1-6]: ";
            cin >> opc;
            Sleep(250);
        }

        switch (opc)
        {
        case 1:
            verInfo();
            break;
        case 2:
            buscar();
            break;
        case 3:
            agregar();
            break;
        case 4:
            modificar();
            break;
        case 5:
            eliminar();
            break;
        case 6:
            repetir = 'N';
            break;
        default:
            break;
        }

        if (opc != 6)
        {
            cout << "\n\tQuiere volver al menu principal? (S/N): ";
            cin >> repetir;

            while (repetir != 'S' && repetir != 's' && repetir != 'N' && repetir != 'n')
            {
                Sleep(250);
                cout << "\nOpcion incorrecta...\nEliga una opcion [S/N]: ";
                cin >> repetir;
                Sleep(250);
            }
        }

    } while (repetir == 'S' || repetir == 's');
    cout << "\n\tCerrando el programa...\n";
    Sleep(1000);
    return 0;
}
/*---------------------------------------------------------------------*/
/* FUNCIONES_DEFINICION */
/*---------------------------------------------------------------------*/
/* La funcion info se encarga de leer el archivo asesoria.txt y guardar toda la información en una estructura para el futuro uso de la misma. Siempre se ejecutará al principio de cada funcion obligatoriamente para tener los datos actualizados. Devuelve el numero de registros guardados*/
int info(void)
{
    /* vble i encargada de guardar la informacion leida en el lugar correcto de mi estructura. Aumentará de valor dentro del bucle while. */
    int i = 0;
    ifstream archivo;
    archivo.open("asesoria.txt", ios ::in);

    if (archivo.fail())
    {
        cout << "\n\tHa ocurrido un problema con el archivo\n\n";
    }
    else
    {
        while (!archivo.eof())
        {
            archivo >> asesor[i].codigo >> asesor[i].nombre >> asesor[i].apellido >> asesor[i].ciudad >> asesor[i].edad >> asesor[i].genero >> asesor[i].consulta;

            /* paso al siguiente registro. (i = numero de registros) */
            i++;
        }
        archivo.close();
    }
    return i;
}

/* Muestra por pantalla la informacion actual del fichero asesoria.txt */
void verInfo(void)
{
    system("cls");
    /* retorno de la funcion info que es el numero de filas del archivo asesoria.txt.
    Al usar la funcion info() para inicializar una variable ya la estoy ejecutando. Entonces ya tendría toda la informacion disponible actualizada. */
    int numRow = info();
    const int N = 7;
    string campo[N] = {"codigo", "nombre", "apellido", "ciudad", "edad", "genero", "consulta"};
    int posInicioCampo[N + 1] = {0, 8, 30, 58, 76, 85, 98, 120};
    string linea = "";

    cout << "\n\t1. Visualizar documento\n\n";

    for (int i = 0; i < N; i++)
    {
        linea += campo[i];
        while (linea.length() < posInicioCampo[i + 1])
            linea += " ";
    }
    cout << linea << endl;
    cout << "------------------------------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < numRow; i++)
    {
        /* Reseteo la linea para dar formato a cada asesor. El metodo to_string es de la libreria <string> */
        linea = "";
        campo[0] = to_string(asesor[i].codigo);
        campo[1] = asesor[i].nombre;
        campo[2] = asesor[i].apellido;
        campo[3] = asesor[i].ciudad;
        campo[4] = to_string(asesor[i].edad);
        campo[5] = asesor[i].genero;
        campo[6] = asesor[i].consulta;

        for (int i = 0; i < N; i++)
        {
            linea += campo[i];
            while (linea.length() < posInicioCampo[i + 1])
                linea += " ";
        }
        cout << linea << endl;
        Sleep(100);
    }
    cout << "\n\t --- Fin de visualizacion del documento ---\n";
    cout << endl;
}

/* funcion que busca un codigo de un asesor dentro del archivo asesor.txt */
int buscar(void)
{
    system("cls");
    /* Siempre ejecuto la funcion info para actualizar la estructura */
    int numRow = info();
    int codigoBuscar;

    cout << "\nIntroduce el codigo del asesor: ";
    cin >> codigoBuscar;

    for (int i = 0; i < numRow; i++)
    {
        if (asesor[i].codigo == codigoBuscar)
        {
            cout << "\nCodigo " << codigoBuscar << " encontrado!\n\n";
            cout << "nombre: " << asesor[i].nombre << endl;
            cout << "apellido: " << asesor[i].apellido << endl;
            cout << "ciudad: " << asesor[i].ciudad << endl;
            cout << "edad: " << asesor[i].edad << endl;
            cout << "genero: " << asesor[i].genero << endl;
            cout << "consulta: " << asesor[i].consulta << endl;

            codigoAux = codigoBuscar;
            return codigoBuscar;
        }
    }
    Sleep(500);
    cout << "\n\n\tCodigo " << codigoBuscar << " no encontrado...\n\n";
    codigoAux = codigoBuscar;
    return 0;
}

/*funcion de agregar asesor. compruebo si existe el codigo para respetar el PRIMARY KEY*/
void agregar(void)
{
    system("cls");
    /* Siempre ejecuto la funcion info para actualizar la estructura */
    int numRow = info();
    int codigoEncontrado = buscar();
    string campoAgregar;
    int edadAgregar;

    if (codigoEncontrado == 0 && (codigoAux >= 1000 && codigoAux <= 9999))
    {
        cout << "\nAGREGANDO NUEVO ASESOR...\n\n";
        fstream archivo;
        archivo.open("asesoria.txt", ios ::app);

        if (archivo.fail())
        {
            cout << "\nHa habido algun problema con el archivo\n";
        }
        else
        {
            archivo << endl;
            archivo << codigoAux << " ";

            cout << "\nIngrese nombre: ";
            cin >> campoAgregar;
            archivo << campoAgregar << " ";

            cout << "Ingrese apellido: ";
            cin >> campoAgregar;
            archivo << campoAgregar << " ";

            cout << "Ingrese ciudad: ";
            cin >> campoAgregar;
            archivo << campoAgregar << " ";

            cout << "Ingrese edad: ";
            cin >> edadAgregar;
            archivo << edadAgregar << " ";

            cout << "Ingrese genero: ";
            cin >> campoAgregar;
            archivo << campoAgregar << " ";

            cout << "Ingrese consulta: ";
            cin >> campoAgregar;
            archivo << campoAgregar;
        }
        archivo.close();
    }
    else
    {
        cout << "\nERROR\n1. El codigo se encontro y no puede ser agregado otro codigo con el mismo valor\n2.  el codigo no se encontro pero se sale del rango [1000-9999]\n";
    }
}

void modificar(void)
{
    system("cls");
    /* Siempre ejecuto la funcion info para actualizar la estructura */
    int numRow = info();
    /* Si codigoEncontrado vale 0, no puedo modificar nada porque no encontre nada.
    Si codigoEncontrado es diferente de 0, tengo el valor del codigo que tengo que modificar */
    string nombreTemp, apellidoTemp, ciudadTemp, edadTemp, generoTemp, consultaTemp;
    int codigoEncontrado = buscar();
    if (codigoEncontrado != 0)
    {
        for (int i = 0; i < numRow; i++)
        {
            if (codigoEncontrado == asesor[i].codigo)
            {
                cout << "\n\nModificando asesor\n";
                cout << "Si no desea modificar el campo ingrese cualquier letra. SOLO 1 CARACTER.\n\n";

                cout << "Nombre: ";
                cin >> nombreTemp;
                if (nombreTemp.length() > 1)
                    asesor[i].nombre = nombreTemp;

                cout << "Apellido: ";
                cin >> apellidoTemp;
                if (apellidoTemp.length() > 1)
                    asesor[i].apellido = apellidoTemp;

                cout << "Ciudad: ";
                cin >> ciudadTemp;
                if (ciudadTemp.length() > 1)
                    asesor[i].ciudad = ciudadTemp;

                cout << "edad: ";
                cin >> edadTemp;
                if (edadTemp.length() > 1)
                    asesor[i].edad = stoi(edadTemp);

                cout << "Genero: ";
                cin >> generoTemp;
                if (generoTemp.length() > 1)
                    asesor[i].genero = generoTemp;

                cout << "Consulta: ";
                cin >> consultaTemp;
                if (consultaTemp.length() > 1)
                    asesor[i].consulta = consultaTemp;
            }
        }
        rename("asesoria.txt", "asesoria_antiguo.txt");
        ofstream archivo;
        archivo.open("asesoria.txt", ios::out);
        if (archivo.fail())
        {
            cout << "\nHa sucedido algun error con el archivo\n";
        }
        else
        {
            for (int i = 0; i < numRow; i++)
            {
                if (i < numRow - 1)
                {
                    archivo << asesor[i].codigo;
                    archivo << " ";
                    archivo << asesor[i].nombre;
                    archivo << " ";
                    archivo << asesor[i].apellido;
                    archivo << " ";
                    archivo << asesor[i].ciudad;
                    archivo << " ";
                    archivo << asesor[i].edad;
                    archivo << " ";
                    archivo << asesor[i].genero;
                    archivo << " ";
                    archivo << asesor[i].consulta;
                    archivo << endl;
                }
                else
                {
                    archivo << asesor[i].codigo;
                    archivo << " ";
                    archivo << asesor[i].nombre;
                    archivo << " ";
                    archivo << asesor[i].apellido;
                    archivo << " ";
                    archivo << asesor[i].ciudad;
                    archivo << " ";
                    archivo << asesor[i].edad;
                    archivo << " ";
                    archivo << asesor[i].genero;
                    archivo << " ";
                    archivo << asesor[i].consulta;
                }
            }
        }
        archivo.close();
    }
}

/* funcion eliminar registro */
void eliminar(void)
{
    system("cls");
    /* Siempre ejecuto la funcion info para actualizar la estructura */
    int numRow = info();
    /* Si codigoEncontrado vale 0, no puedo modificar nada porque no encontre nada.
    Si codigoEncontrado es diferente de 0, tengo el valor del codigo que tengo que modificar */
    int codigoEncontrado = buscar();
    if (codigoEncontrado != 0)
    {
        rename("asesoria.txt", "asesoria_antiguo.txt");
        ofstream archivo;
        archivo.open("asesoria.txt", ios ::out);
        if (archivo.fail())
        {
            cout << "\nHa ocurrido algun error con el archivo\n\n";
        }
        else
        {
            for (int i = 0; i < numRow; i++)
            {
                if (codigoAux == asesor[i].codigo)
                {
                    /* No hago nada y no guardo la informacion en el archivo nuevo. En el documento esta perfecto. En mi programa dejo en blanco esos campos en la estructura */
                    asesor[i].codigo = 0;
                    asesor[i].nombre = "";
                    asesor[i].apellido = "";
                    asesor[i].ciudad = "";
                    asesor[i].edad = 0;
                    asesor[i].genero = "";
                    asesor[i].consulta = "";
                }
                else if (codigoAux != asesor[i].codigo && i < (numRow - 1))
                {
                    archivo << asesor[i].codigo;
                    archivo << " ";
                    archivo << asesor[i].nombre;
                    archivo << " ";
                    archivo << asesor[i].apellido;
                    archivo << " ";
                    archivo << asesor[i].ciudad;
                    archivo << " ";
                    archivo << asesor[i].edad;
                    archivo << " ";
                    archivo << asesor[i].genero;
                    archivo << " ";
                    archivo << asesor[i].consulta;
                    archivo << endl;
                }
                else if (codigoAux != asesor[i].codigo && i < (numRow))
                {
                    archivo << asesor[i].codigo;
                    archivo << " ";
                    archivo << asesor[i].nombre;
                    archivo << " ";
                    archivo << asesor[i].apellido;
                    archivo << " ";
                    archivo << asesor[i].ciudad;
                    archivo << " ";
                    archivo << asesor[i].edad;
                    archivo << " ";
                    archivo << asesor[i].genero;
                    archivo << " ";
                    archivo << asesor[i].consulta;
                }
            }
        }
        archivo.close();
    }
    else
    {
        /* CODIGO NO ENCONTRADO. SALIENDO DEL PROGRAMA. */
    }
}
/*---------------------------------------------------------------------*/
/* PROCEDIMIENTOS_DEFINICION */
/*---------------------------------------------------------------------*/