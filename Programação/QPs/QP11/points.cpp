#include "Point.h"


Point::Point()
{
    this->x_ = 0;
    this->y_ = 0;
}

Point::Point(int x, int y) : x_(x), y_(y) 
{
    
}

Point::Point(const Point& p) : x_(p.get_x()), y_(p.get_y())
{

}

int Point::get_x() const 
{
    return this->x_;
}

int Point::get_y() const 
{
    return this->y_;
}

Point& Point::operator=(const Point& p)
{
    this->x_ = p.get_x();
    this->y_ = p.get_y();

    return *this;
}

Point Point::operator+(const Point& p) const
{
    return Point(this->x_ + p.get_x(), this->y_ + p.get_y());
}

Point& Point::operator+=(const Point& p)
{

    *this = *this + p;

    return *this;
}

Point Point::operator*(int v) const
{
    return Point(v * this->x_, v * this->y_);
}

Point operator*(int x, const Point& p)
{
    return Point(x * p.get_x(), x * p.get_y());
}

std::ostream& operator<<(std::ostream& os, const Point& p)
{
    os << '(' << p.get_x() << ',' << p.get_y() << ')';

    return os;
}

int main()
{
    { Point a, b(1,2), c(b), d(3,4); 
  b = a;
  std::cout << a << ' ' << b << ' ' << c << ' ' << d << '\n'; }
    { Point a, b(1,2), c(b), d(3,4); 
  c = b = a;
  std::cout << a << ' ' << b << ' ' << c << ' ' << d << '\n'; }
  { Point a(1,2), b(3,4), c = a + b, d(5,6);
  b += d;
  std::cout << a << ' ' << b << ' ' << c << ' ' << d << '\n'; }
  { Point a(1,2), b(3,4), c = a * 2, d(5,6);
  b = 2 * d;
  std::cout << a << ' ' << b << ' ' << c << ' ' << d << '\n'; }
  { Point a(1,1), b(0,1), c(1,0), d(1,1);
  d += c += b += a += {1,2};
  d = 2 * d * 2;
  std::cout << a << ' ' << b << ' ' << c << ' ' << d << '\n'; }

    return 0;
}