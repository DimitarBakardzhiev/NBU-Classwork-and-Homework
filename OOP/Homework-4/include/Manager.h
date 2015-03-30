#ifndef MANAGER_H
#define MANAGER_H

#include <Employee.h>


class Manager : public Employee
{
    private:
        string department;

    protected:
        virtual void copy(const Manager&);
        virtual void print(ostream&) const;

    public:
        Manager();
        Manager(string, double, int, string);
        virtual ~Manager();
        Manager(const Manager& other);
        Manager& operator=(const Manager& other);

        string getDepartment() const;
        void setDepartment(string);
};

#endif // MANAGER_H
