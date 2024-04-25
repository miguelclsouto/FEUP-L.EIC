#include "Date3.h"
#include <iomanip>
#include <string>
#include <math.h>
#include <sstream>

using namespace std;

string fill_with_zeros(const string& a, const int len);

Date::Date()
{
    this->yyyymmdd = "00010101";
}

Date::Date(const std::string& year_month_day)
{
    istringstream iss(year_month_day);

    char sep1, sep2;

    bool flag = false;

    int year, month, day;

    if(iss >> year >> sep1 >> month >> sep2 >> day)
    {
        string years, months, days;
        
        if (sep1 != '/' || sep2 != '/')
        {
            flag = true;
        }

        if (year < 10000 && year > 0)

            years = fill_with_zeros(to_string(year), 4);

        else
            flag = true;

        if (!(month > 12 || month < 1))
            months = fill_with_zeros(to_string(month), 2);
        else
            flag = true;

        if (!flag && !(day > num_days(year, month) || day < 1)) // tenho que verificar a flag aqui tb pq senao o mes e o ano nao seriam validos, logo o numero de dias do mes tb nao seria valido

            days =  fill_with_zeros(to_string(day), 2);

        else
            flag = true;
        
        if (flag)
        {
            this->yyyymmdd = "00000000";
        }
        else // flag = false;
        {
            this->yyyymmdd = years + months + days;

        }

    }

    else
    {
        this->yyyymmdd = "00000000";
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
    bool flag;

    string years, months, days;

    if (year < 10000 && year > 0)
        
        years = fill_with_zeros(to_string(year), 4);
    else
        flag = true;

    if (!(month > 12 || month < 1))
        months = fill_with_zeros(to_string(month), 2);
    else
        flag = true;

    if (!flag && !(day > num_days(year, month) || day < 1)) // tenho que verificar a flag aqui tb pq senao o mes e o ano nao seriam validos, logo o numero de dias do mes tb nao seria valido

        days =  fill_with_zeros(to_string(day), 2);
    else
        flag = true;
    
    if (flag)
    {
        this->yyyymmdd = "00000000";
    }
    else // flag = false;
    {
        this->yyyymmdd = years + months + days;

    }

}   

bool Date::is_valid() const
{

    return !(this->yyyymmdd == "00000000"); // se for tudo zero
    // ou verificava uma flag dentro da class

}

int Date::get_year() const
{
    return stoi(this->yyyymmdd.substr(0, 4));

}

int Date::get_month() const
{
    return stoi(this->yyyymmdd.substr(5, 2));
}

int Date::get_day() const
{
    return stoi(this->yyyymmdd.substr(6));
}

string fill_with_zeros(const string& a, const int len)
{
    int n = a.length();

    if (len <= n)
    {
        return a;
    }

    // else

    string b;

    while(n < len)
    {
        b.push_back('0');

        n++;
    }

    b += a; // depois de adicionar o num de zeros adiciono o resto do a

    return b;

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