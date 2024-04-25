#include <iostream>

using namespace std;

bool prime(int p)
{   
    if (p == 1) return false;

    for (int i = 2; i <= p/2; i++)
    {
        if (p % i == 0) return false;
    }

    return true;
}

bool pernicious(int p)
{
    int ones = 0;

    int bit;

    while (p != 0)
    {
        bit = p % 2;

        p /= 2; // int truncation

        if (bit == 1) ones++;

    }

    if (prime(ones)) return true;

    // else
    return false;
}

int main()
{
    int a, b;

    cin >> a >> b;

    for (int i = a; i <= b; i++)
    {
        if (prime(i) && pernicious(i))
        {
            printf("%d ", i);
        }
    }
    return 0;
}