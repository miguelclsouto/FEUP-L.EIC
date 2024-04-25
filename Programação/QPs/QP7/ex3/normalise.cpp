#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "print.h"

using namespace std;


string Upper(const string a);


void normalise(const string& input_fname, const string& output_fname)
{
    ifstream in(input_fname);

    string line;

    ofstream out(output_fname);

    while(getline(in, line))
    {
        string s;

        istringstream iss(line);
    
        int start = line.find_first_not_of(" \t\n\v"); // encontrar o indice do primeiro char que nao e ' ', '\t', '\n' ou '\v'

        int end = line.find_last_not_of(" \t\n\v"); // encontrar o indice do ultimo char que nao e ' ', '\t', '\n' ou '\v'

        if (start < 0 || end < 0)
        {
            continue; // vamos para a prox iteracao
        }

        string word = line.substr(start, end - start + 1);

        out << Upper(word);

        out << '\n';
    
    }

}


string Upper(const string a)
{
    string b;

    for(unsigned int i = 0; i < a.length(); i++)
    {
        b.push_back(toupper(a[i]));
    }

    return b;

}



int main()
{
{ normalise("p3_test1.txt", "p3_test1_out.txt"); 
  print("p3_test1_out.txt"); }
  { normalise("p3_test2.txt", "p3_test2_out.txt"); 
  print("p3_test2_out.txt"); }
  { normalise("p3_test3.txt", "p3_test3_out.txt"); 
  print("p3_test3_out.txt"); }
  { normalise("p3_test4.txt", "p3_test4_out.txt"); 
  print("p3_test4_out.txt"); }
  { normalise("p3_test5.txt", "p3_test5_out.txt"); 
  print("p3_test5_out.txt"); }
    return 0;
}