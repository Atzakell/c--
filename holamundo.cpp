#include <iostream>
using namespace std;
int main()
{
    cout<<"\tHola mundo de arrays"<<endl;
    int array[99];
    for (int i = 0; i < 10; i++){
        cout<<"\nIngrese los valores de del array -> ";
        cin>>array[i];
    }
    cout<<"\nLos valores ingresados fueron: "<<endl;
        for (int i = 0; i < 10; i++){
        cout<<"["<<i+1<<"]"<<array[i]<<endl;
    }
    cin.ignore().get();
}