#include "Person.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

Person::Person(const string& name, const string& address, const string& phone) : name_(name), address_(address), phone_(phone)
{
    name_ = name;
    address_ = address;
    phone_ = phone;
}

bool operator<(const Person p1, const Person p2)
{
    return p1.get_name() < p2.get_name();
}

std::string Person::get_name() const
{
    return name_;
}

std::string Person::get_address() const
{
    return address_;
}

std::string Person::get_phone() const
{
    return phone_;
}

void read_persons_data(const string& file_name, vector<Person>& persons)
{
    ifstream in(file_name);

    string name;

    while(getline(in, name))
    {

        string address;

        if(!getline(in, address)) return;

        string phone;

        if(!getline(in, phone)) return;

        persons.push_back(Person(name, address, phone));

    }

}

void sort_persons_by_name(vector<Person>& persons)
{
    sort(persons.begin(), persons.end()); //, [](const Person p1, const Person p2) {return p1.get_name() < p2.get_name();} );
}

int main()
{
    { vector<Person> persons { 
    Person("Pedro Miguel Faria", "Rua de Santa Catarina, 1234, Porto", "911123456"),
    Person("Maria Roberta Fernandes", "Rua do Santo Silva, 4321, Porto", "987654321") };
  show_persons_data(persons); }
    { vector<Person> persons;
 read_persons_data("persons-1.txt", persons);
 show_persons_data(persons); }
    { vector<Person> persons;
    read_persons_data("persons-1.txt", persons);
    sort_persons_by_name(persons);
    show_persons_data(persons); }
    { vector<Person> persons;
    read_persons_data("persons-2.txt", persons);
    sort_persons_by_name(persons);
    show_persons_data(persons); }

    return 0;
}