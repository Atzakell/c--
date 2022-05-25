#include<iostream>

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
void verLista(TpLista lista);
void insertaFinal(TpLista &lista,int it);

int main(){
    //no hace falta el * ya que se declaró como typedef
    TpLista lista=NULL;
    int n=10;
    int opc;
    do{
        menu();
        cin>>opc;
        switch (opc){
        case 1:
            cout<<"Pon un numero tipo entero -----> ";
            cin>>n;cout<<endl;
            insertaInicio(lista,n);
                system("pause");
            break;
        case 4:
            verLista(lista);
            system("pause");
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
    cout<<"[3]. Insertar por Posición"<<endl;
    cout<<"[4]. Mostrar Lista"<<endl;
    cout<<"[0]. Salir"<<endl<<endl;

    cout<<"Escoga una accion ----> "<<endl;

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
    ptr = new(struct nodo);
    ptr->dato=it;
    ptr->sgte=NULL;
    //?insertar q a una lista existente
    while (l->sgte!=NULL)
        ptr=ptr->sgte;
        ptr->sgte=l;
}

void verLista(TpLista lista){
    int cont=0;
    while (lista != NULL){
        cout<<" "<<cont+1<<") "<<lista->dato<<endl;
        lista=lista->sgte;
        cont++;
    }
    
}

/*void Lista(TpLista lista){
    lista->dato;
    lista=lista->dato;
    cout<<"El nuevo imagen del diagrama de partes -> ";
    for (int i = 0; i < size.lista; i++){
        
    }
    
}*/