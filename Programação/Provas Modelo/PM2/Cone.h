#include "Solid3D.h"
#include <iostream>

#ifndef M_PI
# define M_PI         3.141592653589793238462643383279502884L
#endif

using namespace std;

class Cone : public Solid3D
{
    public:

        Cone(const point& center, const double radius, const double height) : Solid3D(center)
        {
            height_ = height;
            radius_ = radius;
        }


        const float height() const
        {
            return height_;
        }

        const float radius() const
        {
            return radius_;
        }

        double volume() const override
        {
            return M_PI * radius_ * radius_ * height_ / 3;
        }


    private:
        double radius_;
        double height_;

};