#include <iostream>
#include <string>
#include <map>

using namespace std;

bool has_key(const char c, const map<char, char>& r)
{
    return r.find(c) != r.end();
}

void replace(const map<char, char>& r, string& s)
{
    for(char& c : s)
    {
        // if (r.contains(c)) // contains() is a method from c++20
        // {

        //     c = r.at(c);

        // }

        // or i guess i could search to check if the r->first in in r

        if(has_key(c, r))
        {
            // c = r[c]; the [] operator cannot be used in a const map,
            // because the operator [] allows for modifications

            c = r.at(c); // the at function does not modify the map

        }

    }

}

int main()
{
    { string s = "C / C++ @ LEIC";
  replace({ {'C', 'z'}, {'+', '-'}, {'L', 'X'}}, s);
  cout << s << '\n'; }
    { string s = "C / C++ @ LEIC";
  replace({ }, s);
  cout << s << '\n'; }
    { string s = "A B C D E F";
  replace({ {' ', '_'}}, s);
  cout << s << '\n'; }
    { string s = "A B C D E F";
  replace({ {'_', ' '}, {'A', '?'}, {'?', '!'}, {'F', '!'}}, s);
  cout << s << '\n'; }
    return 0;
}