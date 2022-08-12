#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>
using namespace std;

struct Nodo
{
    string tipo;
    string precio;
    int code;
    struct Nodo *sgte;
};
typedef struct Nodo *RNodo;
// OTRAS FUNCIONES
int random(int menor, int mayor);
void VueltoGreedy(int vuelto);
void PagoVuelto(float &monto, float &cantidad, float vuelto, int aux);
void PagoTarjeta(string &tarjeta, string pin, string &tipoTarj);
// DECLARACION DE MENUS Y SUMENUS
int menu();
int menu_Pedido();
int menu_Pagar();
int menu_pagaTarjeta();
int menu_Catalogo_Hombre();
int menu_Chompas_Hombre();
int menu_Casacas_Hombre();
int menu_PoleronBuzo_Hombre();
int menu_JeanPantalon_Hombre();
int menu_Catalogo_Mujer();
int menu_Abrigos_Mujer();
int menu_PolosTops_Mujer();
int menu_ChompasCardigan_Mujer();
int menu_PantalonesJoggers_Mujer();
// DECLARACION DE LISTAS
RNodo removeItem(RNodo &carrito, int codigo);
float SumarCarrito(RNodo &Carrito);
void verCarrito(RNodo lista);
void verListaSE(RNodo lista);
RNodo crearNodo(string type, string price);
RNodo pop(RNodo &list);
void pushTraslado(RNodo &lista, RNodo ptr);
void AddCarrito(RNodo ropa, RNodo tipoRopa, RNodo &carrito);

