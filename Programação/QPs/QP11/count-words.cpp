#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <string>

using namespace std;

size_t count_words(const string& word, const string& phrase);
bool string_smaller(const string& a, const string& b);
string lower(const string& a);

void show_vector(const vector<pair<string, size_t>>& count) 
{

    cout << "[ ";

    for (const auto& e : count) 
    {
        cout << e.first << ":" << e.second << ' ';
    }

    cout << "]\n";

}


void count_words(const string& str, vector<pair<string, size_t>>& count)
{

    set<string> s; // set que tera todas as palavras differentes da palavra

    string string_ = lower(str);

    istringstream iss(string_);

    string temp;

    while(iss >> temp)
    {
        s.insert(temp);
        iss.ignore();
    }

    for(auto iter = s.begin(); iter != s.end(); iter++)
    {

        count.push_back({*iter, count_words(*iter, string_)});

    }

    // lambda function to sort 
    std::sort(count.begin(), count.end(), [](const pair<string, size_t>& x, const pair<string, size_t>& y) { return x.first < y.first; } );

}

string lower(const string& a)
{   
    string s;

    for(char c : a)
    {
      
        s += tolower(c);
        // s.push_back(tolower(c));

    }

    return s;
}

bool string_smaller_equal(const string& a, const string& b)
{
    size_t m = min(a.size(), b.size());

    for(size_t i = 0; i < m; i++)
    {
        if(a[i] > b[i])
        {
            return false;
        }
        else if(b[i] > a[i])
        {
            return true;
        }
    }

    if (b.size() >= a.size())
    {
        return true;
    }
    
    return false;
}

size_t count_words(const string& word, const string& phrase)
{
    istringstream iss(phrase);

    string temp;

    size_t count = 0;

    while(iss >> temp)
    {
        if (temp == word)
        {
            count++;
        }
    }

    return count;

}

int main()
{
  { string s = "If you want to buy  buy  if you don't want to buy  bye bye";
  vector<pair<string, size_t>> count;
  count_words(s, count);
  show_vector(count); }
  { string s = "You can fool some of the people all of the time and all of the people some of the time  but you cannot fool all of the people all of the time";
  vector<pair<string, size_t>> count;
  count_words(s, count);
  show_vector(count); }
  { string s = "A tutor who tooted the flute tried to tutor two young tooters to toot   Said the two to the tutor is it tougher to toot or to tutor two young tooters to toot";
  vector<pair<string, size_t>> count;
  count_words(s, count);
  show_vector(count); }
  { string s = "You do not need to turn on a night light on a clear night like tonight because in a clear night there is always a light light and tonight is a clear night";
  vector<pair<string, size_t>> count;
  count_words(s, count);
  show_vector(count); }
  { string s = "If one doctor doctors another doctor  Does the doctor who doctors the doctor  Doctor the way the doctor he is doctoring doctor  Or does he doctor the doctor  The way the doctor who doctors doctor";
  vector<pair<string, size_t>> count;
  count_words(s, count);
  show_vector(count); }

  return 0;
}