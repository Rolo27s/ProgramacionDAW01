#include <stdlib.h> // Para el uso de system
#include <iostream>
#include <string.h> // Controla cadena de caracteres
using namespace std;

// Convertir numero de sistema decimal a hexadecimal
const int N=12;      // Pasaremos 12 numeros con N = 12
const int BASE=16;  // Base 16 para el problema actual
const string listaHexa[BASE] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};

int comprobarNum(int a);
string decimalToHexadecimal(int d, string &h);
// Uso string y no char por si el usuario se equivoca metiendo varios caracteres.
string comprobarRepetir(string c);      

int main(){
    int nDecimal[N];
    string nHexa[N], repetir;

    do{
        system("cls");
        cout<<"Programa que convierte un numero del sistema decimal a hexadecimal!\n";
        cout<<"-------------------------------------------------------------------\n\n";
        cout<<"Digitaremos numeros naturales del sistema decimal... \n";
        for(int i = 0; i < N; i++){
            cout<<"Introduce numero natural ("<<i+1<<"/"<<N<<") :";
            cin>>nDecimal[i];
            //Nos aseguramos que el datos introducido sea válido.
            nDecimal[i] = comprobarNum(nDecimal[i]); 
        }
        
        cout<<endl;
        cout<<endl;

        // Una vez tenemos los datos, los imprimimos por pantalla
        cout<<"Dato\t\tDecimal\t\tHexadecimal\n";
        cout<<"----\t\t-------\t\t-----------\n";
        for(int i = 0; i < N; i++){
            nHexa[i] = decimalToHexadecimal(nDecimal[i], nHexa[i]);
            cout<<i+1<<"\t\t"<<nDecimal[i]<<"\t\t"<< nHexa[i] <<"\n";
        }

        cout<<endl;
        cout<<endl;   

        cout<<"Desea convertir otro grupo de numeros: S o N  \t";
        cin>>repetir;
        // Nos aseguramos que el datos introducido sea válido.
        repetir = comprobarRepetir(repetir);            
        
        // Reseteo el array hexadecimal
        for(int i = 0; i < N; i++) nHexa[i] = "";

    }while(repetir == "S" || repetir == "s");
    return 0;
}

//Convierto el numero Decimal a numero Hexadecimal.
// Idea de Marco: h = listaHexa[d % BASE] + h;
string decimalToHexadecimal(int d, string &h){
        if(d >= 1)
        {
            h = listaHexa[d % BASE] + h;
            
        d = d / BASE;
        // Recursividad
        decimalToHexadecimal(d, h); 
        }
            return h;
}

/*   <-- CONTROL DE INPUTS -->   */
//Controla que nDecimal sea mayor o igual a 0.
int comprobarNum(int a){
    while(a < 0){
        cout<<"\n\tNumero erroneo. Introduce un valor mayor o igual a 0: ";
        cin>>a;
    }
    return a;
}
//Compruebo que se teclee 'S', 's', 'N', 'n'.
string comprobarRepetir(string c){
    while(c != "S" && c != "s" && c != "N" && c != "n"){
        cout<<"\nOpcion erronea...\n";
        cout<<"Desea realizar otra conversion: S o N   ";
        cin>>c;
    }
    return c;
}