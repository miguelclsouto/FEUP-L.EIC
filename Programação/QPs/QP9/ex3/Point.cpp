#include "Point.h"
#include <math.h>

using namespace std;

Point::Point()
{
    this->x = 0;
    this->y = 0;
}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

Point::Point(const Point& point)
{
    this->x = point.get_x();
    this->y = point.get_y();
}

int Point::get_x() const
{
    return x;
}

int Point::get_y() const
{
    return y;
}

float Point::Distance(const Point& p) const
{
    return sqrt(pow(this->x - p.get_x(), 2) + pow(this->y - p.get_y(), 2));
}

bool Point::operator==(const Point& point) const
{
    return this->x == point.get_x() && this->y == point.get_y();
}

Point& Point::operator=(const Point& point)
{
    this->x = point.get_x();
    this->y = point.get_y();

    return *this;
}
