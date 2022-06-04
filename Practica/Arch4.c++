#include <iostream>

using namespace std;
struct nodo
{
    int nro;
    struct nodo *sgte;
};

typedef struct nodo *TpLista;

TpLista crearNodo()
{
    TpLista nuevo = NULL;
    nuevo = new (struct nodo);
    cout << "Ingresar dato --> ";
    cin >> nuevo->nro;
    cout << endl;
    nuevo->sgte = NULL;
    return nuevo;
}

void push(TpLista &lista)
{

    TpLista q = crearNodo();
    if (lista != NULL)
        q->sgte = lista;
    lista = q;
}

void pop(TpLista &lista)
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

void verPila(TpLista lista)
{

    int i = 0;
    while (lista != NULL)
    {
        cout << " " << i + 1 << ") " << lista->nro << endl;
        lista = lista->sgte;
        i++;
    }
}

void menu()
{

    system("CLS");
    cout << "\n\t Operaciones de PILA\n\n";
    cout << "1.- Funcion Push" << endl;
    cout << "2.- Funcion Pop" << endl;
    cout << "3.- Ver Pila" << endl;
    cout << "0.- Salir" << endl
         << endl;

    cout << "Ingresar Opcion---> " << endl;
}

int main()
{
    TpLista lista = NULL;
    int opc, n, index;
    do
    {
        menu();
        cin >> opc;

        switch (opc)
        {
        case 1:
        {

            push(lista);
            system("pause");
            break;
        }
        case 2:
        {

            pop(lista);
            system("pause");
            break;
        }

        case 3:
        {
            verPila(lista);
            system("pause");
            break;
        }
        }
    } while (opc != 0);

    return 0;
}
