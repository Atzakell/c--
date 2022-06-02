#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Serie Fibonacci
int fib(int n)
{
    if (n < 2)
        return n;

    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n = 8;

    for (int i = 0; i <= n; i++)
    {
        cout << fib(i) << " -> ";
    }
    return 0;
}
