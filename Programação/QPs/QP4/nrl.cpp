#include <iostream>

using namespace std;

char Lower(char c);

int nrl(const char s[], char low[])
{
    int i = 0;

    int repeated = 0;

    int occurences[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // we assume this array is in alphabitical order

    while (s[i] != '\0')
    {
        char b = Lower(s[i]);

        if (b != '\0')
        {
            occurences[b - 'a']++;
        }

        i++;
    }   

    int j = 0;

    for (int i = 0; i < 26; i++)
    {
        if (occurences[i] == 1)
        {
            repeated++;
            low[j] = 'a' + i;
            j++;
        }
    }

    if (j == 0)
    {
        low[j] = '\0';
    }

    // here i will change the low array and discover 
    return repeated;

}

int main()
{
    { const char s[] = "";
  char l[27] = { -1 };
  int r = nrl(s, l);
  cout << '\"' << s << "\" "
       << r << " \"" << l << "\"\n"; }
    { const char s[] = "  F C U P  F E U P  Porto  ";
  char l[27] = { -1 };
  int r = nrl(s, l);
  cout << '\"' << s << "\" "
       << r << " \"" << l << "\"\n"; }
    { const char s[] = " abC dEf GhI jKl MnO pQr StU vWx yZ ";
  char l[27] = { -1 };
  int r = nrl(s, l);
  cout << '\"' << s << "\" "
       << r << " \"" << l << "\"\n"; }
    { const char s[] = " abC dEf GhI jKl MnO pQr StU vWx yZ ABc DeF gHi JkL mNo PqR sTu VwX Yz";
  char l[27] = { -1 };
  int r = nrl(s, l);
  cout << '\"' << s << "\" "
       << r << " \"" << l << "\"\n"; }
{ const char s[] = "The quick brown fox jumps over the lazy dog";
  char l[27] = { -1 };
  int r = nrl(s, l);
  cout << '\"' << s << "\" "
       << r << " \"" << l << "\"\n"; }
       return 0;
}

char Lower(char c)
{
    if (c == ' ')
    {
        return '\0';
    }

    else if ('a' <= c && 'z' >= c)
    {
        return c;
    }

    else
    {

        return c - 'A' + 'a';
    }
}

