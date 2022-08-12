#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct Nodo
{
    int date;
    Nodo *der;
    Nodo *izq;
};

typedef struct Nodo *abb;

abb arbol = NULL;
abb crearNodo(int n);
void mostrarArbol(abb arbol, int cont);
bool busquedaIterativo(abb arbol, int x);
void insertarIretativo(int x);
void mostrarArbol(abb arbol, int cont);
void PreOrden(abb arbol);
void InOrden(abb arbol);
void PostOrden(abb arbol);

void menu();

int main()
{

    int dato = 0, cont = 0, opcion;
    do
    {
        menu();
        cin >> opcion;
        switch (opcion)
        {
        case 1:
        {
            cout << "Ingrese el dato -> ";
            cin >> dato;
            insertarIretativo(dato);
            mostrarArbol(arbol, cont);
            system("pause");
            break;
        }
        case 2:
        {
            PreOrden(arbol);
            system("pause");
            break;
        }
        case 3:
        {

            InOrden(arbol);
            system("pause");
            break;
        }
        case 4:
        {

            PostOrden(arbol);
            system("pause");
            break;
        }
        default:

            break;
        }
    } while (opcion != 0); // fin do while

    menu();
    // getch();
    return 0;
}
/* no lo utilice ya que prefiero declararlo en la misma funcion insertar
abb crearNodo(int n)
{
    abb new_node = new Nodo();
    new_node->date = n;
    new_node->der = NULL;
    new_node->izq = NULL;

    return new_node;
}*/
/*ESTA FUNCION ES PARA CONSISTENCIAR QUE NO SE REPITAN LOS NODOS
bool busquedaIterativo(abb arbol, int x)
{
    if (arbol == NULL) // si el arbol esta vacio
        return false;  // no se puede buscar
    else
    {
        while (arbol != NULL && x != arbol->date)
        {                        // no esta vacio y es diferente al dato del nodo
            if (x < arbol->date) // 7<10 → 7 izquierda
                arbol = arbol->izq;
            else // 15<10 → 15 derecha
                arbol = arbol->der;
        }
        if (arbol != NULL)
            return true; // activar el bool
        else
            return false;
    }
}*/

// inserciones de manera iterativa
void insertarIretativo(int x)
{
    abb new_node = new (struct Nodo);
    new_node->date = x;
    new_node->der = NULL;
    new_node->izq = NULL;
    if (arbol == NULL)
    {
        arbol = new_node; // Se convierte en el nodo raiz
    }
    else
    {
        // if (busquedaIterativo(arbol, x) == false) nota: esto se usa con la consistencia
        //{ // valida si es nodo es apto
        abb anterior, reco;
        anterior = NULL;
        reco = arbol; // le asignamos el nodo arbol
        while (reco != NULL)
        {
            anterior = reco; // guarda la dirección de reco
            if (x < reco->date)
                reco = reco->izq; // 7<10 avanza hacia la izquierda
            else
                reco = reco->der; // 15<10 avanza hacia la derecha
        }
        if (x < anterior->date)
            anterior->izq = new_node;
        else
            anterior->der = new_node;
        //}
        // else
        // cout << "\nEl Dato ingresado ya existe" << endl;
    }
}

void menu()
{
    system("CLS");
    cout << "\n\t MENU" << endl;
    cout << "\n\t [1]. Insertar Nuevo Nodo Iterativo" << endl;
    cout << "\n\t [2]. PreOrden" << endl;
    cout << "\n\t [3]. InOrden" << endl;
    cout << "\n\t [4]. PostOrden" << endl;
    cout << "\n\t [0]. Salir" << endl;
    cout << "\n\t Opcion: ";
}

void mostrarArbol(abb arbol, int cont)
{
    if (arbol == NULL)
    {
        return;
    }
    else
    {
        mostrarArbol(arbol->der, cont + 1);
        int i;
        for (i = 0; i < cont; i++)
        {
            printf("   ");
        }
        printf("%d\n", arbol->date);
        mostrarArbol(arbol->izq, cont + 1);
    }
}

// RECORRIDOS
void PreOrden(abb arbol)
{
    if (arbol == NULL)
    {
        return;
    }
    else
    {
        printf(" %d - ", arbol->date);
        PreOrden(arbol->izq);
        PreOrden(arbol->der);
    }
}

void InOrden(abb arbol)
{
    if (arbol == NULL)
    {
        return;
    }
    else
    {
        InOrden(arbol->izq);
        printf(" %d - ", arbol->date);
        InOrden(arbol->der);
    }
}

void PostOrden(abb arbol)
{
    if (arbol == NULL)
    {
        return;
    }
    else
    {
        PostOrden(arbol->izq);
        PostOrden(arbol->der);
        printf(" %d - ", arbol->date);
    }
}