#include <iostream>
using namespace std;
// 100 primeros numeros de izq a derecha usando un array de dos dimensiones

int main(){
int matrizCuadrada[3][3], num=1;
    system("color 0E");
    cout<<"Introduce 9 valores\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<"Valor "<<num<<": ";
            cin>>matrizCuadrada[i][j];
            num++;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<matrizCuadrada[i][j]<<" ";
            }
        cout<<endl;
        }
    system("pause");
    return 0;
}