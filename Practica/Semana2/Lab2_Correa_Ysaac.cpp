#include <iostream>
#include <time.h>
using namespace std;

//?Estructura del nodo
struct nodo
{
    int dato;
    struct nodo *sgte;
};
// define el tipo de dato nodo como tpLista
typedef struct nodo *TpLista;

void menu();
TpLista crearNodo();
void insertaInicio(TpLista &lista);
void insertaFinal(TpLista &lista);
void insertaPosicion(TpLista &lista, int index);
int VerySumarLista(TpLista &lista);
int numeroRandom(); // random para el valor a insertar
int dado();         // random para el opc

int main()
{
    // no hace falta el * ya que se declaró como typedef
    TpLista lista = NULL;
    int n;
    int opc;
    do
    {
        menu();
        cin >> opc;
        switch (opc)
        {
        case 1:
            insertaInicio(lista);
            system("pause");
            break;
        case 2:
            insertaFinal(lista);
            system("pause");
            break;
        case 3:
            cout << "Ingresa la posicion ----> " << endl;
            cin >> n;
            cout << endl;
            if (n > 0)
            {
                insertaPosicion(lista, n);
            }
            else
            {
                cout << "\nERROR:no existen posiciones negativas ";
            }
            system("pause");
            break;
        case 4:
            cout << "La lista es -> " << VerySumarLista(lista) << endl;
            system("pause");
            break;
        default:
            break;
        }
    } while (opc != 0);
    cin.ignore().get();
}

void menu()
{
    system("CLS");
    cout << "\n\t LISTA ENLAZADA SIMPLE\n\n";
    cout << "[1]. Insertar al Inicio" << endl;
    cout << "[2]. Insertar al Final" << endl;
    cout << "[3]. Insertar por Posicion" << endl;
    cout << "[4]. Mostrar y Sumar de la lista" << endl;
    cout << "[5]. Eliminar al Inicio" << endl;
    cout << "[6]. Eliminar al Final" << endl;
    cout << "[7]. Eliminar por Posicion" << endl;
    cout << "[8]. Buscar y Reemplazar" << endl;

    cout << "[0]. Salir" << endl
         << endl;

    cout << "Escoga una accion ----> ";
}

void insertaInicio(TpLista &lista)
{
    // se crea un puntero q asignando valores que apunta a NULL
    TpLista q = crearNodo();
    //?insertar q a una lista existente
    if (lista != NULL)
    {
        q->sgte = lista; // el valor puntero sgte toma el valor de la lista
        lista = q;       // la nueva lista empezara en q
    }
}

void insertaFinal(TpLista &lista)
{
    // se crea un puntero q asignando valores que apunta a NULL
    TpLista temp = lista;
    TpLista ptr = crearNodo();
    if (lista == NULL)
    {
        lista = ptr;
        return;
    }
    //?insertar q a una lista existente
    while (temp->sgte != NULL)
    {
        temp = temp->sgte;
    }
    temp->sgte = ptr;
}

int VerySumarLista(TpLista &lista)
{
    int acum = 0;
    while (lista != NULL)
    {
        cout << lista->dato << " -> ";
        acum += lista->dato;
        lista = lista->sgte;
    }
    cout << "\nAcumulado de Nodos -> ";
    return acum;
}

int numeroRandom()
{
    return rand() % 100 + 1;
}

int dado()
{
    return rand() % 3 + 1;
}

void insertaPosicion(TpLista &lista, int index)
{
    TpLista t = lista, vr_res = NULL, ptr = NULL;
    int x = 1;
    bool flag = false;

    if (index == 1)
    {
        insertaInicio(lista);
        return;
    }
    ptr = crearNodo();

    while (x != index && t->sgte != NULL)
    {
        vr_res = t;
        t = t->sgte;
        x++;
        if (x == index)
        {
            flag = true;
        }
    }
    if (flag == true)
    {
        vr_res->sgte = ptr;
        ptr->sgte = t;
    }
    else
    {
        cout << "Error en la posicion";
        system("pause");
    }
}

void eliminarPrimerNodo(TpLista &lista)
{
    TpLista temp = lista;

    lista = lista->sgte;
    delete (temp);
}

void eliminarUltimoNodo(TpLista &lista)
{
    TpLista ptr = lista, vr_res = NULL;

    while (ptr->sgte != NULL)
    {
        vr_res = ptr;
        ptr = ptr->sgte;
    }
    vr_res = NULL;
    delete (ptr);
}

void eliminarPosicionNodo(TpLista &lista)
{
    TpLista t = lista, ptr = NULL;
    int index = 4;
    int x = 1;

    while (x != index)
    {
        ptr = t;
        t = t->sgte;
        x++;
    }
    ptr->sgte = t->sgte;
    delete (t);
}

TpLista crearNodo()
{
    TpLista new_ptr = NULL;
    new_ptr = new (struct nodo);
    cout << "Ingresar dato -> ";
    cin >> new_ptr->dato;
    cout << endl;
    new_ptr->sgte = NULL;
    return new_ptr;
}