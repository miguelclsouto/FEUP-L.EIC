#ifndef FCIRCLE_H
#define FCIRCLE_H

#include "Figure.h"

class FCircle : public Figure
{
    private:
        double radius_;

    public:
        FCircle(double x_center=0, double y_center=0, double radius = 0) : Figure(x_center, y_center), radius_(radius) { }

        void draw() const override { std::cout << "C(" << this->x_center_ << ',' << this->y_center_ << ")(" << this->radius_ << ')';}

        ~FCircle() override {}
};

#endif