#include <iostream>
#include <algorithm>

using namespace std;

int median(const int a[], int n)
{
    int* tmp = new int[n];

    for (int i = 0; i < n; i++){
        tmp[i] = a[i];
    }

    sort(tmp, tmp + n);

    int median;

    if (n % 2 == 1)
    {
        median = tmp[n / 2];

    }
    else
    {
        median = (tmp[n / 2] + tmp[n / 2 - 1]) / 2;

    }

    delete [] tmp;

    return median;

}

int main(){

{ const int n = 5; 
  int a[n] { 10, -10, 0, 12, 11 };
  cout << median(a, n) << '\n'; }
  { const int n = 6; 
  int a[n] { 30, 10, 0, -20, 14, 20 };
  cout << median(a, n) << '\n'; }
{ const int n = 1; 
  int a[n] { 99 };
  cout << median(a, n) << '\n'; }{ const int n = 2; 
  int a[n] { 101, 99 };
  cout << median(a, n) << '\n'; }
    return 0;
}