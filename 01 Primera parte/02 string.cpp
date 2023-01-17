#include <iostream>
#include <string>
using namespace std;

int main()
{
	string texto;
	cout<<"Escribe un texto: ";
	getline(cin, texto);
	cout<<"El texto escrito es: "<<texto;
	return 0;
}
