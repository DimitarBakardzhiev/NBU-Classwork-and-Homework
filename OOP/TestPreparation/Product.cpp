/* 
 * File:   Product.cpp
 * Author: mitko
 * 
 * Created on May 14, 2015, 1:13 PM
 */

#include "Product.h"

#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

Product::Product(char name[], unsigned int id, double kg, 
            unsigned h, unsigned w, unsigned l) : id(id), kg(kg), h(h), w(w), l(l) {
    strcpy(this->name, name);
}
    
ostream& Product::inserter(ostream& out) const {
    out << "Product name: " << this->name << endl;
    out << "Id: " << this->id << endl;
    out << "Weight: " << fixed << this->kg << endl;
    out << "Width: " << this->w << endl;
    out << "Height: " << this->h << endl;
    out << "Length: " << this->l;
    
    return out;
}

istream& Product::extractor(istream& in) {
    cout << "Enter product name: ";
    in.getline(this->name, 20);
    cout << "Enter Id: ";
    in >> this->id;
    cout << "Enter weight: ";
    in >> this->kg;
    cout << "Enter width: ";
    in >> this->w;
    cout << "Enter height: ";
    in >> this->h;
    cout << "Enter length: ";
    in >> this->l;
    in.ignore();
    
    return in;
}

ostream& operator<<(ostream &os, const Product &obj) {
    return obj.inserter(os);
}

istream& operator>>(istream &is, Product &obj) {
    return obj.extractor(is);
}