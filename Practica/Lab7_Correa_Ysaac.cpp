#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct nodo
{
    int id;
    int peso;
    struct nodo *sgte;
};

typedef struct nodo *TpLista;

int random(int menor, int mayor);
TpLista crearNodo();
void insertaFinal(TpLista &lista);
void verPila(TpLista lista);
void Seleccion(TpLista lista);
void menu();

int main()
{
    srand(time(NULL));
    TpLista pilaA = NULL;
    int opc;
    do
    {
        menu();
        cin >> opc;

        switch (opc)
        {
        case 1:
        {
            insertaFinal(pilaA);
            verPila(pilaA);
            system("pause");
            break;
        }
        case 2:
        {
            verPila(pilaA);
            system("pause");
            break;
        }

        case 3:
        {
            Seleccion(pilaA);
            system("pause");

            break;
        }
        }
    } while (opc != 0);

    return 0;
}
// funcion practica de random para el valor de 50 y 100
int random(int menor, int mayor)
{
    return menor + rand() % (mayor - menor + 1);
}

// definiendo la estructura del nodo
TpLista crearNodo()
{
    TpLista nuevo = NULL;
    static int var = 0;
    nuevo = new (struct nodo);
    nuevo->id = var++;
    nuevo->peso = random(50, 100);
    nuevo->sgte = NULL;
    return nuevo;
}

// insertar al final
void insertaFinal(TpLista &lista)
{
    TpLista ptr = lista;
    TpLista new_ptr = crearNodo();

    if (lista == NULL)
    {
        lista = new_ptr;
        return;
    }

    while (ptr->sgte != NULL)
    {
        ptr = ptr->sgte;
    }

    ptr->sgte = new_ptr;
}

// visualizar lista, cantidad de nodos y promedio de pesos
void verPila(TpLista lista)
{

    int i = 0;
    float acum = 0;
    float promedio;
    while (lista != NULL)
    {
        cout << "[P" << lista->id << "|" << lista->peso << "kg]  ";
        acum = acum + lista->peso;
        lista = lista->sgte;
        i++;
    }
    promedio = acum / i;
    cout << "\n\nNumero de Productos -> " << i;
    cout << "\nEl peso promedio es -> " << promedio << endl;
}

// ordenamiento por seleccion
void Seleccion(TpLista lista)
{
    // declaracion de nodos
    TpLista actl, sgte;
    TpLista min;
    int tmp, minimo;
    actl = lista; // asigno actual nodo al inico de la lista
    // recorrer
    while (actl->sgte != NULL)
    {
        // el int minimo toma el dato incial
        minimo = actl->peso;
        // otro nodo mini que inicia en lista, aqui los que planeo es que recorra
        min = actl;
        // por ultimo el nodo sgte toma el segundo elemento de la lista
        sgte = actl->sgte;

        while (sgte != NULL)
        {
            // si la lista es 10->7->5->18
            if (sgte->peso < minimo) // 7<10
            {
                minimo = sgte->peso; // int minimo=7
                min = sgte;          // min ahora avanza al nodo siguiente
            }

            sgte = sgte->sgte; // el nodo sgte sigue recorriendo
        }

        tmp = actl->peso;       // tmp = 10
        actl->peso = min->peso; // cambiamos 10 por 7
        min->peso = tmp;        // cambiamos 7 por 10

        actl = actl->sgte; // ahora actual avanza
    }

    cout << "\tLista ordenada por pesos exitosa" << endl;
}

void menu()
{

    system("CLS");
    cout << "\n\t DELIVERY ABARROTES Y ELECTRO\n\n";
    cout << "1.- Registra paquete " << endl;
    cout << "2.- Verificar Registro " << endl;
    cout << "3.- Ordenar segun el peso " << endl;
    cout << "0.- Salir" << endl
         << endl;

    cout << "Ingresar Opcion---> " << endl;
}