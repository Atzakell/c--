#include <iostream>

using namespace std;

struct nodo
{
    int nro;
    struct nodo *next;
};

typedef struct nodo *TpLista;
void menu();
void insertaInicio(TpLista &lista);
void BubbleSort(TpLista lista);
void verLista(TpLista lista);
TpLista crearNodo();

int main()
{
    TpLista lista = NULL;
    int opc;
    do
    {
        menu();
        cin >> opc;

        switch (opc)
        {
        case 1:
        {
            insertaInicio(lista);
            verLista(lista);
            system("pause");
            break;
        }
        case 2:
        {
            BubbleSort(lista);
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
    cout << "Ingresar dato --> ";
    cin >> nuevo->nro;
    cout << endl;
    nuevo->next = NULL;
    return nuevo;
}
void insertaInicio(TpLista &lista)
{

    TpLista ptr = crearNodo();
    if (lista != NULL)
        ptr->next = lista;
    lista = ptr;
}

void BubbleSort(TpLista lista)
{

    TpLista ptr = lista;
    int cont = 0, tmp = 0;
    bool flag = true;
    // contar numero de nodos
    while (ptr = NULL)
    {
        cont++;
        ptr = ptr->next;
    }

    for (int i = 1; i < cont - 1 && flag == true; i++)
    {
        ptr = lista;
        flag = false;
        while (ptr->next != NULL)
        {
            cout << "compara " << ptr->nro << " con " << ptr->next->nro << endl;
            if (ptr->nro > ptr->next->nro)
            {
                tmp = ptr->nro;
                ptr->next->nro = tmp;
                flag = true;
            }
            ptr = ptr->next;
        }
    }
}

void verLista(TpLista lista)
{

    int i = 0;
    while (lista != NULL)
    {
        cout << "[" << lista->nro << "] ";
        lista = lista->next;
        i++;
    }
}

void menu()
{

    system("CLS");
    cout << "\n\t Ordenamientos\n\n";
    cout << "1.- Insertar al inicio" << endl;
    cout << "2.- BubbleSort" << endl;
    cout << "0.- Salir" << endl
         << endl;

    cout << "Ingresar Opcion---> " << endl;
}