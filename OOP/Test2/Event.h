#ifndef EVENT_H
#define	EVENT_H

#include <string>
#include <iostream>

using namespace std;

class Event {
private:
    unsigned day, month, year, invited;
    string title;
    
public:
    Event(unsigned day = 0, unsigned month = 0, unsigned year = 0, 
            string title = "", unsigned invited = 0);

    virtual ostream& inserter(ostream& os) const;
    virtual istream& extractor(istream& is);
};

ostream& operator<<(ostream& os, const Event& obj);
istream& operator>>(istream& is, Event& obj);

#endif

