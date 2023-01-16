//https://learn.microsoft.com/es-es/cpp/cpp/enumerations-cpp?view=msvc-170
#include <iostream>
using namespace std;

int main(){
    /*Esto sirve por ejemplo para hacer listado de menus y jugar con switch*/
    enum color{Rojo, Azul, Verde};
    // string arrColor[3]={"Rojo","Azul","Verde"}; ¿Que diferencia hay?

    int stock[3]={10, 20, 30};
    cout<<"valor de rojo: "<<Rojo<<endl;
    cout<<"valor de azul: "<<Azul<<endl;
    cout<<"valor de verde: "<<Verde<<endl;
    cout<<"Stock de rojo: "<<stock[Rojo]<<endl;

    system("pause");
    return 0;
}