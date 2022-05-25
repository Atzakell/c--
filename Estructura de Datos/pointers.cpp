#include <iostream>

using namespace std;

int main(){
    int B[]={10,4,5,6,2};
    int a = 3;
    int *b = &a;
    int *p=NULL;

    cout<<a<<" -> ";
    cout<<&a<<endl;
    cout<<*b<<" -> ";
    cout<<&b<<" -> ";
    cout<<b<<endl;
    cout<<p;

    for (int i = 0; i < 5; i++){
        cout<<B[i]<<"-> ";
    }
    

    cin.ignore().get();
    return 0;
}