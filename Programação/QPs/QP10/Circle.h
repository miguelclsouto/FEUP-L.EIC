#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <cmath>

#ifndef M_PI 
#define M_PI 3.14159265358979323846  /* pi */
#endif

class Circle: public Shape
{

    private:
        double radius_;

    public:

        Circle(const point& center, const double radius) : Shape(center), radius_(radius) {}

        double area() const override { return this->radius_ * this->radius_ * M_PI; }
        double perimeter() const override { return 2 * M_PI * this->radius_; } 

        bool contains(const point& p) const override { return this->distance(p) <= this->radius_; }

        // a funcao distance calcula a distancia de um ponto p ate ao centro
        double distance(const point& p) const { return std::sqrt((this->get_center().x - p.x) * (this->get_center().x - p.x) + (this->get_center().y - p.y) * (this->get_center().y - p.y)); }

};

#endif