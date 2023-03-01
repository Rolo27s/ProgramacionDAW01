#include <iostream>
using namespace std;

// Clase base
class Animal {
public:
    // Método virtual
    virtual void hablar() {
        cout << "Soy un animal." << endl;
    }
};

// Clase derivada que hereda de Animal
class Perro : public Animal {
public:
    // Método virtual que sobreescribe el de la clase base
    void hablar() override {
        cout << "Soy un perro." << endl;
    }
};

// Clase derivada que hereda de Animal
class Gato : public Animal {
public:
    // Método virtual que sobreescribe el de la clase base
    void hablar() override {
        cout << "Soy un gato." << endl;
    }
};

int main() {
    // Crear objetos de las clases derivadas
    Perro mi_perro;
    Gato mi_gato;

    // Llamar al método virtual de la clase base para cada objeto
    mi_perro.hablar();
    mi_gato.hablar();

    return 0;
}
