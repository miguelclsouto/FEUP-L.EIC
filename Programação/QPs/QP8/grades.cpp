#include <iostream>
#include "Student.h"
#include <iomanip>

using namespace std;

Student::Student(const std::string& id) //: id_(id), courses_({})
{
    id_ = id;
    courses_ = {}; // empty vector
}

std::string Student::get_id() const
{
    return id_;
}

void Student::add(const course& c)
{
    courses_.push_back(c);
}

double Student::avg() const
{   
    double average = 0;

    double sum_credits = 0;

    for(const course& c : courses_)
    {
        if(c.grade < 10)
        {
            continue;
        }

        // else

        sum_credits += c.credits;

        average += c.credits * c.grade;

    }

    return sum_credits != 0 ? average / sum_credits : 0;
}

int main()
{
    { Student s("up2022001111");
  s.add({"FP", 6, 20});
  cout << "[" << s.get_id() << "]/";
  cout << fixed << setprecision(2) << s.avg() << endl; }
  { Student s("up2022002222");
  s.add({"MD", 6, 18}); s.add({"AMI", 6, 16}); s.add({"FSC", 6, 14});
  cout << "[" << s.get_id() << "]/";
  cout << fixed << setprecision(2) << s.avg() << endl; }
  { Student s("up2022003333");
  s.add({"ALGA", 4.5, 18}); s.add({"AMI", 6, 16}); s.add({"PUP", 1.5, 14});
  cout << "[" << s.get_id() << "]/";
  cout << fixed << setprecision(2) << s.avg() << endl; }
  { Student s("up2022004444");
  cout << "[" << s.get_id() << "]/";
  cout << fixed << setprecision(2) << s.avg() << endl; }

    return 0;
}