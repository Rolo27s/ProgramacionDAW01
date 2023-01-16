#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
//programa de array con nº aleatorios. Cual es el mayor y cual es el menor.

int main(){
    int num[100];
    int max=0,min=0;
    for(int i=0;i<=99;i++){
        num[i] = rand();
    }
    min = num[0];
    max = num[0];
    cout<<"100 Numeros aleatorios entre en 1 y el 100\n";
    for(int i=0;i<=99;i++){
        if(i<99){
            cout<<num[i]<<", ";
            if(num[i]>max){
                max = num[i];
            }else if(num[i]<min){
               min =  num[i];
            }else{
            }
        }else{
            cout<<num[i]<<".\n\n";
            if(num[i]>max){
                max = num[i];
            }else if(num[i]<min){
               min =  num[i];
            }else{
            }
        }
    }
    cout<<endl<<"Numero maximo de la serie = "<<max<<endl;
    cout<<"Numero minimo de la serie = "<<min<<endl;
    system("pause");
    return 0;
}