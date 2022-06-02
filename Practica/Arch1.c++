#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Serie Fibonacci

int fib(int n)
{
    if (fib(n) == 0)
    {
        return 0;
    }
    else if (fib(n) == 1)
    {
        return 1;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}

int main()
{
    int n = 8;
    cout << "La serie Fibonacci es: " << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << fib(i) << "->";
    }
    return 0;
}
