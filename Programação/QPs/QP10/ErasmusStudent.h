#ifndef ERASMUSSTUDENT_H
#define ERASMUSSTUDENT_H

#include "Student.h"

class ErasmusStudent : public Student
{
    private:

        string country_; // nao posso ter o mesmo nome para uma funcao e para uma variavel,
        // por isso chamei isto de country_

    public:

        ErasmusStudent(int id, const string& name, const string& course, const string& country) : Student(id, name, course), country_(country) { }
        const string& country() const { return this->country_; } 
        string to_string() const override 
         {  ostringstream out;
            out << id() << '/' << name() << '/' << course() << '/' << country_;
            return out.str(); }

};

#endif