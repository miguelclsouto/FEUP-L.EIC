#include <iomanip>

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "show_file.h"

using namespace std;


void maximum(const string& input_fname, const string& output_fname)
{
    ifstream in(input_fname);

    double n = -1000;

    string line;

    int count = 0;

    ofstream out(output_fname);

    double d;

    while(in >> d)
    {

        // istringstream iss(line);

        // iss >> d; // ler o int

        // in >> d;

        out << fixed << setprecision(3) << d;

        out << '\n';

        if (d > n)
        {
            n = d;
        }

        count++;
    }

    out << "count=";

    out << count;

    out << "/max=";
    
    out << fixed << setprecision(3) << n;

}

int main()
{
{ maximum("p4_test1.txt", "p4_test1_out.txt");
  show_file("p4_test1_out.txt"); }
  { maximum("p4_test2.txt", "p4_test2_out.txt");
  show_file("p4_test2_out.txt"); }
  { maximum("p4_test3.txt", "p4_test3_out.txt");
  show_file("p4_test3_out.txt"); }
  { maximum("p4_test4.txt", "p4_test4_out.txt");
  show_file("p4_test4_out.txt"); }

  return 0;

}