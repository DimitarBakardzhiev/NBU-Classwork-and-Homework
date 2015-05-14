/* 
 * File:   Product.h
 * Author: mitko
 *
 * Created on May 14, 2015, 1:13 PM
 */

#ifndef PRODUCT_H
#define	PRODUCT_H

#include <iostream>

using namespace std;

class Product {
private:
    char name[21];
    unsigned int id;
    double kg;
    unsigned h, w, l;
    
public:
    Product(char[] = "", unsigned int = 0, double = 0., 
            unsigned = 0, unsigned = 0, unsigned = 0);
    
    virtual ostream& inserter(ostream&) const;
    virtual istream& extractor(istream&);
};

ostream& operator<<(ostream &, const Product &);
istream& operator>>(istream &, Product &);

#endif	/* PRODUCT_H */

