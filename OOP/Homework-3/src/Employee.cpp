#include "Employee.h"
#include <iostream>
#include <stdexcept>

Employee::Employee()
{
    this->name = "No name";
    this->salary = 0;
}

Employee::Employee(string name, double salary)
{
    this->setName(name);
    this->setSalary(salary);
}

Employee::~Employee()
{
}

Employee::Employee(const Employee& other)
{
    this->copy(other);
}

void Employee::copy(const Employee& other)
{
    this->name = other.name;
    this->salary = other.salary;
}

Employee& Employee::operator=(const Employee& other)
{
    if (this != &other)
    {
        this->copy(other);
    }

    return *this;
}

string Employee::getName() const
{
    return this->name;
}

void Employee::setName(string name)
{
    if (name == "")
    {
        throw invalid_argument("Name cannot be empty string!");
    }

    this->name = name;
}

double Employee::getSalary() const
{
    return this->salary;
}

void Employee::setSalary(double salary)
{
    if (salary < 0)
    {
        throw invalid_argument("The salary field accepts only non-negative values!");
    }

    this->salary = salary;
}

ostream& operator<<(ostream& os, const Employee& obj)
{
    os << "Name: " << obj.getName() << endl;
    os << "Salary: " << obj.salary;

    return os;
}
