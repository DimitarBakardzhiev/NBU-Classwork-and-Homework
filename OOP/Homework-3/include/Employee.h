#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

using namespace std;

class Employee
{
    private:
        string name;
        double salary;

        void copy(const Employee&);

    public:
        Employee();
        Employee(string, double);
        virtual ~Employee();
        Employee(const Employee&);
        Employee& operator=(const Employee&);

        virtual string getName() const;
        void setName(string);
        double getSalary() const;
        void setSalary(double salary);

        friend ostream& operator<<(ostream&, const Employee&);
};

#endif // EMPLOYEE_H
