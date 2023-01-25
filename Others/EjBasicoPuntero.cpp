/* Ejercicio básico para el entendimiento de punteros */
/* Para trabajar con punteros usaremos dos operadores distintos:
    & : extrae la dirección de la variable a la que se le aplica
    * : accede al contenido de la variable cuya dirección de memoria es apuntada por el puntero, permitiendo su modificación
 */

#include <iostream>
using namespace std;

/* Este uso de punteros normalmente solo lo utilizan los programadores avanzados */
int main()
{
    double media = 2.;
    double *p_media;
    p_media = &media;
    /* En este momento p_media contiene la dirección de memoria donde se encuentra almacenada la variable media */
    *p_media = 3.;

    return 0;
}

/* Otra forma de trabajar de manera más simple sería la siguiente */
int main()
{
    double media = 2.;
    double &r_media{media};
    r_media = 3.;

    /* r_media sería un alias de media y podríamos modificar a media por el alias. */

    return 0;
}

/* Tambien estaría el paso por referencia a una funcion */
void incrementa(int &i) // Nótese el uso de una referencia
{
    i = i + 1;
    cout << "Valor incrementado en funcion: " << i << endl;
}
int main()
{
    int i = 5;
    incrementa(i);
    cout << "Valor incrementado en main: " << i << endl;
}