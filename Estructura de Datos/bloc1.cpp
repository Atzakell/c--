#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int multiplicar(int vec[], int tam);
int suma(int vec[], int tam);
void recorre(int x[], int n);
void mayor(int x[], int n, int &may);
int createRandomNumber();

int main()
{
    int tam, may = 0;
    int acum = 0;
    cout << "Cantidad de elementos -> ";
    cin >> tam;

    int vectorA[tam];
    cout << "\nVector A: " << endl;
    for (int i = 0; i < tam; i++)
    {
        vectorA[i] = createRandomNumber();
        cout << "[" << vectorA[i] << "]"
             << " ";
    }

    recorre(vectorA, tam);
    acum = multiplicar(vectorA, tam - 1);
    mayor(vectorA, tam, may);
    cout << "\nLa multiplicacion es -> " << acum;
    cout << "\nLa suma es -> " << suma(vectorA, tam);
    cout << "\nMayor Elemento -> " << may;

    cin.ignore().get();
}

int multiplicar(int vec[], int tam)
{
    if (tam == 0)
    {
        return (vec[0]);
    }
    return (vec[tam] * multiplicar(vec, tam - 1));
}

int suma(int vec[], int tam)
{
    if (tam == 0)
        return vec[tam];
    else
        return suma(vec, tam - 1) + vec[tam];
}

void recorre(int x[], int n)
{
    if (n > 0)
    {
        recorre(x, n - 1);
    }
}

void mayor(int x[], int n, int &may)
{
    if (n > 0)
    {
        if (x[n - 1] > may)
            may = x[n - 1];
        mayor(x, n - 1, may);
    }
}

int createRandomNumber()
{
    return rand() % 21 + 1;
}