#include "Programmer.h"

Programmer::Programmer() : Employee()
{
}

Programmer::Programmer(string name, double salary) : Employee(name, salary)
{
}

Programmer::~Programmer()
{
}

Programmer::Programmer(const Programmer& other) : Employee(other)
{
}

Programmer& Programmer::operator=(const Programmer& other)
{
    if (this != &other)
    {
        Employee::operator=(other);
    }

    return *this;
}

string Programmer::getName() const
{
    return Employee::getName() + " (Programmer)";
}
