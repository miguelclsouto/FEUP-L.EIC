#ifndef FRECTANGLE_H
#define FRECTANGLE_H

#include "Figure.h"

class FRectangle : public Figure
{
    private:

        double width_;
        double height_;

    public:
        FRectangle(double x_center=0, double y_center=0, double width = 0,  double height = 0) : Figure(x_center, y_center), width_(width), height_(height) {}

        void draw() const override { std::cout << "R(" << this->x_center_ << ',' << this->y_center_ << ")(" << this->width_ << ',' << this->height_ << ')'; }

        ~FRectangle() override {}

};

#endif