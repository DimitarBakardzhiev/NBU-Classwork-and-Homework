#include "SortedSet.h"

SortedSet::SortedSet() : Set()
{
    this->isSorted = false;
}

SortedSet::SortedSet(int n) : Set(n)
{
    this->isSorted = false;
}

SortedSet::~SortedSet()
{
}

SortedSet::SortedSet(const SortedSet& other) : Set(other)
{
    this->isSorted = other.isSorted;
}

void SortedSet::insertionSort()
{
    for (int i = 1; i < this->n; i++)
    {
        int value = this->val[i];
        int index = i;
        while (index > 0 && this->val[index - 1] > value)
        {
            this->val[index] = this->val[index - 1];
            index--;
        }

        this->val[index] = value;
    }

    this->isSorted = true;
}

void SortedSet::add_elem(int element)
{
    Set::add_elem(element);
    this->isSorted = false;
}

ostream& operator<<(ostream& os, SortedSet& obj)
{
    if (obj.isSorted == false)
    {
        obj.insertionSort();
    }

    os << (MultiSet)obj;

    return os;
}
