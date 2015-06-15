/* 
 * File:   ExtendedDelivery.h
 * Author: mitko
 *
 * Created on May 21, 2015, 2:04 PM
 */

#ifndef EXTENDEDDELIVERY_H
#define	EXTENDEDDELIVERY_H

#include "Delivery.h"


class ExtendedDelivery : public Delivery {
private:
    unsigned expireDate;
    
public:
    ExtendedDelivery(char[] = "", unsigned int = 0, double = 0., 
            unsigned = 0, unsigned = 0, unsigned = 0,
            char[] = "", double = 0., unsigned = 0, unsigned expireDate = 0);
    
    ExtendedDelivery& registerExpiredDate(unsigned days);
    ExtendedDelivery& recalculatePrice();
};

#endif	/* EXTENDEDDELIVERY_H */

