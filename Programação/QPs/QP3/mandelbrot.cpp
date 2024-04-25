#include <iostream>
#include "complex.h"
#include <math.h>
#include <cmath>

using namespace std;
double norm(const complex& c);
void add(const complex& a, const complex& b, complex& r);
void mul(const complex& a, const complex& b, complex& r);

complex mandelbrotset(unsigned int n, complex& z_n, const complex& c); // aqui nao passamos o valor por referencia

void add(const complex& a, const complex& b, complex& r)
{
    r.x = a.x + b.x;
    r.y = a.y + b.y;
}

void mul(const complex& a, const complex& b, complex& r)
{
    r.x = a.x * b.x - a.y * b.y;
    r.y = a.x * b.y + a.y * b.x;
}

double norm(const complex& c)
{
    return sqrt(pow((c.x),2) + pow((c.y),2));

}

void mandelbrot(const complex& c, unsigned int n, complex& z_n)
{
    complex copy = z_n; // .copy();
    z_n = mandelbrotset(n, copy, c);
}

complex mandelbrotset(unsigned int n, complex& z_n, const complex& c) // aqui nao passamos o valor por referencia
{
    if (n == 0)
    {
        z_n = {0, 0};
        return z_n;
    }

    complex z_n1 = mandelbrotset(n-1, z_n, c);

    complex copy = z_n1; //.copy();

    mul(copy, copy, z_n1); // modifiquei o z_n1 no mul 

    copy = z_n1; // Voltar o copiar o valor

    add(copy,c , z_n1); // modifiquei o zn_1 na adicao

    // 0 ADD E O MUL PASSAM OS VALORES POR REFERENCIA

    return z_n1;
}

int main()
{
    { complex z_n;
  mandelbrot({1.2, 3.4}, 0, z_n);
  cout << z_n << '\n'; }
  { complex z_n;
  mandelbrot({1, 1}, 1, z_n);
  cout << z_n << '\n'; }
{ complex z_n;
  mandelbrot({1, 1}, 2, z_n);
  cout << z_n << '\n'; }
  { complex z_n;
  mandelbrot({-1.2, 0.4}, 7, z_n);
  cout << z_n << '\n'; }
  { complex z_n;
  mandelbrot({0.1, 3.2}, 4, z_n);
  cout << z_n << '\n'; }
  { complex z_n;
  mandelbrot({-1, 0}, 11, z_n);
  cout << z_n << '\n'; }
    return 0;
}