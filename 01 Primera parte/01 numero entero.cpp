/* Todo archivo guardado en C debe ser formato ".c" para asegurar la compatibilidad. Curiosamente el compilador usado en clases de DAW solo ejecuta archivos .cpp

Declaraciones globales:
{
	#Preprocesador. Entra en la libreria, la carga y utilizará la que necesite el programa.
	cte, vble y funciones.
}

Principal:
__ main(){
.
.
.
}
Al principio del main debemos poner el tipo de elemento que retornará al final. Pe, si retorna un entero,
debería de poner int main(){.....}

Definir funciones:

*/

#include "iostream" 
/* 
cin: Flujo de entrada
cout: Flujo de salida
cerr: Flujo de error no almacenado.
clog: Flujo de error almacenado.
endl: Fin de línea.
*/

using namespace std; // Esto funciona para que cada vez que querramos mostrar en pantalla lo entienda. Usamos el "<<" para mostrar en pantalla

int main(){
	int numero;
	cout<<"Hola mundo"<<endl; //Tambien valdría escribir "Hola mundo\n";
	cout<<"Escribe un numero: ";
	cin>>numero;
	cout<<"El numero es: " <<numero;
	return 0;
}
