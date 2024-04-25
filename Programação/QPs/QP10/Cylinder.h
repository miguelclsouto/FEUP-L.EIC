#ifndef CYLINDER_H
#define CYLINDER_H

#include "Solid.h"

#ifndef M_PI 
#define M_PI 3.14159265358979323846  /* pi */
#endif

class Cylinder: public Solid
{
    private:

        double radius_;

        double height_;

    public:

        Cylinder(const point& c, const double radius, const double height) : Solid(c), radius_(radius), height_(height) { }

        double radius() const { return this->radius_; }
        double height() const { return this->height_; }

        double area() const override { return 2 * this->radius_ * M_PI * (this->radius_ + this->height_); }


};



#endif

