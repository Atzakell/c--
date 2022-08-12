#include <bits/stdc++.h>
using namespace std;

// Una función de utilidad que devuelve
// máximo de dos enteros
int max(int a, int b) { return (a > b) ? a : b; }

// Devuelve el valor máximo que
// se puede poner en una mochila de capacidad W
int knapSack(int W, int wt[], int val[], int n)
{

    // Caso base
    if (n == 0 || W == 0)
        return 0;

    /*Si el peso del artículo n es mayor
     que la capacidad de la mochila W, entonces
     este artículo no puede ser incluido
     en la solucion optima*/
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);

    /*Devolver el máximo de dos casos:
    (1) artículo n incluido
    (2) no incluido*/
    else
        return max(
            val[n - 1] + knapSack(W - wt[n - 1],
                                  wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}

// Código del main
int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << "\tEjecutando problema de la mochila " << endl;
    cout << "\tProduccion -> " << knapSack(W, wt, val, n);
    cin.ignore().get();
    return 0;
}