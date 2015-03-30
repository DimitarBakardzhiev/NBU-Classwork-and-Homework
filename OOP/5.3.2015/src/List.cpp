#include "List.h"
#include <iostream>

template <class T>
List<T>::List()
{
    this->count = 0;
    this->size = 4;
    this->sequence = new T[this->size];
}

template <class T>
List<T>::~List()
{
    delete[] this->sequence;
}

template <class T>
void List<T>::copy(const List& other)
{
    this->count = other.count;
    this->size = other.size;

    this->sequence = new T[this->size];

    for (int i = 0; i < this->count; i++)
    {
        this->sequence[i] = other.sequence[i];
    }
}

template <class T>
List<T>::List(const List& other)
{
    this->copy(other);
}

template <class T>
List<T>& List<T>::operator=(const List& other)
{
    if (this != &other)
    {
        delete[] this->sequence;
        this->copy(other);
    }

    return *this;
}

template <class T>
int List<T>::getCount() const
{
    return this->count;
}

template <class T>
T& List<T>::operator[](int i) const
{
    return this->sequence[i];
}

template <class T>
bool List<T>::isFull() const
{
    return this->count == this->size;
}

template <class T>
void List<T>::add(T value)
{
    this->sequence[this->count] = value;
    this->count++;

    if (this->isFull())
    {
        this->size *= 2;
        T* saveValues = new T[this->size];

        for (int i = 0; i < this->count; i++)
        {
            saveValues[i] = this->sequence[i];
        }

        delete[] this->sequence;

        this->sequence = saveValues;
    }
}

/*
    Не минаваше компилация без следващите два реда.
    http://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor
*/
template class List<double>;
template class List<int>;
