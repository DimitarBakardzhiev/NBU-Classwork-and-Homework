#include "Executive.h"

#include <iostream>

Executive::Executive() : Manager()
{
}

Executive::Executive(string name, double salary, int yearsExperience, string department)
    : Manager(name, salary, yearsExperience, department)
{
}

Executive::~Executive()
{
}

Executive::Executive(const Executive& other) : Manager(other)
{
}

Executive& Executive::operator=(const Executive& other)
{
    if (this != &other)
    {
        Manager::operator=(other);
    }

    return *this;
}

void Executive::print(ostream& os) const
{
    os << "Executive: " << endl;
    Manager::print(os);
}

ostream& operator<<(ostream& os, const Executive& obj)
{
    obj.print(os);
    return os;
}
