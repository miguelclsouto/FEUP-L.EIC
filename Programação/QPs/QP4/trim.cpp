#include <iostream>

using namespace std;

void trim(char s[])
{
    int size = 0;

    if (s[0] == '\0')
    {
        return;
    }

    while(s[size] != '\0')
    {
        size++;
    }

    int i = 0;

    while(s[i] == ' ')
    {
        i++;
    }

    int j = size - 1;

    while(j > 0 && s[j] == ' ') // tenho que verificar se isto acontece tb
    {
        j--;
    }

    // i e j sao as lower e upper boundaries

    int k = 0;

    while(i <= j)
    {
        s[k] = s[i];
        i++;
        k++;
    }

    s[k] = '\0';

}

int main()
{
{ char s[] = " abc! def? ";
  cout << "\"" << s << "\" => ";
  trim(s);
  cout << "\"" << s << "\"\n"; }
  { char s[] = "#abc";
  cout << "\"" << s << "\" => ";
  trim(s);
  cout << "\"" << s << "\"\n"; }
  { char s[] = "    abc def";
  cout << "\"" << s << "\" => ";
  trim(s);
  cout << "\"" << s << "\"\n"; }
  { char s[] = "abc def.   ";
  cout << "\"" << s << "\" => ";
  trim(s);
  cout << "\"" << s << "\"\n"; }
  { char s[] = "   ";
  cout << "\"" << s << "\" => ";
  trim(s);
  cout << "\"" << s << "\"\n"; }
  { char s[] = "";
  cout << "\"" << s << "\" => ";
  trim(s);
  cout << "\"" << s << "\"\n"; }
  { char s[] = " abc  _  def  _  ghi ";
  cout << "\"" << s << "\" => ";
  trim(s);
  cout << "\"" << s << "\"\n"; }
  { char s[] = "a           ";
  cout << "\"" << s << "\" => ";
  trim(s);
  cout << "\"" << s << "\"\n"; }
  return 0;
}