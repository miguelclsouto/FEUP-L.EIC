#include <iostream>
// #include <algorithm>
#include "print_vector.h"
#include <string>
#include <vector>


using namespace std;


template<class T>
constexpr const T& clamp(const T& value, const T& low, const T& high) {
    return (value < low) ? low : (high < value) ? high : value;
}


template <typename T>
void normalise(vector<T>& v, const T& min, const T& max)
{
    int len = v.size();

    for(int i = 0; i < len; i++)
    {

        T c = clamp(v[i], min, max);

        v[i] = c;
    }

    
}

int main()
{
    { vector<int> v { }; normalise(v, 0, 1); print(v); }
    { vector<int> v { 1, 2, 3, 4, 5 }; normalise(v, 1, 5); print(v); }
    { vector<int> v { 1, 2, 3, 4, 5 }; normalise(v, 3, 4); print(v); }
{ vector<double> v { -1.2, 2.2, -3.5, 4.3, 5.2 }; 
  normalise(v, 0.5, 5.1); print(v); }
{ vector<string> v { "Diego", "Afonso", "Antonio", "Bernardo", "Tolentino", "Zeferino", "Xavier" };
  normalise(v, string("Antonio"), string("Zacarias")); print(v); }
    return 0;
}