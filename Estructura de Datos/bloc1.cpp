#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

double multiplicar(int vec[], int tam);
int createRandomNumber();

int main()
{
    int tam;
    double acum = 0;
    cout << "Ingrese el tamaño del vector -> ";
    cin >> tam;

    int vectorA[tam];
    cout << "\nVector A: " << endl;
    for (int i = 0; i < tam; i++)
    {
        vectorA[i] = createRandomNumber();
        cout << vectorA[i] << " -> ";
    }

    acum = multiplicar(vectorA, tam);
    cout << "La multiplicacion es -> " << acum;

    cin.ignore().get();
}

double multiplicar(int vec[], int size)
{
    if (size == 0)
    {
        return (vec[0]);
    }
    return (vec[size] * multiplicar(vec, size - 1));
}

int createRandomNumber()
{
    return rand() % 100 + 1;
}