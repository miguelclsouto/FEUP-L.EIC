#include <iostream>

using namespace std;

bool prime(int p)
{
    for (int i = 2; i <= p/2; i++)
    {
        if (p % i == 0) return false;
    }

    return true;
}

int main()
{
    int n;

    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        if (prime(i))
        {
            printf("%d ", i);
        }
    }
    return 0;
}

