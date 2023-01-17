#include <iostream>
using namespace std;
//PROGRAMA SOLUCION EXAMEN PRIMEROS CONOCIMIENTOS C++
int main(){
    float kg_manzana_stock=1000, kg_pera_stock=1500, kg_platano_stock=2000, kg_fresa_stock=5000, kg_sandia_stock=500,  kg_venta=0;
    float precio_manzana=2.50, precio_pera=1.75, precio_platano=1.55, precio_fresa=2.70, precio_sandia=1.25, caja=0.0;
    int opcion=0, op_fruta=0;
    char repetir='Y';

    while(repetir == 'Y' || repetir == 'y'){
        cout<<"--- Menu de control de ALMACEN DE FRUTAS ---\n";
        cout<<"    (1) Vender fruta\n"; // Indicar en el menu cuanta fruta se vendio y cuanto se ingreso por esa venta.
        cout<<"    (2) Consultar caja\n"; //Asumimos que comenzamos un nuevo ciclo y la caja empieza a cero.
        cout<<"    (3) Reponer stock de almacen\n"; //Desvinculado con caja. Reponemos a traves de una cuenta ajena no controlada en este programa.
        cout<<"    (4) Consultar stock actual\n";
        cout<<"    (5) Editar precios\n\n";

        cout<<"Elige una opcion: ";
        cin>>opcion;
        cout<<endl;
        while(opcion<1||opcion>5){
            cout<<"Opcion erronea, elige una opcion correcta: ";
            cin>>opcion;
            cout<<endl;
        }
        switch(opcion){
            case 1:
                cout<<"Que fruta vas a vender?: \n";
                cout<<"    (1) Manzana\n";
                cout<<"    (2) Pera\n";
                cout<<"    (3) Platano\n";
                cout<<"    (4) Fresa\n";
                cout<<"    (5) Sandia\n\n";
                cin>>op_fruta;
                while(op_fruta<1||op_fruta>5){
                    cout<<"Opcion erronea, elige una opcion correcta: ";
                    cin>>op_fruta;
                    cout<<endl;
                    }
                switch(op_fruta){
                    case 1:
                        cout<<"Vas a vender manzanas. Cuantos Kg?: ";
                        cin>>kg_venta;
                        if(kg_venta <= kg_manzana_stock){
                            kg_manzana_stock-=kg_venta;
                            cout<<"Has ingresado "<<kg_venta*precio_manzana<<" euros\n";
                            caja = caja + (kg_venta*precio_manzana);
                        }
                        else{
                            cout<<"No hay stock\n";
                        }
                            break;
                    case 2:
                        cout<<"Vas a vender peras. Cuantos Kg?: ";
                        cin>>kg_venta;
                        if(kg_venta <= kg_pera_stock){
                            kg_pera_stock-=kg_venta;
                            cout<<"Has ingresado "<<kg_venta*precio_pera<<" euros\n";
                            caja = caja + (kg_venta*precio_pera);
                        }
                        else{
                            cout<<"No hay stock\n";
                        }
                            break;
                    case 3:
                        cout<<"Vas a vender platanos. Cuantos Kg?: ";
                        cin>>kg_venta;
                        if(kg_venta <= kg_platano_stock){
                            kg_platano_stock-=kg_venta;
                            cout<<"Has ingresado "<<kg_venta*precio_platano<<" euros\n";
                            caja = caja + (kg_venta*precio_platano);
                        }
                        else{
                            cout<<"No hay stock\n";
                        }
                            break;
                    case 4:
                        cout<<"Vas a vender peras. Cuantos Kg?: ";
                        cin>>kg_venta;
                        if(kg_venta <= kg_fresa_stock){
                            kg_fresa_stock-=kg_venta;
                            cout<<"Has ingresado "<<kg_venta*precio_fresa<<" euros\n";
                            caja = caja + (kg_venta*precio_fresa);
                        }
                        else{
                            cout<<"No hay stock\n";
                        }
                            break;
                    case 5:
                        cout<<"Vas a vender sandias. Cuantos Kg?: ";
                        cin>>kg_venta;
                        if(kg_venta <= kg_sandia_stock){
                            kg_sandia_stock-=kg_venta;
                            cout<<"Has ingresado "<<kg_venta*precio_sandia<<" euros\n";
                            caja = caja + (kg_venta*precio_sandia);
                        }
                        else{
                            cout<<"No hay stock\n";
                        }
                            break;
                    break;
                    }
                system("pause");
                break;
            case 2:
                cout<<"Vamos a consultar el monto total de la caja (solo ventas de fruta)\n";
                cout<<"Se han registrado un total de "<<caja<<" euros\n"; //error "caja"
                system("pause");
                break;
            case 3:
                cout<<"Reposicion de stock del almacen\n";
                cout<<"Que fruta quieres reponer?: ";
                cout<<"    (1) Manzana\n";
                cout<<"    (2) Pera\n";
                cout<<"    (3) Platano\n";
                cout<<"    (4) Fresa\n";
                cout<<"    (5) Sandia\n\n";
                cin>>op_fruta;
                while(op_fruta<1||op_fruta>5){
                    cout<<"Opcion erronea, elige una opcion correcta: ";
                    cin>>op_fruta;
                    cout<<endl;
                    }
                switch(op_fruta){
                    case 1:
                        cout<<"Vas a reponer manzanas. Cuantos Kg?: ";
                        cin>>kg_venta; //Reutilizo esta variable. Realmente aqui me estaré refiriendo a kg_repuestos, pero aprovecho recursos reciclando variables.
                        while(kg_venta<=0){
                            cout<<"Opcion erronea, elige una opcion correcta: ";
                            cin>>kg_venta;
                            cout<<endl;
                        }
                        kg_manzana_stock += kg_venta;
                            break;
                    case 2:
                        cout<<"Vas a reponer peras. Cuantos Kg?: ";
                        cin>>kg_venta; //Reutilizo esta variable. Realmente aqui me estaré refiriendo a kg_repuestos, pero aprovecho recursos reciclando variables.
                        while(kg_venta<=0){
                            cout<<"Opcion erronea, elige una opcion correcta: ";
                            cin>>kg_venta;
                            cout<<endl;
                        }
                        kg_pera_stock += kg_venta;
                            break;
                    case 3:
                        cout<<"Vas a reponer platanos. Cuantos Kg?: ";
                        cin>>kg_venta; //Reutilizo esta variable. Realmente aqui me estaré refiriendo a kg_repuestos, pero aprovecho recursos reciclando variables.
                        while(kg_venta<=0){
                            cout<<"Opcion erronea, elige una opcion correcta: ";
                            cin>>kg_venta;
                            cout<<endl;
                        }
                        kg_platano_stock += kg_venta;
                            break;
                    case 4:
                        cout<<"Vas a reponer fresas. Cuantos Kg?: ";
                        cin>>kg_venta; //Reutilizo esta variable. Realmente aqui me estaré refiriendo a kg_repuestos, pero aprovecho recursos reciclando variables.
                        while(kg_venta<=0){
                            cout<<"Opcion erronea, elige una opcion correcta: ";
                            cin>>kg_venta;
                            cout<<endl;
                        }
                        kg_fresa_stock += kg_venta;
                            break;
                    case 5:
                        cout<<"Vas a reponer sandias. Cuantos Kg?: ";
                        cin>>kg_venta; //Reutilizo esta variable. Realmente aqui me estaré refiriendo a kg_repuestos, pero aprovecho recursos reciclando variables.
                        while(kg_venta<=0){
                            cout<<"Opcion erronea, elige una opcion correcta: ";
                            cin>>kg_venta;
                            cout<<endl;
                        }
                        kg_sandia_stock += kg_venta;
                            break;
                system("pause");
                break;
                }
            case 4:
                cout<<"Consulta del stock actual disponible en el almacen en Kg\n";
                cout<<"Manzanas: "<<kg_manzana_stock<<endl;
                cout<<"Peras: "<<kg_pera_stock<<endl;
                cout<<"Platanos: "<<kg_platano_stock<<endl;
                cout<<"Fresas: "<<kg_fresa_stock<<endl;
                cout<<"Sandias: "<<kg_sandia_stock<<endl;
                system("pause");
                break;
            case 5:
                cout<<"SUB-menu de EDICION DE PRECIOS\n";
                cout<<"A que fruta le quieres editar su precio de venta al publico?: \n";
                cout<<"    (1) Manzana\n";
                cout<<"    (2) Pera\n";
                cout<<"    (3) Platano\n";
                cout<<"    (4) Fresa\n";
                cout<<"    (5) Sandia\n\n";
                cin>>op_fruta;
                while(op_fruta<1||op_fruta>5){
                    cout<<"Opcion erronea, elige una opcion correcta: ";
                    cin>>op_fruta;
                    cout<<endl;
                    }
                
                switch (op_fruta)
                {
                case 1:
                    cout<<"Vas a editar el precio de las manzanas. Cual es el nuevo precio?: ";
                        cin>>precio_manzana;
                        while(precio_manzana<=0){
                            cout<<"Opcion erronea, elige una opcion correcta: ";
                            cin>>precio_manzana;
                            cout<<endl;
                        }
                            break;
                case 2:
                        cout<<"Vas a editar el precio de las peras. Cual es el nuevo precio?: ";
                        cin>>precio_pera;
                        while(precio_pera<=0){
                            cout<<"Opcion erronea, elige una opcion correcta: ";
                            cin>>precio_pera;
                            cout<<endl;
                        }
                            break;
                case 3:
                        cout<<"Vas a editar el precio de los platanos. Cual es el nuevo precio?: ";
                        cin>>precio_platano;
                        while(precio_platano<=0){
                            cout<<"Opcion erronea, elige una opcion correcta: ";
                            cin>>precio_platano;
                            cout<<endl;
                        }
                            break;
                case 4:
                        cout<<"Vas a editar el precio de las fresas. Cual es el nuevo precio?: ";
                        cin>>precio_fresa;
                        while(precio_fresa<=0){
                            cout<<"Opcion erronea, elige una opcion correcta: ";
                            cin>>precio_fresa;
                            cout<<endl;
                        }
                            break;
                case 5:
                        cout<<"Vas a editar el precio de las sandias. Cual es el nuevo precio?: ";
                        cin>>precio_sandia;
                        while(precio_sandia<=0){
                            cout<<"Opcion erronea, elige una opcion correcta: ";
                            cin>>precio_sandia;
                            cout<<endl;
                        }
                            break;
                }
                system("pause");
                break;
        }

        cout<<"Quieres volver al menu inicial? (Y/N): ";
        kg_venta=0;
        opcion=0;
        op_fruta=0;
        cin>>repetir;
        while(repetir!='Y' && repetir!='y' && repetir!='N' && repetir!='n'){
            cout<<"Opcion erronea, elige una opcion correcta: ";
            cin>>repetir;
            cout<<endl;
        }
        system("cls");
    }
    system("pause");
    return 0;
}