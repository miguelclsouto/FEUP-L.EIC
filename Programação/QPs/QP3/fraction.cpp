#include <iostream>
#include "fraction.h"

using namespace std;

int gcd(int a, int b)
{
    if (b == 0) return a;

    return gcd(b, a % b);
}

fraction add(fraction a, fraction b)
{
    fraction c { a.num  * b.den + b.num * a.den, a.den * b.den};

    int d = gcd(c.num, c.den);

    if (c.den / d < 0) // poderia ter adicionado uma funcao para fzr isto
    {
        c.den = -c.den;
        c.num = -c.num;

        // trocar o menos de sitio

    }


    return {c.num / d, c.den / d};
}

fraction mul(fraction a, fraction b)
{
    fraction c { a.num * b.num, a.den * b.den };

    int d = gcd(c.num, c.den);

    if (c.den / d < 0) // poderia ter adicionado uma funcao para fzr isto
    {
        c.den = -c.den;
        c.num = -c.num;

        // trocar o menos de sitio
        
    }

    return {c.num / d, c.den / d};
}



int main()
{
    { fraction a { 0, 1 }, b { 2, 1};
  cout << add(a,b) << ' ' << mul(a,b) << '\n'; }
  { fraction a { 1, 1 }, b { -1, 2};
  cout << add(a,b) << ' ' << mul(a,b) << '\n'; }
  { fraction a { -3, 2 }, b { 3, 2 };
  cout << add(a,b) << ' ' << mul(a,b) << '\n'; }
  { fraction a { -3, 2 }, b { -2, 3 };
  cout << add(a,b) << ' ' << mul(a,b) << '\n'; }
  { fraction a { -7, 24 }, b { 1, 3 };
  cout << add(a,b) << ' ' << mul(a,b) << '\n'; }
  { fraction a { -8, 25 }, b { 3, 4 };
  cout << add(a,b) << ' ' << mul(a,b) << '\n'; }
  cout << add({7,4536}, mul({-5,21}, add({1,2}, mul({-2,3}, {1,9})))) << '\n';
  return 0;
}