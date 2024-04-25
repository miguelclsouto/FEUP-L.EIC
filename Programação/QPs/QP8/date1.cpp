#include <iostream>
#include <iomanip>
#include <math.h>
#include "Date1.h"

using namespace std;

Date::Date()
{
    year = 1;
    month = 1;
    day = 1;
}

Date::Date(int year, int month, int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
}

int Date::get_year() const
{
    return year;
}

int Date::get_month() const
{
    return month;
}

int Date::get_day() const
{
    return day;
}

bool is_before(const Date& date1, const Date& date2)
{
    int date1_year = date1.get_year();
    int date1_month = date1.get_month();
    int date1_day = date1.get_day();

    int date2_year = date2.get_year();
    int date2_month = date2.get_month();
    int date2_day = date2.get_day();

    // tb podia fzr isto com operator overloading

    if(date1_year > date2_year)
    {
        return false;
    }
    else if (date1_year < date2_year)
    {

        return true;

    }
    else  // eles sao iguais
    {
       
        if(date1_month > date2_month)
        {
            return false;
        }

        else if(date1_month < date2_month)
        {
            return true;
        }

        else // mesmo mes
        {
            if(date1_day < date2_day)
            {
                return true;
            }

            else if (date1_day > date2_day)
            {

                return false;
            }
            
        }

    }

    // else they are the same

    return false;

}

int main()
{
    Date d1; d1.write(); cout << '\n';
    Date d2(2020, 2, 29); d2.write(); cout << '\n';
    Date d3(1925, 4, 30); d3.write(); cout << '\n';
    Date d4, d5(2022,4,29); d4.write(); cout << '-' << boolalpha << is_before(d4, d5) << '\n';
    Date d6(2023,10,31), d7(2022, 4, 29); d6.write(); cout << '-' << boolalpha << is_before(d6, d7) << '\n';  
    return 0;
}