#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>
using namespace std;

struct Nodo
{
  string tipo;
  float precio;
  struct Nodo *sgte;
};
typedef struct Nodo *RNodo;
// DECLARACION DE MENUS Y SUMENUS
int menu();
int menu_pedido();
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
void verListaSE(RNodo lista);

// ESQUELETO DEL CODIGO
int main()
{
  setlocale(LC_ALL, "");
  RNodo Ropa;
  string model;
  int price;
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
        oppedido = menu_pedido();
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
                RNodo chompa = NULL;
                chompa = new (struct Nodo);
                switch (opChompasH)
                {
                case 1:
                {
                  chompa->tipo = "CHOMPA INDEX PARA HOMBRE ERING";
                  chompa->precio = 99.95;
                  chompa->sgte = NULL;
                  verListaSE(chompa);
                  system("pause");
                  break;
                }
                case 2:
                {
                  chompa->tipo = "CHOMPA MARQUIS PARA HOMBRE ALGODÓN VNTEXT";
                  chompa->precio = 129.99;
                  chompa->sgte = NULL;
                  verListaSE(chompa);
                  system("pause");
                  break;
                }
                case 3:
                {
                  chompa->tipo = "GZUCK CHOMPA HILOS DEST IRON";
                  chompa->precio = 199.00;
                  chompa->sgte = NULL;
                  verListaSE(chompa);
                  system("pause");
                  break;
                }
                case 4:
                {
                  chompa->tipo = "DIESEL CHOMPAS K-JERSEY VERDANT GREEN HOMBRE";
                  chompa->precio = 671.30;
                  chompa->sgte = NULL;
                  verListaSE(chompa);
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
                // MENU CASACAS
                switch (opCasacasH)
                {
                case 1:

                  break;

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
                switch (opPoleronBuzoH)
                {
                case 1:

                  break;

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
                switch (opJeanPantalonH)
                {
                case 1:

                  break;

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
                switch (opAbrigosM)
                {
                case 1:

                  break;

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
                switch (opPolosTopsM)
                {
                case 1:

                  break;

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
                switch (opChompasCardiganM)
                {
                case 1:

                  break;

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
                switch (opPantalonesJoggersM)
                {
                case 1:

                  break;

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
      // anular pedido (borrar nodo)
      break;
    }

    default:
    {
      cout << "Datos no validos D:";
      break;
    }
    }
  } while (opc != 0);
}
// LISTAS
void verListaSE(RNodo lista)
{
  int i = 0;

  while (lista != NULL)
  {
    cout << "\t [ ] HA AGREGADO " << lista->tipo << "S/.";
    cout.precision(4);
    cout << lista->precio << " A SU CARRITO DE COMPRA" << endl;
    lista = lista->sgte;
    i++;
  }
}

// AREA DE MENUS Y SUBMENUS
int menu()
{
  system("CLS");
  cout << "===================TIENDA M&H========================" << endl;
  cout << "1.-Realizar pedido " << endl;
  cout << "2.-Anular pedido " << endl;
  cout << "0.-Salir" << endl;

  cout << "\n\t\tSeleccione -> ";
  int opmenu;
  cin >> opmenu;
  cout << endl;
  return opmenu;
}

int menu_pedido()
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

// funcion practica de random para el valor de 50 y 100
int random(int menor, int mayor)
{
  return menor + rand() % (mayor - menor + 1);
}
