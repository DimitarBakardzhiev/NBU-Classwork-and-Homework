#include "Employee.h"

#include <iostream>
#include <stdexcept>

Employee::Employee()
{
    this->name = "No name";
    this->salary = 0;
    this->yearsExperience = 0;
}

Employee::Employee(string name, double salary, int yearsExperience)
{
    this->setName(name);
    this->setSalary(salary);
    this->setYearsExperience(yearsExperience);
}

void Employee::copy(const Employee& other)
{
    this->name = other.name;
    this->salary = other.salary;
    this->yearsExperience = other.yearsExperience;
}

Employee::~Employee()
{
}

Employee::Employee(const Employee& other)
{
    this->copy(other);
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
        throw invalid_argument("Name cannot be empty!");
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
        throw invalid_argument("Negative values cannot be assigned to salary!");
    }

    this->salary = salary;
}

int Employee::getYearsExperience() const
{
    return this->yearsExperience;
}

void Employee::setYearsExperience(int yearsExperience)
{
    if (yearsExperience < 0)
    {
        throw invalid_argument("Negative values cannot be assigned to years of experience!");
    }

    this->yearsExperience = yearsExperience;
}

void Employee::print(ostream& os) const
{
    os << "Name: " << this->name << endl;
    os << "Salary: " << this->salary << endl;
    os << "Years of experience: " << this->yearsExperience;
}

ostream& operator<<(ostream& os, const Employee& obj)
{
    obj.print(os);
    return os;
}
