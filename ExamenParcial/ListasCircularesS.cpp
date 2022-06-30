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

    while (x = !pos && p->sgte != lista)
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
    TpLista ptr = lista, tmp = NULL;
    if (lista == NULL)
    {
        cout << "ERROR: lista vacia ... no permitido ";
        system("pause");
        return;
    }
    if (lista->sgte != lista)
    {
        while (ptr->sgte != lista)
        {
            tmp = ptr;
            ptr = ptr->sgte;
        }
        tmp->sgte = lista;
        cout << "\n Nodo al final eliminado -> " << ptr->nro << endl;
        delete (ptr);
        system("pause");
    }
    else
    {
        lista = NULL;
        cout << "\n Nodo al final eliminado -> " << ptr->nro << endl;
        delete (ptr);
        system("pause");
    }
}

void eliminarInicio(TpLista &lista)
{
    TpLista ptr = lista, tmp = lista;
    if (lista == NULL)
    {
        cout << "ERROR: lista vacia ... no permitido ";
        system("pause");
        return;
    }
    while (ptr->sgte != lista)
        ptr = ptr->sgte;

    ptr->sgte = lista->sgte;
    lista = lista->sgte;

    cout << "\nEl elemento eliminado al inicio es -> " << tmp->nro << endl;
    delete (tmp);
    system("pause");
}

void insertaInicio(TpLista &lista)
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
        lista = ptr;
    }
    cout << "El dato ingresado alinicio es -> " << ptr->nro << endl;
}

void insertaFinal(TpLista &lista)
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

    cout << "El dato ingresado al final es -> " << ptr->nro << endl;
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

    while (x != pos && p->sgte != lista)
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
    TpLista ptr = lista;
    int i = 0;
    if (lista == NULL)
    {
        cout << "ERROR: lista vacia " << endl;
        return;
    }

    while (ptr->sgte != lista)
    {
        cout << " " << i + 1 << ") " << ptr->nro << endl;
        ptr = ptr->sgte;
        i++;
    }
    cout << " " << i + 1 << ") " << ptr->nro << endl;
}

void menu()
{

    system("CLS");
    cout << "\n\t LISTA CIRCULAR SIMPLE\n\n";
    cout << "1.- Insertar al Inicio" << endl;
    cout << "2.- Insertar al Final" << endl;
    cout << "3.- Insertar por Posicion" << endl;
    cout << "4.- Mostrar Lista" << endl;
    cout << "5.- Eliminar al Inicio" << endl;
    cout << "6.- Eliminar al Final" << endl;
    cout << "7.- Eliminar por Posicion" << endl;
    cout << "0.- Salir" << endl
         << endl;

    cout << "Ingresar Opcion---> ";
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
