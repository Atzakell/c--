#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void menu();

struct nodo
{
    string nom;
    int nro;
    struct nodo *sgte;
};

typedef struct nodo *TpLista;

int randomid()
{
    int x;
    x = 1 + rand() % (1001 - 1);
    return x;
}

TpLista crearNodo()
{
    TpLista nuevo = NULL;
    nuevo = new (struct nodo);
    cout << "Ingresar pedido (tipo,id)--> ";
    cin >> nuevo->nom;
    nuevo->nro = randomid();
    cout << " id-> " << nuevo->nro;
    cout << endl;
    nuevo->sgte = NULL;
    return nuevo;
}

void push(TpLista &lista)
{
    static int x = 1;
    if (x <= 8)
    {
        TpLista q = crearNodo();
        if (lista != NULL)
        {
            q->sgte = lista;
        }
        lista = q;
        x++;
    }
    else
    {
        cout << "LIMITE MAXIMO DE PEDIDOS ";
        system("pause");
        menu();
    }
}

// Extraer mediante pop una direccion de memoria
TpLista pop(TpLista &lista)
{
    TpLista t = lista;
    if (lista == NULL)
    {
        cout << "ERROR: lista vacia ... no permitido ";
        return t;
    }
    lista = lista->sgte;
    t->sgte = NULL;
    return t;
}

void verPila(TpLista lista)
{

    int i = 0;
    while (lista != NULL)
    {
        cout << " " << i + 1 << ") " << lista->nom << " , " << lista->nro << endl;
        lista = lista->sgte;
        i++;
    }
}
// existe una inconsistencia -> cuando aplicas reasignar a una pila por segunda vez se sobreescribe el pedido sin embargo la tercera vez que se reasigna si se aplica
void pushTraslado(TpLista &lista1, TpLista &lista2, TpLista ptr)
{
    if (lista1 != NULL && lista2 != NULL)
    {
        if (ptr->nom == "abarr")
        {
            ptr->sgte = lista1;
        }

        if (ptr->nom == "elec")
        {
            ptr->sgte = lista2;
        }
    }

    if (ptr->nom == "abarr")
    {
        lista1 = ptr;
    }

    if (ptr->nom == "elec")
    {
        lista2 = ptr;
    }
}

void desencolar(TpLista &lista)
{
    TpLista t = lista;
    if (lista == NULL)
    {
        cout << "ERROR: lista vacia ... no permitido ";
        return;
    }
    lista = lista->sgte;
    delete (t);
}

void despachar(TpLista &lista1, TpLista &lista2, string tipo)
{
    if (tipo == "abarr")
    {
        desencolar(lista1);
    }
    else if (tipo == "elec")
    {
        desencolar(lista2);
    }
    else
    {
        cout << "ERROR EN INDICAR EL TIPO ";
        menu();
    }
}

void menu()
{

    system("CLS");
    cout << "\n\t DELIVERY ABARROTES Y ELECTRO\n\n";
    cout << "1.- Recibir Pedido " << endl;
    cout << "2.- Reasignar pedidos " << endl;
    cout << "3.- Mostrar listas " << endl;
    cout << "4.- Despachar paquete " << endl;
    cout << "0.- Salir" << endl
         << endl;

    cout << "Ingresar Opcion---> " << endl;
}

int main()
{
    srand(time(NULL));
    TpLista pilaP = NULL, pilaA = NULL, pilaE = NULL;
    TpLista temp = NULL;
    string tipo;
    int opc;
    do
    {
        menu();
        cin >> opc;

        switch (opc)
        {
        case 1:
        {

            push(pilaP);
            system("pause");
            break;
        }
        case 2:
        {
            temp = pop(pilaP);
            pushTraslado(pilaA, pilaE, temp);
            system("pause");
            break;
        }

        case 3:
        {
            cout << "======================= LISTA DE PEDIDOS =================" << endl
                 << endl;
            verPila(pilaP);
            cout << "======================= ABARROTES =================" << endl
                 << endl;
            verPila(pilaA);
            cout << "======================= ELECTRO =================" << endl
                 << endl;
            verPila(pilaE);
            system("pause");

            break;
        }
        case 4:
        {
            cout << "Indicar el tipo (abarr/elec) -> ";
            cin >> tipo;
            despachar(pilaA, pilaE, tipo);
            cout << "Despacho Exitoso :D";
            system("pause");
            break;
        }
        }
    } while (opc != 0);

    return 0;
}
