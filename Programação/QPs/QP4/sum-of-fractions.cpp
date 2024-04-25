#include <iostream>
#include "fraction.h"

using namespace std;

int gcd(const int a, const int b);

fraction sum(const fraction fa[], int n)
{
    if (n < 1)
    {
        return {0, 1};
    }

    fraction sum = {fa[0].num, fa[0].den};

    for (int i = 1; i < n; i++)
    {

        fraction temp = fa[i];

        // preciso ter cuidado para nao enganar na ordem de fzr estar operacoes de multiplicacao para as fracoes, porque se nao estiver na ordem certa, podera nao dar o resultado esperado

        temp.num *= sum.den;

        
        sum.den *= temp.den;
        sum.num *= temp.den;
        
        
        sum.num += temp.num;
        // vou fzr tudo e depois eu calculo a fracao irredutivel
    }


    int mdc = gcd(sum.num, sum.den);

    if (sum.num == 0 || sum.den == 0)
    {
        return {0, 1};
    }

    if (sum.num * sum.den < 0)
    {
        return {- abs(sum.num / mdc), abs(sum.den / mdc)};
    }

    return {sum.num / mdc, sum.den / mdc};

}

int gcd(const int a, const int b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

int main()
{
    { const int n = 1;
  const fraction fa[n] { {1, 2} };
  cout << sum(fa, n) << '\n'; }
  { const int n = 2;
  const fraction fa[n] { {1, 2}, {-1, 3} };
  cout << sum(fa, n) << '\n'; }
{ const int n = 3;
  const fraction fa[n] { {1, 2}, {-1, 3}, {-3, 4} };
  cout << sum(fa, n) << '\n'; }
  { const int n = 4;
  const fraction fa[n] { {-1, 4}, {1, 2}, {-1, 8}, {-1, 8} };
  cout << sum(fa, n) << '\n'; }
  { const int n = 5;
  const fraction fa[n] { {0, 1}, {1, 2}, {-2, 3}, {3, 4}, {-4, 5} };
  cout << sum(fa, n) << '\n'; }
  { const int n = 6;
  const fraction fa[n] { {133,60}, {0, 1}, {1, 2}, {-2, 3}, {3, 4}, {-4, 5} };
  cout << sum(fa, n) << '\n'; }

  return 0;
}