#ifndef SET_H
#define SET_H

#include <MultiSet.h>
#include <iostream>

using namespace std;

class Set : public MultiSet
{
    private:
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
};

#endif // SET_H
