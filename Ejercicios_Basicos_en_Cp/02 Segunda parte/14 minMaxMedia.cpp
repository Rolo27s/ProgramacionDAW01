#include <iostream>
using namespace std;
const int REP=10;
float max(float num[REP]);
float min(float num[REP]);
float media(float num[REP]);

int main(){
    float num[REP];

    cout<<"INTRODUCE "<<REP<<" NUMEROS POR TECLADO Y DETECTA EL MAYOR, EL MENOR Y LA MEDIA ARITMETICA.\n";
    for(int i=1;i<=REP;i++){
        cout<<"Introduce el numero ("<<i<<"/"<<REP<<"): ";
        cin>>num[i-1];
    }
    cout<<"\nEl maximo es: ";
    cout<<max(num);

    cout<<"\nEl minimo es: ";
    cout<<min(num);

    cout<<"\nLa media es: ";
    cout<<media(num);
    return 0;
}

float max(float num[REP]){
float Nmax = num[0];
    for(int i=1;i<=REP;i++){
        if(num[i-1]>Nmax){
            Nmax=num[i-1];
        }
    }
    return Nmax;
}

float min(float num[REP]){
float Nmin = num[0];
    for(int i=1;i<=REP;i++){
        if(num[i-1]<Nmin){
            Nmin=num[i-1];
        }
    }
    return Nmin;
}

float media(float num[REP]){
float Nmedia = 0;
    for(int i=1;i<=REP;i++){
            Nmedia += num[i-1];
        }
    Nmedia = (Nmedia/REP);
    return Nmedia;
}