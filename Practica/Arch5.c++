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

void encolar(TpLista &lista)
{
    TpLista p = lista;
    TpLista q = crearNodo();

    if (lista == NULL)
    {
        lista = q;
        return;
    }

    while (p->sgte != NULL)
    {
        p = p->sgte;
    }

    p->sgte = q;
}

void verCola(TpLista lista)
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
    cout << "\n\t LISTA ENLAZADA SIMPLE\n\n";
    cout << "1.- Encolar" << endl;
    cout << "2.- Desencolar" << endl;
    cout << "3.- Ver Cola" << endl;
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

            encolar(lista);
            system("pause");
            break;
        }
        case 2:
        {

            desencolar(lista);
            system("pause");
            break;
        }

        case 3:
        {
            verCola(lista);
            system("pause");
            break;
        }
        }
    } while (opc != 0);

    return 0;
}
