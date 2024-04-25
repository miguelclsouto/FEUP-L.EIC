#include <iostream>

using namespace std;

void advance(int delta, int& d, int& m, int& y);
bool is_leap_year(int y);
bool pass_to_next_month(int delta, int total, int day);
int month_days(int m, int y);

int main()
{
    {
    int d = 1, m = 1, y = 2022; 
    advance(0, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n';
    }
    {
    int d = 1, m = 10, y = 2022; 
    advance(10, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n';
    }
    {
    int d = 2, m = 6, y = 2022; 
    advance(31, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n';
    }
    {
    int d = 2, m = 7, y = 2022; 
    advance(31, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n';
    }
    {
    int d = 25, m = 2, y = 2000; 
    advance(4, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n';
    }
    {
    int d = 25, m = 2, y = 2001; 
    advance(4, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n';
    }
    {
    int d = 2, m = 12, y = 1900; 
    advance(365 + 5, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n';
    }
    {
    int d = 31, m = 3, y = 1903; 
    advance(365 + 366 + 30 + 5, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n';
    }
    return 0;
}

void advance(int delta, int& d, int& m, int& y) // o d, o m e p y estao por referencia
{
    enum months {JANUARY = 1,FEBRUARY,MARCH,APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER };

    // enum days {JANUARY = 31,FEBRUARY = 28 ,MARCH = 31,APRIL = 30, MAY = 31, JUNE = 30, JULY = 31, AUGUST = 31, SEPTEMBER = 30, OCTOBER = 31, NOVEMBER = 30, DECEMBER = 31};

    while (delta > 0)
    {
        int totaldays = month_days(m, y);
        
        if (!pass_to_next_month(delta, totaldays, d))
        {
            d += delta;
            delta = 0;
        }
        else // tenho que passar para o proximo mes
        {
            m += 1;

            // tenho que primeiro subtrair no delta e depois mudar o dia
            
            delta -= (totaldays - d + 1);
            d = 1;

            if (m > 12)
            {
                m = 1;
                y += 1;
            }
        }
    }

    //return "%d %d %d", d, m, y; 

}

bool pass_to_next_month(int delta, int total, int day)
{
    return (day + delta) > total;
}

int month_days(int m, int y)
{
    switch(m)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 2: // fev
            return (is_leap_year(y) ? 29 : 28);
        default:
            return 30;
    }
}

bool is_leap_year(int y)
{
    if (y % 100 == 0 && y % 400 != 0)
    {
        return false;
    }
    else if (y % 4 == 0)
    {
        return true;
    }

    return false;
}