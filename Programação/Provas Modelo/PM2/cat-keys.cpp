#include <iostream>
#include <string>
#include <list>
#include <map>
#include <climits>
// #include <iterator>

using namespace std;

unsigned get_min(const map<string, unsigned>& m)
{

    unsigned min = UINT_MAX;

    for(auto pair : m)
    {
        //
        unsigned temp = pair.second;
        //

        if(min > temp)
        {
            min = temp;
        }

    }

    return min;

    // OR (these loops also work)

    // if(m.size() < 1)
    // {
    //     return UINT_MAX;
    // }

    // unsigned min = m.begin()->second;

    // for(auto itr = ++m.begin(); itr != m.end(); itr++)
    // {

    // }

    // for(auto itr = std::next(m.begin()); itr != m.end(); itr++) // std::next is a part of the <iterator> library
    // {

    // }
}

string cat_keys(list<map<string, unsigned>> lst)
{

    if(lst.size() == 0)
    {
        return "";
    }

    auto min_itr = lst.begin();

    // *min_itr is a map

    // na maior parte das vezes em vez de usares iteradores podes iterar sobre cada elemento
    // for(auto elem : data_struct)

    unsigned abs_min = get_min(*min_itr); // absolute_minimum

    for(auto itr = ++lst.begin(); itr != lst.end(); itr++)
    {
        unsigned temp_min = get_min(*itr);// temporary_minimum

        if(abs_min > temp_min)
        {
            min_itr = itr;

            abs_min = temp_min;
        }

    }

    string s;

    for(auto itr = min_itr->begin(); itr != min_itr->end(); itr++)
    {
        // s += itr->first
        s.insert(s.size(), itr->first);
    }

    return s;

}


int main()
{
    { list<map<string, unsigned>> m2 = {
    { {"s1", 13}, {"s2", 2} } };
  cout << cat_keys(m2) << endl; }
    { list<map<string, unsigned>> m1 = {
    { {"s1", 1} } };
  cout << cat_keys(m1) << endl; }
  { list<map<string, unsigned>> m3 = {
    { {"s1", 13}, {"s2", 2} }, 
    { {"s3", 3}, {"s4", 4} }, { {"s5", 16} } };
  cout << cat_keys(m3) << endl; }
  { list<map<string, unsigned>> m4 = {
    { {"s1", 13}, {"s2", 4} }, { {"s3", 3}, {"s4", 4} } };
  cout << cat_keys(m4) << endl; }

    return 0;
}