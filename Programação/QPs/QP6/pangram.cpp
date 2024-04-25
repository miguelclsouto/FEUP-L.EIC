#include <iostream>
#include <string>


using namespace std;


bool pangram(const string& s, string& m)
{

    int abc[26] = {0}; // inicializar tudo a 0


    for(unsigned int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if(c != ' ')
        {
            abc[tolower(c) - 'a'] += 1;
        }
        // else, passa para a frente / para o proximo char
    }


    bool pan = true;


    for(int i = 0; i < 26; i++)
    {
        if(abc[i] == 0)
        {
            m.push_back(i + 'a');
            pan = false;
        }
    }

    // m.pushback('\0'); // acabar a string // aqui nao preciso de fzr isto. A class das strings ja da conta disso

    return pan;

}

using namespace std;

int main()
{
    { string s = "";
  string m = "";
  bool r = pangram(s, m);
  cout << '\"' << s << "\" "
       << boolalpha << r << " \"" << m << "\"\n"; }
    { string s = "The quick brown fox jumps over the lazy dog";
  string m = "";
  bool r = pangram(s, m);
  cout << '\"' << s << "\" " 
       << boolalpha << r << " \"" << m << "\"\n"; }
    { string s = "A quick brown fox jumps over a classy dog";
  string m = "";
  bool r = pangram(s, m);
  cout << '\"' << s << "\" " 
       << boolalpha << r << " \"" << m << "\"\n"; }
    { string s = " abC dEf GhI jKl MnO pQr StU vWx yZ ";
  string m = "";
  bool r = pangram(s, m);
  cout << '\"' << s << "\" " 
       << boolalpha << r << " \"" << m << "\"\n"; }
{ string s = " Stu yZ abC GhI MnO pQr   ";
  string m = "";
  bool r = pangram(s, m);
  cout << '\"' << s << "\" " 
       << boolalpha << r << " \"" << m << "\"\n"; }
    return 0;
}