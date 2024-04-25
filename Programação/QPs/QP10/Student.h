#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <iostream>

class Student : public Person
{
    private:
        string course_; // nao posso ter o mesmo nome para uma funcao e para uma variavel,
        // por isso chamei isto de course_

    public:

        Student(int id, const string& name, const string& course) : Person(id, name), course_(course) {};
        const string& course() const { return this->course_; }

        string to_string() const override 
        {  ostringstream out;
            out << id() << '/' << name() << '/' << course_;
            return out.str(); }

};

#endif