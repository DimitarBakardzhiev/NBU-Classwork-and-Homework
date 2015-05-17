#include "Manager.h"

Manager::Manager(unsigned id, string name, unsigned age,
        unsigned experience, double salary, string qualification,
        string department, unsigned employees)
    : Employee(id, name, age, experience, salary, qualification), 
        department(department), employees(employees) {
}

ostream& Manager::inserter(ostream &os) const {
    Employee::inserter(os);
    os << endl;
    os << "Department: " << this->department << endl;
    os << "Employees: " << this->employees;
    
    return os;
}

istream& Manager::extractor(istream &is) {
    Employee::extractor(is);
    is >> this->department;
    is >> this->employees;
    
    return is;
}