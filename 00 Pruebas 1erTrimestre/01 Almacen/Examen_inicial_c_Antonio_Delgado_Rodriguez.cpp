#include <iostream>
#include <stdlib.h> //No se uso en su dia

using namespace std;

main ()
	{
	float kgfruta [5] = {1000, 1500, 2000, 5000, 500};
	float pvp [5] = {2.50, 1.75, 1.55, 2.70, 1.25};
	float tventa = 0, pventa = 0, kgcompra = 0, nprecio = 0;
	int imenu = 0;
	
	system ("color 02");
	do //repetiremos el menu hasta que se pulse 0
		{
		pventa = 0, kgcompra = 0;
		cout << "Bienvenido a la aministracion de la fruteria Antonito." << endl << endl << endl; //primer menu
		cout << "*******************************************************" << endl << endl;
		cout << "Que quiere hacer?" << endl << endl;
		cout << "1. Vender fruta." << endl;
		cout << "2. Saldo de vena de fruta total." << endl;
		cout << "3. Comprar frutas para el almacen." << endl;
		cout << "4. Consular stock de frutas." << endl;
		cout << "5. Cambiar precio de frutas." << endl;
		cout << "0. Salir." << endl << endl;
		cin >> imenu;
			while (imenu < 0 or imenu > 6)
				{
				cout << "Numero incorrecto. Introduzca un numero entre 0 y 5, por favor." << endl;
				cin >> imenu;
				}
			switch (imenu)
				{
				case 1: //menu para vender fruta
					{
					do //repetiremos el menu hasta que se pulse 0
						{	
						system ("cls");
						cout << "Que fruta quiere vender?" << endl << endl;
						cout << "1. Manzanas." << endl;
						cout << "2. Peras." << endl;
						cout << "3. Platanos." << endl;
						cout << "4. Fresas." << endl;
						cout << "5. Sandia." << endl;
						cout << "0. Volver." << endl << endl;
						cin >> imenu;
						while (imenu < 0 or imenu > 6) //Nos aseguramos de que se meta el numero correcto
							{
							cout << "Numero incorrecto. Introduzca un numero entre 0 y 5, por favor." << endl;
							cin >> imenu;
							}
						if (imenu == 0)
							{
							
							}
						else if (kgfruta [imenu - 1] == 0) //Nos aseguramos de que haya stock antes de vender siquiera
							{
							cout << "No te queda stock de esa fruta. Tienes que comprar mas." << endl << endl;
							}
						else
							{
							cout << "Cuantos kg quieres vender?" << endl;
							cin >> kgcompra;
							while (kgcompra < 0 or kgcompra > kgfruta [imenu - 1])
								{
								if (kgcompra < 0)
									{
									cout << "Introduzca un numero positivo, por favor." << endl;
									cin >> kgcompra;
									}
								else //Nos aseguramos de que haya stock suficiente
									{
									cout << "No te queda tanto stock. Introduce un numero menor o igual que " <<  kgfruta [imenu - 1] << "." << endl; 
									cin >> kgcompra;
									}
								}
							pventa = kgcompra * pvp [imenu - 1]; //calculamos el precio de esta compra
							tventa = tventa + pventa; //actualizamos el dinero ganado vendiendo
							kgfruta [imenu - 1] = kgfruta [imenu - 1] - kgcompra; //actualizamos la fruta que queda en stock
							cout << "Lo que ha comprado cuesta un total de " << pventa << " Euros" << endl << endl;
							}
						system ("pause");
						system ("cls");
						} while (imenu != 0);
					imenu = 1;
					system ("cls");
					break;
					}
				case 2: //menu para consultar dinero ganado vendiendo
					{
					system ("cls");
					cout << "El dinero total de la venta de fruta es " << tventa << " Euros." << endl << endl;
					system ("pause");
					system ("cls");
					break;
					}
				case 3: //Menu para comporar fruta para el almacen
					{
					do //repetiremos el menu hasta que se pulse 0
						{
						system ("cls");
						cout << "Que fruta quiere comprar?" << endl << endl;
						cout << "1. Manzanas." << endl;
						cout << "2. Peras." << endl;
						cout << "3. Platanos." << endl;
						cout << "4. Fresas." << endl;
						cout << "5. Sandia." << endl;
						cout << "0. Volver." << endl << endl;
						cin >> imenu;
						while (imenu < 0 or imenu > 6)
							{
							cout << "Numero incorrecto. Introduzca un numero entre 0 y 5, por favor." << endl;
							cin >> imenu;
							}
						if (imenu == 0)
							{
							
							}
						else
							{
							cout << "Cuantos kg quieres comprar?" << endl;
							cin >> kgcompra;
									while (kgcompra < 0 or imenu > 6)
									{
									cout << "Introduzca un numero positivo, por favor." << endl;
									cin >> kgcompra;
									}
							kgfruta [imenu - 1] = kgfruta [imenu - 1] + kgcompra; //actualizamos la fruta que queda en stock
							cout << "Compra realizada. Ahora tienes un total de " << kgfruta [imenu - 1] << " Kg." << endl << endl;
							system ("pause");
							system ("cls");
							}
						} while (imenu != 0);
					imenu = 1;
					system ("cls");
					break;
					}
				case 4: //consulta el stock de frutas
					{
					system ("cls");
					cout << "Stock total de fruta." << endl << endl;
					cout << kgfruta [0] << "kg de manzanas." << endl;
					cout << kgfruta [1] << "kg de peras." << endl;
					cout << kgfruta [2] << "kg de platanos." << endl;
					cout << kgfruta [3] << "kg de fresas." << endl;
					cout << kgfruta [4] << "kg de sandia." << endl << endl;
					system ("pause");
					system ("cls");
					break;
					}
				case 5: //Menu para actualizar el precio de la fruta
					{
					do //repetiremos el menu hasta que se pulse 0
						{
						system ("cls");
						cout << "El precio de que fruta quieres actualizar?" << endl << endl;
						cout << "1. Manzanas." << endl;
						cout << "2. Peras." << endl;
						cout << "3. Platanos." << endl;
						cout << "4. Fresas." << endl;
						cout << "5. Sandia." << endl;
						cout << "0. Volver." << endl << endl;
						cin >> imenu;
						while (imenu < 0 or imenu > 6)
							{
							cout << "Numero incorrecto. Introduzca un numero entre 0 y 5, por favor." << endl;
							cin >> imenu;
							}
						if (imenu == 0)
							{
							
							}
						else
							{
							cout << "Cuanto quieres que valga el kg?" << endl;
							cin >> nprecio;
									while (nprecio < 0)
									{
									cout << "Introduzca un numero positivo, por favor." << endl;
									cin >> nprecio;
									}
							pvp [imenu - 1] = nprecio; //actualizamosel precio de la fruta
							cout << "Precio actualizado. Ahora el kg vale " << pvp [imenu - 1] << " Euros." << endl << endl;
							system ("pause");
							system ("cls");
							}
						} while (imenu != 0);
					imenu = 1;
					system ("cls");
					break;
					}
				}
		} while (imenu != 0);
	}
