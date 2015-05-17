#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::istream;
using std::endl;

class Employee {
private:
    unsigned id;
    string name;
    unsigned age;
    unsigned experience;
    double salary;
    string qualification;
    
public:
    Employee(unsigned id = 0, string name = "", unsigned age = 0,
            unsigned experience = 0, double salary = 0., string qualification = "");
    
    virtual ostream& inserter(ostream &os) const;
    virtual istream& extractor(istream &is);
    
    unsigned getAge() const;
    unsigned getExpericence() const;
    double getSalary() const;
};

ostream& operator<<(ostream &os, Employee &obj);
istream& operator>>(istream &is, Employee &obj);

#endif

