#include <iostream>

using namespace std;
struct nodo
{
    int nro;
    struct nodo *sgte;
};

typedef struct nodo *TpLista;

void eliminarInicio(TpLista &lista);

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

void eliminarPosicion(TpLista &lista, int pos)
{
    TpLista p = lista, t = NULL;
    int x = 1;
    bool flag = false;

    if (pos == 1)
    {
        eliminarInicio(lista);
        return;
    }
    if (lista == NULL)
    {
        cout << "ERROR: lista vacia ... no permitido ";
        system("pause");
        return;
    }

    while (x = !pos && p->sgte != NULL)
    {
        t = p;
        p = p->sgte;
        x++;
        if (x == pos)
            flag == true;
    }

    if (flag == true)
    {
        t->sgte = p->sgte;
        cout << "Nodo eliminado es Nr. " << p->nro << endl;
        delete (p);
        system("pause");
    }
    else
    {
        cout << endl
             << "ERROR: Posicion fuera de rango ";
        system("pause");
    }
}

void eliminarFinal(TpLista &lista)
{
    TpLista p = lista, t = NULL;
    if (lista == NULL)
    {
        cout << "ERROR: lista vacia ... no permitido ";
        system("pause");
        return;
    }
    if (lista->sgte = NULL)
    {
        lista = NULL;
        delete (p);
        return;
    }

    while (p->sgte != NULL)
    {
        t = p;
        p = p->sgte;
    }
    t->sgte = NULL;
    cout << "Nodo eliminado es Nr. " << p->nro << endl;
    delete (p);
    system("pause");
}

void eliminarInicio(TpLista &lista)
{
    TpLista t = lista;
    if (lista == NULL)
    {
        cout << "ERROR: lista vacia ... no permitido ";
        system("pause");
        return;
    }
    lista = lista->sgte;
    delete (t);
    system("pause");
}

void insertaInicio(TpLista &lista)
{

    TpLista q = crearNodo();
    if (lista != NULL)
        q->sgte = lista;
    lista = q;
}

void insertaFinal(TpLista &lista)
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

void insertaPosicion(TpLista &lista, int pos)
{
    TpLista p = lista, t = NULL, q = NULL;
    int x = 1;
    bool flag = false;

    if (pos == 1)
    {
        insertaInicio(lista);
        return;
    }
    q = crearNodo();

    while (x != pos && p->sgte != NULL)
    {
        t = p;
        p = p->sgte;
        x++;
        if (pos == x)
            flag = true;
    }
    if (flag == true)
    {
        t->sgte = q;
        q->sgte = p;
    }
    else
    {
        cout << "ERROR: Posicion ingresada fuera de rango..." << endl;
        system("pause");
    }
}

void verLista(TpLista lista)
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
    cout << "1.- Insertar al Inicio" << endl;
    cout << "2.- Insertar al Final" << endl;
    cout << "3.- Insertar por Posicion" << endl;
    cout << "4.- Mostrar Lista" << endl;
    cout << "5.- Eliminar al Inicio" << endl;
    cout << "6.- Eliminar al Final" << endl;
    cout << "7.- Eliminar por Posicion" << endl;
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

            insertaInicio(lista);
            system("pause");
            break;
        }
        case 2:
        {

            insertaFinal(lista);
            system("pause");
            break;
        }
        case 3:
        {
            cout << "Ingresar posicion ---->  ";
            cin >> n;
            cout << endl;
            if (n > 0)
                insertaPosicion(lista, n);
            else
            {
                cout << "\nERROR: solo permite valores > 0 " << endl;
                system("pause");
            }

            break;
        }

        case 4:
        {
            verLista(lista);
            system("pause");
            break;
        }

        case 5:
        {
            eliminarInicio(lista);
            break;
        }
        case 6:
        {
            eliminarFinal(lista);
            break;
        }
        case 7:
        {
            cout << "\nIngrese posicion -> ";
            cin >> index;
            eliminarPosicion(lista, index);
            system("pause");
            break;
        }
        }
    } while (opc != 0);

    return 0;
}
