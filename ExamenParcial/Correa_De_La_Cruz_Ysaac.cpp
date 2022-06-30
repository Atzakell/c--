#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <ctype.h>
#include <cstdlib>

using namespace std;

struct nodo
{
    string tipo;
    int valor;
    struct nodo *sgte;
};

typedef struct nodo *TpLista;

TpLista crearNodo();
void menu();
int random(int menor, int mayor);
void insertarNodo(TpLista &lista);
void verListaCircular(TpLista lista);
void recorrer(TpLista &lista);
TpLista pop(TpLista &lista);
void pushTraslado(TpLista &lista, TpLista ptr);
void verPilaIDA(TpLista lista);

string type[] = {"A", "B", "C"};

int main()
{
    srand(time(NULL));
    TpLista nodoA = NULL, FColocar = NULL, temp = NULL;
    int opcion;
    do
    {
        menu();
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            insertarNodo(nodoA);
            cout << endl;
            cout << "\n\tLISTA CIRCULAR" << endl
                 << endl;
            verListaCircular(nodoA);
            system("pause");
            break;
        }
        case 2:
        {
            recorrer(nodoA);
            temp = pop(nodoA);
            pushTraslado(FColocar, temp);
            cout << endl;
            cout << "\n\tLISTA CIRCULAR" << endl
                 << endl;
            verListaCircular(nodoA);
            cout << "\n\tLISTA CIRCULAR" << endl
                 << endl;
            verPilaIDA(FColocar);
            system("pause");
            break;
        }

        default:
            break;
        }

    } while (opcion != 0);
}

TpLista crearNodo()
{
    int letra = rand() % 3;

    TpLista nuevo = NULL;
    nuevo = new (struct nodo);
    nuevo->tipo = type[letra];
    nuevo->valor = random(1, 50);
    nuevo->sgte = NULL;
    return nuevo;
}
// usé la insercion al final para la lista, visualmente es mas comoda

void insertarNodo(TpLista &lista)
{
    TpLista tmp = lista;
    TpLista ptr = crearNodo();

    if (lista == NULL)
    {
        lista = ptr;
        ptr->sgte = lista;
    }
    else
    {
        while (tmp->sgte != lista)
            tmp = tmp->sgte;

        tmp->sgte = ptr;
        ptr->sgte = lista;
    }
    cout << "El dato ingresado es -> [" << ptr->tipo << "|" << ptr->valor << "]" << endl;
}

void recorrer(TpLista &lista)
{
    TpLista tmp = lista;
    if (tmp != NULL)
    {
        do
        {
            tmp->valor = tmp->valor + 40;
            tmp = tmp->sgte;

        } while (tmp != lista);
        if (tmp->valor > 100)
        {
            pop(tmp);
        }
    }
    else
    {
        cout << "ERROR: Lista vacia ";
    }
}
// Extraer mediante pop una direccion de memoria
TpLista pop(TpLista &lista)
{
    TpLista ptr = lista, temp = lista;
    if (lista == NULL)
    {
        cout << "ERROR: lista vacia ... no permitido ";
        return ptr;
    }
    lista = lista->sgte;
    ptr->sgte = NULL;

    return ptr;
}

void pushTraslado(TpLista &lista, TpLista ptr)
{
    if (lista != NULL)
    {
        ptr->sgte = lista;
    }
    lista = ptr;
    ptr->sgte = lista;
}
void verListaCircular(TpLista lista)
{
    TpLista ptr = lista;
    int i = 0;

    if (lista == NULL)
    {
        cout << "ERROR: lista vacia " << endl;
        return;
    }

    while (ptr->sgte != lista)
    {
        cout << "[" << ptr->tipo << "|" << ptr->valor << "]  ";
        ptr = ptr->sgte;
        i++;
    }
    cout << "[" << ptr->tipo << "|" << ptr->valor << "]  ";
}

void verPilaIDA(TpLista lista)
{
    int i = 0;
    while (lista != NULL)
    {
        cout << " [" << lista->tipo << "|" << lista->valor << "]  ";
        lista = lista->sgte;
        i++;
    }
}

// funcion practica de random para el valor de 50 y 100
int random(int menor, int mayor)
{
    return menor + rand() % (mayor - menor + 1);
}

// menu de selecciones segun los que nos piden
void menu()
{
    system("CLS");
    cout << "\n\t MENU DE OPCIONES \n\n";
    cout << "1.-Insertar Elementos a la LCS" << endl;
    cout << "2.-Adicionar y Transferir la LCS" << endl;
    cout << "3.-" << endl;
    cout << "0.-Salir" << endl
         << endl;

    cout << "Ingresar Opcion---> ";
}