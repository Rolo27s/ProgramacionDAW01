/* Como novedad usaremos para resolver el problema la herramienta substr de la libreria string.h
Ejemplo de uso:
    string str1 = "Apples are red";
    string str2 = str1.substr(11, 3);
    El primer dígito marca la posicion de inicio del substring y el segundo la longitud a partir de ahí y contando esa misma)
 */

/* ENCODING USED: windows-1252 to solve special characters*/
#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <fstream>
#include <string.h>
using namespace std;

const int N = 10; // Mi listado tendra de momento 10 registros

struct user{
    string id;
    string nombre;
    string apellido;
    string ciudad;
    string edad;
    string genero;
    string consulta;
};

user registro [N];

float comprobarNum(float a);
char comprobarChar(char c);
void leerGuardar();
/* Console log de manera manual (comentado por defecto) */
/* void consoleLogCpp(); */
void buscarId(string code);

int main(){
    setlocale(LC_ALL, "");
    char again;
    string idCode;

    do{
        system ("cls");

        leerGuardar();
        
        cout << "\n Que id quieres buscar: ";
        cin >> idCode;
        buscarId(idCode);

        /* Un pequeño console log rudimentario para comprobar info (por defecto comentado) */
        /* consoleLogCpp(); */

        cout << "\nDesea procesar nuevamente: S o N:";
        cin >> again;
        again = comprobarChar(again);
    }while(again == 'S' || again == 's');
    return 0;
}

// Comprueba si el char es S, S, N o n para un correcto funcionamiento del programa.
char comprobarChar(char c){
    while(c != 'S' && c != 's' && c != 'N' && c != 'n'){
            cout << "Opcion incorrecta\n";
            cout << "Elige (S/N): ";
            cin >> c;
        }
    return c;
}

// Funcion que comprueba que el número introducido sea mayor a 0 para el uso correcto del programa
float comprobarNum(float a){
    while(a <= 0){
        cout << "Opcion incorrecta\n";
        cout << "Introduce valor: ";
        cin >> a;
    }
    return a;
}
    
//Funcion que lee el archivo asesoria.txt y guarda informacion del mismo en programa
void leerGuardar(){
    ifstream archivo;
    string nombreArchivo = "asesoria.txt", texto, subString;
    int infoid, tamanoFrase, spaceCount = 0, marker=0, rowCount=0;

    archivo.open(nombreArchivo.c_str(), ios::in);

    if(archivo.fail()){
        cout << "No se encontro el archivo " << nombreArchivo << endl;
    }else {
        /* eof (end of file). El while estará activo hasta el final del archivo */
        while(!archivo.eof()){
            /* Leemos la primera linea de texto y la guardamos en el string texto */
            getline(archivo, texto);
            
            /* Controlo el tamaño de la frase */
            tamanoFrase = texto.length();
            
            for (int i = 0; i < tamanoFrase; i++){
                if (texto[i] == ' '){
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
                    marker = i+1;
                }
                /* Uso este else if porque en este punto del código ya tengo el contador y el marcador actualizado y puedo reaccionar a partir del ultimo espacio */
                else if(spaceCount == 6){
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
}

/* Funcion que enseña por pantalla información sobre la estructura */
/* void consoleLogCpp(){
    cout << "\t\n\nPrograma que lee " << N << " registros y genera el archivo de salida informe.txt\n";
    cout << "\t-------------------------------------------------------------------------------\n\n";
    cout << "\t\t Datos de los registros de crédito\n";
    cout << "\t\t-----------------------------------\n\n";

    cout << "Nit." << "\t  Nombres  " << "\t  Apellidos  " << "\tCiudad" << "\tEdad " << " \tGenero " << "\tConsulta\n";
    cout << "----" << "\t  -------  " << "\t  ---------  " << "\t------"<< " \t---- " << " \t------ " << "\t---------\n";
    for(int i=0; i < N; i++){
        cout << registro[i].id << "\t"<<registro[i].nombre << "\t"<<registro[i].apellido << "\t"<<registro[i].ciudad << "\t"<<registro[i].edad << "\t"<<registro[i].genero << "\t\t"<<registro[i].consulta;
        cout << endl;
    }
    cout << "----" << "\t  -------  " << "\t  ---------  " << "\t------"<< " \t---- " << " \t------ " << "\t---------\n\n";
} */

/* Busca el id que pasa por referencia el usuario */
void buscarId(string code){
    bool codeOK = 0;
    for (int i = 0; i < N; i++){
        if (registro[i].id == code){
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
    if (codeOK == 0) cout << "\nId no registrada...\n";
}