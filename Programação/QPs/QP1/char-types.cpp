#include <iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;

    char c;

    int digits = 0;

    int letters = 0;

    int none = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> c;

        if ('0' <= c && c <= '9')
        {
            digits++;
        }
        else if (('a' <= c && c <= 'z' ) || ('A' <= c && c <= 'Z'))
        {
            letters++;
        }
        else
        {
            none++;
        }

    }

    printf("%d %d %d", letters, digits, none);

    return 0;
}