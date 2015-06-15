#include "Appointment.h"

Appointment::Appointment(DateTime date, string description,
            string address, string personToMeet)
    : date(date), description(description), address(address), personToMeet(personToMeet){
}

bool Appointment::operator<(Appointment &other) {
    return this->date < other.date;
}

ostream& Appointment::inserter(ostream& os) {
    os << this->date << endl;
    os << this->description << endl;
    os << this->address << endl;
    os << this->personToMeet;
    return os;
}

ostream& operator<<(ostream& os, Appointment &obj) {
    return obj.inserter(os);
}