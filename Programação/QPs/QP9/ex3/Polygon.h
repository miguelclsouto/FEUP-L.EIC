#ifndef POLYGON_H
#define POLYGON_H

#include "Point.h"
#include <vector>
#include <iostream>

using namespace std;

class Polygon
{
    vector<Point> polygon;

    public:

        Polygon();

        Polygon(const vector<Point>& polygon);

        void add_vertex(const int pos, const Point& point);

        bool get_vertex(const int pos, Point& point) const; // i could do this using operator[] overloading

        Polygon& operator=(const vector<Point>& polygon);

        float perimeter() const;

        void show() const { cout << '{'; for (Point p : polygon) p.show(); cout << '}'; };


};

#endif