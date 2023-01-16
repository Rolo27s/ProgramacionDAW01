#include <iostream>
using namespace std;
//PROGRAMA QUE INTRODUCE N NUMEROS POR TECLADO Y DETECTA EL MAYOR, EL MENOR Y LA MEDIA ARITMETICA.

int main(){
    int rep=0, numNums=0;
    float max=0, min=0, tot=0, media=0, num=0;

    cout<<"---PROGRAMA QUE INTRODUCE N NUMEROS POR TECLADO Y DETECTA EL MAYOR, EL MENOR Y LA MEDIA ARITMETICA.---\n";
    cout<<"Cuantos numeros quieres introducir en el programa?: ";
    cin>>rep;
    while(rep<2){
        cout<<"Debemos introducir al menos dos numeros (2): ";
        cin>>rep;
    }
    
    for(int i=1;i<=rep;i++){
        cout<<"Introduce el numero ("<<i<<"/"<<rep<<"): ";
        cin>>num;
        if(i==1){
        max=num;
        min=num;
        }else{
            if(num>max){
                max = num;
            }else if(num<min){
                min = num;
            }else{    
        }}
        tot += num;
        numNums = i;
    }
    media=tot/numNums;
    cout<<"El numero mayor es el "<<max<<endl;
    cout<<"El numero menor es el "<<min<<endl;
    cout<<"La media aritmetica de los "<<numNums<<" numeros introducidos es "<<media<<endl;
    system("pause");
    return 0;
}