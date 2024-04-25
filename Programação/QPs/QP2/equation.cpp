#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int solve_eq(int a, int b, int c, double& x1, double& x2);

int solutionnum(int a, int b, int c);

int main()
{
    {
    double x1, x2; 
    int r = solve_eq(1, 1, 0, x1, x2); 
    cout << fixed << setprecision(7) << r << ' ' << x1 << ' ' << x2 << '\n';
    }
    {
    double x1, x2; 
    int r = solve_eq(1, -2, 1, x1, x2); 
    cout << fixed << setprecision(7) << r << ' ' << x1 << ' ' << x2 << '\n';
    }
    {
    double x1, x2; 
    int r = solve_eq(1, 1, 1, x1, x2); 
    cout << fixed << setprecision(7) << r << ' ' << x1 << ' ' << x2 << '\n';
    }
    {
    double x1, x2; 
    int r = solve_eq(1, -1, 0, x1, x2); 
    cout << fixed << setprecision(7) << r << ' ' << x1 << ' ' << x2 << '\n';
    }
    {
    double x1, x2; 
    int r = solve_eq(3, 4, -2, x1, x2); 
    cout << fixed << setprecision(7) << r << ' ' << x1 << ' ' << x2 << '\n';
    }
    return 0;
}


int solve_eq(int a, int b, int c, double& x1, double& x2)
{
    int num = solutionnum(a, b, c);

    int q = b * b - 4 * a * c;

    if (num < 2)
    {
        x2 = NAN;

        if(num < 1)
        {
            x1 = NAN;
        }
        else
        {
            x1 = -b/(2.0 * a);
        }
    }
    else
    {
        x1 = (-b - sqrt(q))/(2.0 * a);
        x2 = (-b + sqrt(q))/(2.0 * a);
    }
    
    return num;

}

int solutionnum(int a, int b, int c)
{
    int q = b * b - 4 * a * c;

    if (q > 0) return 2;

    else if (q == 0) return 1;

    return 0;
}
