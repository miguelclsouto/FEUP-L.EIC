#ifndef SUM_H
#define SUM_H

#include "Operation.h"

class Sum : public Operation
{
    private:


    public:

        Sum(int op1, int op2) : Operation(op1, op2) {}

        int operation() const override { return this->get_op1() + this->get_op2(); }
    
};

#endif