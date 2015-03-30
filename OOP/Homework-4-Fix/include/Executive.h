#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <Manager.h>


class Executive : public Manager
{
    protected:
        virtual void print(ostream&) const;

    public:
        Executive();
        Executive(string, double, int, string);
        virtual ~Executive();
        Executive(const Executive& other);
        Executive& operator=(const Executive& other);

        friend ostream& operator<<(ostream&, const Executive&);
};

#endif // EXECUTIVE_H
