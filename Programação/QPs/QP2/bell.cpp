#include <iostream>

using namespace std;

unsigned long bell(unsigned long n);
unsigned long bc(unsigned long n, unsigned long k);
unsigned long factorial(unsigned long n);

int main()
{
    cout << bell(0) << '\n';
    cout << bell(1) << '\n';
    cout << bell(2) << '\n';
    cout << bell(3) << '\n';
    cout << bell(4) << '\n';
    cout << bell(5) << '\n';
    cout << bell(6) << '\n';

    return 0;
}

unsigned long bell(unsigned long n)
{
    unsigned long sum = 0;

    if( n == 0 || n == 1)
    {
        return 1;
    }

    for (unsigned long i = 0; i < n; i++)
    {
        sum += bc(n-1, i) * bell(i);
    }

    return sum;
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
