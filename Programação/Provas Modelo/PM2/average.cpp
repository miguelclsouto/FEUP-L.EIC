#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "show_file.h"

using namespace std;

void average(const string& input_fname, const string& output_fname)
{

    ifstream in(input_fname);

    ofstream out(output_fname);

    string line;

    int lines = 0;

    while(getline(in, line))
    {

        istringstream iss(line);

        float num;

        float average = 0;

        int num_elements = 0;

        while(iss >> num)
        {

            average += num;
            num_elements++;

        }

        average = average / num_elements;

        out << fixed << setprecision(3) << (average) << '\n';

        lines++;

    }

    out << "lines=" << lines;

}

int main()
{
    { average("p1a-1.txt", "p1a-1_out.txt");
    show_file("p1a-1_out.txt"); }
    { average("p1a-2.txt", "p1a-2_out.txt");
    show_file("p1a-2_out.txt"); }
    { average("p1a-3.txt", "p1a-3_out.txt");
    show_file("p1a-3_out.txt"); }
    { average("p1a-4.txt", "p1a-4_out.txt");
    show_file("p1a-4_out.txt"); }

    return 0;
}