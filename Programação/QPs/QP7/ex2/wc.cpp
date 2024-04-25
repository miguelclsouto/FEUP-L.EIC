#include <iostream>
#include "wc.h"
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

wcresult wc(const string& filename)
{
    ifstream in(filename);

    wcresult temp = {0, 0, 0}; // tudo inicializado a 0

    string line;
    
    while(getline(in, line))
    {

        istringstream iss(line);

        string s;

        temp.bytes += line.length() + 1; // fazemos + 1 por causa do '\n' para passarmos para a proxima linha
        // temp.bytes += s.length(); // cada char ocupa um byte

        while(iss >> s)
        {
            temp.words++;
            
        }

        temp.lines++;


    }

    return temp;
}

int main()
{

    { wcresult r = wc("p2_test1.txt"); 
  cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }
  { wcresult r = wc("p2_test2.txt"); 
  cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }
  { wcresult r = wc("p2_test3.txt"); 
  cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }
  { wcresult r = wc("p2_test4.txt"); 
  cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }
  { wcresult r = wc("p2_test5.txt"); 
  cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }
    return 0;
}