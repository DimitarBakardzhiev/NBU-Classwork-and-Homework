/* 
 * File:   ExtendedDelivery.cpp
 * Author: mitko
 * 
 * Created on May 21, 2015, 2:04 PM
 */

#include "ExtendedDelivery.h"

ExtendedDelivery::ExtendedDelivery(char name[], unsigned int id, double kg, 
        unsigned h, unsigned w, unsigned l,
        char deliveryName[], double price, unsigned count, unsigned expireDate)
    : Delivery(name, id, kg, h, w, l, deliveryName, price, count) {
    this->expireDate = expireDate;
}

ExtendedDelivery& ExtendedDelivery::registerExpiredDate(unsigned days) {
    this->expireDate -= days;
    if (this->expireDate < 0) {
        this->expireDate = 0;
        cout << "Expired!" << endl;
    }

    return *this;
}

ExtendedDelivery& ExtendedDelivery::recalculatePrice() {
    if (this->expireDate <= 2) {
        this->price *= 4. / 10;
    }

    return *this;
}