#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int k, d;

    cin >> k >> d;

    double sum = 0;

    int a;

    for (int i = 0; i <= k; i++)
    {
        if (i % 2 == 0) a = 1; // par

        else a = -1; // impar
        

        // isto ja esta fora do else-if
        sum += a/(2.0 * i + 1);

        

    }

    cout << fixed << setprecision(d) << sum * 4;

    return 0;

}