#include "DateTime.h"

DateTime::DateTime(int year, int month, int day, int hours, int minutes)
    : year(year), month(month), day(day), hours(hours), minutes(minutes){
}

bool DateTime::operator<(DateTime& other) {
    if (this->year < other.year) {
        return 1;
    } else if (this->year == other.year) {
        
        if (this->month < other.month) {
            return 1;
        } else if (this->month == other.month) {
            
            if (this->day < other.day) {
                return 1;
            } else if (this->day == other.day) {
                
                if (this->hours < other.hours) {
                    return 1;
                } else if (this->hours == other.hours) {
                    if (this->minutes < other.minutes) {
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    return 0;
                }
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

ostream& DateTime::inserter(ostream& os) {
    os << this->day << "." << this->month << "." << this->year << " ";
    os << this->hours << ":" << this->minutes;
    
    return os;
}

ostream& operator<<(ostream& os, DateTime &obj) {
    return obj.inserter(os);
}