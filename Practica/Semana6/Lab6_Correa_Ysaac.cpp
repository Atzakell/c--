#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
// definir el nodo
struct nodo
{
    string L;
    int id;
    int nro;
    struct nodo *sgte;
    struct nodo *ante;
};

typedef struct nodo *TpLista;

// funciones
TpLista crearNodo();
void InsertarNodo(TpLista &lista);
void recorrer(TpLista &lista);
void verLista(TpLista lista);
void EliminarInicio(TpLista &lista);
void EliminarFinal(TpLista &lista);
void EliminarIndex(TpLista &lista, int pos);
void menu();
int random(int menor, int mayor);

int main()
{
    srand(time(NULL));
    TpLista listaA = NULL;
    int opc;
    do
    {
        menu();
        cin >> opc;

        switch (opc)
        {
        case 1:
        {

            InsertarNodo(listaA);
            verLista(listaA);
            system("pause");
            break;
        }
        case 2:
        {
            recorrer(listaA);
            verLista(listaA);
            system("pause");
            break;
        }
        }
    } while (opc != 0);

    return 0;
}
// funcion practica de random para el valor de 100 y 300
int random(int menor, int mayor)
{
    return menor + rand() % (mayor - menor + 1);
}
// creacion de nodo
TpLista crearNodo()
{
    TpLista nuevo = NULL;
    static int var = 0;
    nuevo = new (struct nodo);
    nuevo->L = 'C';
    nuevo->id = var++;
    nuevo->nro = random(100, 300);
    cout << endl;
    nuevo->sgte = NULL;
    nuevo->ante = NULL;
    return nuevo;
}
// Insertar nodos, en este caso puse que se inserten al final
void InsertarNodo(TpLista &lista)
{
    TpLista tmp = lista;
    TpLista new_ptr = crearNodo();
    if (lista == NULL)
    {
        lista = new_ptr;
        new_ptr->sgte = lista;
        new_ptr->ante = lista;
    }
    else
    {
        lista->ante->sgte = new_ptr;
        new_ptr->ante = lista->ante;
        new_ptr->sgte = lista;
        lista->ante = new_ptr;
    }
}
// esta funcion recorre la lista restando 50 a cada nodo
void recorrer(TpLista &lista)
{
    TpLista tmp = lista;
    static int cont = 0; // variable estatica, para mi forma practica de contar las vueltas
    if (tmp != NULL)
    {
        do
        {
            tmp->nro = tmp->nro - 50;
            tmp = tmp->ante;
        } while (tmp != lista);
        cont++;
        cout << "\nNumero de vueltas -> " << cont;
    }
    else
    {
        cout << "ERROR: Lista vacia ";
    }
}
// extraccion parecido a un pop
TpLista pop(TpLista &lista)
{
    TpLista tmp = lista;
    if (lista == NULL)
    {
        cout << "ERROR: lista vacia ... no permitido ";
        return tmp;
    }

    /*lista = lista->sgte;
    tmp->sgte = NULL;
    return tmp;*/
    return tmp;
}

void verLista(TpLista lista)
{
    TpLista retorno = NULL, topeUltimo = lista->ante, topePrimero = lista;
    int i = 0;
    cout << "\n=====================Lista de IDA====================  " << endl
         << endl;
    while (lista->sgte != topePrimero)
    {
        cout << "[" << lista->L << lista->id << "|" << lista->nro << "]  ";
        retorno = lista;
        lista = lista->sgte;
        i++;
    }
    cout << "[" << lista->L << lista->id << "|" << lista->nro << "]  ";

    // No vi necesario poner las 2 listas solo la de ida
    /*
   lista=retorno;
   cout << "\n\n=====================Lista de RETORNO====================  " << endl
        << endl;
   i++;
   while (lista->ante != topeUltimo)
   {
       cout << "[" << lista->L << lista->id << "|" << lista->nro << "]  ";
       lista = lista->ante;
       i--;
   }
   cout << "[" << lista->L << lista->id << "|" << lista->nro << "]  ";
   cout << endl<<endl;*/
}
// menu con 2 opciones
void menu()
{

    system("CLS");
    cout << "\n\t LISTA CIRCULAR DOBLE\n\n";
    cout << "1.- Crear nodo " << endl;
    cout << "2.- Recorrer y extraer " << endl;
    cout << "0.- Salir" << endl
         << endl;

    cout << "Ingresar Opcion---> ";
}
