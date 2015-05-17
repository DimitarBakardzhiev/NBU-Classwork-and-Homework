#ifndef MANAGER_H
#define	MANAGER_H

#include "Employee.h"

class Manager : public Employee {
private:
    string department;
    unsigned employees;
    
public:
    Manager(unsigned id = 0, string name = "", unsigned age = 0,
            unsigned experience = 0, double salary = 0., string qualification = "",
            string department = "", unsigned employees = 0);
    
    virtual ostream& inserter(ostream &os) const;
    virtual istream& extractor(istream &is);
};

#endif

