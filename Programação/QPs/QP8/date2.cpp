#include <iostream>
#include <iomanip>
#include <math.h>
#include "Date2.h"
#include <sstream>
using namespace std;

Date::Date()
{
    year = 1;
    month = 1;
    day = 1;
}

Date::Date(const std::string& year_month_day)
{
    istringstream iss(year_month_day);

    char sep1, sep2;

    bool flag = false;

    if(iss >> year >> sep1 >> month >> sep2 >> day)
    {

        
        if (sep1 != '/' || sep2 != '/')
        {
            flag = true;
        }

        if (year < 10000 && year > 0)
            this->year = year;
        else
            flag = true;

        if (!(month > 12 || month < 1))
            this->month = month;
        else
            flag = true;

        if (!flag && !(day > num_days(year, month) || day < 1))
            this->day = day;
        else
            flag = true;
        
        if (flag)
        {
            this->year = 0;
            this->month = 0;
            this->day = 0;
        }

    }

    else
    {
        this->year = 0;
        this->month = 0;
        this->day = 0;
    }


    // iss >> sep;

    // iss >> month;

    // iss >> sep;

    // iss >> day;
}

int Date::num_days(int year, int month) {
  int n_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (month == 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    return 29;
  return n_days[month - 1];
}

Date::Date(int year, int month, int day)
{
    // podia implementar isto como uma funcao
    bool flag = false;

    if (year < 10000 && year > 0)
        this->year = year;
    else
        flag = true;

    if (!(month > 12 || month < 1))
        this->month = month;
    else
        flag = true;

    // o num days esta dentro da classe

    if (!flag && !(day > num_days(year, month) || day < 1))
        this->day = day;
    else
        flag = true;
    
    if (flag)
    {
        this->year = 0;
        this->month = 0;
        this->day = 0;
    }

}   

bool Date::is_valid() const
{

    return !(year == 0 && month == 0 && day == 0);

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

int main()
{

Date d1; d1.write(); cout << (d1.is_valid() ? "" : "-invalid") << endl;
Date d2(2022, 4, 31); d2.write(); cout << (d2.is_valid() ? "" : "-invalid") << endl;
Date d3("2ooo/2/28"); d3.write(); cout << (d3.is_valid() ? "" : "-invalid") << endl;
Date d4("1900/1/1"); d4.write(); cout << (d4.is_valid() ? "" : "-invalid") << endl;
Date d5("2022#12#31"); d5.write(); cout << (d5.is_valid() ? "" : "-invalid") << endl;

    return 0;
}