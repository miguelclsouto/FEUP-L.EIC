#include <iostream>
#include "Date.h"

using namespace std;

Date::Date()
{
    this->year_ = 1;
    this->month_ = 1;
    this->day_ = 1;
}

Date::Date(int year, int month, int day)
{
    this->year_ = year;
    this->month_ = month;
    this->day_ = day;
}

bool Date::is_before(const Date& date) const
{
    bool before = false;

    if(this->year_ < date.year_)
    {
        before = true;
    }
    else if(this->year_ == date.year_)
    {
        if(this->month_ < date.month_)
        {
            before = true;
        }
        else if(this->month_ == date.month_)
        {
            if(this->day_ < date.day_)
            {
                before = true;
            }
        }
    }

    return before;

}

// int main()
// {


//     return 0;
// }