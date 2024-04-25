#include <iostream>
#include <algorithm>
using namespace std;

int adigits2(int a, int b, int c)
{
    int array[3] = {a, b, c};

    int max, med, min;
    max = 0;
    med = 0;
    min = 0;

    // max e min sao os indexes no array

    for (int i = 0; i < 2; i++)
    {
        if (array[max] < array[i + 1])
        {
            max = i + 1;
        }
    }

    for (int i = 0; i < 2; i++)
    {
        if (array[min] > array[i + 1])
        {
            min = i + 1;
        }
    }

    for (int i = 0; i < 3; i++)
    {

        // max e min sao os indexes no array

        if (i != max && i != min)
        {
            med = i;
        }

    }

    return array[max] * 100 + array[med] * 10 + array[min];

}

int adigits(int a, int b, int c)
{
    int maxi = max(max(a, b), max(b, c));

    int mini = min(min(a, b), min(b, c));

    int med = - mini - maxi + a + b + c;

    return maxi * 100 + 10 * med + mini;
}

int main()
{   
    cout << adigits(4, 2, 5) << '\n';
    cout << adigits(9, 1, 9) << '\n';
    cout << adigits(1, 2, 3) << '\n';
    cout << adigits(1, 0, 0) << '\n';

    cout << adigits2(4, 2, 5) << '\n';
    cout << adigits2(9, 1, 9) << '\n';
    cout << adigits2(1, 2, 3) << '\n';
    cout << adigits2(1, 0, 0) << '\n';

    return 0;
}