#include <iostream>
using namespace std;
// 100 primeros numeros de izq a derecha usando un array de dos dimensiones

int main(){
int matrizCuadrada[10][10], num=2;
    system("color 0E");
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            matrizCuadrada[i][j] = num;
            if(matrizCuadrada[i][j]<10){
                cout<<"00"<<matrizCuadrada[i][j]<<" ";
            }else if(matrizCuadrada[i][j]<100){
                cout<<"0"<<matrizCuadrada[i][j]<<" ";
            }
            else{
                cout<<matrizCuadrada[i][j]<<" ";
            }
            num=num+2;
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}