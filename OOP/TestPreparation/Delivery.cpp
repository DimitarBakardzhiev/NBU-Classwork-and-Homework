/* 
 * File:   Delivery.cpp
 * Author: mitko
 * 
 * Created on May 14, 2015, 2:13 PM
 */

#include "Delivery.h"

#include "Product.h"
#include <iostream>
#include <cstring>

using namespace std;

Delivery::Delivery(char name[], unsigned int id, double kg, 
        unsigned h, unsigned w, unsigned l,
        char deliveryName[], double price, unsigned count) 
            : Product(name, id, kg, h, w, l), price(price), count(count) {
    strcpy(this->deliveryName, deliveryName);
}
    
ostream& Delivery::inserter(ostream& out) const {
    Product::inserter(out);
    out << endl << "Delivery name: " << this->deliveryName << endl;
    out << "Price: " << this->price << endl;
    out << "Count: " << this->count;
    
    return out;
}

istream& Delivery::extractor(istream &in) {
    Product::extractor(in);
    cout << "Enter Deilverer's name: ";
    in.getline(this->deliveryName, 30);
    cout << "Enter price: ";
    in >> this->price;
    cout << "Enter count: ";
    in >> this->count;
    in.ignore();
    
    return in;
}

Delivery& Delivery::sale(int count) {
    if (this->count >= count) {
        this->count--;
    } else {
        this->count = 0;
        cerr << "Not enough products!" << endl;
    }
    
    return *this;
}