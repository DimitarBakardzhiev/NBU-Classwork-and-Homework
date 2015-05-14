/* 
 * File:   Delivery.h
 * Author: mitko
 *
 * Created on May 14, 2015, 2:13 PM
 */

#ifndef DELIVERY_H
#define	DELIVERY_H

#include "Product.h"
#include <iostream>

using namespace std;

class Delivery : public Product {
private:
    char deliveryName[31];
    double price;
    unsigned count;
    
public:
    Delivery(char[] = "", unsigned int = 0, double = 0., 
            unsigned = 0, unsigned = 0, unsigned = 0,
            char[] = "", double = 0., unsigned = 0);
    
    virtual ostream& inserter(ostream&) const;
    virtual istream& extractor(istream&);
    
    Delivery& sale(int);
};

#endif	/* DELIVERY_H */

