#include <iostream>
#include <string>

using namespace std;

int main()
{
	string firstName = "";
	string lastName = "";
	int edad = 0;
	cout<<"Nombre: ";
	getline(cin, firstName);
	cout<<"Apellidos: ";
	getline(cin, lastName);
	string fullName = firstName + " " + lastName;
	cout<<"Edad: ";
	cin>>edad;
	
	cout<<"Informacion recopilada.\n";
	
	cout<<fullName;
	cout<<". "<<edad<<" años";
	return 0;
}
