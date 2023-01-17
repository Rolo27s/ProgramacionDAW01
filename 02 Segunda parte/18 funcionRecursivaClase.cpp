#include <iostream>
using namespace std;
int funcion(int contador);

int main(){
    funcion(5);

    system("pause");
    return 0;
}

int funcion(int contador){
    if(contador==0){
        return 0;
    }
    cout<<contador;
    funcion(contador-1);
}