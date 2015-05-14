#include "Set.h"

template<typename T>
Set<T>::Set()
{
    this->size = 4;
    this->data = new T[this->size];
    this->count = 0;
}

template<typename T>
Set<T>::Set(const Set& other) {
    this->size = other.size;
    this->data = new T[this->size];
    this->count = other.count;
    
    for (int i = 0; i < this->count; i++) {
        this->data[i] = other.data[i];
    }
}

template<typename T>
Set<T>::~Set()
{
    delete[] this->data;
}

template<typename T>
bool Set<T>::contains(T element) const {
    for (int i = 0; i < this->count; i++) {
        if (this->data[i] == element) {
            return true;
        }
    }

    return false;
}

template<typename T>
bool Set<T>::isEmpty() const {
    return this->count == 0;
}

template<typename T>
void Set<T>::extend() {
    this->size *= 2;
    T* newArray = new T[this->size];
    
    for (int i = 0; i < this->count; i++) {
        newArray[i] = this->data[i];
    }

    delete[] this->data;
    this->data = newArray;
}

template<typename T>
void Set<T>::add(T element) {
    if (this->count == this->size) {
        this->extend();
    }

    if (!this->contains(element)) {
        this->data[this->count] = element;
        this->count++;
    }
}

template<typename T>
void Set<T>::remove(T element) {
    // TODO
}