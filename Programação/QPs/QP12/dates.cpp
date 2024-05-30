#include "Date.h"
#include <iostream>
#include <vector>
// #include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

bool operator<(const Date& d1, const Date& d2);
bool operator==(const Date& d1, const Date& d2);
bool operator<=(const Date& d1, const Date& d2);
bool operator>(const Date& d1, const Date& d2);
bool operator>=(const Date& d1, const Date& d2);

std::ostream& operator<<(std::ostream& out, const Date& d1);

bool operator<(const Date& d1, const Date& d2)
{
    if (d1.getYear() != d2.getYear())
    {
        return d1.getYear() < d2.getYear();
    }
    else if (d1.getMonth() != d2.getMonth())
    {
        return d1.getMonth() < d2.getMonth();
    }
    else // (d1.getYear() == d2.getYear()) && (d1.getMonth() == d2.getMonth())
    {
        return d1.getDay() < d2.getDay();
    }

}

// ou 
// bool operator<(const Date& d1, const Date& d2)
// {
//     if (d1.getYear() < d2.getYear())
//     {
//         return true;
//     }
//     else if (d1.getYear() > d2.getYear())
//     {
//         return false;
//     }
//     else // d1.getYear() == d2.getYear()
//     {
//         if (d1.getMonth() < d2.getMonth())
//         {
//             return true;
//         }
//         else if (d1.getMonth() > d2.getMonth())
//         {
//             return false;
//         }
//         else // d1.getDay() == d2.getDay()
//         {
//             if (d1.getDay() < d2.getDay())
//             {
//                 return true;
//             }
//             else if (d1.getDay() > d2.getDay())
//             {
//                 return false;
//             }
//             // else sao iguais d1 == d2
//             else
//             {
//                 return false;
//             }
//         }   
//     }
// }

bool operator==(const Date& d1, const Date& d2)
{
    return d1.getYear() == d2.getYear() && d1.getMonth() == d2.getMonth() && d1.getDay() == d2.getDay();
}

bool operator<=(const Date& d1, const Date& d2)
{
    return d1 == d2 || d1 < d2;
}

bool operator>(const Date& d1, const Date& d2)
{
    return !(d1 <= d2);
}

bool operator>=(const Date& d1, const Date& d2)
{
    return !(d1 < d2); // ou return d1 > d2 || d1 == d2
}

std::ostream& operator<<(std::ostream& out, const Date& d1)
{
    out << std::setw(4) << std::setfill('0') << d1.getYear() << '/';

    out << std::setw(2) << std::setfill('0') << d1.getMonth() << '/';

    out << std::setw(2) << std::setfill('0') << d1.getDay();
    
    return out;
}

int main()
{
    { vector<Date> dates = { {2023,11,15}, {2021,12,8}, {2023,11,14} };
  sort(dates.begin(), dates.end());
  for (const auto& d : dates) cout << d << " ";
  cout << '\n'; }
  { vector<Date> dates = { {2000,1,1}, {2000,2,1}, {2000,12,31} };
  sort(dates.begin(), dates.end());
  for (const auto& d : dates) cout << d << " ";
  cout << '\n'; }
  { vector<Date> dates = { {2001,10,31}, {2005,10,31}, {2010,10,31}, {1992,10,31} };
  sort(dates.begin(), dates.end());
  for (const auto& d : dates) cout << d << " ";
  cout << '\n'; }
  { vector<Date> dates = { {2023,4,28}, {999,1,1} };
  sort(dates.begin(), dates.end());
  for (const auto& d : dates) cout << d << " ";
  cout << '\n'; }
  { vector<Date> dates = { {2075,2,2}, {2077,10,10}, {2075,2,2}};
  sort(dates.begin(), dates.end());
  for (const auto& d : dates) cout << d << " ";
  cout << '\n'; }  

    return 0;
}
