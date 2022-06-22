#include <iostream>
using namespace std;
int main()
{
    cout << "\tHola mundo de arrays:" << endl;
    int array[99];
    cout << "Ingrese valores: " << endl;
	
    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << ") ";
        cin >> array[i];
    }

    cout << "\nLos valores ingresados fueron: " << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "[" << i + 1 << "]" << array[i] << "  ";
    }
    cin.ignore().get();
}