RNodo crearNodo(string type, string price)
{
    RNodo nuevo = NULL;
    int cod = random(800, 999);
    nuevo = new (struct Nodo);
    nuevo->code = cod;
    nuevo->tipo = type;
    nuevo->precio = price;
    nuevo->sgte = NULL;
    verListaSE(nuevo);
    return nuevo;
}
RNodo Ropa = NULL, Carrito = NULL;
// ESQUELETO DEL CODIGO
int main()
{
    setlocale(LC_ALL, "");
    int opc;
    do
    {
        opc = menu();
        switch (opc)
        {
        // MENU PRINCIPAL
        case 1:
        {
            int oppedido;
            do
            {
                oppedido = menu_Pedido();
                // MENU_PEDIDO
                switch (oppedido)
                {
                case 1:
                {
                    int opCatalogoH;
                    do
                    {
                        opCatalogoH = menu_Catalogo_Hombre();
                        // MENU_CATALOGO_HOMBRE
                        switch (opCatalogoH)
                        {
                        case 1:
                        {
                            int opChompasH;
                            do
                            {
                                opChompasH = menu_Chompas_Hombre();
                                // MENU CHOMPAS
                                RNodo chompaH;
                                switch (opChompasH)
                                {
                                case 1:
                                {
                                    chompaH = crearNodo("CHOMPA INDEX PARA HOMBRE ERING", "99.95");
                                    AddCarrito(Ropa, chompaH, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 2:
                                {
                                    chompaH = crearNodo("CHOMPA MARQUIS PARA HOMBRE ALGODÓN VNTEXT", "129.99");
                                    AddCarrito(Ropa, chompaH, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 3:
                                {
                                    chompaH = crearNodo("GZUCK CHOMPA HILOS DEST IRON", "199.00");
                                    AddCarrito(Ropa, chompaH, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 4:
                                {
                                    chompaH = crearNodo("DIESEL CHOMPAS K-JERSEY VERDANT GREEN HOMBRE", "671.30");
                                    AddCarrito(Ropa, chompaH, Carrito);
                                    system("pause");
                                    break;
                                }
                                default:
                                    break;
                                }
                            } while (opChompasH != 0);
                            break;
                        }
                        case 2:
                        {
                            int opCasacasH;
                            do
                            {
                                opCasacasH = menu_Casacas_Hombre();
                                RNodo casacaH;
                                // MENU CASACAS
                                switch (opCasacasH)
                                {
                                case 1:
                                {
                                    casacaH = crearNodo("CASACA KENNETH STEVENS PARA HOMBRE PLUMA", "249.99");
                                    AddCarrito(Ropa, casacaH, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 2:
                                {
                                    casacaH = crearNodo("CASACA INDEX PARA HOMBRE PARKA BLOQUES EBLOCK", "119.99");
                                    AddCarrito(Ropa, casacaH, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 3:
                                {
                                    casacaH = crearNodo("PARKA CLOUDBREAK PARA HOMBRE DRUE", "219.99");
                                    AddCarrito(Ropa, casacaH, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 4:
                                {
                                    casacaH = crearNodo("CORTAVIENTO HOMBRE RED BULL BATALLA AZUL", "170.29");
                                    AddCarrito(Ropa, casacaH, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 5:
                                {
                                    casacaH = crearNodo("CASACA JACK&JONES PARA HOMBRE NOLAN BIKER", "979.95");
                                    AddCarrito(Ropa, casacaH, Carrito);
                                    system("pause");
                                    break;
                                }
                                default:
                                    break;
                                }
                            } while (opCasacasH != 0);
                            break;
                        }
                        case 3:
                        {
                            int opPoleronBuzoH;
                            do
                            {
                                opPoleronBuzoH = menu_PoleronBuzo_Hombre();
                                // MENU POLERONES Y BUZOS
                                RNodo polBuzH;
                                switch (opPoleronBuzoH)
                                {
                                case 1:
                                {
                                    polBuzH = crearNodo("SWEATSHIRT BULTACO LUCAS", "89.00");
                                    AddCarrito(Ropa, polBuzH, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 2:
                                {
                                    polBuzH = crearNodo("POLERÓN MARQUIS PARA HOMBRE DYLANNIGHT", "149.99");
                                    AddCarrito(Ropa, polBuzH, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 3:
                                {
                                    polBuzH = crearNodo("POLERÓN UNDER ARMOUR UA RIVAL TERRY", "199.90");
                                    AddCarrito(Ropa, polBuzH, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 4:
                                {
                                    polBuzH = crearNodo("BUZO CONJUNTO REEBOK POLIALGODÓN IDENTITY", "219.29");
                                    AddCarrito(Ropa, polBuzH, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 5:
                                {
                                    polBuzH = crearNodo("BUZO CONJUNTO PUMA POLY SUIT CL", "249.89");
                                    AddCarrito(Ropa, polBuzH, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 6:
                                {
                                    polBuzH = crearNodo("DIESEL POLERONES S-CRAZY-B1 BLUE", "1021.30");
                                    AddCarrito(Ropa, polBuzH, Carrito);
                                    system("pause");
                                    break;
                                }

                                default:
                                    break;
                                }
                            } while (opPoleronBuzoH != 0);
                            break;
                        }
                        case 4:
                        {
                            int opJeanPantalonH;
                            do
                            {
                                opJeanPantalonH = menu_JeanPantalon_Hombre();
                                // MENU POLERONES Y BUZOS
                                RNodo JnPntH;
                                switch (opJeanPantalonH)
                                {
                                case 1:
                                {
                                    JnPntH = crearNodo("PANTALÓN ROBERT LEWIS JAMES SLIM", "72.00");
                                    AddCarrito(Ropa, JnPntH, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 2:
                                {
                                    JnPntH = crearNodo("JEAN MARQUIS PARA HOMBRE FAUSTO", "169.99");
                                    AddCarrito(Ropa, JnPntH, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 3:
                                {
                                    JnPntH = crearNodo("PANTALÓN DE BUZO INDEX PARA JOGGER URBAN", "139.90");
                                    AddCarrito(Ropa, JnPntH, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 4:
                                {
                                    JnPntH = crearNodo("JEAN LOIS PARA HOMBRE BURGOS", "129.29");
                                    AddCarrito(Ropa, JnPntH, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 5:
                                {
                                    JnPntH = crearNodo("JEAN PIONIER PARA HOMBRE RIVALD ZK", "159.89");
                                    AddCarrito(Ropa, JnPntH, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 6:
                                {
                                    JnPntH = crearNodo("PANTALÓN DE BUZO JACK & JONES GORDON NEWSOFT", "83.97");
                                    AddCarrito(Ropa, JnPntH, Carrito);
                                    system("pause");
                                    break;
                                }

                                default:
                                    break;
                                }
                            } while (opJeanPantalonH != 0);
                            break;
                        }
                        default:
                            cout << "Datos no validos D:" << endl;
                            break;
                        }
                    } while (opCatalogoH != 0);

                    break;
                }
                case 2:
                {
                    int opCatalogoM;
                    do
                    {
                        opCatalogoM = menu_Catalogo_Mujer();
                        // MENU CATALOGO MUJER
                        switch (opCatalogoM)
                        {
                        case 1:
                        {
                            int opAbrigosM;
                            do
                            {
                                opAbrigosM = menu_Abrigos_Mujer();
                                // MENU ABRIGOS
                                RNodo abrigoM;
                                switch (opAbrigosM)
                                {
                                case 1:
                                {
                                    abrigoM = crearNodo("ABRIGO INDEX PARA MUJER FAVION", "379.99");
                                    AddCarrito(Ropa, abrigoM, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 2:
                                {
                                    abrigoM = crearNodo("SACO MARCÉ D'SHENK", "239.99");
                                    AddCarrito(Ropa, abrigoM, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 3:
                                {
                                    abrigoM = crearNodo("ABRIGO SAMANTHA ONLY ALPACA PARA MUJER BABY ALPACA", "1800.90");
                                    AddCarrito(Ropa, abrigoM, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 4:
                                {
                                    abrigoM = crearNodo("CARDIGAN MANUELA MUJER WEAR BASICS", "149.00");
                                    AddCarrito(Ropa, abrigoM, Carrito);
                                    system("pause");
                                    break;
                                }

                                default:
                                    break;
                                }
                            } while (opAbrigosM != 0);
                            break;
                        }
                        case 2:
                        {
                            int opPolosTopsM;
                            do
                            {
                                opPolosTopsM = menu_PolosTops_Mujer();
                                // MENU POLOS Y TOPS
                                RNodo topsM;
                                switch (opPolosTopsM)
                                {
                                case 1:
                                {
                                    topsM = crearNodo("POLERA MANGA LARGA CUELLO REDONDO LILI", "39.99");
                                    AddCarrito(Ropa, topsM, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 2:
                                {
                                    topsM = crearNodo("POLO MARQUIS PARA MUJER MANGAS BOMBACHAS", "36.00");
                                    AddCarrito(Ropa, topsM, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 3:
                                {
                                    topsM = crearNodo("POLO TANTIENNE PARA MUJER MANGA LARGA EUCALIPTO", "119.99");
                                    AddCarrito(Ropa, topsM, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 4:
                                {
                                    topsM = crearNodo("POLO INDEX PARA MUJER PITAS", "79.99");
                                    AddCarrito(Ropa, topsM, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 5:
                                {
                                    topsM = crearNodo("POLO RIVER ISLAND PARA MUJER", "50.00");
                                    AddCarrito(Ropa, topsM, Carrito);
                                    system("pause");
                                    break;
                                }
                                default:
                                    break;
                                }
                            } while (opPolosTopsM != 0);
                            break;
                        }
                        case 3:
                        {
                            int opChompasCardiganM;
                            do
                            {
                                opChompasCardiganM = menu_ChompasCardigan_Mujer();
                                // MENU CHOMPAS Y CARDIGANS
                                RNodo ChomCardgM;
                                switch (opChompasCardiganM)
                                {
                                case 1:
                                {
                                    ChomCardgM = crearNodo("CHOMPA PEPE JEANS SWEATER CAMELIA", "159.99");
                                    AddCarrito(Ropa, ChomCardgM, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 2:
                                {
                                    ChomCardgM = crearNodo("CHOMPA TALLY WEIJL SPUNYVELIA", "229.99");
                                    AddCarrito(Ropa, ChomCardgM, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 3:
                                {
                                    ChomCardgM = crearNodo("CARDIGAN NAVIGATA BICOLOR CANDY", "169.99");
                                    AddCarrito(Ropa, ChomCardgM, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 4:
                                {
                                    ChomCardgM = crearNodo("SWEATER CARDIGAN INDEX ALGODÓN DEMARA", "129.99");
                                    AddCarrito(Ropa, ChomCardgM, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 5:
                                {
                                    ChomCardgM = crearNodo("CHOMPA AZIZ CARDIGAN DUBAI", "722.00");
                                    AddCarrito(Ropa, ChomCardgM, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 6:
                                {
                                    ChomCardgM = crearNodo("SWEATER CARDIGAN INDEX CEDOBLE", "49.99");
                                    AddCarrito(Ropa, ChomCardgM, Carrito);
                                    system("pause");
                                    break;
                                }

                                default:
                                    break;
                                }
                            } while (opChompasCardiganM != 0);
                            break;
                        }
                        case 4:
                        {
                            int opPantalonesJoggersM;
                            do
                            {
                                opPantalonesJoggersM = menu_PantalonesJoggers_Mujer();
                                // MENU PANTALONES Y JOGGERS
                                RNodo PantJoggM;
                                switch (opPantalonesJoggersM)
                                {
                                case 1:
                                {
                                    PantJoggM = crearNodo("JOGGER EVERLAST LEGEND", "107.99");
                                    AddCarrito(Ropa, PantJoggM, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 2:
                                {
                                    PantJoggM = crearNodo("PANTALON SODA BLUES WIDE LEG BLAIR", "104.99");
                                    AddCarrito(Ropa, PantJoggM, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 3:
                                {
                                    PantJoggM = crearNodo("PANTALÓN ESPRIT", "309.99");
                                    AddCarrito(Ropa, PantJoggM, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 4:
                                {
                                    PantJoggM = crearNodo("BUZO JOGGER KAYRA POBLET 100`%` ALGODÓN", "62.93");
                                    AddCarrito(Ropa, PantJoggM, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 5:
                                {
                                    PantJoggM = crearNodo("PANTALÓN SODA BLUES MANLY", "159.99");
                                    AddCarrito(Ropa, PantJoggM, Carrito);
                                    system("pause");
                                    break;
                                }
                                case 6:
                                {
                                    PantJoggM = crearNodo("PANTALÓN PIONIER PARA MUJER YASSIRA", "111.99");
                                    AddCarrito(Ropa, PantJoggM, Carrito);
                                    system("pause");
                                    break;
                                }

                                default:
                                    break;
                                }
                            } while (opPantalonesJoggersM != 0);
                            break;
                        }
                        default:
                            cout << "Datos no validos D:" << endl;
                            break;
                        }
                    } while (opCatalogoM != 0);
                    break;
                }
                default:
                {
                    cout << "Datos ingresados no validos D:";
                    break;
                }
                }
            } while (oppedido != 0);

            break;
        }
        case 2:
        {
            int oppagar;
            float monto, cantidad, vuelto;
            string tarjeta, pin, tipoTarj;
            int codigo;
            int aux;
            do
            {
                oppagar = menu_Pagar();
                switch (oppagar)
                {
                case 1:
                {
                    PagoVuelto(monto, cantidad, vuelto, aux);
                    system("pause");
                    break;
                }
                case 2:
                {
                    int optarjeta;
                    do
                    {
                        optarjeta = menu_pagaTarjeta();
                        switch (optarjeta)
                        {
                        case 1:
                        {
                            tipoTarj = "Visa";
                            PagoTarjeta(tarjeta, pin, tipoTarj);
                            system("pause");
                            break;
                        }
                        case 2:
                        {
                            tipoTarj = "Mastercard";
                            PagoTarjeta(tarjeta, pin, tipoTarj);
                            system("pause");
                            break;
                        }
                        case 3:
                        {
                            tipoTarj = "Diners Club";
                            PagoTarjeta(tarjeta, pin, tipoTarj);
                            system("pause");
                            break;
                        }
                        case 4:
                        {
                            tipoTarj = "American Express";
                            PagoTarjeta(tarjeta, pin, tipoTarj);
                            system("pause");
                            break;
                        }
                        default:
                        {
                            cout << "Datos ingresados no validos D:";
                            break;
                        }
                        }
                    } while (optarjeta != 0);
                    break;
                }
                case 3:
                {
                    removeItem(Carrito, codigo);
                    system("pause");
                    break;
                }
                default:
                    break;
                }
            } while (oppagar != 0);
            break;
        }
        }
    } while (opc != 0);
}
// LISTAS
RNodo removeItem(RNodo &carrito, int codigo)
{
    RNodo recorre;
    recorre = carrito;
    if (recorre->code == codigo)
    {
        carrito = carrito->sgte;
        delete (recorre);
    }
    else
    {
        while ((recorre->sgte)->code != codigo)
        {
            recorre = recorre->sgte;
        }
        delete (recorre->sgte);
        recorre->sgte = recorre->sgte->sgte;
    }
}
/*
void removeItem(RNodo &carrito, string codigo)
{
    RNodo actual = carrito;
    RNodo anterior = NULL;
    verCarrito(Carrito);
    cout << "\tIngrese el codigo de la ropa que desea remover ";
    cin >> codigo;
    string R1 = "R";
    string R2 = to_string(actual->code);
    R1 += R2;
    while ((actual != NULL) && (R1 != codigo))
    {
        anterior = actual;
        actual = actual->sgte;
    }
    if (actual == NULL)
    {
        if (carrito == NULL)
        {
            cout << "\tEl carrito esta vacio" << endl;
        }
        else
        {
            cout << "\tNo se ha encontrado el codigo en el Carrito" << endl;
        }
    }
    else
    {
        if (carrito == actual)
        {
            carrito = actual->sgte;
        }
        else
        {
            anterior->sgte = actual->sgte;
        }
        delete (actual);
        cout << "\tRopa removida con codigo [R" << codigo << "] del carrito" << endl;
    }
}*/
float SumarCarrito(RNodo &carrito)
{
    float acum = 0, precio;
    verCarrito(Carrito);
    while (carrito != NULL)
    {
        precio = stof(carrito->precio);
        acum += precio;
        carrito = carrito->sgte;
    }
    cout << "\n\tEl precio total es -> ";
    return acum;
}
void AddCarrito(RNodo ropa, RNodo tipoRopa, RNodo &carrito)
{
    ropa = pop(tipoRopa);
    pushTraslado(carrito, ropa);
    verCarrito(carrito);
}

void pushTraslado(RNodo &list, RNodo ptr)
{
    if (list != NULL)
    {
        ptr->sgte = list;
    }
    list = ptr;
}

RNodo pop(RNodo &list)
{
    RNodo ptr = list;
    if (list == NULL)
    {
        cout << "ERROR: lista vacia ... no permitido ";
        return ptr;
    }
    list = list->sgte;
    ptr->sgte = NULL;
    return ptr;
}

void verListaSE(RNodo lista)
{
    int i = 0;
    while (lista != NULL)
    {
        cout << "\t HA AGREGADO "
             << "[R" << lista->code << "]" << lista->tipo << " S/.";
        cout << lista->precio << " A SU CARRITO DE COMPRA :D" << endl;
        lista = lista->sgte;
        i++;
    }
}

void verCarrito(RNodo lista)
{
    int i = 0;
    cout << "\t ESTADO DEL CARRITO " << endl;
    while (lista != NULL)
    {
        cout << "\t[R" << lista->code << "]" << lista->tipo << " S/." << lista->precio << endl;
        lista = lista->sgte;
        i++;
    }
}
// OTRAS FUNCIONES
int random(int menor, int mayor)
{
    return menor + rand() % (mayor - menor + 1);
}
void PagoTarjeta(string &tarjeta, string pin, string &tipoTarj)
{
    float total = SumarCarrito(Carrito);
    cout << "S/." << fixed << setprecision(2) << total << endl;
    cout << "\tUSTED HA SELECCIONADO " << tipoTarj << endl;
    cout << "\tIngrese su numero de tarjeta (XXXX-XXXX-XXXX-XXXX)" << endl;
    cout << "\t";
    cin >> tarjeta;
    while (tarjeta.length() != 19)
    {
        cout << "\tNumero de tarjeta no valido, por favor ingrese denuevo " << endl;
        cout << "\t";
        cin >> tarjeta;
    }
    cout << "\tPor favor ingrese el numero de PIN (XXXX)" << endl;
    cout << "\t";
    cin >> pin;
    while (pin.length() != 4)
    {
        cout << "\tNumero de PIN no valido o numero de digitos incorrecto" << endl;
        cout << "\t";
        cin >> pin;
    }
    cout << "\tProceso completado, ya puede generar su boleta " << endl;
}
void PagoVuelto(float &monto, float &cantidad, float vuelto, int aux)
{
    monto = SumarCarrito(Carrito);
    cout << "S/." << fixed << setprecision(2) << monto << endl;
    cout << "\tIngrese el monto con el que va a cancelar -> ";
    cin >> cantidad;
    vuelto = cantidad - monto;
    aux = static_cast<int>(vuelto);
    cout << "\tEl Vuelto exacto es de: " << endl;
    VueltoGreedy(aux);
    aux = vuelto - aux;
    cout << "\tAdicionando en centimos " << aux << endl
         << endl;
    cout << "\tProceso completado, ya puede generar su boleta " << endl;
}
void VueltoGreedy(int vuelto)
{
    int moneda[] = {100, 50, 20, 10, 5, 2, 1};
    int veces[] = {0, 0, 0, 0, 0, 0, 0};
    int n = 7;
    int i;

    for (i = 0; i < n; i++)
    {
        veces[i] = vuelto / moneda[i];
        vuelto = vuelto % moneda[i];
    }
    for (i = 0; i < n; i++)
    {
        if (moneda[i] > 9)
        {
            cout << "\tBillete" << moneda[i] << " cantidad " << veces[i] << endl;
        }
        else
        {
            cout << "\tMoneda" << moneda[i] << " cantidad " << veces[i] << endl;
        }
    }
}
// AREA DE MENUS Y SUBMENUS
int menu()
{
    system("CLS");
    cout << "===================TIENDA M&H========================" << endl;
    cout << "1.-Realizar pedido " << endl;
    cout << "2.-Pagar pedido " << endl;
    cout << "0.-Salir" << endl;

    cout << "\n\t\tSeleccione -> ";
    int opmenu;
    cin >> opmenu;
    cout << endl;
    return opmenu;
}

int menu_Pagar()
{
    system("CLS");
    cout << "===================SELECCIONE UN METODO DE PAGO========================" << endl;
    cout << "1.-Pago en efectivo" << endl;
    cout << "2.-Pago con tarjeta " << endl;
    cout << "3.-Eliminar un producto del carrito" << endl;
    cout << "0.-Salir" << endl;
    cout << "\n\t\tSeleccione -> ";
    int oppagar;
    cin >> oppagar;
    cout << endl;
    return oppagar;
}

int menu_pagaTarjeta()
{
    system("CLS");
    cout << "===================SELECCIONE SU TARJETA PARA PAGAR========================" << endl;
    cout << "1.-Visa" << endl;
    cout << "2.-Mastercard " << endl;
    cout << "3.-Diners Club" << endl;
    cout << "4.-American Express" << endl;
    cout << "0.-Salir" << endl;
    cout << "\n\t\tSeleccione -> ";
    int optarjeta;
    cin >> optarjeta;
    cout << endl;
    return optarjeta;
}

int menu_Pedido()
{
    system("CLS");
    cout << "===================ELIJA EL TIPO DE ROPA========================" << endl;
    cout << "1.-Ropa para caballeros " << endl;
    cout << "2.-Ropa para Damas " << endl;
    cout << "0.-Regresar" << endl;

    cout << "\n\t\tSeleccione -> ";
    int oppedido;
    cin >> oppedido;
    cout << endl;
    return oppedido;
}

int menu_Catalogo_Hombre()
{
    system("CLS");
    cout << "===================ROPA PARA HOMBRE========================" << endl;
    cout << "[1].-Chompas " << endl;
    cout << "[2].-Casacas " << endl;
    cout << "[3].-Polerones y buzos" << endl;
    cout << "[4].-Jeans y pantalones" << endl;
    cout << "[0].-Regresar " << endl;

    cout << "\n\t\tSeleccione -> ";
    int opCatalogoH;
    cin >> opCatalogoH;
    cout << endl;
    return opCatalogoH;
}

int menu_Chompas_Hombre()
{
    system("CLS");
    cout << "================================CHOMPAS==============================" << endl;
    cout << "[1].-CHOMPA INDEX PARA HOMBRE ERING...........................S/99.95" << endl;
    cout << "[2].-CHOMPA MARQUIS PARA HOMBRE ALGODÓN VNTEXT...............S/129.99" << endl;
    cout << "[3].-GZUCK CHOMPA HILOS DEST IRON............................S/199.00" << endl;
    cout << "[4].-DIESEL CHOMPAS K-JERSEY VERDANT GREEN HOMBRE............S/671.30" << endl;
    cout << "[0].-Regresar " << endl;

    cout << "\n\t\tSeleccione -> ";
    int opChompaH;
    cin >> opChompaH;
    cout << endl;
    return opChompaH;
}

int menu_Casacas_Hombre()
{
    system("CLS");
    cout << "================================CASACAS==============================" << endl;
    cout << "[1].-CASACA KENNETH STEVENS PARA HOMBRE PLUMA................S/249.99" << endl;
    cout << "[2].-CASACA INDEX PARA HOMBRE PARKA BLOQUES EBLOCK...........S/119.99" << endl;
    cout << "[3].-PARKA CLOUDBREAK PARA HOMBRE DRUE.......................S/219.99" << endl;
    cout << "[4].-CORTAVIENTO HOMBRE RED BULL BATALLA AZUL................S/170.29" << endl;
    cout << "[5].-CASACA JACK&JONES PARA HOMBRE NOLAN BIKER...............S/979.95" << endl;
    cout << "[0].-Regresar " << endl;

    cout << "\n\t\tSeleccione -> ";
    int opCasacaH;
    cin >> opCasacaH;
    cout << endl;
    return opCasacaH;
}

int menu_PoleronBuzo_Hombre()
{
    system("CLS");
    cout << "===========================POLERONES Y BUZOS=========================" << endl;
    cout << "[1].-SWEATSHIRT BULTACO LUCAS.................................S/89.00" << endl;
    cout << "[2].-POLERÓN MARQUIS PARA HOMBRE DYLANNIGHT..................S/149.99" << endl;
    cout << "[3].-POLERÓN UNDER ARMOUR UA RIVAL TERRY.....................S/199.90" << endl;
    cout << "[4].-BUZO CONJUNTO REEBOK POLIALGODÓN IDENTITY...............S/219.29" << endl;
    cout << "[5].-BUZO CONJUNTO PUMA POLY SUIT CL.........................S/249.89" << endl;
    cout << "[6].-DIESEL POLERONES S-CRAZY-B1 BLUE......................S/1,021.30" << endl;
    cout << "[0].-Regresar " << endl;

    cout << "\n\t\tSeleccione -> ";
    int opPoleronBuzoH;
    cin >> opPoleronBuzoH;
    cout << endl;
    return opPoleronBuzoH;
}

int menu_JeanPantalon_Hombre()
{
    system("CLS");
    cout << "===========================JEANS Y PANTALONES========================" << endl;
    cout << "[1].-PANTALÓN ROBERT LEWIS JAMES SLIM.........................S/72.00" << endl;
    cout << "[2].-JEAN MARQUIS PARA HOMBRE FAUSTO.........................S/169.99" << endl;
    cout << "[3].-PANTALÓN DE BUZO INDEX PARA JOGGER URBAN................S/139.90" << endl;
    cout << "[4].-JEAN LOIS PARA HOMBRE BURGOS............................S/129.29" << endl;
    cout << "[5].-JEAN PIONIER PARA HOMBRE RIVALD ZK......................S/159.89" << endl;
    cout << "[6].-PANTALÓN DE BUZO JACK & JONES GORDON NEWSOFT.............S/83.97" << endl;
    cout << "[0].-Regresar " << endl;

    cout << "\n\t\tSeleccione -> ";
    int opJeanPantalonH;
    cin >> opJeanPantalonH;
    cout << endl;
    return opJeanPantalonH;
}

int menu_Catalogo_Mujer()
{
    system("CLS");
    cout << "===================ROPA PARA MUJER========================" << endl;
    cout << "[1].-Abrigos" << endl;
    cout << "[2].-Polos y Tops" << endl;
    cout << "[3].-Chompas y Cardigans" << endl;
    cout << "[4].-Pantalones y Joggers" << endl;
    cout << "[0].-Regresar " << endl;

    cout << "\n\t\tSeleccione -> ";
    int opCatalogoM;
    cin >> opCatalogoM;
    cout << endl;
    return opCatalogoM;
}

int menu_Abrigos_Mujer()
{
    system("CLS");
    cout << "===============================ABRIGOS===============================" << endl;
    cout << "[1].-ABRIGO INDEX PARA MUJER FAVION..........................S/379.99" << endl;
    cout << "[2].-SACO MARCÉ D'SHENK......................................S/239.99" << endl;
    cout << "[3].-ABRIGO SAMANTHA ONLY ALPACA PARA MUJER BABY ALPACA....S/1,800.90" << endl;
    cout << "[4].-CARDIGAN MANUELA MUJER WEAR BASICS......................S/149.00" << endl;
    cout << "[0].-Regresar " << endl;

    cout << "\n\t\tSeleccione -> ";
    int opAbrigosM;
    cin >> opAbrigosM;
    cout << endl;
    return opAbrigosM;
}

int menu_PolosTops_Mujer()
{
    system("CLS");
    cout << "============================POLOS Y TOPS=============================" << endl;
    cout << "[1].-POLERA MANGA LARGA CUELLO REDONDO LILI...................S/39.99" << endl;
    cout << "[2].-POLO MARQUIS PARA MUJER MANGAS BOMBACHAS.................S/36.00" << endl;
    cout << "[3].-POLO TANTIENNE PARA MUJER MANGA LARGA EUCALIPTO.........S/119.99" << endl;
    cout << "[4].-POLO INDEX PARA MUJER PITAS..............................S/79.99" << endl;
    cout << "[5].-POLO RIVER ISLAND PARA MUJER.............................S/50.00" << endl;
    cout << "[0].-Regresar " << endl;

    cout << "\n\t\tSeleccione -> ";
    int opPolosTopsM;
    cin >> opPolosTopsM;
    cout << endl;
    return opPolosTopsM;
}

int menu_ChompasCardigan_Mujer()
{
    system("CLS");
    cout << "========================CHOMPAS Y CARDIGANS==========================" << endl;
    cout << "[1].-CHOMPA PEPE JEANS SWEATER CAMELIA.......................S/159.99" << endl;
    cout << "[2].-CHOMPA TALLY WEIJL SPUNYVELIA...........................S/229.99" << endl;
    cout << "[3].-CARDIGAN NAVIGATA BICOLOR CANDY.........................S/169.99" << endl;
    cout << "[4].-SWEATER CARDIGAN INDEX ALGODÓN DEMARA...................S/129.99" << endl;
    cout << "[5].-CHOMPA AZIZ CARDIGAN DUBAI..............................S/722.00" << endl;
    cout << "[6].-SWEATER CARDIGAN INDEX CEDOBLE...........................S/49.99" << endl;
    cout << "[0].-Regresar " << endl;

    cout << "\n\t\tSeleccione -> ";
    int opChompasCardiganM;
    cin >> opChompasCardiganM;
    cout << endl;
    return opChompasCardiganM;
}

int menu_PantalonesJoggers_Mujer()
{
    system("CLS");
    cout << "========================PANTALONES Y JOOGERS=========================" << endl;
    cout << "[1].-JOGGER EVERLAST LEGEND..................................S/107.99" << endl;
    cout << "[2].-PANTALON SODA BLUES WIDE LEG BLAIR......................S/104.99" << endl;
    cout << "[3].-PANTALÓN ESPRIT.........................................S/309.99" << endl;
    cout << "[4].-BUZO JOGGER KAYRA POBLET 100`%` ALGODÓN..................S/62.93" << endl;
    cout << "[5].-PANTALÓN SODA BLUES MANLY...............................S/159.99" << endl;
    cout << "[6].-PANTALÓN PIONIER PARA MUJER YASSIRA.....................S/111.99" << endl;
    cout << "[0].-Regresar " << endl;

    cout << "\n\t\tSeleccione -> ";
    int opPantalonesJoggersM;
    cin >> opPantalonesJoggersM;
    cout << endl;
    return opPantalonesJoggersM;
}
