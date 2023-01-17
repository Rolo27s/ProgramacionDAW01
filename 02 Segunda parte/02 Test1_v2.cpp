#include <iostream>
#include <string.h>
using namespace std;


int main(){
    float pesofruta[5]={1000, 1500, 2000, 5000, 500};
    float preciofruta[5]={2.50, 1.75, 1.55, 2.70, 1.25};
    float caja=0.0, kg_venta=0;
    int opcion=0, cod_fruta=0, n=5;
    string fruta[5]={"manzanas","peras", "platanos", "fresas", "sandias"};
    char repetir='Y';
    system("COLOR 0E");

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
            cout<<"\nOpcion erronea, elige una opcion correcta: ";
            cin>>opcion;
            cout<<endl;
        }
    switch (opcion)
    {
    case 1:
        cout<<"Submenu de ventas\n";
        cout<<"Puedes comprar:\n";
        for(int i=1;i<=n;i++){
            cout<<"("<<i<<") "<<fruta[i-1];
            cout<<endl;
        }
        cout<<"Introduce el codigo de la fruta: ";
        cin>>cod_fruta;
        while(cod_fruta<1||cod_fruta>n){
            cout<<"\nOpcion erronea, elige una opcion correcta: ";
            cin>>cod_fruta;
            cout<<endl;
        }
        cout<<"Has elegido '"<<fruta[cod_fruta-1]<<"'\n";
        cout<<"Cuantos Kg quieres comprar?: ";
        cin>>kg_venta;
        if(kg_venta>0 && kg_venta<=pesofruta[cod_fruta-1]){
            cout<<"Aqui tiene "<<kg_venta<<" kg de "<<fruta[cod_fruta-1]<<". Gracias, vuelva pronto!\n";
            pesofruta[cod_fruta-1] -= (kg_venta);
            caja += (kg_venta*preciofruta[cod_fruta-1]); 
        }else{
            cout<<"Disculpe, pero no puedo hacer la venta en esos terminos\n";
        }
        break;
    case 2:
        cout<<"Consulta - Caja\n";
        cout<<caja;
        break;
    case 3:
        cout<<"Submenu - Reponer Stock\n";
        cout<<"Puedes reponer:\n";
        for(int i=1;i<=n;i++){
            cout<<"("<<i<<") "<<fruta[i-1];
            cout<<endl;
        }
        cout<<"Introduce el codigo de la fruta: ";
        cin>>cod_fruta;
        while(cod_fruta<1||cod_fruta>n){
            cout<<"\nOpcion erronea, elige una opcion correcta: ";
            cin>>cod_fruta;
            cout<<endl;
        }
        cout<<"Has elegido '"<<fruta[cod_fruta-1]<<"'\n";
        cout<<"Cuantos Kg quieres reponer?: ";
        cin>>kg_venta; //Usare la variable kg_venta para optimizar un poco de codigo, aunque realmente me refiero a kg_reponer.
        if(kg_venta>0){
            pesofruta[cod_fruta-1] += kg_venta;
        }
        break;
    case 4:
        cout<<"Consulta - Stock\n";
        for(int i=1;i<=n;i++){
            cout<<"("<<i<<") "<<fruta[i-1]<<" stock disponible: "<<pesofruta[i-1]<<endl;
        }
        break;
    case 5:
        cout<<"Submenu- Editar precios:\n";
        for(int i=1;i<=n;i++){
            cout<<"("<<i<<") "<<fruta[i-1];
            cout<<endl;
        }
        cout<<"Introduce el codigo de la fruta: ";
        cin>>cod_fruta;
        while(cod_fruta<1||cod_fruta>n){
            cout<<"\nOpcion erronea, elige una opcion correcta: ";
            cin>>cod_fruta;
            cout<<endl;
        }
        cout<<"Has elegido '"<<fruta[cod_fruta-1]<<"'\n";
        cout<<"El precio hasta ahora era "<<preciofruta[cod_fruta-1]<<" euros. Cual sera ahora el nuevo precio?: ";
        cin>>preciofruta[cod_fruta-1];
        while(preciofruta[cod_fruta-1]<=0){
            cout<<"\nPrecio erroneo, introduce nuevamente el precio: ";
            cin>>preciofruta[cod_fruta-1];
        }
        break;
    default:
        break;
    }

    cout<<"\nQuieres volver al menu inicial? (Y/N): ";
    kg_venta=0;
    opcion=0;
    cod_fruta=0;
    cin>>repetir;
    while(repetir!='Y' && repetir!='y' && repetir!='N' && repetir!='n'){
        cout<<"Opcion erronea, elige una opcion correcta: ";
        cin>>repetir;
        cout<<endl;
    }
    system("cls");
    }
    return 0;
}