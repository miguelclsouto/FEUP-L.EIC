#include "Polygon.h"


Polygon::Polygon()
{
    polygon.clear();
}

Polygon::Polygon(const vector<Point>& polygon) : polygon(polygon)
{

}

bool Polygon::get_vertex(const int pos, Point& point) const
{
    if (pos > int(polygon.size()) || pos <= 0)
    {
        return false;
    }
    else
    {
        point = Point(polygon[pos - 1]); // inicializar o point com o point do polygon index

        // point = polygon[index - 1]; // operator overloading
    }

    return true;
}

void Polygon::add_vertex(const int pos, const Point& point)
{
    if (pos - 1 >= int(polygon.size()))
    {
        
        polygon.insert(polygon.end(), point);
    }
    else
        polygon.insert(polygon.begin() + pos - 1, point);
}

Polygon& Polygon::operator=(const vector<Point>& polygon)
{
    this->polygon = polygon;

    return *this;
}

float Polygon::perimeter() const
{
    float sum = 0;

    for(unsigned int i = 0; i < polygon.size() - 1; i++)
    {
        // dist entre o ponto no i e o ponto depois / a seguir ao i;
        // polygon[i] : Point (class)

        sum += polygon[i].Distance(polygon[i + 1]);

    }

    sum += polygon[polygon.size() - 1].Distance(polygon[0]);

    return sum;

}
