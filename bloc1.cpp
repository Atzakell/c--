#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;
int main(){
    char cajita_vacia[100];
    char enamorado_dela_vida[100]="k sabe";
    cout<<"Empieza la cancion ---> ";
    cin>>cajita_vacia;
    cin.ignore();
    if ((strcmp(cajita_vacia,enamorado_dela_vida)==0))
    {
        cout<<"AQUEL K NUNKA AMOOO, LO TRISTE DE UNA DECEPCIOOONNN.";cout<<endl;
        cout<<"SUFRIIIIR UN DESENGAÑOOOOOO ENAMORADO MAS K NUNKAAA DEL AMOR EQUIVOCADOOOO "<<endl;
    }
    cin.ignore().get();
    return 0;
}