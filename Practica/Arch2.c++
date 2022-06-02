#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct ente
{
    string nombre;
    int edad;
    float peso;
    float estatura;
    // constructor
    ente(string nombre)
    {
        cout << "Ente creado " << endl;
        this->nombre = nombre;
    }
    ente(int edad, float peso)
    {
        this->edad = edad;
        this->peso = peso;
    }
    ente(string nombre, int edad, float peso, float estatura)
    {
        this->nombre = nombre;
        this->edad = edad;
        this->peso = peso;
        this->estatura = estatura;
    }
};

int main()
{
    ente ysaac("Ysaac");
    ysaac.edad = 21;
    ysaac.peso = 65.7f;
    ysaac.estatura = 1.74f;

    ente amigo = {"Kely", 23, 54.1f, 1.53};

    ente amigo = {23, 54.1f};

    cin.ignore().get();
    return 0;
}