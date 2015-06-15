#ifndef DATETIME_H
#define	DATETIME_H

#include <iostream>

using std::ostream;
using std::endl;

class DateTime {
private:
    int year;
    int month;
    int day;
    int hours;
    int minutes;
    
public:
    DateTime(int year = 0, int month = 0, int day = 0, int hours = 0, int minutes = 0);
    
    bool operator<(DateTime& other);
    ostream& inserter(ostream& os);
};

ostream& operator<<(ostream& os, DateTime &obj);

#endif	/* DATETIME_H */

