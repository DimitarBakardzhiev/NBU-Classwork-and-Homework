#ifndef SORTEDSET_H
#define SORTEDSET_H

#include <Set.h>


class SortedSet : public Set
{
    private:
        void insertionSort();
        bool isSorted;

    public:
        SortedSet();
        SortedSet(int);
        virtual ~SortedSet();
        SortedSet(const SortedSet&);

        void add_elem(int);
        friend ostream& operator<<(ostream&, SortedSet&);
};

#endif // SORTEDSET_H
