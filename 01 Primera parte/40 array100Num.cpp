#include <iostream>
using namespace std;
/*array del 1 al 100 y luego los mostramos.
primero mostrar de menor a mayor
luego de mayor a menor*/

int main(){
    int num[100];
    for(int i=0;i<=99;i++){
        num[i] = i+1;
    }
        cout<<"Los numeros de menor a mayor del 1 al 100 son:\n";
        for(int i=0;i<=99;i++){
            if(i<99){
                cout<<num[i]<<", ";
            }else{
                cout<<num[i]<<".\n\n";
            }
    }
        cout<<"Los numeros de mayor a menor del 100 al 1 son:\n";
        for(int i=99;i>=0;i--){
            if(i>0){
                cout<<num[i]<<", ";
            }else{
                cout<<num[i]<<".\n\n";
            }
    }
    system("pause");
    return 0;
}