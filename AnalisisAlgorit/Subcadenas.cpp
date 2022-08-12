#include <iostream>
#include <string.h>
using namespace std;

/* Devuelve la longitud más larga
   subcadena común de X[0..m-1]
   y Y[0..n-1]*/
int LCSubStr(char *X, char *Y, int m, int n)
{
    /* Crear una tabla para almacenar
     longitudes de mayor
     sufijos comunes de subcadenas.
     Tenga en cuenta que LCSuff[i][j] contiene
     longitud del sufijo común más largo
     de X[0..i-1] e Y[0..j-1].*/

    int LCSuff[m + 1][n + 1];
    int result = 0; /* Para almacenar la longitud de la
                    subcadena común más larga*/

    /* Los siguientes pasos construyen LCSuff[m+1][n+1] en
        moda de abajo hacia arriba. */
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            /* La primera fila y la primera columna
            las entradas no tienen significado lógico,
            se usan solo por simplicidad
            de programa*/
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
            {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                result = max(result, LCSuff[i][j]);
            }
            else
                LCSuff[i][j] = 0;
        }
    }
    return result;
}

// Codigo main
int main()
{
    char X[] = "OldSite:GeeksforGeeks.org";
    char Y[] = "NewSite:GeeksQuiz.com";

    int m = strlen(X);
    int n = strlen(Y);

    cout << "La longitud de la subcadena comun mas larga es -> "
         << LCSubStr(X, Y, m, n);
    cin.ignore().get();
    return 0;
}