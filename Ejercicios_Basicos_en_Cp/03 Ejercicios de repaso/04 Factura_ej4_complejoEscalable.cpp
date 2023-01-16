//Programa de factura - Ejercicio 4
#include <iostream>
#include <string.h>

using namespace std;

struct datos{
    string codArt;  //Codigo del articulo
    string descr;   //Descripcion del articulo
    float precio;   //Precio del artículo
    int cant;       //Cantidad de compra
    int formaPago;  //Forma de pago 1.Efectivo 2.Cheque 3.Tarjeta
};

datos capturaDatos(datos &info);
int comprobarNum(int a);
string comprobarPago(datos &info);
void imprimirDatos(datos info2);
void comprobarCHAR(string &letra);

int main(){
    string opcion;
    datos info;

    info.formaPago=0;
    
    do{
        capturaDatos(info);
        imprimirDatos(info);
        cout<<"Desea procesar otra compra: S o N  ";
        comprobarCHAR(opcion);
    }while(opcion=="s"||opcion=="S");
    
    return 0;
}

datos capturaDatos(datos &info){ //captura de datos
    cout<<"Programa que calcula el total a pagar de una factura!\n"<<endl;
    cout<<"---------------------------------------------\n"<<endl;
    cout<<"Captura y validacion de datos...\n"<<endl;
    cout<<"Digite el codigo del articulo: ";
    cin>>info.codArt;
    cout<<""<<endl;

    cout<<"Ingrese la descripcion del articulo: ";
    cin>>info.descr;
    cout<<""<<endl;

    cout<<"Digite el precio del articulo: ";
    cin>>info.precio;
    info.precio = comprobarNum(info.precio);
    cout<<""<<endl;

    cout<<"Ingrese la cantidad de compra: ";
    cin>>info.cant;
    info.cant = comprobarNum(info.cant);
    cout<<""<<endl;

    cout<<"Digite el numero de forma de pago: 1.Efectivo 2.Cheque 3.Tarjeta: ";
    comprobarPago(info);
    cout<<""<<endl;

    cout<<"Calculando el total a pagar...\n\n";
    return info;
}

int comprobarNum(int a){ // comprobar numero para que sea mayor a 0
    while(a<=0){
        cout<<"Error... Ingrese nuevamente el valor: ";
        cin>>a;
    }
    return a;
}

string comprobarPago(datos &info){ // comprobar el pago
    
    if (info.formaPago!=0){
        if(info.formaPago == 1){
            return "Efectivo";
        }else if(info.formaPago == 2){
            return "Cheque";
        }else{
            return "Tarjeta";
        }
    }

    do{
        cin>>info.formaPago;
        if(info.formaPago !=1 && info.formaPago !=2 && info.formaPago !=3){
            cout<<"Opcion erronea. Introduzca otra vez forma de pago: 1.Efectivo 2.Cheque 3.Tarjeta: ";
        }
    }while(info.formaPago !=1 && info.formaPago !=2 && info.formaPago !=3);

}

void imprimirDatos(datos info2){ // imprimir la informacion
    float totalini = info2.cant*info2.precio;

    cout<<"\t\tImprimir datos y resultados\t\t\n";
    cout<<"-----------------------------------------------\n";
    cout<<"Codigo del articulo: \t\t"<<info2.codArt<<endl;
    cout<<"Descripcion del articulo: \t"<<info2.descr<<endl;
    cout<<"Precio del articulo: \t\t"<<info2.precio<<endl; //notacion cientifica
    cout<<"Cantidad de compra: \t\t"<<info2.cant<<endl;
    cout<<"Total de venta: \t\t"<<totalini<<endl; //Ver como devolver numeros en notacion cientifica
    cout<<"Forma de pago: \t\t\t"<<comprobarPago(info2)<<endl;
    switch (info2.formaPago)
    {
    case 1:
        cout<<"Descuento aplicado: \t\t"<<totalini*0.1<<endl;
        cout<<"Valor a pagar: \t\t\t"<<totalini-totalini*0.1<<endl;
        break;
    case 2:
        cout<<"Descuento aplicado: \t\t"<<totalini*0.1*0.05<<endl;
        cout<<"Valor a pagar: \t\t"<<totalini-totalini*0.05<<endl;
        break;
    case 3:
        cout<<"Descuento aplicado: \t\t"<<"0"<<endl;
        cout<<"Valor a pagar: \t\t"<<totalini<<endl;
        break;
    default:
        break;
    }
}

void comprobarCHAR(string &letra){ // comprobar la repeticion
    do{
        cin>>letra;
        if(letra!="s"&&letra!="S"&&letra!="n"&&letra!="N"){
            cout<<"Opcion erronea, introduzca otra vez S o N: ";
        }
    }while(letra!="s"&&letra!="S"&&letra!="n"&&letra!="N");
}