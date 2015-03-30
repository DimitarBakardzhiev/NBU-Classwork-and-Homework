#ifndef MULTISET_H
#define MULTISET_H

#include <iostream>

class MultiSet
{
    public:
        MultiSet();
        MultiSet(int);
        MultiSet(const MultiSet &);
        ~MultiSet();
        void add_elem(int);
        void del_elem(int);
        int length() const;
        MultiSet operator/(const MultiSet &)const;
        MultiSet operator+(const MultiSet &)const;
        MultiSet operator-(const MultiSet &)const;
        void set_n(int);
        void set_val(int*, int);
        int* get_val()const;
        friend std::ostream& operator<<(std::ostream&, const MultiSet &);
    protected:
        int n;
        int * val;
};

#endif // MULTISET_H
