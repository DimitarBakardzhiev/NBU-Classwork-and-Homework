/* 
 * File:   Container.cpp
 * Author: mitko
 * 
 * Created on May 7, 2015, 1:22 PM
 */

#include "Container.h"
#include <typeinfo>

template<typename T, typename S>
Container<T, S>::Container() {
    this->first = T();
    this->second = S();
}

template<typename T, typename S>
Container<T, S>::Container(const T &f, const S &s) : first(f), second(s) {
}

template<typename T, typename S>
Container<T, S>& Container<T, S>::operator+=(const Container& other) {
    this->first += other.first;
    return *this;
}

template<typename T, typename S>
bool Container<T, S>::operator>(const Container & other) const {
    return this->second > other.second;
}

template<typename T, typename S>
istream& Container<T, S>::ext(istream & is) {
    is >> this->first >> this->second;
    return is;
}

template<typename T, typename S>
ostream& Container<T, S>::ins(ostream& os) const {
    os << "Type first: " << typeid(T).name() << " value first: " << this->first << endl;
    os << "Type second: " << typeid(S).name() << " value second: " << this->second << endl;
}

template<typename T, typename S>
istream& operator>>(istream & is, Container<T, S> &obj) {
    obj.ins(is);
    return is;
}

template<typename T, typename S>
ostream& operator<<(ostream & os, const Container<T, S> &obj) {
    obj.ext(os);
    return os;
}