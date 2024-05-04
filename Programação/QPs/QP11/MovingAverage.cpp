#include <iostream>
#include <iomanip>
#include "MovingAverage.h"

using namespace std;

MovingAverage::MovingAverage(std::size_t n)
{
    n_ = n;
}

void MovingAverage::update(double value)
{
    if(values_.size() >= n_)
    {
      values_.pop_front();
    }

    values_.push_back(value);
}

double MovingAverage::get() const
{
    size_t num = values_.size();

    double sum = 0;

    for(auto v: values_)
    {
        sum += v;
    }

    return sum / num;

}

int main()
{
    { MovingAverage ma(1); 
  const MovingAverage& r = ma;
  ma.update(1.0); 
  cout << fixed << setprecision(2) << r.get() << '\n'; }
    { MovingAverage ma(1); 
  double a[] { 1.2, 3.4, 5.0 };
  for (double x : a) { 
    ma.update(x); 
    cout << fixed << setprecision(2) <<  ma.get() << ' ';
  }
  cout << fixed << setprecision(2) <<  ma.get() << '\n'; }
{ MovingAverage ma(2); 
  double a[] { 1.2, 3.4, 5.0 };
  for (double x : a) { 
    ma.update(x); 
    cout << fixed << setprecision(2) <<  ma.get() << ' ';
  }
  cout << fixed << setprecision(2) <<  ma.get() << '\n'; }
{ MovingAverage ma(3); 
  double a[] { 1.2, 3.4, 5.0 };
  for (double x : a) { 
    ma.update(x); 
    cout << fixed << setprecision(2) <<  ma.get() << ' ';
  }
  cout << fixed << setprecision(2) <<  ma.get() << '\n'; }
{ MovingAverage ma(4); 
  double a[] { 0.1, 1.2, -1.2, 3.4, 5.6, -2.3, 3.7 };
  for (double x : a) ma.update(x);
  cout << fixed << setprecision(2) <<  ma.get() << '\n'; }
    return 0;
}