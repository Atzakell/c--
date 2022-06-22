#include <iostream>

using namespace std;

struct nodo
{
    int nro;
    struct nodo *sgte;
    struct nodo *ante;
};

typedef struct nodo *TpLista;

TpLista crearNodo();
void InsertarInicio(TpLista &lista);
void InsertarFinal(TpLista &lista);
void InsertarIndex(TpLista &lista, int pos);
void verLista(TpLista lista);
void EliminarInicio(TpLista &lista);
void EliminarFinal(TpLista &lista);
void EliminarIndex(TpLista &lista, int pos);
void menu();

int main()
{
    TpLista listaA = NULL;
    int index;
    int opc;
    do
    {
        menu();
        cin >> opc;

        switch (opc)
        {
        case 1:
        {

            InsertarInicio(listaA);
            system("pause");
            break;
        }
        case 2:
        {
            InsertarFinal(listaA);
            system("pause");
            break;
        }
        case 3:
        {
            cout << "Ingresar posicion ---->  ";
            cin >> index;
            cout << endl;
            if (index > 0)
                InsertarIndex(listaA, index);
            else
            {
                cout << "\nERROR: solo permite valores > 0 " << endl;
                system("pause");
            }
        }
        case 4:
        {
            EliminarInicio(listaA);
            system("pause");
            break;
        }
        case 5:
        {
            EliminarFinal(listaA);
            system("pause");
            break;
        }
        case 6:
        {
            cout << "Ingrese la posicion ->";
            cin >> index;
            EliminarIndex(listaA, index);
            system("pause");
            break;
        }
        case 7:
        {
            cout << "=======================LISTA A=================" << endl
                 << endl;
            verLista(listaA);
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
    nuevo->sgte = NULL;
    nuevo->ante = NULL;
    return nuevo;
}

void InsertarInicio(TpLista &lista)
{
    TpLista new_ptr = crearNodo();
    if (lista != NULL)
    {
        new_ptr->sgte = lista;
        lista->ante = new_ptr;
    }
    lista = new_ptr;
}

void InsertarFinal(TpLista &lista)
{
    TpLista new_ptr = lista;
    TpLista ptr = crearNodo();

    if (lista == NULL)
    {
        lista = ptr;
        return;
    }

    while (new_ptr->sgte != NULL)
    {
        new_ptr = new_ptr->sgte;
    }
    new_ptr->sgte = ptr;
    ptr->ante = new_ptr;
}

void InsertarIndex(TpLista &lista, int pos)
{
    TpLista new_ptr = lista, ptr = NULL;
    int cont = 1;
    bool flag = false;
    if (pos == 1)
    {
        InsertarInicio(lista);
        return;
    }
    ptr = crearNodo();

    while (cont != pos && new_ptr->sgte != NULL)
    {
        new_ptr = new_ptr->sgte;
        cont++;
        if (pos == cont)
            flag = true;
    }
    if (flag == true)
    {
        ptr->sgte = new_ptr;
        new_ptr->ante->sgte = ptr;
        ptr->ante = new_ptr->ante;
        new_ptr->ante = ptr;
    }
    else
    {
        cout << "ERROR: posicion ingresada no valida " << endl;
        system("pause");
    }
}

void EliminarInicio(TpLista &lista)
{

    if (lista == NULL)
    {
        cout << "ERROR: lista vacia ... no permitido" << endl;
        system("pause");
        return;
    }
    if (lista->sgte == NULL)
    {
        delete (lista);
        lista = NULL;
        return;
    }
    lista = lista->sgte;
    delete (lista->ante);
    lista->ante = NULL;
    system("pause");
}

void EliminarFinal(TpLista &lista)
{
    TpLista new_ptr = lista;
    if (lista == NULL)
    {
        cout << "ERROR: la lista esta vacia D:";
        system("pause");
        return;
    }
    if (lista->sgte == NULL)
    {
        lista = NULL;
        delete (new_ptr);
        return;
    }
    while (new_ptr != NULL)
    {
        new_ptr = new_ptr->sgte;
    }
    new_ptr->ante->sgte = NULL;
    cout << "El nodo eliminado es -> " << new_ptr->nro << endl;
    delete (new_ptr);
}

void EliminarIndex(TpLista &lista, int pos)
{
    TpLista new_ptr = lista;
    bool flag = false;
    int cont = 1;

    if (pos == 1)
    {
        EliminarInicio(lista);
        return;
    }
    if (lista == NULL)
    {
        cout << "ERROR: La lista se encuesta vacia";
        system("pause");
        return;
    }

    while (cont != pos && new_ptr->sgte != NULL)
    {
        new_ptr = new_ptr->sgte;
        cont++;
        if (cont == pos)
        {
            flag = true;
        }
    }
    if (flag == true)
    {
        if (new_ptr->sgte == NULL)
        {
            EliminarFinal(lista);
        }
        else
        {
            new_ptr->ante->sgte = new_ptr->sgte;
            new_ptr->sgte->ante = new_ptr->ante;
            cout << "El nodo eliminado es -> " << new_ptr->nro << endl;
            delete (new_ptr);
            system("pause");
        }
    }
    else
    {
        cout << "ERROR: Posicion fuera de rango D:";
        system("pause");
    }
}

void verLista(TpLista lista)
{
    TpLista retorno = NULL;
    int i = 0;
    cout << "Relacion de IDA" << endl
         << endl;
    while (lista != NULL)
    {
        cout << " " << i + 1 << ") " << lista->nro << endl;
        retorno = lista;
        lista = lista->sgte;
        i++;
    }
    lista = retorno;
    cout << "Relacion de RETORNO" << endl
         << endl;
    while (lista != NULL)
    {
        cout << " " << i + 1 << ") " << lista->nro << endl;
        lista = lista->ante;
        i--;
    }
}

void menu()
{

    system("CLS");
    cout << "\n\t Operaciones de PILA\n\n";
    cout << "1.- Insertar al Inicio " << endl;
    cout << "2.- Insertar al Final" << endl;
    cout << "3.- Insertar por posicion" << endl;
    cout << "4.- Eliminar al Inicio" << endl;
    cout << "5.- Eliminar al Final" << endl;
    cout << "6.- Eliminar por posicion" << endl;
    cout << "7.- Mostrar Lista" << endl;
    cout << "0.- Salir" << endl
         << endl;

    cout << "Ingresar Opcion---> " << endl;
}
