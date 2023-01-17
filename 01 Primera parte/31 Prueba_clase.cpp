#include <iostream>
#include <string>
using namespace std;

class Alumno{
    public:
    int id;
    string nombre;
    int notaPractica;
    int notaTeoria;
    int notaParticipacion;
};

int main(){
    int nAlu=0;
    Alumno alumno;

    cout<<"Numero de alumnos: ";
    cin>>nAlu;

    //for(int i=1;i<=nAlu;i++){
        alumno.id = 1;
        cout<<"Nombre del alumno:";
            cin>>alumno.nombre;
        cout<<"Nota de practica:";
            cin>>alumno.notaPractica;
        cout<<"Nota de teoria:";
            cin>>alumno.notaTeoria;
        cout<<"Nota de participacion:";
            cin>>alumno.notaParticipacion;
    //}

    return 0;
}