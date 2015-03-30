#include "Manager.h"

#include <iostream>
#include <stdexcept>

Manager::Manager() : Employee()
{
    this->department = "No department";
}

Manager::Manager(string name, double salary, int yearsExperience, string department)
    : Employee(name, salary, yearsExperience)
{
    this->setDepartment(department);
}

void Manager::copy(const Manager& other)
{
    Employee::copy(other);
    this->department = other.department;
}

void Manager::print(ostream& os) const
{
    Employee::print(os);
    os << endl;
    os << "Department: " << this->department;
}

Manager::~Manager()
{
}

Manager::Manager(const Manager& other)
{
    this->copy(other);
}

Manager& Manager::operator=(const Manager& other)
{
    if (this != &other)
    {
        this->copy(other);
    }

    return *this;
}

string Manager::getDepartment() const
{
    return this->department;
}

void Manager::setDepartment(string department)
{
    if (department == "")
    {
        throw invalid_argument("Department cannot be empty!");
    }

    this->department = department;
}
