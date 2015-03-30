#include "Set.h"

Set::Set() : MultiSet()
{
}

Set::Set(int n) : MultiSet(n)
{
}

Set::~Set()
{
}

Set::Set(const Set& other) : MultiSet(other)
{
}

Set::Set(const MultiSet& other) : MultiSet(other)
{
}

void Set::add_elem(int element)
{
    if (!this->contains(element))
    {
        MultiSet::add_elem(element);
    }
}

void Set::removeDuplicates()
{
    int length = 0;
    int* newArray = new int[this->n];

    // get unique values
    for (int i = 0; i < this->n; i++)
    {
        if (i > 0)
        {
            bool contains = false;
            for (int j = 0; j < length; j++)
            {
                if (newArray[j] == this->val[i])
                {
                    contains = true;
                    break;
                }
            }

            if (contains)
            {
                continue;
            }
        }

        newArray[length] = this->val[i];
        length++;
    }

    // shrink the size of the array with unique values
    delete[] this->val;
    this->val = new int[length];
    this->n = length;
    for (int i = 0; i < length; i++)
    {
        this->val[i] = newArray[i];
    }

    delete[] newArray;
}

ostream& operator<<(ostream& os, const Set& obj)
{
    os << "{";
    for(int i = 0; i < obj.n; i++)
    {
        if(i != 0 && i < obj.n)
        {
            os << "\t";
        }

        os << obj.val[i];
    }

    os << "}";
	return os;
}

bool Set::contains(int value) const
{
    for (int i = 0; i < this->n; i++)
    {
        if (this->val[i] == value)
        {
            return true;
        }
    }

    return false;
}

Set Set::operator+(const Set& other) const
{
    MultiSet multiSetResult = MultiSet::operator+(other);
    Set result = (Set)multiSetResult;
    result.removeDuplicates();

    return result;
}
