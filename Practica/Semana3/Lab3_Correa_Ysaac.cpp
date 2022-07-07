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

TpLista crearNodo();
void menu();
void insertaFinal(TpLista &lista);
void mostrarLista(TpLista lista);
int Par(TpLista &lista);
int Suma(TpLista &lista);
int Cant(TpLista &lista);

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
            insertaFinal(lista);
            mostrarLista(lista);
            system("pause");
            break;
        case 2:
            mostrarLista(lista);
            cout << "\nNumero de Nodos -> " << Cant(lista);
            cout << "\nAcumulado -> " << Suma(lista);
            cout << endl;
            system("pause");
            break;
        case 3:

            system("pause");
            break;
        case 4:

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
    cout << "[1]. Insertar al Final" << endl;
    cout << "[2]. Mostrar Nodos y Suma" << endl;
    cout << "[3]. Insertar por Posicion" << endl;

    cout << "[0]. Salir" << endl
         << endl;

    cout << "Escoga una accion ----> ";
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

TpLista crearNodo()
{
    TpLista new_ptr = NULL;

    new_ptr = new (struct nodo);
    cout << "Ingresar dato -> ";
    cin >> new_ptr->dato;
    cout << endl;
    new_ptr->dato = Par(new_ptr); // asigno la funcion para que compruebe la paridad
                                  // si es correcto se crea el nodo correctamente
    new_ptr->sgte = NULL;
    return new_ptr;
}

void mostrarLista(TpLista lista)
{
    int cont = 0;
    while (lista != NULL)
    {
        cout << " " << cont + 1 << ") " << lista->dato << endl;
        lista = lista->sgte;
        cont++;
    }
}

int Par(TpLista &lista)
{
    int num_par = lista->dato; // valor aux al campo dato dela lista
    int mayor = 999;
    while (num_par % 2 == 1 || num_par > mayor) // ciclo de comprobacion de par o impar
    {

        if (num_par < mayor && num_par % 2 == 0)
        {
            cout << lista->dato;
            mayor = lista->dato;
            return num_par;
        }
        else
        {
            cout << "\nERROR" << endl;
            cout << "Ingrese un numero par y menor-> ";
            cin >> num_par;
        }
    }

    // retorno del valor par
}

int Suma(TpLista &lista)
{ // declaro una variable reserva para no tocar la lista
    TpLista var_rsv = lista;
    int acum = 0;
    // recorrer lista
    while (var_rsv != NULL)
    {
        acum = acum + var_rsv->dato; // acumulando valores
        var_rsv = var_rsv->sgte;
    }
    return acum; // retorno la suma
}

int Cant(TpLista &lista)
{ // declaro una variable reserva para no tocar la lista
    TpLista var_rsv = lista;
    int cont = 0;
    while (var_rsv != NULL) // contando las repeticiones
    {
        var_rsv = var_rsv->sgte;
        cont++;
    }
    return cont; // retornando el contador
}