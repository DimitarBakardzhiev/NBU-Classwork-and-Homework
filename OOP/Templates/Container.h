/* 
 * File:   Container.h
 * Author: mitko
 *
 * Created on May 7, 2015, 1:22 PM
 */

#ifndef CONTAINER_H
#define	CONTAINER_H

#include <iostream>

using namespace std;

template<typename T, typename S>
class Container {
    private:
        T first;
        S second;
        
    public:
        Container();
        Container(const T &, const S &);
        
        Container& operator+=(const Container&);
        bool operator>(const Container &) const;
        
        istream& ext(istream &);
        ostream& ins(ostream&) const;
};

template<typename T, typename S>
istream& operator>>(istream &, Container<T, S> &);
template<typename T, typename S>
ostream& operator<<(ostream &, const Container<T, S> &);

#endif	/* CONTAINER_H */