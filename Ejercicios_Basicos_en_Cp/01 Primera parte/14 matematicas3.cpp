#include <iostream>
#include <cctype> // OR "ctype.h" ... es lo mismo.

using namespace std;

int main(){
	float Practica=11, Teoria=11, Participacion=11, NotaFinal=11;
	
	cout<<"Programa para el calculo de la nota final del alumno.\n\n";
	cout<<"Le informamos que el sistema de evaluacion esta formado por la siguiente formula:\n";
	cout<<"  Nota Final = (Practica * 0.3 + Teoria * 0.6 + Participacion * 0.1)\n";
	cout<<"(En este caso, no tendremos ninguna nota minima en ningun campo)\n";
	cout<<"Recordamos al usuario que utilice el programa que las notas estaran comprendidas entre el 0 y el 10.\n\n";
	
	cout<<"Nota de Practica: "; 
	cin>>Practica;
	
	if(Practica>=0 && Practica <= 10 && Practica != isalpha(Practica)){
		cout<<"Nota de Teoria: "; 
		cin>>Teoria;
		if(Teoria>=0 && Teoria <= 10 && Teoria != isalpha(Teoria)){
			cout<<"Nota de Participacion: "; 
			cin>>Participacion;
			if(Participacion>=0 && Participacion <= 10 && Participacion != isalpha(Participacion)){
				NotaFinal=(Practica * 0.3 + Teoria * 0.6 + Participacion * 0.1);
				cout<<NotaFinal;
				if(NotaFinal >= 5){
					cout<<"\n\nAPROBADO\n";
				}else{
					cout<<"\n\nSUSPENSO\n";
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
	
	return 0;
}
