#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point
{
    int x, y;

    public:
    
        Point();
        Point(int x, int y);
        Point(const Point& point); 
        
        int get_x() const;
        int get_y() const;
        float Distance(const Point& p) const;
        void show() const { std::cout << '(' << x << ',' << y << ')'; }

        bool operator==(const Point& point) const;

        Point& operator=(const Point& point);
};

#endif