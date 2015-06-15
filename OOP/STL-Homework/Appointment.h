#ifndef APPOINTMENT_H
#define	APPOINTMENT_H

#include <string>
#include <iostream>
#include "DateTime.h"

using std::string;
using std::ostream;
using std::endl;

class Appointment {
private:
    DateTime date;
    string description;
    string address;
    string personToMeet;
    
public:
    Appointment(DateTime date = DateTime(), string description = "",
            string address = "", string personToMeet = "");
    
    bool operator<(Appointment &other);
    ostream& inserter(ostream& os);
};

ostream& operator<<(ostream& os, Appointment &obj);

#endif

