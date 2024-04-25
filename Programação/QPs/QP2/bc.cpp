#include <iostream>

using namespace std;

unsigned long bc(unsigned long n, unsigned long k);
unsigned long factorial(unsigned long n);

int main()
{
    cout << bc(5, 0) << '\n';
    cout << bc(5, 1) << '\n';
    cout << bc(5, 5) << '\n';
    cout << bc(5, 2) << '\n';
    cout << bc(12, 7) << '\n';
    cout << bc(20, 10) << '\n';
    return 0;
}

unsigned long bc(unsigned long n, unsigned long k)
{
    unsigned long d = 1;
    unsigned long q = 1;

    d = factorial(k);

    // if (k == 0 || n == 0 || k == n)
    // {
    //     return  1;
    // }

    for (unsigned long i = n; i > n - k; i--)
    {
        q *= i;
    }

    return q / d;
}

unsigned long factorial(unsigned long n)
{
    if( n == 0 || n == 1)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

