#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

bool same_word(string a,string b);

int count(const string& fname, const string& word)
{
    ifstream in(fname);

    string c;

    int d = 0;

    while(true)
    {
        in >> c;

        if(in.eof())
        {
            break;
        }
        else if(same_word(c, word))
        {
            d++;
        }

    }

    return d;
}

bool same_word(string a,string b)
{
    unsigned int d = a.length();

    for (unsigned int i = 0; i < d; i++)
    {
        if(toupper(a[i]) != toupper(b[i]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cout << count("p1_test_a.txt", "THE") << '\n';
    cout << count("p1_test_a.txt", "0") << '\n';
    cout << count("p1_test_a.txt", "code") << '\n';
    cout << count("p1_test_b.txt", "Collider") << '\n';
    cout << count("p1_test_b.txt", "you") << '\n';
    return 0;
}
