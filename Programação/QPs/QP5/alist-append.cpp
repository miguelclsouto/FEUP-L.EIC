#include <iostream>

#include "alist.h"

using namespace std;

void append(alist* a, const alist* b)
{
  
    if (b->size < 1)
    {
      return;
    }

    
    int* n = new int[a->size + b->size];
  
    // agora tenho que colocar os numeros aqui

    int k = 0;

    for (int i = 0; i < a->size; i++)
    {

      n[k] = a->elements[i];
      k++;

    }

    for (int i = 0; i < b->size; i++)
    {

      n[k] = b->elements[i];
      k++;

    } 

    delete [] a->elements;

    a->elements = n;

    // by doing this they will point to the same place in memory :) ok

    a->size = a->size + b->size;

}

int main()
{
    { alist* a = empty();
  const alist* b = empty();
  append(a, b);
  print(a);
  destroy(a);
  destroy(b); }
{ alist* a = empty();
  const int nB = 2;
  int eB[nB] = { 1, 2 };
  const alist* b = build(nB, eB);
  append(a, b);
  print(a);
  destroy(a);
  destroy(b); }
  { const int nA = 2;
  int eA[nA] = { 1, 2 }; 
  alist* a = build(nA, eA);
  const alist* b = empty();
  append(a, b);
  print(a);
  destroy(a); 
  destroy(b); }
  { const int nA = 2;
  int eA[nA] = { 1, 2 };
  alist* a = build(nA, eA);
  const int nB = 3;
  int eB[nB] = { 3, 4, 5 };
  const alist* b = build(nB, eB);
  append(a, b);
  print(a);
  destroy(a);
  destroy(b); }
  { const int nA = 4;
  int eA[nA] = { 1, 2, 3, 4 };
  alist* a = build(nA, eA);
  const int nB = 3;
  int eB[nB] = { 5, 6, 7 };
  const alist* b = build(nB, eB);
  append(a, b);
  print(a);
  destroy(a);
  destroy(b); }

  return 0;
}