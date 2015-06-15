#include "Event.h"

Event::Event(unsigned day, unsigned month, unsigned year, 
            string title, unsigned invited)
    : day(day), month(month), year(year), title(title), invited(invited){
}

ostream& Event::inserter(ostream& os) const {
    return os << day << "." << month << "." << year << " " << title << " " << invited;
}

istream& Event::extractor(istream& is) {
    is >> day >> month >> year >> title >> invited;
    while (title.length() > 20) {
        is >> title;
    }
    
    return is;
}

ostream& operator<<(ostream& os, const Event& obj) {
    return obj.inserter(os);
}

istream& operator>>(istream& is, Event& obj) {
    return obj.extractor(is);
}