/*
ENUNCIADO DEL EJERCICIO 10
Escriba, compile y ejecute un programa en C++ que aplique funciones de
usuario para el cálculo del punto de equilibrio en unidades y pesos para 22
productos, los datos ingresados por teclado son: código, costo fijo, costo
unitario y precio de venta. 
Aplique la fórmula 
peu = costo fijo / (precio venta – costo unitario) y 
pe$ = peu * precio de venta, donde peu es el punto de
equilibrio en unidades y pe$ el punto de equilibrio en pesos.
*/

//Controla cantidad de numeros a mostrar con la funcion setprecision().
// cout << setprecision(10);       respeta 10 digitos de la parte entera
// cout << fixed << setprecision(2); respeta 2 digitos de la parte decimal
#include <iomanip>

#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h> // Libreria necesaria para el uso de comandos tipo system
using namespace std;

const int N_PRODUCTOS=22; //El grupo de productos tendrá 22 N_PRODUCTOS en este caso.

struct infoProducto{
    int id;
    int code;
    double costoFijo;
    float costoUnitario;
    float precioVenta;
    float equilibrioUd;
    double equilibrioPesos;
};
 infoProducto lista_productos[N_PRODUCTOS]; //Cada grupo tendrá "N_PRODUCTOS" definido como constante arriba en el codigo.

void insertarInfo(int n);
float comprobarNum(float a);
string comprobarCHAR(string letra);
void verInfo(int n);

int main(){
    string opcion;
    //Contador usado para saber cuantos productos hemos registrado. Tambien sirve para acceder correctamente a la estructura y salir del bucle de ingresar datos.
    int cont = 0; 
    
    do{
        system("cls"); //Primero limpio la pantalla para cuando el programa quiera generar otro grupo nuevo.
        cout<<"Programa que calcula el punto de equilibrio de produccion!\n";
        cout<<"--------------------------------------------------------------------\n\n";
        //En este apartado introducimos toda la informacion de un grupo de PRODUCTOS.
        do{
            cout<<"\nInsertando informacion de producto ("<<cont+1<<"/"<<N_PRODUCTOS<<")...\n";
            insertarInfo(cont);
            cont++;
        }while(cont < N_PRODUCTOS);

        //Cuando pare de procesar productos, que muestre el listado de la informacion recopilada
        verInfo(N_PRODUCTOS);
        //Desea procesar otro grupo¿? Si si, vuelve a empezar, si no, sale del programa.
        cout<<"\nDesea procesar otro grupo de productos: S o N  ";
        cin>>opcion;
        opcion = comprobarCHAR(opcion); //Llama a la funcion comprobar Char
        cont = 0; //Reseteo el contador para empezar a sobreescribir informacion y generar otro nuevo grupo, si fuera necesario.
    }while(opcion == "S" || opcion == "s");

    return 0;
}

//Comprueba que el numero sea mayor o igual a 0 para el buen funcionamiento del programa
float comprobarNum(float a){
    while(a <= 0){
        cout<<"Error... Ingrese nuevamente el valor: ";
        cin>>a;
    }
    return a;
}

//Defines los valores de un producto
void insertarInfo(int n){
    //Genera automaticamente el Nº caso
    lista_productos[n].id = n+1;
    
    cout<<"Codigo de producto: ";
    cin>>lista_productos[n].code;
    
    cout<<"Costo fijo: ";
    cin>>lista_productos[n].costoFijo;
    lista_productos[n].costoFijo = comprobarNum(lista_productos[n].costoFijo); // Llamamos a la funcion para controlar costoFijo.
    
    cout<<"Costo unitario: ";
    cin>>lista_productos[n].costoUnitario;
    lista_productos[n].costoUnitario = comprobarNum(lista_productos[n].costoUnitario); // Llamamos a la funcion para controlar costoUnitario.
   
    cout<<"Precio venta: ";
    cin>>lista_productos[n].precioVenta;
    lista_productos[n].precioVenta = comprobarNum(lista_productos[n].precioVenta); // Llamamos a la funcion para controlar PrecioVenta.
    
    //Formula para sacar el equilibrio unidades: peu = costo fijo / (precio venta – costo unitario)
    lista_productos[n].equilibrioUd = lista_productos[n].costoFijo / (lista_productos[n].precioVenta - lista_productos[n].costoUnitario); 
    
    //Formula para sacar el equilibrio en pesos: pe$ = peu * precio de venta
    lista_productos[n].equilibrioPesos = lista_productos[n].equilibrioUd * lista_productos[n].precioVenta;
    cout<<"---------------------------------------------------------\n\n";
}

//Esta funcion imprime por pantalla toda la informacion de un grupo de productos.
void verInfo(int n){
    cout<<"---------------------------------------\n";
    cout<<"No.  \tCodigo de     \tCosto    \tCosto       \tPrecio    \tEquilibrio    \tEquilibrio\n";
    cout<<"caso.\tProducto      \tFijo     \tUnitario    \tVenta     \tUnidades      \ten pesos  \n";
    cout<<"---- \t-----------   \t---------\t----------  \t-------   \t------------  \t----------\n";
    cout << setprecision(10);
        for(int i = 0; i < n ; i++){
            //Imprimo por pantalla los registros de los N_PRODUCTOS
            cout<<lista_productos[i].id<<"\t"<<lista_productos[i].code<<"\t\t"<<lista_productos[i].costoFijo<<"\t"<<lista_productos[i].costoUnitario<<"\t\t"<<lista_productos[i].precioVenta<<"\t\t"<<lista_productos[i].equilibrioUd<<"\t"<<"\t"<<lista_productos[i].equilibrioPesos;
            cout<<endl;
        }
    cout<<"---- \t-----------   \t---------\t----------  \t-------   \t------------  \t----------\n\n\n";

}

//Comprueba para procesar otro grupo y que solo se usen 4 caracteres ('S', 's', 'N', 'n')
string comprobarCHAR(string letra){
    do{
        if(letra != "s" && letra != "S" && letra != "n" && letra != "N"){
            cout<<"Opcion erronea, introduzca otra vez S o N: ";
            cin>>letra;
        }
    }while(letra != "s" && letra != "S" && letra != "n" && letra != "N");
    return letra;
}