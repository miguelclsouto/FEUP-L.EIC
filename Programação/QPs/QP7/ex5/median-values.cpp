#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include "show_file.h"
#include <algorithm>

using namespace std;

void calc_medians(const string& input_fname, const string& output_fname)
{
    string c;

    string line;

    ifstream in(input_fname);

    ofstream out(output_fname);

    while(getline(in, line))
    {
        istringstream iss(line); // pq e que preciso desta linha

        iss >> c; // ler a primeira letra da line

        if (c == "#") // entao e um comentario
        {
            continue; // queremos ir para a prox linha
        }

        double e;

        vector<double> d;

        while(iss >> e)
        {
            d.push_back(e);
        }

        sort(d.begin(), d.end());

        double median;

        if(d.size() == 0)
        {
            continue;
        }

        if (d.size() % 2 == 0)
        { // par
            median = (d[d.size() / 2] + d[d.size() / 2 - 1]) / 2;
        }
        else // odd
        { 
            median = d[d.size() / 2];
        }

        out << c << ' ';
        // out << median;
        out << fixed << setprecision(1) << median; 
        out << '\n';
        
    }

}

int main()
{
    { calc_medians("p5_test1.txt", "p5_test1_out.txt"); 
  show_file("p5_test1_out.txt"); }
    { calc_medians("p5_test2.txt", "p5_test2_out.txt"); 
  show_file("p5_test2_out.txt"); }
    { calc_medians("p5_test3.txt", "p5_test3_out.txt"); 
  show_file("p5_test3_out.txt"); }
   { calc_medians("p5_test4.txt", "p5_test4_out.txt"); 
  show_file("p5_test4_out.txt"); } 
{ calc_medians("p5_test5.txt", "p5_test5_out.txt"); 
  show_file("p5_test5_out.txt"); }
  return 0;
}