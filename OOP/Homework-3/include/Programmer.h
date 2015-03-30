#ifndef PROGRAMMER_H
#define PROGRAMMER_H

#include <Employee.h>

class Programmer : public Employee
{
    public:
        Programmer();
        Programmer(string, double);
        virtual ~Programmer();
        Programmer(const Programmer& other);
        Programmer& operator=(const Programmer& other);

        string getName() const;
};

#endif // PROGRAMMER_H
