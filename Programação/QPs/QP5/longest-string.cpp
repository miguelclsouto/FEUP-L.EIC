#include <iostream>
using namespace std;

int calsize(const char p[])
{
    int i = 0;
    while( p[i] != '\0')
    {
        i++;

    }

    return i;
}

const char* longest(const char* pa[])
{
    if(pa[0] == nullptr)
    {
        return "";
    }

    int bigger = 0; // for now // inicializacao
    int bigger_size = calsize(pa[0]);

    int i = 1;

    while(pa[i] != nullptr)
    {
        int size = calsize(pa[i]);

        if (size >= bigger_size)
        {

            bigger_size = size;

            bigger = i;
        }

        i++;

    }

    return pa[bigger];

}


int main()
{{ const char* pa[] = { "C++", nullptr };
  cout << "\"" << longest(pa) << "\"\n"; }
    { const char* pa[] = { "", "0123", "Hello", "world", "!", nullptr };
  cout << "\"" << longest(pa) << "\"\n"; }
{ const char* pa[]  = { "Hello_world", "Hello", "Hello world", nullptr };
  cout << "\"" << longest(pa) << "\"\n"; }
{ const char* pa[] = { "Hello world!", "Hello_world", "Hello world", nullptr };
  cout << "\"" << longest(pa) << "\"\n"; }
{ const char* pa[] = { "C++", "Python", "Java", "C#", "Julia", "Rust", "Haskell", "Typescript", "OCaml", "Fortran", nullptr };
  cout << "\"" << longest(pa) << "\"\n"; }
    return 0;
}