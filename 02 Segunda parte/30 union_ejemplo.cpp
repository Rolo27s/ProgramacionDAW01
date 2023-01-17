#include <iostream>
using namespace std;

int main(){
// Union usa solo un espacio de memoria para el ultimo valor declarado. Todos los demás serán basura y no estarán controlados.
union{
    int x;
    float y;
    double z;
};
    x = 25;
    y = 245.245;
    z = 9.41415;

    cout<<x<<endl;
    cout<<y<<endl; //el valor en y sobreescribe el valor de x
    cout<<z<<endl; //el valor en z sobreescribe el valor de y

    return 0;
}