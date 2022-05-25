#include <iostream>
using namespace std;
int main(){
    int A[2];
    for(int i=0;i<2;i++){
        cin>>A[i];
        A[i]=A[i+1];
    }
    cout<<"Valores"<<endl;
    for(int i=0;i<2;i++){
        cout<<"["<<i+1<<"]"<<A[i];
    }
    cin.ignore().get();
}