#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

using namespace std;

class Employee
{
    private:
        string name;
        double salary;
        int yearsExperience;

    protected:
        virtual void copy(const Employee&);
        virtual void print(ostream&) const;

    public:
        Employee();
        Employee(string, double, int);
        virtual ~Employee();
        Employee(const Employee&);
        Employee& operator=(const Employee&);

        string getName() const;
        void setName(string);
        double getSalary() const;
        void setSalary(double);
        int getYearsExperience() const;
        void setYearsExperience(int);

        friend ostream& operator<<(ostream&, const Employee&);
};

#endif // EMPLOYEE_H
