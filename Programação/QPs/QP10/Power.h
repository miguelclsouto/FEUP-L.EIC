#ifndef POWER_H
#define POWER_H

#include "Operation.h"

#include <cmath>

class Power : public Operation
{
    private:


    public:

        Power(int op1, int op2) : Operation(op1, op2) {}

        int operation() const override { return std::pow(this->get_op1(), this->get_op2()); }

};

#endif