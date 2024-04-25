#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
    private:
        double width_;

        double height_;

    public:
        Rectangle(const point& center, const double width, const double height) : Shape(center), width_(width), height_(height) {}

        double area() const override { return this->width_ * this->height_; }
        double perimeter() const override { return this->width_ * 2 + 2 * this->height_; }

        bool contains(const point& p) const override { return (p.x >= this->get_center().x - width_ / 2 && p.x <= this->get_center().x + width_ / 2 && p.y >= this->get_center().y - height_ / 2 && p.y <= this->get_center().y + height_ / 2); }

};

#endif