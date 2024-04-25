#include <iostream>
#include "Person.h"
#include <string>

using namespace std;

Person::Person()
{
    this->name_ = "NO_NAME"; // "NO_NAME", default date
    this->birth_date_ = Date(); // default Date Constructor
}

Person::Person(const std::string& name, const Date& birth_date) : name_(name), birth_date_(birth_date)
{

}

std::string Person::get_name() const
{
    return this->name_;
}

Date Person::get_birth_date() const
{
    return this->birth_date_;
}



// int main()
// {


//     return 0;
// }