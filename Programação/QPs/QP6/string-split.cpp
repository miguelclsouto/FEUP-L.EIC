#include <string>
#include <iostream>
#include "print_string.h"
#include <vector>

using namespace std;

void split(const string& s, vector<string>& v)
{
    size_t fim = 0;

    size_t pos = 0;

    string str;

    while (fim != string::npos)
    {   
        fim = s.find(' ', pos);

        str = s.substr(pos, fim - pos); // tamanho do str

        pos = fim + 1;

        if(str != "") 
        {
            v.push_back(str); // adicionar este valor
        }

    }

    // a = s.find(' ', s.length()); // ou ate ao s.length()

    str = s.substr(pos, fim - pos);
}

int main()
{
{ string s = "";
  vector<string> v;
  split(s, v);
  print(v); }
  { string s = "    ";
  vector<string> v;
  split(s, v);
  print(v); }
  { string s = "  a b  c ";
  vector<string> v;
  split(s, v);
  print(v); }
  { string s = "C++ LEIC FCUP FEUP";
  vector<string> v;
  split(s, v);
  print(v); }
  { string s = "       C++        ";
  vector<string> v;
  split(s, v);
  print(v); }
    return 0;
}