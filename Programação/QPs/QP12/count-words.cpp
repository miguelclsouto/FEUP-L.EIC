#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;



bool has_key(const string c, const map<string, size_t>& r)
{
    return r.find(c) != r.end();
}

string tolower(const string& s)
{
    string k;

    for(char c : s)
    {
        k.push_back(tolower(c));
    }

    return k;
}

void count_words(const string& str, map<string, size_t>& count)
{

    istringstream iss(str);

    string s;

    while(iss >> s)
    {
        s = tolower(s);

        if (has_key(s, count))
        {
            count[s]++;
        }
        else
        {
            count[s] = 1;
        }

        iss.ignore(); //  iss.ignore(1)

    }
}

void show_map(const map<string, size_t>& count) 
{

    cout << "[ ";

    for (const auto& e : count) 
    {

        cout << e.first << ":" << e.second << ' ';

    }

    cout << "]\n";
    
}

int main()
{
    { string s = "If you want to buy  buy  if you don't want to buy  bye bye";
  map<string, size_t> count; 
  count_words(s, count);
  show_map(count); }
    { string s = "You can fool some of the people all of the time and all of the people some of the time  but you cannot fool all of the people all of the time";
  map<string, size_t> count; 
  count_words(s, count);
  show_map(count); }
  { string s = "A tutor who tooted the flute tried to tutor two young tooters to toot   Said the two to the tutor is it tougher to toot or to tutor two young tooters to toot";
  map<string, size_t> count;
  count_words(s, count);
  show_map(count); }
    { string s = "You do not need to turn on a night light on a clear night like tonight because in a clear night there is always a light light and tonight is a clear night";
  map<string, size_t> count;
  count_words(s, count);
  show_map(count); }
  { string s = "If one doctor doctors another doctor  Does the doctor who doctors the doctor  Doctor the way the doctor he is doctoring doctor  Or does he doctor the doctor  The way the doctor who doctors doctor";
  map<string, size_t> count;
  count_words(s, count);
  show_map(count); }

    return 0;
}