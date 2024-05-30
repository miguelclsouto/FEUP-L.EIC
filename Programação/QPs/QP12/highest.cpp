#include <iostream>
#include <map>
#include <string>
#include <list>

using namespace std;

string student_highest_avg(map<string, list<int>> m);
float average(const map<string, list<int>>& m, const string& name);
float average2(const list<int>& m);

string student_highest_avg(map<string, list<int>> m)
{
    if (m.size() == 0) // or if (m.begin() == m.end())
    {
        return "";
    }

    auto itr = m.begin();

    // itr is an iterator
    // because, here the elements of the map are treated as like a pair

    string highest_average_name = itr->first;

    float highest_average = average(m, highest_average_name);

    itr++;

    while(itr != m.end())
    {
        // float temp_average = average(m, itr->first);
        float temp_average = average2(itr->second);

        if (highest_average < temp_average)
        {
            highest_average_name = itr->first;
            highest_average = temp_average;
        }

        itr++;
    }

    return highest_average_name;

    // for(auto itr = m.begin() + 1, itr < m.end(); itr++)
    // {

    // }

}

// tb podia criar uma funcao average com apenas a lista de ints daquele nome como argumento
float average(const map<string, list<int>>& m, const string& name)
{
    // aqui tenho que usar p.at(), pois o operator [] permite 
    // modificações à lista do map, mas o map é um argumento const
    list<int> p = m.at(name);

    float acc = 0;

    for(int x : p)
    {
        acc += x;
    }

    return acc / p.size();

}

float average2(const list<int>& m)
{
    float acc = 0;

    for(int x : m)
    {
        acc += x;
    }

    return acc / m.size();

}

int main()
{
    { map<string, list<int>> m1 = {
      {"Jerry", {10, 20, 15}}};
  cout << student_highest_avg(m1) << endl; }
  { map<string, list<int>> m2 = {
      {"Elaine", {15, 18, 14, 16}}, {"Newman", {18, 12, 19}}};
  cout << student_highest_avg(m2) << endl; }
  { map<string, list<int>> m3 = {
      {"Whatley", {10, 10}}, {"Kramer", {11, 12, 14}}, {"Cosmo", { 15, 10, 13}}};
  cout << student_highest_avg(m3) << endl; }
  { map<string, list<int>> m4 = {
      {"Costanza", {0, 11}}, {"Frank", {8, 12}}};
  cout << student_highest_avg(m4) << endl; }
  { map<string, list<int>> m5 = {
      {"Frank", {10, 15}}, {"Costanza", {10, 14}} };
  cout << student_highest_avg(m5) << endl; }

    return 0;
}