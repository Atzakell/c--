#include<iostream>
#include<time.h>
using namespace std;

//?Estructura del nodo
struct nodo{
    int dato;
    struct nodo *sgte;
};
//define el tipo de dato nodo como tpLista
typedef struct nodo *TpLista;

void menu();
void insertaInicio(TpLista &lista,int it);
void insertaFinal(TpLista &lista,int it);
int VerySumarLista(TpLista &lista);
int numeroRandom(); //random para el valor a insertar
int dado(); //random para el opc

int main(){
    //no hace falta el * ya que se declaró como typedef
    TpLista lista=NULL;
    int n;
    int opc;
    do{
        menu();
        cin>>opc;
        switch (opc){
        case 1:
            n=numeroRandom();
            cout<<"El numero entero que se pondra es -> ";
            cout<<n<<endl;
            insertaInicio(lista,n);
                system("pause");
            break;
        case 2:
            n=numeroRandom();
            cout<<"El numero entero que pondra es -> ";
            cout<<n<<endl;
            insertaFinal(lista,n);
                system("pause");
            break;
        case 3: 
            cout<<"Esta opcion de anadira proximamente"<<endl;
            system("pause");
        case 4:
            cout<<"La lista es -> "<<VerySumarLista(lista)<<endl;
            system("pause");
            break;
        default:
            break;
        }
    }while (opc!=0);
    cin.ignore().get();
}


void menu(){
    system ("CLS");
    cout<<"\n\t LISTA ENLAZADA SIMPLE\n\n";
    cout<<"[1]. Insertar al Inicio"<<endl;
    cout<<"[2]. Insertar al Final"<<endl;
    cout<<"[3]. Insertar por Posicion"<<endl;
    cout<<"[4]. Mostrar y Sumar de la lista"<<endl;
    cout<<"[0]. Salir"<<endl<<endl;

    cout<<"Escoga una accion ----> ";

}

void insertaInicio(TpLista &lista,int it){
    //se crea un puntero q asignando valores que apunta a NULL
    TpLista q=NULL;
    q = new(struct nodo);
    q->dato=it;
    q->sgte=lista;
    //?insertar q a una lista existente
    q->sgte=lista;      //el valor puntero sgte toma el valor de la lista
    lista=q;            //la nueva lista empezara en q
}

void insertaFinal(TpLista &lista,int it){
    //se crea un puntero q asignando valores que apunta a NULL
    TpLista ptr=NULL, l=lista;
    if(ptr!=NULL){
        ptr = new(struct nodo);
        ptr->dato=it;
        ptr->sgte=NULL;
    //?insertar q a una lista existente
    while (l->sgte!=NULL){
        l=l->sgte;
        }
        l->sgte=ptr;
    }else{
        void insertaInicio(TpLista &lista,int it);
    }
    
    
}

int VerySumarLista(TpLista &lista) {
    int acum=0;
    while(lista!=NULL){
        cout<<lista->dato<<" -> ";
        acum+=lista->dato;
        lista=lista->sgte;
    }
    cout<<"\nAcumulado de Nodos -> ";
    return acum;
}

int numeroRandom(){
    return rand() % 100+1;
}

int dado(){
    return rand() % 3+1;
}