#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;

double average(const string& fname)
{
    int num = 0;

    double acc = 0;

    ifstream in(fname);

    while(true) // !in.eof()
    {
        double d;

        if(in.eof())
        {
            break;
        }

        if(in >> d)
        {
            acc += d;
            num++;
        }
        else
        {
            in.clear();
            in.ignore(); // in.ignore(1);
        }

    }

    return acc / num;

}

int main()
{

    { double m = average("p6_test1.txt"); 
  cout << fixed << setprecision(2) << m << '\n'; }
{ double m = average("p6_test2.txt"); 
  cout << fixed << setprecision(2) << m << '\n'; }
    { double m = average("p6_test3.txt"); 
  cout << fixed << setprecision(2) << m << '\n'; }
{ double m = average("p6_test4.txt"); 
  cout << fixed << setprecision(2) << m << '\n'; }
    { double m = average("p6_test5.txt"); 
  cout << fixed << setprecision(2) << m << '\n'; }
  return 0;

}