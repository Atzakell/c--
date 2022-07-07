#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct nodo
{
    int peso1;
    int peso2;
    int peso3;
    struct nodo *sgte;
    struct nodo *ante;
};

typedef struct nodo *TpLista;

void menu();
TpLista crearNodo();
void push(TpLista &lista);
TpLista pop(TpLista &lista);
void pushTraslado(TpLista &lista, TpLista ptr);
void AsignarPesos(TpLista &lista);
void verPila1(TpLista lista);
void verPilaIDA(TpLista lista);
void verPilaIDA2(TpLista lista);
int random(int menor, int mayor);

int main()
{
    TpLista pilaA = NULL, FDescarga = NULL;
    TpLista temp = NULL;
    int n = 0;
    int opc;
    do
    {
        menu();
        cin >> opc;

        switch (opc)
        {
        case 1:
        {
            push(pilaA);
            break;
        }
        case 2:
        {
            temp = pop(pilaA);
            pushTraslado(FDescarga, temp);
            cout << "\n\n=================PILA DE DESCARGA==================" << endl
                 << endl;
            verPilaIDA(FDescarga);
            system("pause");
            break;
        }
        case 3:
        {
            AsignarPesos(FDescarga);
            cout << "\n\n=================PILA DE DESCARGA==================" << endl;
            verPilaIDA2(FDescarga);
            system("pause");
            break;
        }
        case 5:
        {
            verPila1(pilaA);
            system("pause");
            break;
        }
        }
    } while (opc != 0);
    return 0;
}

TpLista crearNodo()
{
    TpLista nuevo = NULL;
    nuevo = new (struct nodo);
    nuevo->peso1 = random(10, 50);
    nuevo->peso2 = 0;
    nuevo->peso3 = 0;
    cout << "El peso ingresado es -> " << nuevo->peso1 << endl;
    system("pause");
    nuevo->sgte = NULL;
    nuevo->ante = NULL;
    return nuevo;
}

void push(TpLista &lista)
{
    static int x = 1;
    if (x <= 5)
    {
        TpLista new_ptr = crearNodo();
        if (lista != NULL)
        {
            new_ptr->sgte = lista;
            lista->ante = new_ptr;
        }
        lista = new_ptr;
        x++;
    }
    else
    {
        cout << "LIMITE MAXIMO DE PESOS ";
        system("pause");
        menu();
    }
}

// Extraer mediante pop una direccion de memoria
TpLista pop(TpLista &lista)
{
    TpLista ptr = lista;
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
}
// no se ejecuta bien, el primer valor se chanca cada vez que se asigna ;(
void AsignarPesos(TpLista &lista)
{
    TpLista new_ptr = lista;
    new_ptr->peso2 = random(10, 20);
    lista = lista->sgte;
}

void verPila1(TpLista lista)
{
    int i = 0;
    while (lista != NULL)
    {
        cout << " " << i + 1 << ") " << lista->peso1 << endl;
        lista = lista->sgte;
        i++;
    }
}

void verPilaIDA(TpLista lista)
{
    int i = 0;
    while (lista != NULL)
    {
        cout << " [" << lista->peso1 << "]  ";
        lista = lista->sgte;
        i++;
    }
}

void verPilaIDA2(TpLista lista)
{
    int i = 0;
    while (lista != NULL)
    {
        cout << "  [" << lista->peso2 << "]\n"
             << "  [" << lista->peso1 << "]" << endl;
        cout << endl;
        lista = lista->sgte;
        i++;
    }
}

void menu()
{

    system("CLS");
    cout << "\n\t Operaciones de PILA\n\n";
    cout << "1.- Insertar elementos en Pila " << endl;
    cout << "2.- Descargar elemetos de la Pila" << endl;
    cout << "3.- Asignar pesos a lista" << endl;
    cout << "5.- Mostrar Pila" << endl;
    cout << "0.- Salir" << endl
         << endl;

    cout << "Ingresar Opcion---> ";
}

int random(int menor, int mayor)
{
    return menor + rand() % (mayor - menor + 1);
}
