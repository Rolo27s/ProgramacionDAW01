#include <iostream>
#include <stdlib.h>
using namespace std;
//PROGRAMA DE UN CAJERO AUTOMATICO
int main()
{
	float saldo = 2500, ret=0, ingr=0;;
	int op1=0, op2=0;
	
	do{
		cout<<"Bienvenido al banco Santander, que desea realizar:\n";
		cout<<"--- MENU PRINCIPAL ---\n";
		cout<<"  (1)RETIRAR\n  (2)CONSULTAR\n  (3)INGRESAR\n  (4)SALIR\nELIGE UNA OPCION:";
		cin>>op1;
		while(op1<1 || op1>4){
			cout<<"Opcion erronea. Introduce una opcion correcta del menu...\n";
			system("pause");
			system("cls");
			cout<<"Bienvenido al banco Santander, que desea realizar:\n";
			cout<<"--- MENU PRINCIPAL ---\n";
			cout<<"  (1)RETIRAR\n  (2)CONSULTAR\n  (3)INGRESAR\n  (4)SALIR\nELIGE UNA OPCION:";
			cin>>op1;
		}
		switch (op1)
		{
		case 1:
			cout<<"Seleccione en el menu el monto a retirar:\n";
			cout<<" (1)10\n (2)20\n (3)40\n (4)60\n (5)80\n (6)100\n (7)200\n (8)OTRO\nELECCION:";
			cin>>op2;
			while(op2<1 || op2>8){
				cout<<"Opcion erronea. Introduce una opcion correcta del menu.\nELECCION:";
				cout<<" (1)10\n (2)20\n (3)40\n (4)60\n (5)80\n (6)100\n (7)200\n (8)OTRO\nELECCION:";
				cin>>op2;
			}
			if(op2 == 8){
				cout<<"Seleccione cantidad (min 10 y max 600):";
				cin>>ret;
				while((ret<10&&ret!=0) || ret>600){
					cout<<"Cantidad erronea. Si desea salir pulse 0...\nSeleccione cantidad (min 10 y max 600):";
					cin>>ret;
				}
				if(saldo >= ret){
					saldo = saldo - ret;
					cout<<"Retiro realizado.\n";
					system("pause");
					system("cls");
				}else{
					cout<<"Fondos insuficientes.\n";
					system("pause");
					system("cls");
				}
			}else{
				switch (op2)
				{
					case 1:
						if(saldo >= saldo-10){
							saldo = saldo - 10;
							cout<<"Retiro realizado.\n";
							system("pause");
							system("cls");
						}else{
							cout<<"Fondos insuficientes.\n";
							system("pause");
							system("cls");
						}
						break;
					case 2:
						if(saldo >= saldo-20){
							saldo = saldo - 20;
							cout<<"Retiro realizado.\n";
							system("pause");
							system("cls");
						}else{
							cout<<"Fondos insuficientes.\n";
							system("pause");
							system("cls");
						}
						break;
					case 3:
						if(saldo >= saldo-40){
							saldo = saldo - 40;
							cout<<"Retiro realizado.\n";
							system("pause");
							system("cls");
						}else{
							cout<<"Fondos insuficientes.\n";
							system("pause");
							system("cls");
						}
						break;
					case 4:
						if(saldo >= saldo-60){
							saldo = saldo - 60;
							cout<<"Retiro realizado.\n";
							system("pause");
							system("cls");
						}else{
							cout<<"Fondos insuficientes.\n";
							system("pause");
							system("cls");
						}
						break;
					case 5:
						if(saldo >= saldo-80){
							saldo = saldo - 80;
							cout<<"Retiro realizado.\n";
							system("pause");
							system("cls");
						}else{
							cout<<"Fondos insuficientes.\n";
							system("pause");
							system("cls");
						}
						break;
					case 6:
						if(saldo >= saldo-100){
							saldo = saldo - 100;
							cout<<"Retiro realizado.\n";
							system("pause");
							system("cls");
						}else{
							cout<<"Fondos insuficientes.\n";
							system("pause");
							system("cls");
						}
						break;
					case 7:
						if(saldo >= saldo-200){
							saldo = saldo - 200;
							cout<<"Retiro realizado.\n";
							system("pause");
							system("cls");
						}else{
							cout<<"Fondos insuficientes.\n";
							system("pause");
							system("cls");
						}
						break;
					default:
						break;
				}}
			break;
		case 2:
			cout<<"Monto actual de su saldo: "<<saldo<<" euros\n";
			system("pause");
			system("cls");
			break;
		case 3:
			cout<<"Cuanto desea ingresar:";
			cin>>ingr;
			while(ingr<0){
				cout<<"Cantidad erronea. Vuelva a ingresar la cantidad:\n";
				cin>>ingr;
			}
			saldo = saldo + ingr;
			cout<<"Ingreso realizado con exito.\n";
			system("pause");
			system("cls");
			break;
		default:
			break;
		}
	}while(op1 != 4);
	cout<<"Gracias por confiar en nosotros.\n";
	system("pause");
	return 0;
}