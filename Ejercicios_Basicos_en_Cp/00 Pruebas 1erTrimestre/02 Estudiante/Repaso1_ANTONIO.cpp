/*Escriba, compile y ejecute un programa en C++ que calcule
 la nota final del estudiante conocidos tres notas parciales 
 que se leen por teclado al igual que el nombre del estudiante, 
 las notas parciales tienen ponderaciones de 0.25, 0.30 y 0.45 respectivamente*/
 
 
#include <iostream>
#include <stdlib.h> 
 
using namespace std;



struct calificacion{
	
	string apellido;
	double nota1;
	double nota2;
	double nota3;
};

void recogerdatos (calificacion &estudiante);
void error (double &nota);
void mostrar (calificacion &estudiante);

main (){
	calificacion estudiante;
	char repetir;
		
	system ("color 02");
	do{
		cout << "Porgrama que calcula la nota final del estudiante!" << endl;
		cout << "----------------------------------------------------------" << endl;
		recogerdatos (estudiante); //Llamamos a una función que recoja los datos del estudiante
		mostrar (estudiante);
		cout << endl << "Desea procesar otro estudiante? S o N    ";
		cin >> repetir;
		if (repetir != 'S' and repetir != 's' and repetir != 'N' and repetir != 'n'){
			while (repetir != 'S' and repetir != 's' and repetir != 'N' and repetir != 'n'){
				cout << endl << "Parametro incorrecto, introduzca S o N    ";
				cin >> repetir;				
			}
		}
	system ("cls");
	}while (repetir == 'S' or repetir == 's');
}


void recogerdatos (calificacion &estudiante){ //Funcion que recoge los datos del estudiante
	cout << endl << "Introduce el apellido del estudiante: ";
	cin >> estudiante.apellido;
	cout << endl << "Introduce sus notas entre 0 y 5";
	cout << endl << "Introduce la primera nota: ";
	cin >> estudiante.nota1;
	error (estudiante.nota1); //Nos aseguramos que el numero introducido sea valido
	cout << endl << "Introduce la segunda nota: ";
	cin >> estudiante.nota2;
	error (estudiante.nota2); //Nos aseguramos que el numero introducido sea valido
	cout << endl << "Introduce la tercera nota nota: ";
	cin >> estudiante.nota3;
	error (estudiante.nota3); //Nos aseguramos que el numero introducido sea valido
}

void error (double &nota){ //funcion que pide una nota hasta que esta sea valida
	while (nota > 5 or nota < 0){
		cout << endl << "Nota no valida, introduzca un valor entre 0 y 5: ";
		cin >> nota;
	}
}

void mostrar (calificacion &estudiante){ //Funcion que muestra las notas
	cout << endl << endl << endl << "Imprimir datos y resultados";
	cout << endl << "----------------------------------------------------------";
	cout << endl << endl << "Boletin de notas del estudiante:     " << estudiante.apellido;
	cout << endl << endl << "La primera nota parcial y su porcentaje son: " << estudiante.nota1 << "   0.25";
	cout << endl << endl << "La segunda nota parcial y su porcentaje son: " << estudiante.nota2 << "   0.30";
	cout << endl << endl << "La tercera nota parcial y su porcentaje son: " << estudiante.nota3 << "   0.45";
	cout << endl << endl << "La final del estudiante es: " << (estudiante.nota1 * 0.25) + (estudiante.nota2 * 0.30) + (estudiante.nota3 * 0.45);
	cout << endl << endl << "----------------------------------------------------------" << endl;
}
	
	

