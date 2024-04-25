#include <iostream>

#include "cdata.h"


using namespace std;

int cal_size(const cdata a[], int n)
{
    int size = 0;

    for(int i = 0; i < n; i++)
    {
        size += a[i].count; // somar o numero de valores para calcular o size total
    }

    return size;

}


int* expand_cdata(const cdata a[], int n)
{
    int size = cal_size(a, n);

    int* tmp = new int[size];

    int k = 0;

    for (int i = 0; i < n; i++)
    {

        int v = a[i].count;

        for (int j = 0; j < v; j++) // a[i].count vezes
        {
            tmp[k] = a[i].value;
            k++;
            // e mais facil utilizar outra variavel k
        }

    }

    return tmp;

}

int main()
{
    { const int n = 1;
  const cdata a[] { { 3, 999 } };
  int* r = expand_cdata(a, n);
  print_array(r, 3);
  delete [] r; }
    { const int n = 3;
  const cdata a[] { { 3, 100 }, { 2, 200 }, { 1, 300 } };
  int* r = expand_cdata(a, n);
  print_array(r, 6);
  delete [] r; }
    { const int n = 1;
  const cdata a[] { { 1, 999 } };
  int* r = expand_cdata(a, n);
  print_array(r, 1);
  delete [] r; }
    { const int n = 2;
  const cdata a[] { { 20, 1 }, { 17, 2} };
  int* r = expand_cdata(a, n);
  print_array(r, 37);
  delete [] r; }
{ const int n = 4;
  const cdata a[] { { 2, 5 }, { 1, 2 }, { 3, 0 }, { 7, -1 } };
  int* r = expand_cdata(a, n);
  print_array(r, 13);
  delete [] r; }
    return 0;
}