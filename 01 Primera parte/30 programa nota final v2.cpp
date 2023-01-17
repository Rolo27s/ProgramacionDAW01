#include <iostream>
using namespace std;

int main(){
	float Practica=0, Teoria=0, Participacion=0, NotaFinal=0;
	
	cout<<"Programa para el calculo de la nota final del alumno.\n\n";
	cout<<"Vamos a controlar a 5 alumnos en este programa.\n\n";
	cout<<"Le informamos que el sistema de evaluacion esta formado por la siguiente formula:\n";
	cout<<"  Nota Final = (Practica * 0.3 + Teoria * 0.6 + Participacion * 0.1)\n";
	cout<<"(En este caso, no tendremos ninguna nota minima en ningun campo)\n";
	cout<<"Recordamos al usuario que utilice el programa que las notas estaran comprendidas entre el 0 y el 10.\n\n";
	
	for(int cont = 1; cont<=5; cont++)
	{
		cout<<"\n Alumno "<<cont<<endl;
		cout<<"Nota de Practica: "; 
		cin>>Practica;
		while(Practica < 0 || Practica > 10){
			cout<<"Nota erronea. Vuelve a introducir la nota bien...\n";
			cin>>Practica;
			}
			if(Practica>=0 && Practica <= 10){
				cout<<"Nota de Teoria: "; 
				cin>>Teoria;
					while(Teoria < 0 || Teoria > 10){
					cout<<"Nota erronea. Vuelve a introducir la nota bien...\n";
					cin>>Teoria;
					}
				if(Teoria>=0 && Teoria <= 10){
					cout<<"Nota de Participacion: "; 
					cin>>Participacion;
						while(Participacion < 0 || Participacion > 10){
						cout<<"Nota erronea. Vuelve a introducir la nota bien...\n";
						cin>>Participacion;
						}
					if(Participacion>=0 && Participacion <= 10){
						NotaFinal=(Practica * 0.3 + Teoria * 0.6 + Participacion * 0.1);
						cout<<NotaFinal;
						if(NotaFinal >= 5){
							cout<<"\nAPROBADO\n\n";
						}else{
							cout<<"\nSUSPENSO\n\n";
				}
					}else{
						cout<<"Nota de Participacion erronea.";
					}
				}else{
					cout<<"Nota de Teoria erronea.";
				}
			}else{
				cout<<"Nota de Practica erronea.";
			}
	}
	return 0;
}
