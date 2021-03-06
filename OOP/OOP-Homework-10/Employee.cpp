#include "Employee.h"

Employee::Employee(unsigned id, string name, unsigned age,
            unsigned experience, double salary, string qualification)
    : id(id), name(name), age(age), experience(experience),
        salary(salary), qualification(qualification) {
}

ostream& Employee::inserter(ostream& os) const {
    os << "Employee: " << this->id << endl;
    os << "Name: " << this->name << endl;
    os << "Age: " << this->age << endl;
    os << "Experience: " << this->experience << endl;
    os << "Salary: " << this->salary << endl;
    os << "Qualification: " << this->qualification;
    
    return os;
}

istream& Employee::extractor(istream &is) {
    is >> this->id;
    is >> this->name;
    is >> this->age;
    is >> this->experience;
    is >> this->salary;
    is >> this->qualification;
    
    return is;
}

ostream& operator<<(ostream &os, Employee &obj) {
    return obj.inserter(os);
}

istream& operator>>(istream &is, Employee &obj) {
    return obj.extractor(is);
}

unsigned Employee::getAge() const {
    return this->age;
}

unsigned Employee::getExpericence() const {
    this->experience;
}

double Employee::getSalary() const {
    this->salary;
}

Employee* getYoungest(Employee **arr, int count) {
    Employee *youngest = arr[0];
    for (int i = 1; i < count; i++) {
        if (arr[i]->getAge() < youngest->getAge()) {
            youngest = arr[i];
        }
    }
    
    return youngest;
}

Employee* getMostExperienced(Employee **arr, int count) {
    Employee *mostExperienced = arr[0];
    for (int i = 1; i < count; i++) {
        if (arr[i]->getExpericence() > mostExperienced->getExpericence()) {
            mostExperienced = arr[i];
        }
    }
    
    return mostExperienced;
}

Employee* getHighestPaid(Employee **arr, int count) {
    Employee *highestPaid = arr[0];
    for (int i = 1; i < count; i++) {
        if (arr[i]->getSalary() > highestPaid->getSalary()) {
            highestPaid = arr[i];
        }
    }
    
    return highestPaid;
}