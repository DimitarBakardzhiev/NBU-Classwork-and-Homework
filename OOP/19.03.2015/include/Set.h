#ifndef SET_H
#define SET_H

#include <MultiSet.h>
#include <iostream>

using namespace std;

class Set : public MultiSet
{
    protected:
        void removeDuplicates();
        bool contains(int) const;

    public:
        Set();
        Set(int);
        virtual ~Set();
        Set(const Set&);
        Set(const MultiSet&);
        void add_elem(int);
        Set operator+(const Set&) const;

        friend ostream& operator<<(ostream&, const Set&);
};

#endif // SET_H
